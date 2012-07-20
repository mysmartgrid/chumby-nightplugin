#ifndef TIMEPAGE_H
#define TIMEPAGE_H

#include <QWizardPage>

namespace Ui {
class TimePage;
}

class TimePage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit TimePage(QWidget *parent = 0);
    ~TimePage();
	
private slots:
	void hourUp();
	void hourDown();
	void minuteUp();
	void minuteDown();
	
private:
    Ui::TimePage *ui;
};

#endif // TIMEPAGE_H
