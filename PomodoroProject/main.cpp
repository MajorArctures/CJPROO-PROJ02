#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Obter caminho absoluto da pasta do executável
    QString stylePath = QCoreApplication::applicationDirPath() + "/styles.qss";
    QFile file(stylePath);

    if (file.exists()) {
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream stream(&file);
            QString styleSheet = stream.readAll();
            app.setStyleSheet(styleSheet);
            qDebug() << " Estilo carregado de:" << stylePath;
            file.close();
        } else {
            qWarning("Não foi possível abrir o arquivo styles.qss");
        }
    } else {
        qWarning(" Arquivo styles.qss não encontrado em:");
        qWarning() << stylePath.toUtf8().constData();
    }

    MainWindow w;
    w.show();
    return app.exec();
}
