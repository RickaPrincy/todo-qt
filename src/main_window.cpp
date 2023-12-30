#include "main_window.h"
#include "./ui_main_window.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(770, 400);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QString name = ui->input_name->text();
    QString description = ui->input_description->text();

    if(name.isEmpty() || description.isEmpty()){
        QMessageBox::critical(this, "Error", "Name and Description cannot be empty");
        return;
    }
}
