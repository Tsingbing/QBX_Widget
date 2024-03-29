
#ifndef MASTERTHREAD_H
#define MASTERTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include "data_struct.h"

//! [0]
class MasterThread : public QThread
{
    Q_OBJECT

public:
    explicit MasterThread(QObject *parent = nullptr);
    ~MasterThread();

    void transaction(const QString &portName, int waitTimeout, const QByteArray &request);
    void run() Q_DECL_OVERRIDE;

signals:
    void response(const QByteArray &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    QString portName;
	QByteArray request;
    int waitTimeout;
    QMutex mutex;
    QWaitCondition cond;
    bool quit;
};
//! [0]

#endif // MASTERTHREAD_H
