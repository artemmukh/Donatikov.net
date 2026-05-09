#include "newnamewindow.h"
#include <QMessageBox>
#include "profilewindow.h"

newnamewindow::newnamewindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

newnamewindow::~newnamewindow()
{}

void newnamewindow::on_pushButtonName_clicked() {
	if (ui.lineEditPassword->text().isEmpty() or ui.lineEditName->text().isEmpty()) {
		QMessageBox::critical(this, "Error", "Every field should be filled!");
		return;
	}

	if (ui.lineEditPassword->text() != "1") {//TODO: implement login logic
		QMessageBox::critical(this, "Error", "There is mistake in your password.");
		return;
	}
	else {
		QMessageBox::information(this, "Name", "Name changed succesfully");
		profilewindow* profile = new profilewindow(this);
		profile->show();
		this->hide();

	}



}



void newnamewindow::on_toolButton_clicked() {
	profilewindow* profile = new profilewindow(this);
	profile->show();
	this->hide();

}
