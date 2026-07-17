#include "QTExample.h"
#include <QApplication>
#include <QWidget>
#include <QMainWindow>

#include "ui_Formulario.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	QMainWindow mainWindow;

	Ui::Form ui;
	ui.setupUi(&mainWindow);

	mainWindow.show();


    return app.exec();
}