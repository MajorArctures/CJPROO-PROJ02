#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"
//#include "styles.qss"

//Adiciona o QTimer
#include <QTimer>
//Adiciona a caixa de mensagem
#include <QMessageBox>
//Para arquivos base QT - StyleSheet = qss
#include <QFile>
//Para animação
#include <QPropertyAnimation>
//Para fonte personalizada
#include <QFontDatabase>
//Para o Polish->
#include <QStyle>
#include <QDebug>

//para imagem do BG
#include <QPixmap>
#include <QPalette>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    isPaused(false),
    currentMode(POMODORO),
    pomodoroCount(0),
    pomEnd(false)

{

    ui->setupUi(this);
    ui->Pomodoro->setCurrentIndex(0);


    // Configura os QTimeEdit para mostrar mm:ss
    setupTimeEdits();

    //Cria o timer e chama o updateTimer
    pomodoroTimer = new QTimer(this);
    connect(pomodoroTimer, &QTimer::timeout, this, &MainWindow::updatePomodoro);

    // Inicialmente desabilita o botão de pausa
    ui->btnPausePomodoro->setEnabled(false);

    //fonte
    QFontDatabase::addApplicationFont("resources/fonts/Baloo2.ttf");

    //BG - criado como uma label
    QPixmap bg("resources/images/background.png");
    if (!bg.isNull()) {
        bg = bg.scaled(300, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation);

        QLabel *bgLabel = new QLabel(this);
        bgLabel->setPixmap(bg);
        bgLabel->setAlignment(Qt::AlignRight | Qt::AlignTop);

        // Posiciona no canto direito
        int xPos = this->width() - bg.width();
        int yPos = 0;

        bgLabel->setGeometry(
            xPos,
            yPos+50, //p deslocar p baixo
            bg.width(),
            bg.height()
            );
    }
    this->setFixedSize(600, 450);

    // Mostra o tempo padrão do Pom no display = 25min
    QTime defaultPomodoroTime = ui->timePom->time();
    ui->labelTimer->setText(defaultPomodoroTime.toString("mm:ss"));
    ui->progressPomodoro->setValue(0);

}

//destrutor
MainWindow::~MainWindow()
{
    delete ui;
}

//botão de config para pomodoro
void MainWindow::on_btnGoBack_clicked()
{
    // Atualiza o display com o tempo configurado
    QTime displayTime;
    switch(currentMode) {
    case POMODORO: displayTime = ui->timePom->time(); break;
    case SHORT_BREAK: displayTime = ui->timeSB->time(); break;
    case LONG_BREAK: displayTime = ui->timeLB->time(); break;
    }

    ui->labelTimer->setText(displayTime.toString("mm:ss"));
    ui->Pomodoro->setCurrentIndex(0);

    // Se estiver parado, atualiza também o remainingSeconds
    if(!pomodoroTimer->isActive()) {
        totalSeconds = remainingSeconds = displayTime.minute() * 60 + displayTime.second();
        ui->progressPomodoro->setValue(0);
    }
}

//botão de pomodoro para config
void MainWindow::on_btnConfig_clicked()
{
    ui->Pomodoro->setCurrentIndex(1);
}

//Config de botão para pausa
void MainWindow::on_btnPausePomodoro_clicked()
{
    if (isPaused) {
        // Se estava pausado, retoma
        pomodoroTimer->start(1000);
        ui->btnPausePomodoro->setText("PAUSE");
        isPaused = false;
    } else {
        // Se estava rodando, pausa
        pomodoroTimer->stop();
        ui->btnPausePomodoro->setText("RESUME");
        isPaused = true;
    }
}

//Edits para o tempo ficar em m:s e não h:m
void MainWindow::setupTimeEdits()
{
    // Configura todos os QTimeEdit para mostrar minutos:segundos
    ui->timePom->setDisplayFormat("mm:ss");
    ui->timeSB->setDisplayFormat("mm:ss");
    ui->timeLB->setDisplayFormat("mm:ss");

    // Define valores padrão
    ui->timePom->setTime(QTime(0, 25, 0));  // 25 minutos
    ui->timeSB->setTime(QTime(0, 5, 0));    // 05 minutos
    ui->timeLB->setTime(QTime(0, 15, 0));   // 15 minutos
}

//Configuração do botão de reset
void MainWindow::on_btnResetPomodoro_clicked()
{
    QTime resetTime;
    switch(currentMode) {
    case POMODORO: resetTime = ui->timePom->time(); break;
    case SHORT_BREAK: resetTime = ui->timeSB->time(); break;
    case LONG_BREAK: resetTime = ui->timeLB->time(); break;
    }
    pomodoroTimer->stop();

    // Restaura o tempo original
    QTime tempo = ui->timePom->time();
    remainingSeconds = totalSeconds = tempo.minute() * 60 + tempo.second();

    // Atualiza a interface
    ui->labelTimer->setText(tempo.toString("mm:ss"));
    ui->progressPomodoro->setValue(0);          // Zera a barra de progresso
    ui->btnStartPomodoro->setEnabled(true);     // Habilita o botão de start
    ui->btnPausePomodoro->setEnabled(false);    // Desabilita o botão de pause
    ui->btnPausePomodoro->setText("PAUSE");     // Fixa o texto Pause no botão
    isPaused = false;                           // Atualiza o modo para não pausado
}

//Inicia nova sessão de pom/sb/lb
void MainWindow::startNextSession()
{
    //para o timer
    pomodoroTimer->stop();

    // Só muda de estado se o pomEnd == true
    /*Para entender SB e LB só acontecem quando se completa um ciclo de pomodoro*/
    if (pomEnd) {
        if (currentMode == POMODORO) {
            pomodoroCount++; //para trocar entre SB e LB - 4 pomodoros = 1 LB

            //checa se pomodoroCount é igual a 4 por divisão
            if (pomodoroCount % POM_FOR_LB == 0) {
                currentMode = LONG_BREAK;
                ui->labelStatus->setText("Long Break Time!");
            } else {
                currentMode = SHORT_BREAK;
                ui->labelStatus->setText("Short Break Time!");
            }
        } else {
            currentMode = POMODORO;
            ui->labelStatus->setText("Pomodoro Time!");
        }
        pomEnd = false;
    }

    // Configura o tempo baseado no modo qie está
    QTime tempo;
    switch(currentMode) {
    case POMODORO:  tempo = ui->timePom->time(); break;
    case SHORT_BREAK: tempo = ui->timeSB->time(); break;
    case LONG_BREAK: tempo = ui->timeLB->time(); break;
    }

    totalSeconds = remainingSeconds = tempo.minute() * 60 + tempo.second();

    // Atualiza UI
    ui->labelTimer->setText(tempo.toString("mm:ss"));
    ui->progressPomodoro->setValue(0);
    ui->btnStartPomodoro->setEnabled(false);
    ui->btnPausePomodoro->setEnabled(true);
    ui->btnPausePomodoro->setText("PAUSE");
    ui->labelStatus->setText("Pomodoro Time!");
    isPaused = false;

    pomodoroTimer->start(1000);
    UIMode();
}

//Função para atualizar o pomodoro
void MainWindow::updatePomodoro()
{
    //Faz a contagem regressiva
    if (remainingSeconds > 0) {
        remainingSeconds--;

        // Atualiza display
        int minutes = remainingSeconds / 60; //Minutos
        int seconds = remainingSeconds % 60; //Segundos

        //Essa QString escreve em cima do "%1" de acordo com o que é passado
        ui->labelTimer->setText(QString("%1:%2")
        /*  2 é p numero de casas
            10 é p sistema de numeração
            Qchar 0 é p adicionar a esquerda */
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0')));

        // Atualiza progresso
        // A barra pega o progresso d tempo já decorrido
        int progress = 100 * (totalSeconds - remainingSeconds) / totalSeconds;
        ui->progressPomodoro->setValue(progress);
    } else {
        pomodoroTimer->stop();
        pomEnd = true;          // Marca que o tempo acabou
        startNextSession();     // Inicia próxima sessão

        // Toca um som
        //nota: tem que trocar, ta irritante!!!!
        QApplication::beep();
    }
}

//O botão de reiniciar o pomodoro, zera a contagem!
void MainWindow::on_btnStartPomodoro_clicked()
{
    currentMode = POMODORO;
    pomodoroCount = 0;
    pomEnd = false;  // Reseta o estado
    UIMode();
    startNextSession();
}

//Carrega os diferentes estilos
void MainWindow::loadStylesheet(const QString &mode) {
    //para confgigurar o caminho
    QString path = QCoreApplication::applicationDirPath() + "/" + mode;
    QFile file(path);

    //Para localizar erros na hora de abrir
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "Erro ao abrir arquivo QSS:" << path;
        return;
    }

    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);
}

//seitch para trocar os estilos
void MainWindow::UIMode() {
    switch(currentMode) {
    case POMODORO: //azul
        loadStylesheet("pomodoro.qss");
        ui->labelStatus->setText("Pomodoro Time!");
        break;
    case SHORT_BREAK: //
        loadStylesheet("shortbreak.qss");
        ui->labelStatus->setText("Short Break!");
        break;
    case LONG_BREAK:
        loadStylesheet("longbreak.qss");
        ui->labelStatus->setText("Long Break!");
        break;
    }
}

