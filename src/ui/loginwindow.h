#pragma once

#include <QMainWindow>
#include "ui_loginwindow.h"

class loginwindow : public QMainWindow
{
	Q_OBJECT

public:
	loginwindow(QWidget *parent = nullptr);
	~loginwindow();

private slots:
	void on_pushButtonLogIn_clicked();
	void on_pushButtonSignIn_clicked();
private:
	Ui::loginwindowClass ui;
};

