#include "mainwindow.h"
#include "global_consts.h"

#include <QApplication>


namespace GlobalConstants {
const QSize mainWindowSize(480, 220);
const QString apiURL("*type URL here*");
const QString appName("Currency Calculator");
const QMap<Colors, QColor> colors = {{Colors::GREY, QColor("#EDF4F2")},
                                     {Colors::OLIVE, QColor("#7C8363")},
                                     {Colors::DARK_GREEN, QColor("#31473A")}};
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();
    
    return app.exec();
}
