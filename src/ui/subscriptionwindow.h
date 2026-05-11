#pragma once

#include <QMainWindow>
#include "ui_subscriptionwindow.h"

class subscriptionwindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit subscriptionwindow(QStringList prices, QString& labelText, QWidget* parent = nullptr);
	~subscriptionwindow();

private slots:
	void on_pushButtonSub_clicked();
	void on_toolButtonBack_clicked();
	void on_comboBoxCardsPay_currentIndexChanged(int index);
	void on_comboBoxPeriod_currentIndexChanged(int index);
private:
	Ui::subscriptionwindowClass ui;
	QString labelText;
	QStringList prices;
	
};

