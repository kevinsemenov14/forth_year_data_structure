#include "headers\mainwindow.h"
#include "headers\adminlogin.h"

// Will prob move to stadiumvisitplan.h
#include "headers\database.h" //includes QSqlDatabase & QSqlQueryModel & QSqlQuery

#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

// Will be the indexes of the pages on the pages stack widget
enum page{
    // If you create a new page, please make an enum for it.
    WelcomePage,
    AdminWelcomePage
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    adminLoggedIn = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

// If a mainwindow is created elsewhere, this will set the page index.
void MainWindow::SetIndex(int passedIndex)
{
    ui->pages->setCurrentIndex(passedIndex);
    if(passedIndex == AdminWelcomePage){
        adminLoggedIn = true;
    }
}

// Menubar: Login Go will check if an admin is already logged in or not.
void MainWindow::on_actiongo_triggered()
{
    if(adminLoggedIn){
        qDebug() << "\nAdmin Already Logged In Exception.\n";
        QMessageBox::information(this, "Uh oh!", "You are already Logged In!");
    }else{
        AdminLogin *a = new AdminLogin(this);
        a->show();
    }
}
