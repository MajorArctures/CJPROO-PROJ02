#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnGoBack_clicked();
    void on_btnConfig_clicked();
    void on_btnStartPomodoro_clicked();
    void on_btnPausePomodoro_clicked();
    void updatePomodoro();
    void on_btnResetPomodoro_clicked();


private:
    Ui::MainWindow *ui;
    QTimer *pomodoroTimer;
    int totalSeconds;
    int remainingSeconds;
    bool isPaused;
    void setupTimeEdits();                          // Para editar os Qtime com mm:ss
    void UIMode();                                  // Método p atualizar o status (a label) no UI
    void loadStylesheet(const QString &filename);   // Para fazer as mudanças de estilo


    enum TimerMode { POMODORO, SHORT_BREAK, LONG_BREAK };
    TimerMode currentMode;
    int pomodoroCount;                               // Contador de pomodoros completos
    const int POM_FOR_LB = 4;                        // Const para Long break
    bool pomEnd;
    void startNextSession();
};
#endif
