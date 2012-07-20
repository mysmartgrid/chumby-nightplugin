#include "daypage.h"
#include "ui_daypage.h"

DayPage::DayPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::DayPage)
{
    ui->setupUi(this);
}

DayPage::~DayPage()
{
    delete ui;
}
