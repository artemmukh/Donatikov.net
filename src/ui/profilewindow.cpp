#include "profilewindow.h"
#include "dashboardscreen.h"
#include "aboutuswindow.h"
#include "notificationscreen.h"
#include "newpasswordwindow.h"
#include "newnamewindow.h"
#include <QMessageBox>

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
void profilewindow::on_pushButtonChangeName_clicked() {
	newnamewindow* newname = new newnamewindow(this);
	newname->show();
	this->hide();

}
void profilewindow::on_pushButtonChangePassword_clicked() {
	newpasswordwindow* newpassword = new newpasswordwindow(this);
	newpassword->show();
	this->hide();
}
void profilewindow::on_pushButtonNotifications_clicked() {
	notificationscreen* notification = new notificationscreen(this);
	notification->show();
	this->hide();

}
void profilewindow::on_pushButtonHelp_clicked() {
	QMessageBox::information(this, "Help", "For help you can contact us by number +9981234567 or by email donatikov.net@gmail.com");

}
void profilewindow::on_pushButtonAbout_clicked(){
	aboutuswindow* aboutus = new aboutuswindow(this);
	aboutus->show();
	this->hide();
}