#pragma once

#include <QMainWindow>
#include "ui_mainwindow.h"

class mainwindow : public QMainWindow
{
	Q_OBJECT

public:
	mainwindow(QWidget *parent = nullptr);
	~mainwindow();

private slots:
	void on_pushButtonSignIn_clicked();
	void on_pushButtonLogIn_clicked();

private:
	Ui::mainwindowClass ui;
};

