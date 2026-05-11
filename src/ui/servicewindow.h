#pragma once

#include <QMainWindow>
#include "ui_servicewindow.h"

class servicewindow : public QMainWindow
{
	Q_OBJECT

public:
	servicewindow(QWidget *parent = nullptr);
	~servicewindow();

private slots:
	void on_toolButtonBack_clicked();
	void on_toolButtonYT_clicked();
	void on_toolButtonSpotify_clicked();
	void on_toolButtonNetflix_clicked();
	void on_toolButtonGOG_clicked();
	void on_toolButtonSteam_clicked();
	void on_toolButtonEpic_clicked();
	

private:
	Ui::servicewindowClass ui;
};

