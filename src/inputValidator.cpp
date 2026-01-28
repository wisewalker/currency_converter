#include "inputValidator.h"

InputValidator::InputValidator(QObject *parent)
    : QDoubleValidator{parent}
{
    this->setDecimals(7);
    this->setBottom(0.0);
    this->setTop(1000.0);
    this->setNotation(QDoubleValidator::StandardNotation);
}

QValidator::State InputValidator::validate(QString &input, int &pos) const
{
    if (input.isEmpty()) {
        return Intermediate;
    }

    if (input.length() > 1)
        if (input.startsWith("0") && !input.startsWith("0."))
            return Invalid;

    if (input.count('.') == 1) {
        int dotIndex = input.indexOf('.');
        QString afterDot = input.mid(dotIndex + 1);
        if (afterDot.length() > this->decimals()) {
            return Invalid;
        }
    }
    
    bool castSuccess;
    double value = this->locale().toDouble(input, &castSuccess);
    if (!castSuccess) {
        return Invalid;
    }

    if (this->bottom() < value && value < this->top()) {
        return Intermediate;
    } else if (value < this->bottom() || this->top() < value) {
        return Invalid;
    }

    return this->QDoubleValidator::validate(input, pos);
}
