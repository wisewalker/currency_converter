#include "dropMenuDelegate.h"

DropMenuDelegate::DropMenuDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
    
}

void DropMenuDelegate::paint(QPainter *painter,
                             const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    painter->save();

    QStyleOptionViewItem opt = option;
    this->initStyleOption(&opt, index);

    QVariant iconVar = index.data(Qt::DecorationRole);
    if (iconVar.isValid() && iconVar.canConvert<QIcon>()) {
        QIcon icon = iconVar.value<QIcon>();

        QRect iconRect = opt.rect;
        iconRect.setWidth(opt.decorationSize.width());
        iconRect = QStyle::alignedRect(opt.direction,
                                       Qt::AlignLeft | Qt::AlignVCenter,
                                       opt.decorationSize,
                                       iconRect);

        QPixmap pixmap = icon.pixmap(opt.decorationSize);
        painter->drawPixmap(iconRect, pixmap);
        
        opt.rect.setLeft(iconRect.right() + 4);
    }


    QString text = index.data(Qt::DisplayRole).toString();

    QString currencyCode = text.section(' ', 0, 0);
    QString currencyName = text.section(' ', 1);

    QString html = QString("<b style='color:#e8f5e9;'>%1</b> "
                           "<i style='color:#e8f5e9;'>%2</i>")
                       .arg(currencyCode, currencyName);

    if (opt.state & QStyle::State_Selected)
        painter->fillRect(opt.rect, opt.palette.highlight());

    QTextDocument doc;
    doc.setHtml(html);
    doc.setDocumentMargin(2);

    painter->translate(opt.rect.left(), opt.rect.top());
    QRect clip(0, 0, opt.rect.width(), opt.rect.height());
    doc.drawContents(painter, clip);
    
    painter->restore();
}
