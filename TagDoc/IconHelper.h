#ifndef ICONHELPER_H
#define ICONHELPER_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QtGui>
#include <QtWidgets>
#include <qfont.h>

class IconHelper : public QObject
{
    Q_OBJECT
private:
    explicit IconHelper(QObject *parent = 0);
    QFont iconFont;
    static IconHelper* _instance;
public:
    static IconHelper* Instance()
    {
        static QMutex mutex;
        if(!_instance)
        {
            QMutexLocker locker(&mutex);
            if(!_instance)
            {
                _instance = new IconHelper;
            }
        }
        return _instance;
    }
    void SetIcon(QLabel* ctl,QChar c,int size=10);
    void SetIcon(QPushButton* ctl,QChar c,int size=10);

signals:

public slots:

};

#endif // ICONHELPER_H
