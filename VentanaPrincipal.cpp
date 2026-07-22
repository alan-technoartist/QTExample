#include "VentanaPrincipal.hpp"
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


}