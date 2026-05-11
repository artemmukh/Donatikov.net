#include "servicewindow.h"
#include "dashboardscreen.h"
#include "subscriptionwindow.h"

servicewindow::servicewindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

servicewindow::~servicewindow()
{}

void servicewindow::on_toolButtonBack_clicked() {
	dashboardscreen* dashboard = new dashboardscreen(this);
	dashboard->show();
	this->hide();
}
void servicewindow::on_toolButtonYT_clicked() {
	QString name = "Youtube";
	QStringList prices = { "22000", "50000", "120000"};
	subscriptionwindow* subscription = new subscriptionwindow(prices, name, this);
	subscription->show();
	this->hide();
}
void servicewindow::on_toolButtonSpotify_clicked() {
	QString name = "Spotify";
	QStringList prices = { "21000", "60000", "100000" };
	subscriptionwindow* subscription = new subscriptionwindow(prices, name, this);
	subscription->show();
	this->hide();
}
void servicewindow::on_toolButtonNetflix_clicked() {
	QString name = "Netflix";
	QStringList prices = { "20000", "55000", "110000" };
	subscriptionwindow* subscription = new subscriptionwindow(prices, name, this);
	subscription->show();
	this->hide();
}
void servicewindow::on_toolButtonGOG_clicked() {

}
void servicewindow::on_toolButtonSteam_clicked() {

}
void servicewindow::on_toolButtonEpic_clicked(){

}

