#include "mainwindow.h"
#include "global_consts.h"

#include <QApplication>
#include <QString>
#include <QRegularExpression>

namespace GlobalConstants {
//App UI global parms
const QString appName("Currency Convertor");
const QSize mainWindowSize(480, 220);
//API related parms
const QString apiURL("https://api.exchangerate-api.com/v4/latest/usd");
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();
  
    return app.exec();
}   
