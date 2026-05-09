#pragma once

#include <QMainWindow>
#include "ui_newnamewindow.h"

class newnamewindow : public QMainWindow
{
	Q_OBJECT

public:
	newnamewindow(QWidget *parent = nullptr);
	~newnamewindow();

private slots:
	void on_pushButtonName_clicked();

	void on_toolButton_clicked();

private:
	Ui::newnamewindowClass ui;
};

