//
// Created by user on 03.05.2026.
//

#ifndef README_MD_MAINWINDOW_H
#define README_MD_MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //README_MD_MAINWINDOW_H