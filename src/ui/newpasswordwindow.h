#pragma once

#include <QMainWindow>
#include "ui_newpasswordwindow.h"

class newpasswordwindow : public QMainWindow
{
	Q_OBJECT

public:
	newpasswordwindow(QWidget *parent = nullptr);
	~newpasswordwindow();

private slots:
	void on_pushButtonPassword_clicked();

	void on_toolButton_clicked();

private:
	Ui::newpasswordwindowClass ui;
};

