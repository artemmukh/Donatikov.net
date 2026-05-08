#include "topupscreen.h"
#include "dashboardscreen.h"
#include <QMessageBox>

topupscreen::topupscreen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QIntValidator* validator = new QIntValidator(0, 100000000, this);
	ui.lineEditBalance->setValidator(validator);

	ui.comboBoxCards->addItem("+ Add card");

	
}

topupscreen::~topupscreen()
{}



void topupscreen::on_pushButton1_clicked() {
	ui.lineEditBalance->setText("10000");
}
void topupscreen::on_pushButton25_clicked() {
	ui.lineEditBalance->setText("25000");
}
void topupscreen::on_pushButton3_clicked() {
	ui.lineEditBalance->setText("30000");
}
void topupscreen::on_pushButton5_clicked() {
	ui.lineEditBalance->setText("50000");
}
void topupscreen::on_pushButtonTopUp_clicked() {
	if (ui.lineEditBalance->text().isEmpty())
	{
		QMessageBox::warning(this, "Error", "Fill the balance field");
		return;
	}
	QMessageBox::warning(this, "test", "test");
	

}
void topupscreen::on_toolButtonBack_clicked() {
	
	
	dashboardscreen* dashboard = new dashboardscreen(this);
	dashboard->show();
	this->hide();
}