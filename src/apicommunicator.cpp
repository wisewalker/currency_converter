#include "apicommunicator.h"

APICommunicator::APICommunicator(QObject *parent)
    : QObject{parent}
{
    m_networkManager = new QNetworkAccessManager(this);
    m_networkManager->setObjectName("networkManager");

    QObject::connect(m_networkManager,
                     &QNetworkAccessManager::finished,
                     this,
                     &APICommunicator::onAPI_RequestFinished);

    for (const auto &currency : m_currencyNames) {
        makeRequest(currency);
        m_pendingRequests.insert("Request - " + currency);
    }
}

void APICommunicator::makeRequest(const QString &currency)
{
    QNetworkRequest *request = new QNetworkRequest(QUrl(GlobalConstants::apiURL + currency));

    m_networkManager->get(*request);
}

void APICommunicator::printCurrencyData()
{
    qDebug() << "Currency Data---------------------------------------------";
    for (const auto &fromCurrency : m_currencyNames) {
        qDebug() << "From " << fromCurrency;
        for (const auto &toCurrency : m_currencyNames) {
            qDebug() << "To " << toCurrency << ": " << m_currencies[fromCurrency][toCurrency];
        }
    } 
}

const QMap<QString, QMap<QString, qreal>> &APICommunicator::currencyData() const
{
    return this->m_currencies;
}

const QStringList &APICommunicator::currencyNames() const
{
    return this->m_currencyNames;
}

void APICommunicator::onAPI_RequestFinished(QNetworkReply *reply)
{
    QErrorMessage errorBox;
    errorBox.setParent(qobject_cast<QWidget*>(this->parent()));
    
    if (!reply->error()) {
        QByteArray obtainedData = reply->readAll();
        QJsonDocument document = QJsonDocument::fromJson(obtainedData);

        if (document.isArray() || document.isEmpty() || document.isNull()) {            
            errorBox.showMessage("Problem occured while parsing JSON!\n");
            errorBox.exec();
            QApplication::quit();
        }

        QJsonObject rootObject = document.object();

        QJsonObject currency_values = rootObject["rates"].toObject();
        if(currency_values.isEmpty())
        {
            QErrorMessage errorBox;
            errorBox.showMessage("Problem occured while parsing JSON!\n");
            errorBox.exec();
            QApplication::quit();
        }
        
        QString baseCode = rootObject["base"].toString();
        
        for (const auto &currencyName : m_currencyNames) {
            m_currencies[baseCode][currencyName] = currency_values[currencyName].toDouble();
        }
        
        //Add this check-construction in order to prevent any actions (like, printing currency data)
        //before we conduct all requests and process according data
        m_pendingRequests.remove("Request - " + baseCode);
        
        if(m_pendingRequests.isEmpty())
        {
            emit allRequestsFinished();
        }
    }
    else
    {
        errorBox.showMessage("Problem occured while getting service reply!\n");
        errorBox.exec();
        QApplication::quit();
    }
    
    reply->deleteLater();
}

APICommunicator::~APICommunicator()
{
    
}
