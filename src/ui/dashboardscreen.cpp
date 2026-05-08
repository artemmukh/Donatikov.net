#include "dashboardscreen.h"
#include "profilewindow.h"
#include "topupscreen.h"

dashboardscreen::dashboardscreen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

dashboardscreen::~dashboardscreen()
{}

void dashboardscreen::on_pushButtonSend_clicked() {

}
void dashboardscreen::on_pushButtonTopUp_clicked() {
	topupscreen* topup = new topupscreen(this);
	topup->show();
	this->hide();
}
void dashboardscreen::on_pushButtonSearch_clicked() {

}
void dashboardscreen::on_pushButtonProfile_clicked() {
	profilewindow* profile = new profilewindow(this);
	profile->show();
	this->hide();
}