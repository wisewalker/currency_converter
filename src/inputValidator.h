#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <QObject>
#include <QDoubleValidator>
#include <QRegularExpression>

class InputValidator : public QDoubleValidator
{
    Q_OBJECT
public:
    explicit InputValidator(QObject *parent = nullptr);

private:
    virtual QValidator::State validate(QString &input, int &pos) const override;
    
signals:
};

#endif // INPUTVALIDATOR_H
