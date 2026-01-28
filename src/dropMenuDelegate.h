#ifndef DROPMENUDELEGATE_H
#define DROPMENUDELEGATE_H

#include <QStyledItemDelegate>

#include <QPainter>
#include <QApplication>
#include <QTextDocument>
#include <QRegularExpression>
#include <QString>

class DropMenuDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit DropMenuDelegate(QObject *parent = nullptr);
    
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;


signals:
};

#endif // DROPMENUDELEGATE_H
