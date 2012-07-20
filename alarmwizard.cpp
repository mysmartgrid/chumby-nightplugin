#include "alarmwizard.h"

#include "timepage.h"
#include "daypage.h"

AlarmWizard::AlarmWizard(QWidget *parent, Alarm* alarm) :
    QWizard(parent)
{
	if ( alarm )
	{
		//load settings
		setField("hour", alarm->getHour());
		setField("minute", alarm->getMinute());
	}
	
	setPage(0, new TimePage());
	setPage(1, new DayPage());
	
	//setStartId(0); //not needed as default startId is 0
}
