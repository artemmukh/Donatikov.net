#include "newpasswordwindow.h"
#include <QMessageBox>
#include "profilewindow.h"

newpasswordwindow::newpasswordwindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

newpasswordwindow::~newpasswordwindow()
{}

void newpasswordwindow::on_pushButtonPassword_clicked() {
	if (ui.lineEditPassword->text().isEmpty() or ui.lineEditPasswordOne->text().isEmpty() or ui.lineEditPasswordTwo->text().isEmpty()) {
		QMessageBox::critical(this, "Error", "Every field should be filled!");
		return;
	}

	if (ui.lineEditPassword->text() != "1") {//TODO: implement login logic
		QMessageBox::critical(this, "Error", "There is mistake in your password.");
		return;
	}
	else {
		if (ui.lineEditPasswordOne->text().length() < 8) {
			QMessageBox::critical(this, "Error", "Passwords should at least 8 characters!");
			return;
		}
		if (ui.lineEditPasswordOne->text() != ui.lineEditPasswordTwo->text()) {
			QMessageBox::critical(this, "Error", "Passwords should match!");
			return;
		}
		QMessageBox::information(this, "Password", "Password changed succesfully");
		profilewindow* profile = new profilewindow(this);
		profile->show();
		this->hide();
		
	}
	
	
	
}



void newpasswordwindow::on_toolButton_clicked() {
	profilewindow* profile = new profilewindow(this);
	profile->show();
	this->hide();
	
}