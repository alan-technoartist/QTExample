#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <memory>
#include "ui_DialogoNuevoContacto.h" // Autogenerado a partir del .ui

namespace Ui {
	class DialogoNuevoContacto;
}

class DialogoNuevoContacto : public QDialog {
	Q_OBJECT

public:
	DialogoNuevoContacto(QWidget* parent = nullptr);
	~DialogoNuevoContacto() = default;

	std::unique_ptr<Ui::dialogoNuevoContacto> ui; // "Puente" para acceder a elementos de la UI

};