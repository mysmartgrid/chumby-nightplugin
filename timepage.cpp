#include "timepage.h"
#include "ui_timepage.h"

#include <QtCore/QTime>

TimePage::TimePage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::TimePage)
{
    ui->setupUi(this);
		
		QTime now = QTime::currentTime();
		ui->hourEdit->setText(QString::number(now.hour()));
		ui->minEdit->setText(QString::number(now.minute()));
		
		registerField("hour", ui->hourEdit);
		registerField("minute", ui->minEdit);
}

TimePage::~TimePage()
{
    delete ui;
}

void TimePage::hourUp()
{
	int hour = ui->hourEdit->text().toInt();
	if ( hour < 23 )
		ui->hourEdit->setText(QString::number(hour+1));
	else
		ui->hourEdit->setText("00");
}

void TimePage::hourDown()
{
	int hour = ui->hourEdit->text().toInt();
	if ( hour > 0 )
		ui->hourEdit->setText(QString::number(hour-1));
	else
		ui->hourEdit->setText("23");
}

void TimePage::minuteUp()
{
	int minute = ui->minEdit->text().toInt();
	if ( minute < 23 )
		ui->minEdit->setText(QString::number(minute+1));
	else
		ui->minEdit->setText("00");
}

void TimePage::minuteDown()
{
	int minute = ui->minEdit->text().toInt();
	if ( minute > 0 )
		ui->minEdit->setText(QString::number(minute-1));
	else
		ui->minEdit->setText("59");
}
