#include "sendmoneyscreen.h"
#include "dashboardscreen.h"
#include <QMessageBox>
#include <QInputDialog>

sendmoneyscreen::sendmoneyscreen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QIntValidator* validator = new QIntValidator(0, 100000000, this);
	ui.lineEditBalance->setValidator(validator);
	ui.lineEditReciever->setValidator(validator);
}

sendmoneyscreen::~sendmoneyscreen()
{}

void sendmoneyscreen::on_pushButton1_clicked() {
	ui.lineEditBalance->setText("10000");
}
void sendmoneyscreen::on_pushButton25_clicked() {
	ui.lineEditBalance->setText("25000");
}
void sendmoneyscreen::on_pushButton3_clicked() {
	ui.lineEditBalance->setText("30000");
}
void sendmoneyscreen::on_pushButton5_clicked() {
	ui.lineEditBalance->setText("50000");
}

void sendmoneyscreen::on_pushButton1Reciever_clicked() {
	ui.lineEditReciever->setText("10000");
}
void sendmoneyscreen::on_pushButton25Reciever_clicked() {
	ui.lineEditReciever->setText("25000");
}
void sendmoneyscreen::on_pushButton3Reciever_clicked() {
	ui.lineEditReciever->setText("30000");
}
void sendmoneyscreen::on_pushButton5Reciever_clicked() {
	ui.lineEditReciever->setText("50000");
}


void sendmoneyscreen::on_pushButtonSend_clicked() {
	if (ui.lineEditBalance->text().isEmpty())
	{
		QMessageBox::warning(this, "Error", "Fill the balance field");
		return;
	}
	QMessageBox::warning(this, "test", "test");


}
void sendmoneyscreen::on_toolButtonBack_clicked() {


	dashboardscreen* dashboard = new dashboardscreen(this);
	dashboard->show();
	this->hide();
}

void sendmoneyscreen::on_comboBoxCards_currentIndexChanged(int index) {
	if (index == ui.comboBoxCards->count() - 1) {
		ui.comboBoxCards->setCurrentIndex(0);
		bool cancelOrOk;
		QString cardNum = QInputDialog::getText(this, "Add card", "Card number:", QLineEdit::Normal, "", &cancelOrOk);

		if (!cancelOrOk or cardNum.isEmpty())
			return;

		if (cardNum.length() != 8 or cardNum.contains(QRegularExpression("[^0-9]"))) {//[^0-9] everything except 0 to 9 symbols
			QMessageBox::warning(this, "Error", "Card should consist of 8 numbers!");
			return;
		}


		int yesOrNoBox = QMessageBox::question(this, "Add card", "Are you sure you want to add " + cardNum + " card?", QMessageBox::Yes | QMessageBox::No);

		if (yesOrNoBox == QMessageBox::Yes) {
			ui.comboBoxCards->insertItem(ui.comboBoxCards->count() - 1, cardNum.left(5) + "** VISA");
			ui.comboBoxCards->setCurrentIndex(ui.comboBoxCards->count() - 2);
		}




	}
}