#include "summarypage.h"
#include "ui_summarypage.h"

#include "alarmwizard.h"

#include <QtCore/QDebug>

SummaryPage::SummaryPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::SummaryPage)
{
    ui->setupUi(this);
}

void SummaryPage::initializePage()
{
		ui->textBrowser->append(field("hour").toString());
		ui->textBrowser->append(field("minute").toString());
		ui->textBrowser->append(field("monday").toString());
		ui->textBrowser->append(field("tuesday").toString());
		ui->textBrowser->append(field("wednesday").toString());
		ui->textBrowser->append(field("thursday").toString());
		ui->textBrowser->append(field("friday").toString());
		ui->textBrowser->append(field("saturday").toString());
		ui->textBrowser->append(field("sunday").toString());
		ui->textBrowser->append(field("weekday").toString());
		ui->textBrowser->append(field("weekend").toString());
		ui->textBrowser->append(field("name").toString());
		ui->textBrowser->append(((AlarmWizard*) wizard())->getSource());
}

SummaryPage::~SummaryPage()
{
    delete ui;
}

int SummaryPage::nextId() const
{
	return -1;
}
