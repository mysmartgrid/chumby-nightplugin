#include "sourcepage.h"
#include "ui_sourcepage.h"

#include "alarmwizard.h"
#include "../../controlpanel/musiccontrol.h"

#include <QtCore/QDebug>

SourcePage::SourcePage(QWidget *parent, QString source) :
  QWizardPage(parent),
  _ui(new Ui::SourcePage),
  _source(source)
{
	_ui->setupUi(this);
	
	_plugin = NULL;

	connect(_ui->sourceList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(selectSource(QListWidgetItem*)));
}

SourcePage::~SourcePage()
{
	delete _ui;
}

void SourcePage::initializePage()
{
	if ( _source.isEmpty() )
	{
		_ui->sourceList->addItems(Msg::MusicControl::getInstance().getAudioPlugins());
		//load source from wizard, if available
		if ( !((AlarmWizard*) wizard())->getSource().isEmpty() )
		{
			QString src = ((AlarmWizard*) wizard())->getSource();
			int index = src.indexOf("/");
			src.remove(index, src.length());
			qDebug() << "abcde" << src;
			QList<QListWidgetItem*> items = _ui->sourceList->findItems(src, Qt::MatchExactly);
			if ( items.size() != 1 )
				return;
			
			_ui->sourceList->clearSelection();
			items.first()->setSelected(true);
			selectSource(items.first());
		}
	} else {
		Msg::AudioPlugin* plugin = getPlugin();
		_ui->sourceList->addItems(plugin->getSourceList());
		//load source from wizard, if available
		if ( !((AlarmWizard*) wizard())->getSource().isEmpty() )
		{
			QString src = ((AlarmWizard*) wizard())->getSource();
			int index = src.indexOf("/");
			src.remove(0, index + 1);
			qDebug() << "abcde" << src;
			QList<QListWidgetItem*> items = _ui->sourceList->findItems(src, Qt::MatchExactly);
			if ( items.size() != 1 )
				return;
			
			_ui->sourceList->clearSelection();
			items.first()->setSelected(true);
			selectSource(items.first());
		}
	}
}

void SourcePage::selectSource(QListWidgetItem *item)            
{                                                               
	if ( item )                                                 
	{                                                           
		qDebug() << item->text();
		QString src;
		if ( !_source.isEmpty() )
			src = QString("%1/%2").arg(_source, item->text());
		else
			src = item->text();
		//((AlarmWizard*)this->wizard())->setNewSource(src);      
		qDebug() << src;                                        
		_source = src;
		getPlugin();
		emit completeChanged();
	}                                                           
}

bool SourcePage::isComplete() const
{
	return _ui->sourceList->selectedItems().size() > 0;
}

int SourcePage::nextId() const
{
	qDebug() << "pre nextId";
	if ( _source.isEmpty() )
		return ((AlarmWizard*)this->wizard())->getNextPage();
	if ( _plugin != NULL && _plugin->isFinal(getPath()) )
	{
		((AlarmWizard*) wizard())->setSource(_source);      
		return AlarmWizard::NAMEPAGE;
	}
	else
	{
		SourcePage* next_page = new SourcePage(NULL, _source);
		((AlarmWizard*) this->wizard())->addPage(next_page);
		return ((AlarmWizard*)this->wizard())->getNextPage();
	}
}

Msg::AudioPlugin* SourcePage::getPlugin()
{
	int index = _source.indexOf("/");
	qDebug() << "Index:" << index;
	QString sourcePlugin = _source;
	if ( index > 0 )
		sourcePlugin.remove(index, sourcePlugin.length());
	qDebug() << "Plugin:" << sourcePlugin;
	if ( _plugin == NULL || _plugin->getName().compare(sourcePlugin.toStdString()) != 0 )
		_plugin = Msg::MusicControl::getInstance().getAudioPlugin(sourcePlugin);
	return _plugin;
}

QString SourcePage::getPath() const
{
	int index = _source.indexOf("/");
	qDebug() << "Index:" << index;
	if ( index < 0 )
		return "";
	
	QString pluginSource = _source;
	pluginSource.remove(0, index + 1);
	qDebug() << "Path:" << pluginSource;
	return pluginSource;
}
