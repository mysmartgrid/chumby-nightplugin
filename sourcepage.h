#ifndef SOURCEPAGE_H
#define SOURCEPAGE_H

#include <QWizardPage>
#include <QListWidgetItem>

#include "../../controlpanel/audioplugin.h"

namespace Ui {
class SourcePage;
}

class SourcePage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit SourcePage(QWidget *parent = 0, QString source = "");
	void initializePage();
	bool isComplete() const;
	int nextId() const;
    ~SourcePage();
	
protected slots:
	void selectSource(QListWidgetItem *item);
    
private:
		Msg::AudioPlugin* getPlugin();
		QString getPath() const;
    Ui::SourcePage *_ui;
		QString _source;
		Msg::AudioPlugin* _plugin;
};

#endif // SOURCEPAGE_H
