#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "global_consts.h"

#include <QMainWindow>

#include <QDebug>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QValidator>
#include <QComboBox>

#include <QPixmap>
#include <QIcon>
#include <QGradient>

#include <QVBoxLayout>
#include <QHBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    using appliedLayout_t = QVBoxLayout;
    
private:
    appliedLayout_t *m_mainLayout = nullptr;
    QLabel *m_windowSign = nullptr;

    QLineEdit *m_lineEdit_1 = nullptr;
    QComboBox *m_currencyMenu_1 = nullptr;
    QPushButton *m_convertButton = nullptr;
    QLineEdit *m_lineEdit_2 = nullptr;
    QComboBox *m_currencyMenu_2 = nullptr;
    
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void configureInterface();
    void configureInterfaceColorScheme();
    
    
    ~MainWindow();
};


#endif // MAINWINDOW_H
