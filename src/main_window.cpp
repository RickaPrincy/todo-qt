#include "main_window.h"
#include "./ui_main_window.h"
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(770, 400);
    setWindowTitle("Ricka's todo");
    ui->setupUi(this);
    ui->todosTables->setColumnCount(3);
    QStringList todos_headers;
    todos_headers << "Name" << "Description" << "Status";
    ui->todosTables->setHorizontalHeaderLabels(todos_headers);

    ui->todosTables->setColumnWidth(0, ui->todosTables->width() / 4);
    ui->todosTables->setColumnWidth(1, ui->todosTables->width() / 2);
    ui->todosTables->setColumnWidth(2, ui->todosTables->width() / 4);
    ui->todosTables->verticalHeader()->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QString name = ui->inputName->text();
    QString description = ui->inputDescription->text();
    ui->inputName->clear();
    ui->inputDescription->clear();

    if(name.isEmpty() || description.isEmpty()){
        QMessageBox::information(this, "Empty field", "Name and Description cannot be empty");
        return;
    }
    int rowCount = ui->todosTables->rowCount();

    ui->todosTables->insertRow(rowCount);
    ui->todosTables->setItem(rowCount, 0, new QTableWidgetItem(name));
    ui->todosTables->setItem(rowCount, 1, new QTableWidgetItem(description));
    ui->todosTables->setItem(rowCount, 2, new QTableWidgetItem("false"));

    // Create a QComboBox for the "Status" column
    QComboBox *status = new QComboBox();

    status->addItem("Pending");
    status->addItem("Done");
    status->addItem("In Progress");
    status->setCurrentIndex(0);

    ui->todosTables->setCellWidget(rowCount, 2, status);
    status->setStyleSheet("QComboBox QAbstractItemView { selection-color: black; }");

}
