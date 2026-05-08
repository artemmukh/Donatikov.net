#pragma once

#include <QMainWindow>
#include "ui_dashboardscreen.h"

class dashboardscreen : public QMainWindow
{
	Q_OBJECT

public:
	dashboardscreen(QWidget *parent = nullptr);
	~dashboardscreen();

private slots:
	void on_pushButtonSend_clicked();
	void on_pushButtonTopUp_clicked();
	void on_pushButtonSearch_clicked();
	void on_pushButtonProfile_clicked();



private:
	Ui::dashboardscreenClass ui;
};

