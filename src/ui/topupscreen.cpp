#include "topupscreen.h"
#include "dashboardscreen.h"
#include <QMessageBox>
#include <QInputDialog>

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

void topupscreen::on_comboBoxCards_currentIndexChanged(int index) {
	if (index == ui.comboBoxCards->count() - 1) {
		ui.comboBoxCards->setCurrentIndex(0);
		bool cancelOrOk;
		QString cardNum= QInputDialog::getText(this, "Add card", "Card number:", QLineEdit::Normal, "", &cancelOrOk);

		if (!cancelOrOk or cardNum.isEmpty())
			return;

		if (cardNum.length() != 8 or cardNum.contains(QRegularExpression("[^0-9]"))) {//[^0-9] everything except 0 to 9 symbols
			QMessageBox::warning(this, "Error", "Card should consist of 8 numbers!");
			return;
		}


		int yesOrNoBox= QMessageBox::question(this, "Add card", "Are you sure you want to add "+ cardNum+" card?", QMessageBox::Yes | QMessageBox::No);

		if (yesOrNoBox == QMessageBox::Yes) {
			ui.comboBoxCards->insertItem(ui.comboBoxCards->count() - 1, cardNum.left(5) + "** VISA");
			ui.comboBoxCards->setCurrentIndex(ui.comboBoxCards->count() - 2);
		}




	}
}