#include "myclass.h"

#include <QtCore/QtPlugin>
#include "myclassplugin.h"


MyClassPlugin::MyClassPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void MyClassPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool MyClassPlugin::isInitialized() const
{
	return initialized;
}

QWidget *MyClassPlugin::createWidget(QWidget *parent)
{
	return new MyClass(parent);
}

QString MyClassPlugin::name() const
{
	return "MyClass";
}

QString MyClassPlugin::group() const
{
	return "My Plugins";
}

QIcon MyClassPlugin::icon() const
{
	return QIcon();
}

QString MyClassPlugin::toolTip() const
{
	return QString();
}

QString MyClassPlugin::whatsThis() const
{
	return QString();
}

bool MyClassPlugin::isContainer() const
{
	return false;
}

QString MyClassPlugin::domXml() const
{
	return "<widget class=\"MyClass\" name=\"myClass\">\n"
		" <property name=\"geometry\">\n"
		"  <rect>\n"
		"   <x>0</x>\n"
		"   <y>0</y>\n"
		"   <width>100</width>\n"
		"   <height>100</height>\n"
		"  </rect>\n"
		" </property>\n"
		"</widget>\n";
}

QString MyClassPlugin::includeFile() const
{
	return "myclass.h";
}

