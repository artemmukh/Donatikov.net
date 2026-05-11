#include "subscriptionwindow.h"
#include "servicewindow.h"
#include <QMessageBox>
#include <QInputDialog>

subscriptionwindow::subscriptionwindow(QStringList prices, QString& labelText, QWidget* parent)
	: QMainWindow(parent), labelText(labelText), prices(prices)
{
	
	ui.setupUi(this);
	ui.labelName->setText(labelText);
}

subscriptionwindow::~subscriptionwindow()
{}

void subscriptionwindow::on_pushButtonSub_clicked() {
	
}

void subscriptionwindow::on_toolButtonBack_clicked() {
	servicewindow* service = new servicewindow(this);
	service->show();
	this->hide();
	
}

void subscriptionwindow::on_comboBoxPeriod_currentIndexChanged(int index) {
	switch (index) {
	case 0:
		ui.labelPrice->setText("-");
		break;
	case 1:
		ui.labelPrice->setText(prices[0]+" UZS");
		break;
	case 2:
		ui.labelPrice->setText(prices[1] + " UZS");
		break;
	case 3:
		ui.labelPrice->setText(prices[2] + " UZS");
		break;
	}
}

void subscriptionwindow::on_comboBoxCardsPay_currentIndexChanged(int index) {
	if (index == ui.comboBoxCardsPay->count() - 1) {
		ui.comboBoxCardsPay->setCurrentIndex(0);
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
			ui.comboBoxCardsPay->insertItem(ui.comboBoxCardsPay->count() - 1, cardNum.left(5) + "** VISA");
			ui.comboBoxCardsPay->setCurrentIndex(ui.comboBoxCardsPay->count() - 2);
		}




	}
}