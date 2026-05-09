#include "aboutuswindow.h"
#include "profilewindow.h"

aboutuswindow::aboutuswindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

aboutuswindow::~aboutuswindow()
{}

void aboutuswindow::on_toolButtonBack_clicked() {
	profilewindow* profile = new profilewindow(this);
	profile->show();
	this->hide();
}



