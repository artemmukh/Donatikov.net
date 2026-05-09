#include "mainwindow.h"
#include <QMessageBox>
#include "loginwindow.h"
#include "dashboardscreen.h"

mainwindow::mainwindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

mainwindow::~mainwindow()
{}

void mainwindow::on_pushButtonSignIn_clicked() {
	if (ui.lineEditUsername->text() == "" or ui.lineEditPassword->text() == "") {
		QMessageBox::critical(this, "Error", "Both login and password should be filled!");

		return;
	}//validating for empty fields

	if (ui.lineEditUsername->text() == "1" and ui.lineEditPassword->text() == "1") {//TODO: написать логику логина
		dashboardscreen* dashboard = new dashboardscreen(this);
		dashboard->show();
		this->hide();
		
	}//check for right user
}

void mainwindow::on_pushButtonLogIn_clicked() {
	loginwindow* a = new loginwindow(this);
	a->show();
	this->hide();
}
