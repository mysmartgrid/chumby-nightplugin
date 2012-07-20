#include "alarmform.h"
#include "ui_alarmform.h"

#include "alarmwizard.h"

#include <QtCore/QDebug>

AlarmForm::AlarmForm(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::AlarmForm)
{
    _ui->setupUi(this);
		
		_ui->alarmList->addItem("New Alarm");
		
		//connect(_ui->alarmList, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(editAlarm(QListWidgetItem*, QListWidgetItem*)));
		connect(_ui->alarmList, SIGNAL(itemSelectionChanged()), this, SLOT(editAlarm()));
		connect(_ui->doneButton, SIGNAL(clicked()), this, SLOT(close()));
}

AlarmForm::~AlarmForm()
{
    delete _ui;
}

/*void AlarmForm::editAlarm(QListWidgetItem *previous, QListWidgetItem *current)
{
	if ( previous )
		qDebug() << previous->text();
	if ( current )
		qDebug() << "->" << current->text();
}*/

void AlarmForm::editAlarm()
{
	AlarmWizard *wizard = new AlarmWizard();
	wizard->showFullScreen();
}
