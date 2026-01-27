#ifndef APICOMMUNICATOR_H
#define APICOMMUNICATOR_H

#include "global_consts.h"
#include "mainwindow.h"

#include <QObject>

#include <QApplication>

#include <QErrorMessage>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

class APICommunicator : public QObject
{
    Q_OBJECT

private:
    QNetworkAccessManager *m_networkManager = nullptr;
    const QStringList m_currencyNames
        = {"RUB", "USD", "EUR", "CHF", "GBP", "JOD", "JPY", "PLN", "SEK", "TRY"};
    QMap<QString, QMap<QString, qreal>> m_currencies;
    
    QSet<QString> m_pendingRequests;
    
public:
    explicit APICommunicator(QObject *parent = nullptr);

    void printCurrencyData();

    const QMap<QString, QMap<QString, qreal>> &currencyData() const;

    const QStringList &currencyNames() const;
    
    ~APICommunicator();

private:
    void makeRequest(const QString& currency);
    
private slots:
    void onAPI_RequestFinished(QNetworkReply* reply);
    
signals:
    void allRequestsFinished();
};

#endif // APICOMMUNICATOR_H
