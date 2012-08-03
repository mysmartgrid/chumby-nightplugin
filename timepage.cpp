#include "timepage.h"
#include "ui_timepage.h"

#include <QtCore/QDebug>
#include <QtCore/QTime>

TimePage::TimePage(QWidget *parent) :
  QWizardPage(parent),
  ui(new Ui::TimePage)
{
	ui->setupUi(this);

	registerField("hour", ui->hourEdit);
	registerField("minute", ui->minEdit);
}

void TimePage::initializePage()
{
	if ( ! field("hour").toString().isEmpty() )
	{
		qDebug() << "loaded time:" << field("hour").toString() << field("minute").toString();
		ui->hourEdit->setText(QString::number(field("hour").toInt()).rightJustified(2, '0'));
		ui->minEdit->setText(QString::number(field("minute").toInt()).rightJustified(2, '0'));
	} else {
		QTime now = QTime::currentTime();
		ui->hourEdit->setText(QString::number(now.hour()).rightJustified(2, '0'));
		ui->minEdit->setText(QString::number(now.minute()).rightJustified(2, '0'));
	}
	
	connect(ui->hourUp, SIGNAL(clicked()), this, SLOT(hourUp()));
	connect(ui->hourDown, SIGNAL(clicked()), this, SLOT(hourDown()));
	connect(ui->minUp, SIGNAL(clicked()), this, SLOT(minuteUp()));
	connect(ui->minDown, SIGNAL(clicked()), this, SLOT(minuteDown()));
}

TimePage::~TimePage()
{
	delete ui;
}

void TimePage::hourUp()
{
	int hour = ui->hourEdit->text().toInt();
	if ( hour < 23 )
		ui->hourEdit->setText(QString::number(hour+1).rightJustified(2, '0'));
	else
		ui->hourEdit->setText("00");
}

void TimePage::hourDown()
{
	int hour = ui->hourEdit->text().toInt();
	if ( hour > 0 )
		ui->hourEdit->setText(QString::number(hour-1).rightJustified(2, '0'));
	else
		ui->hourEdit->setText("23");
}

void TimePage::minuteUp()
{
	int minute = ui->minEdit->text().toInt();
	if ( minute < 59 )
		ui->minEdit->setText(QString::number(minute+1).rightJustified(2, '0'));
	else
		ui->minEdit->setText("00");
}

void TimePage::minuteDown()
{
	int minute = ui->minEdit->text().toInt();
	if ( minute > 0 )
		ui->minEdit->setText(QString::number(minute-1).rightJustified(2, '0'));
	else
		ui->minEdit->setText("59");
}
