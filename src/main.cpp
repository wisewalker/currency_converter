#include "mainwindow.h"
#include "global_consts.h"

#include "apicommunicator.h"

#include <QApplication>
#include <QString>
#include <QRegularExpression>

#include <QMetaEnum>

namespace GlobalConstants {
//App UI global parms
const QString appName("Currency Convertor");
const QSize mainWindowSize(480, 220);
//API related parms
const QString apiURL("*your api*");
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    
    //window.show();
    

    return app.exec();
}   
