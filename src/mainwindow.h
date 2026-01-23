#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "global_consts.h"
#include "dropMenuDelegate.h"

#include <QMainWindow>

#include <QDebug>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QComboBox>

#include <QPixmap>
#include <QIcon>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QFile>
#include <QAbstractItemView>

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
    
    ~MainWindow();
    
private:
    void configureInterfaceStructure();
    void configureInterfaceStyle();
    void configureInterfaceFunctionality();
    
private slots:
        
};


#endif // MAINWINDOW_H
