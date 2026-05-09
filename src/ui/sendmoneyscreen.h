#pragma once

#include <QMainWindow>
#include "ui_sendmoneyscreen.h"

class sendmoneyscreen : public QMainWindow
{
	Q_OBJECT

public:
	sendmoneyscreen(QWidget *parent = nullptr);
	~sendmoneyscreen();

private slots:
	void on_pushButton1_clicked();
	void on_pushButton25_clicked();
	void on_pushButton3_clicked();
	void on_pushButton5_clicked();

	void on_pushButton1Reciever_clicked();
	void on_pushButton25Reciever_clicked();
	void on_pushButton3Reciever_clicked();
	void on_pushButton5Reciever_clicked();

	void on_pushButtonSend_clicked();
	void on_toolButtonBack_clicked();
	void on_comboBoxCards_currentIndexChanged(int index);

private:
	Ui::sendmoneyscreenClass ui;
};

