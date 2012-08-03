#include "namepage.h"
#include "ui_namepage.h"

NamePage::NamePage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::NamePage)
{
    ui->setupUi(this);
		
		registerField("name", ui->nameEdit);
}

NamePage::~NamePage()
{
    delete ui;
}

void NamePage::initializePage()
{
	if ( field("name").toString().isEmpty() )
	{
		ui->nameEdit->setText("foobar");
	} else {
		ui->nameEdit->setText(field("name").toString());
	}
}
