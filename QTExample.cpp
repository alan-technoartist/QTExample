#include "QTExample.h"
#include <QApplication>
#include <QMainWindow>

#include "VentanaPrincipal.hpp"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv); // "Singleton" de QT

	VentanaPrincipal mainWindow;	// Elemento "padre"

	mainWindow.show();

    return app.exec();	// Inicializar el motor de QT
}