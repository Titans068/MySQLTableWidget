#include <QMessageBox>
#include <QTableWidgetItem>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

QSqlDatabase db;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try{
        ui->setupUi(this);
        db = QSqlDatabase::addDatabase("QMYSQL", "sakila");
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("");
        db.setDatabaseName("sakila");
        int rowIndex = 0;
        if (db.open()) {
            QSqlQuery query(QSqlDatabase::database("sakila"));
            query.prepare("SELECT * FROM city");
            if (query.exec())
            {
                ui->table->setRowCount(query.size());
                ui->table->setColumnCount(4);
                ui->table->setHorizontalHeaderLabels(QStringList() << "City ID" << "City" << "Country ID" << "Last Update");
                while (query.next())
                {
                    QString id = query.value(0).toString();
                    QString ShortName = query.value(1).toString();
                    QString tel = query.value(2).toString();
                    //data columns
                    QTableWidgetItem* item1 = new QTableWidgetItem();
                    item1->setText(id);
                    ui->table->setItem(rowIndex, 0, item1);
                    QTableWidgetItem* item2 = new QTableWidgetItem();
                    item2->setText(ShortName);
                    ui->table->setItem(rowIndex, 1, item2);
                    QTableWidgetItem* item3 = new QTableWidgetItem();
                    item3->setText(tel);
                    ui->table->setItem(rowIndex, 2, item3);
                    QTableWidgetItem* item4 = new QTableWidgetItem();
                    item4->setText(query.value(3).toString());
                    ui->table->setItem(rowIndex, 3, item4);
                    rowIndex = rowIndex + 1;
                }
            }
            db.close();
        }
        } catch(std::exception& e){
            QMessageBox mbox;
            mbox.critical(0,"Error",e.what());
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

