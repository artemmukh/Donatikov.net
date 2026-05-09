#pragma once

#include <QMainWindow>
#include "ui_notificationscreen.h"

class notificationscreen : public QMainWindow
{
	Q_OBJECT

public:
	notificationscreen(QWidget *parent = nullptr);
	~notificationscreen();

private slots:
	void on_pushButtonDisable_clicked();
	void on_toolButtonBack_clicked();


private:
	Ui::notificationscreenClass ui;
};

