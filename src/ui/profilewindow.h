#pragma once

#include <QMainWindow>
#include "ui_profilewindow.h"


class profilewindow : public QMainWindow
{
	Q_OBJECT

public:
	profilewindow(QWidget *parent = nullptr);
	~profilewindow();

public slots:
	void on_toolButtonBack_clicked();
	void on_pushButtonChangeName_clicked();
	void on_pushButtonChangePassword_clicked();
	void on_pushButtonNotifications_clicked();
	void on_pushButtonHelp_clicked();
	void on_pushButtonAbout_clicked();


private:
	Ui::profilewindowClass ui;
};

