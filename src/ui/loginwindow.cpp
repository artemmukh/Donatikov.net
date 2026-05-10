#include "loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "dashboardscreen.h"

#include <QRegularExpressionValidator>

loginwindow::loginwindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QRegularExpression emailValidator(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");//validation for email
	QRegularExpressionValidator* validator = new QRegularExpressionValidator(emailValidator, this);
	ui.lineEditEmail->setValidator(validator);
	
	
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
	dashboardscreen* dashboard = new dashboardscreen(this);
	dashboard->show();
	this->hide();
}
