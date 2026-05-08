#include "profilewindow.h"
#include "dashboardscreen.h"

profilewindow::profilewindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

profilewindow::~profilewindow()
{}

void profilewindow::on_toolButtonBack_clicked() {
	dashboardscreen* dashboard = new dashboardscreen(this);
	dashboard->show();
	this->hide();
	
}
void profilewindow::on_pushButtonChangeName_clicked() {}
void profilewindow::on_pushButtonChangePassword_clicked() {}
void profilewindow::on_pushButtonNotifications_clicked() {}
void profilewindow::on_pushButtonHelp_clicked() {}
void profilewindow::on_pushButtonAbout_clicked(){}