#include "VentanaPrincipal.hpp"
#include "DialogoNuevoContacto.hpp"
#include <iostream>

VentanaPrincipal::VentanaPrincipal(QWidget* parent) :
	QMainWindow(parent)
{
	ui = std::make_unique<Ui::MainWindow>();
	ui->setupUi(this);

	connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
		QString nombre = ui->inputNombre->text().trimmed();

		if (ui->guardarCheckBox->isChecked()) {

			QFile file("datos.txt");
			if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
				QTextStream out(&file);
				out << "Nombre: " << nombre << "\n";
				out << "Genero: " << ui->generoBox->currentText() << "\n";
				file.close();
			}
		}

		QMessageBox::information(this, "Informacion", "Hola " + nombre + "\n" + "Genero: " + ui->generoBox->currentText());

		});
	//connect(ui->generoBox, &QComboBox::currentTextChanged, this, [this]() {std::cout << "Current" << std::endl; });

	connect(ui->actionNuevo, &QAction::triggered, this, [this]() {

		std::cout << "Click en Nuevo" << std::endl;
		
		DialogoNuevoContacto dialogo(this);

		if (dialogo.exec() == QDialog::Accepted) {
			std::cout << "Dialogo aceptado" << std::endl;

			QString nombre = dialogo.ui->nombreNuevo->text().trimmed();
			QString correo = dialogo.ui->correoNuevo->text().trimmed();

			std::cout << "Nombre: " << nombre.toStdString() << std::endl;
			std::cout << "Correo: " << correo.toStdString() << std::endl;

			contactos[nombre] = correo;

			ui->listaContactos->addItem(nombre + " - " + correo);

		}

		});

}