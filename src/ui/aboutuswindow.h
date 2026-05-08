#pragma once

#include <QMainWindow>
#include "ui_aboutuswindow.h"

class aboutuswindow : public QMainWindow
{
	Q_OBJECT

public:
	aboutuswindow(QWidget *parent = nullptr);
	~aboutuswindow();

private slots:
	void on_toolButtonBack_clicked();

private:
	Ui::aboutuswindowClass ui;
};

