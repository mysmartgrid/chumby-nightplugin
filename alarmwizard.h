#ifndef ALARMWIZARD_H
#define ALARMWIZARD_H

#include <QWizard>

#include "../../controlpanel/alarmdaemon.h"

class AlarmWizard : public QWizard
{
    Q_OBJECT
public:
    explicit AlarmWizard(QWidget *parent = 0, Alarm *alarm = 0);
    
signals:
    
public slots:
    
};

#endif // ALARMWIZARD_H
