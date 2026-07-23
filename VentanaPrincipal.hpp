#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <QFile>
#include <memory>
#include "ui_Formulario.h" // Autogenerado a partir del .ui

namespace Ui {
	class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow {
	Q_OBJECT

public:
	VentanaPrincipal(QWidget* parent = nullptr);
	~VentanaPrincipal() = default;

private:
	std::unique_ptr<Ui::MainWindow> ui; // "Puente" para acceder a elementos de la UI
	std::map<QString, QString> contactos; // Mapa para almacenar contactos (nombre -> correo)
};