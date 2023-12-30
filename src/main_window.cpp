#include "main_window.h"
#include "./ui_main_window.h"
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(770, 400);
    setWindowTitle("Todo");
    ui->setupUi(this);
    ui->todosTables->setColumnCount(4);
    QStringList todos_headers;
    todos_headers << "Name" << "Deadline" << "Status" << "Actions";
    ui->todosTables->setHorizontalHeaderLabels(todos_headers);

    ui->todosTables->setColumnWidth(0, 1.5 * ui->todosTables->width() / 5);
    ui->todosTables->setColumnWidth(1, 1.5 * ui->todosTables->width() / 5);
    ui->todosTables->setColumnWidth(2, ui->todosTables->width() / 5);
    ui->todosTables->setColumnWidth(3, ui->todosTables->width() / 5);
    ui->todosTables->verticalHeader()->setVisible(false);
    ui->deadline->setDateTime(QDateTime::currentDateTime());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QString name = ui->inputName->text();
    QDateTime deadline = ui->deadline->dateTime();
    ui->inputName->clear();
    ui->deadline->setDateTime(QDateTime::currentDateTime());

    if(name.isEmpty() || !deadline.isValid()){
        QMessageBox::information(this, "Empty field", "Name and Deadline cannot be empty");
        return;
    }

    int rowCount = ui->todosTables->rowCount();

    ui->todosTables->insertRow(rowCount);
    ui->todosTables->setItem(rowCount, 0, new QTableWidgetItem(name));

    QDateTimeEdit *deadlineItem = new QDateTimeEdit();
    deadlineItem->setDateTime(deadline);
    ui->todosTables->setCellWidget(rowCount, 1, deadlineItem);

    QComboBox *status = new QComboBox();

    status->addItem("Pending");
    status->addItem("Done");
    status->addItem("In Progress");
    status->setCurrentIndex(0);

    ui->todosTables->setCellWidget(rowCount, 2, status);
    status->setStyleSheet("QComboBox QAbstractItemView { selection-color: black; }");

    QPushButton *deleteButton = new QPushButton();
    deleteButton->setText("Delete");
    ui->todosTables->setCellWidget(rowCount, 3, deleteButton);
}
