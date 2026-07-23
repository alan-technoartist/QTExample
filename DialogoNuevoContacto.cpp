#include "DialogoNuevoContacto.hpp"
#include <iostream>

DialogoNuevoContacto::DialogoNuevoContacto(QWidget* parent) :
	QDialog(parent)
{
	ui = std::make_unique<Ui::dialogoNuevoContacto>();
	ui->setupUi(this);


}