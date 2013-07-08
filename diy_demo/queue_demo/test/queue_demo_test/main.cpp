// main.cpp
#include <QApplication>
#include <QTextCodec>

#include "window.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

	Window *window = new Window();
	window->move(300, 400);
	window->show();

	return app.exec();

}
