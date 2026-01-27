#include "mainwindow.h"

void MainWindow::configureInterfaceStyle()
{
    QFile styleFile(":/resources/ui_style.css");
    if (!styleFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Style file CANNOT be read!";
        return;
    } else {
        QTextStream in(&styleFile);
        this->setStyleSheet(in.readAll());
    }
}

void MainWindow::configureInterfaceFunctionality()
{
    const double maxEnterValue = 10.0;
    QDoubleValidator *validator = new QDoubleValidator(this);
    validator->setRange(0.0, maxEnterValue, 6);
    
    m_lineEdit_1->setValidator(validator);

    m_lineEdit_2->setValidator(validator);
    m_lineEdit_2->setReadOnly(true);
    
    QStringList currencies = m_apiCommunicator->currencyNames();
    currencies.sort();
    
    m_currencyMenu_1->setItemDelegate(new DropMenuDelegate(m_currencyMenu_1));
    m_currencyMenu_2->setItemDelegate(new DropMenuDelegate(m_currencyMenu_2));

    for (QStringList::iterator currency_iter = currencies.begin();
         currency_iter != currencies.end();
         ++currency_iter) {
        
        m_currencyMenu_1->addItem(QIcon(":"+*currency_iter), *currency_iter);
        m_currencyMenu_2->addItem(QIcon(":"+*currency_iter), *currency_iter);
    }
}

void MainWindow::configureInterfaceStructure()
{
    //Configure window main UI elements:
    //App page sign
    m_windowSign = new QLabel(GlobalConstants::appName, this);
    m_windowSign->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    m_windowSign->setObjectName("windowSign");
    m_windowSign->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    //#1 Line editor
    m_lineEdit_1 = new QLineEdit(m_lineEdit_1);
    m_lineEdit_1->setObjectName("lineEdit_1");
    m_lineEdit_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    //#1 Drop-down menu
    m_currencyMenu_1 = new QComboBox(this);
    m_currencyMenu_1->setObjectName("currencyMenu_1");
    m_currencyMenu_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    m_currencyMenu_1->view()->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    //Coversion button
    m_convertButton = new QPushButton(this);
    m_convertButton->setObjectName("conversionButton");
    m_convertButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    //#2 Line editor
    m_lineEdit_2 = new QLineEdit(this);
    m_lineEdit_2->setObjectName("lineEdit_2");
    m_lineEdit_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    //#2 Drop-down menu
    m_currencyMenu_2 = new QComboBox(this);
    m_currencyMenu_2->setObjectName("currencyMenu_2");
    m_currencyMenu_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    //Horizonal layout for main elements: line-editors, menu-s etc.
    QHBoxLayout *interactiveUI_layout = new QHBoxLayout;
    interactiveUI_layout->setContentsMargins(10, 5, 10, 5);

    interactiveUI_layout->addStretch(0);
    interactiveUI_layout->addWidget(m_lineEdit_1, 0, Qt::AlignLeft);
    interactiveUI_layout->addSpacing(-5);
    interactiveUI_layout->addWidget(m_currencyMenu_1, 0, Qt::AlignLeft);
    interactiveUI_layout->addSpacing(15);
    interactiveUI_layout->addWidget(m_convertButton, 0, Qt::AlignHCenter);
    interactiveUI_layout->addSpacing(15);
    interactiveUI_layout->addWidget(m_lineEdit_2, 0, Qt::AlignRight);
    interactiveUI_layout->addSpacing(-5);
    interactiveUI_layout->addWidget(m_currencyMenu_2, 0, Qt::AlignRight);
    interactiveUI_layout->addStretch(0);

    //Configure window main layout
    m_mainLayout = new QVBoxLayout(this);
    this->setLayout(m_mainLayout);

    m_mainLayout->addStretch(0);
    m_mainLayout->addWidget(m_windowSign);
    m_mainLayout->addStretch(0);
    m_mainLayout->addLayout(interactiveUI_layout);
    m_mainLayout->addStretch(2);  
    m_mainLayout->addSpacing(GlobalConstants::mainWindowSize.height() / 5);
    
    //set debug info
    m_mainLayout->setObjectName("mainWindowLayout");
}

void MainWindow::initConfiguration()
{
    configureInterfaceFunctionality();
    show();
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle(GlobalConstants::appName);
    this->setObjectName("mainWindow");
    this->setMinimumSize(GlobalConstants::mainWindowSize);
    
    configureInterfaceStructure();
    configureInterfaceStyle();
    
    m_apiCommunicator = new APICommunicator(this);
    
    QObject::connect(m_apiCommunicator,
                     &APICommunicator::allRequestsFinished,
                     this,
                     &MainWindow::initConfiguration);
    
    this->hide();
}

MainWindow::~MainWindow()
{
    
}
