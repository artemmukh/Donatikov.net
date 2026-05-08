#include "loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

loginwindow::loginwindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

loginwindow::~loginwindow()
{}

void loginwindow::on_pushButtonSignIn_clicked() {
	mainwindow* a = new mainwindow(this);
	a->show();
	this->hide();
}

void loginwindow::on_pushButtonLogIn_clicked() {
	if (ui.lineEditEmail->text().isEmpty() or ui.lineEditName->text().isEmpty() or ui.lineEditPasswordOne->text().isEmpty() or ui.lineEditPasswordTwo->text().isEmpty() or ui.lineEditUsername->text().isEmpty()) {
		QMessageBox::critical(this, "Error", "Every field should be filled!");
		return;
	}
	if (ui.lineEditPasswordOne->text().length() < 8) {
		QMessageBox::critical(this, "Error", "Passwords should at least 8 characters!");
		return;
	}
	if (ui.lineEditPasswordOne->text() != ui.lineEditPasswordTwo->text()) {
		QMessageBox::critical(this, "Error", "Passwords should match!");
		return;
	}
}