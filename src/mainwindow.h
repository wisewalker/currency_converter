#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "global_consts.h"
#include "dropMenuDelegate.h"
#include "apicommunicator.h"
#include "inputValidator.h"

#include <QMainWindow>

#include <QDebug>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QComboBox>

#include <QIcon>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QFile>
#include <QAbstractItemView>

class APICommunicator;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    using appliedLayout_t = QVBoxLayout;
    
private:
    //Interface constants
    const double maxEnterValue = 1'000'000'000.0;
    const int maxDigitsAfterDot = 2;
    
    appliedLayout_t *m_mainLayout = nullptr;
    QLabel *m_windowSign = nullptr;

    QLineEdit *m_lineEdit_1 = nullptr;
    QComboBox *m_currencyMenu_1 = nullptr;
    QPushButton *m_exchangeCurrenciesButton = nullptr;
    QLineEdit *m_lineEdit_2 = nullptr;
    QComboBox *m_currencyMenu_2 = nullptr;

    APICommunicator *m_apiCommunicator = nullptr;
        
public:
    explicit MainWindow(QWidget *parent = nullptr);
    
    ~MainWindow();
    
private:
    void configureInterfaceStructure();
    void configureInterfaceStyle();
    void configureInterfaceFunctionality();
    QString calculateCurrencyResultValue(const QString &enteredValue,
                                       const QString &fromCurrancy,
                                       const QString &toCurrancy);
    
private slots:
    void initConfiguration();
    void onCurrencyMenuOptionChanged(int);
    void onEntryFieldChanged(const QString &text);
    void onExchangeCurrencies(bool);
};


#endif // MAINWINDOW_H
