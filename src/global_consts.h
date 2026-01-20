#ifndef GLOBAL_CONSTS_H
#define GLOBAL_CONSTS_H

#include <QSize>
#include <QColor>
#include <QMap>
#include <QString>

namespace GlobalConstants {
enum class Colors { GREY, OLIVE, DARK_GREEN };
extern const QSize mainWindowSize;
extern const QString apiURL;
extern const QString appName;
//palette main colors
extern const QMap<Colors, QColor> colors;
}

#endif // GLOBAL_CONSTS_H
