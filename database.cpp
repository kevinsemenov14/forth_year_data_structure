#include "database.h" //includes QSqlDatabase
#include <QDebug>
#include <QFileInfo>


// To access the databse anywhere, include the header file ex: "headers\database.h"
// To reference the databse, use the syntax ex: Database::getInstance()->functionName()

Database* Database::instance = nullptr; // Static pointer to the database (global)
// This should be the only global variable/pointer
// This is also an example of lazy initialization (database expression for the way we initialized).


// Default constructor that will OPEN the database. If it succeeds there will
// be console output.
// Private Constructor because you do not want anyone to instantiate a new Database
Database::Database(): QSqlDatabase(addDatabase("QSQLITE"))
{
    this->setDatabaseName("./assets/AllStarDatabase.db");
    QFileInfo existingDatabaseInfo ("./assets/AllStarDatabase.db");

    if(existingDatabaseInfo.exists()){
        qDebug() << "Database file is open\n";
        this->open();
    }else{
        qDebug() << "Database file not open.\n";
    }
}

// This will return a pointer to the database and is static.
Database* Database::getInstance()
{
    // if the database has not been initialized, initialize it.
    if(instance == nullptr){
        instance = new Database;
    }
    return instance;
}

/******************************************************************************************
* REFERENCE TEST METHODS FOR LEARNING SQL. DO NOT USE OR ERASE UNTIL SPRINT 3 TURN IN
* PLEASE.
*
* I hope these methods are helpful for anyone who wants to understand or
* create their own query methods. These are also great references if you forgot
* how to do something, or need a little brain fart recover.
*****************************************************************************************/
// Example Query Method
//void Database::testMethod(const QString stadiumName){
//    QSqlQuery query(*this); //Initialize, and pass in the current instance of the database

//    // prepare the query. Here is a basic query example
//    // SELECT variablenames, variablenames (or * for all)
//    // FROM tablename
//    // WHERE condition;
//    query.prepare("SELECT * FROM Stadiums WHERE name = ?;");

//    // This will bind the '?' with the passed in variable stadiumName
//    query.bindValue(0, stadiumName);

//    // query.exec() MUST BE CALLED. for good practice, I put it inside an if
//    // and out put if it did not execute properly
//    if(query.exec()){
//        query.first(); // This will allow you to start at the beginning of the returned query

//        // From there, you access the indexes of the query using, query.value based on the order in the tables.
//        // be sure to cast it to c++ data type like string, int, double, or float. (I reccomend doubles instead of floats)
//        qDebug() << query.value(0).toString() << endl;
//        qDebug() << query.value(1).toInt() << endl;
//        qDebug() << query.value(2).toString() << endl;
//        qDebug() << query.value(3).toString() << endl;
//        qDebug() << query.value(4).toString() << endl;
//        qDebug() << query.value(5).toInt() << endl;
//        qDebug() << query.value(6).toString() << endl;
//    }else{
//        qDebug() << "void Test Method query did not execute properly!\n";
//    }

//    // Normally, query methods like these would have a returned data type or data structure
//    // containing the value(s) that you want.
//    // Because this method is void, this method would be called like so:
//    // EX:   Database::getInstance()->testMethod("Angel Stadium of Anaheim");
//}

// Example Query Method with models
//QSqlQueryModel* Database::testMethod(const QString stadiumName)
//{
//    // QT allows us to use sql tables on table views (model)
//    // The reason why we use (model) table views is because (model) table views are used for EXTERNAL data
//    // while table widgets are used for LOCAL data. A data base is not c++ or our own stored code, so a
//    // table view model is used.

//    // This is setting a QSqlQueryModel which will make our tableview look like our sql tables. (in DB Browswer)
//    QSqlQueryModel* model = new QSqlQueryModel;

//    // Instead of preparing a query, we are setting a model's query with a passed in QString.
//    QString string = "SELECT * FROM Stadiums WHERE name = \""
//                     + stadiumName + "\";";
//    model->setQuery(string);

//    // once returned, the return model value needs to be placed in a setModel for a tableview
//    // EX: auto model = Database::getInstance()->testMethod("Angel Stadium of Anaheim");
//    //     ui->testTableView->setModel(model);
//    return model;
//}






















