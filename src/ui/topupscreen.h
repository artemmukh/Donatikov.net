#pragma once

#include <QMainWindow>
#include "ui_topupscreen.h"

class topupscreen : public QMainWindow
{
	Q_OBJECT

public:
	topupscreen(QWidget *parent = nullptr);
	~topupscreen();

private slots:
	void on_pushButton1_clicked();
	void on_pushButton25_clicked();
	void on_pushButton3_clicked();
	void on_pushButton5_clicked();
	void on_pushButtonTopUp_clicked();
	void on_toolButtonBack_clicked();
	

private:
	Ui::topupscreenClass ui;
};

