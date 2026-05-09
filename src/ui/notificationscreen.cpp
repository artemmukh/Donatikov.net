#include "notificationscreen.h"
#include "profilewindow.h"

notificationscreen::notificationscreen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

notificationscreen::~notificationscreen()
{}

void notificationscreen::on_pushButtonDisable_clicked() {
	ui.comboBoxOthers->setCurrentIndex(2);
	ui.comboBoxSpecialOffers->setCurrentIndex(2);
	ui.comboBoxTransactions->setCurrentIndex(2);
}

void notificationscreen::on_toolButtonBack_clicked() {
	profilewindow* profile = new profilewindow(this);
	profile->show();
	this->hide();
}

