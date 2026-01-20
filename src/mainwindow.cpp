#include "mainwindow.h"

void MainWindow::configureInterfaceColorScheme()
{
    // //temp local variable to describe and use shades of base colors
    // QColor tempColor;
    // //Set window background color
    // QPalette windowPalette;
    // QLinearGradient backgroundColorGradient(QPointF(0.0, 0.0),
    //                                         QPointF(GlobalConstants::mainWindowSize.width(),
    //                                                 GlobalConstants::mainWindowSize.height()));
    // backgroundColorGradient.setColorAt(0.0,
    //                                    GlobalConstants::colors[GlobalConstants::Colors::DARK_GREEN]);
    // tempColor = GlobalConstants::colors[GlobalConstants::Colors::DARK_GREEN];
    // tempColor.setRed(tempColor.red() * 0.50);
    // tempColor.setGreen(tempColor.green() * 0.50);
    // tempColor.setBlue(tempColor.blue() * 0.50);
    // backgroundColorGradient.setColorAt(1.0, tempColor);
    // backgroundColorGradient.setCoordinateMode(QGradient::CoordinateMode::LogicalMode);

    // windowPalette.setBrush(QPalette::ColorRole::Window, QBrush(backgroundColorGradient));

    // this->setPalette(windowPalette);

    // //Configure window UI elements:
    // //App page sign
    // QPalette windowSignPalette;
    // windowPalette.setColor(QPalette::Base, GlobalConstants::colors[GlobalConstants::Colors::OLIVE]);
    // windowPalette.setColor(QPalette::WindowText,
    //                        GlobalConstants::colors[GlobalConstants::Colors::DARK_GREEN]);
    // windowPalette.setColor(QPalette::Text,
    //                        GlobalConstants::colors[GlobalConstants::Colors::DARK_GREEN]);

    // m_windowSign->setPalette(windowSignPalette);
    // m_windowSign->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    // m_windowSign->setAutoFillBackground(true);
}

void MainWindow::configureInterface()
{
    //Configure window main layout
    m_mainLayout = new QVBoxLayout(this);
    this->setLayout(m_mainLayout);
    m_mainLayout->setContentsMargins(10, 5, 10, 20);

    //Configure window main UI elements:
    //App page sign
    m_windowSign = new QLabel(GlobalConstants::appName, this);
    m_windowSign->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    m_mainLayout->addSpacing(0);
    m_mainLayout->addWidget(m_windowSign);

    //Horizonal layout for main elements: line-editors, menu-s etc.
    QHBoxLayout *interactiveUI_layout = new QHBoxLayout;
    interactiveUI_layout->addSpacing(5);
    interactiveUI_layout->setContentsMargins(20, 5, 20, 5);
    m_mainLayout->addLayout(interactiveUI_layout);

    //#1 Line editor
    m_lineEdit_1 = new QLineEdit(this);
    m_lineEdit_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    interactiveUI_layout->addWidget(m_lineEdit_1);

    //#1 Drop-down menu
    m_currencyMenu_1 = new QComboBox(this);
    m_currencyMenu_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    interactiveUI_layout->addWidget(m_currencyMenu_1);

    //Coversion button
    m_convertButton = new QPushButton("Convert", this);
    interactiveUI_layout->addWidget(m_convertButton);
    
    //#2 Line editor
    m_lineEdit_2 = new QLineEdit(this);
    m_lineEdit_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    interactiveUI_layout->addWidget(m_lineEdit_2);

    //#2 Drop-down menu
    m_currencyMenu_2 = new QComboBox(this);
    m_currencyMenu_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    interactiveUI_layout->addWidget(m_currencyMenu_2);

    m_mainLayout->addSpacing(GlobalConstants::mainWindowSize.height()/2.5);
    
    //set debug info
    m_mainLayout->setObjectName("Main Window Layout");
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle(GlobalConstants::appName);
    //does not demonstrate any effect
    this->setFixedSize(GlobalConstants::mainWindowSize);
    this->setMinimumSize(GlobalConstants::mainWindowSize);
    this->setMaximumSize(GlobalConstants::mainWindowSize);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    
    
    this->setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    configureInterface();
    configureInterfaceColorScheme();
    
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    
    //set debug info
    this->setObjectName("App Main Window");
}

MainWindow::~MainWindow() {}
