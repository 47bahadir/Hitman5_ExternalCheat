#include "Hitman5_External.h"
#include <QtWidgets/QApplication>
#include <QStyleFactory>
#include <QSettings>
#include <QWidget>

#ifdef Q_OS_WINDOWS
#include <Windows.h>
#include <dwmapi.h>
#pragma comment(lib, "Dwmapi.lib")
#endif

void setDarkTitleBar(QWidget* widget)
{
	#ifdef Q_OS_WINDOWS
	HWND hwnd = reinterpret_cast<HWND>(widget->winId());
	BOOL dark = TRUE;
	DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &dark, sizeof(dark));
	#endif
}

class DarkTitleBarEventFilter : public QObject
{
public:
	DarkTitleBarEventFilter(QObject* parent = nullptr) : QObject(parent) {}

	bool eventFilter(QObject* obj, QEvent* event) override
	{
		if (event->type() == QEvent::Show)
		{
			QWidget* widget = qobject_cast<QWidget*>(obj);
			if (widget && widget->isWindow())
			{
				setDarkTitleBar(widget);
			}
		}
		return false;
	}
};

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	DarkTitleBarEventFilter* darkTitleBarFilter = new DarkTitleBarEventFilter(&a);
	a.installEventFilter(darkTitleBarFilter);

	// turn on Windows dark mode
	QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);
	if (settings.value("AppsUseLightTheme") == 0) {
		qApp->setStyle(QStyleFactory::create("Fusion"));
		QPalette darkPalette;
		darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
		darkPalette.setColor(QPalette::WindowText, Qt::white);
		darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
		darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
		darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
		darkPalette.setColor(QPalette::ToolTipText, Qt::white);
		darkPalette.setColor(QPalette::Text, Qt::white);
		darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
		darkPalette.setColor(QPalette::ButtonText, Qt::white);
		darkPalette.setColor(QPalette::BrightText, Qt::red);
		darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
		darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
		darkPalette.setColor(QPalette::HighlightedText, Qt::black);
		qApp->setPalette(darkPalette);
		qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
	}

	Hitman5_External w;
	w.show();
	return a.exec();
}