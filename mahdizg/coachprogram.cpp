#include "coachprogram.h"
#include "ui_coachprogram.h"
#include "coach.h"
#include "coachprogram.h"
#include <QMessageBox>
#include"QDebug"
#include"QObject"
#include<QDate>
#include<QTime>
#include<QString>
#include "modifiercoach.h"
#include "programs.h"
#include "modifierprogrammes.h"
#include "QTextStream"
#include "QTextDocument"
#include <QPrinter>
#include <QPrintDialog>
#include<QSqlRecord>
#include<QSqlRelationalTableModel>



CoachProgram::CoachProgram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoachProgram)
{

    ui->setupUi(this);
    ui->ANIMATION->setText("Bienvenue");
    animation=new QPropertyAnimation(ui->ANIMATION,"geometry");
    animation->setDuration(5000);
    animation->setStartValue(ui->ANIMATION->geometry());
    animation->setEndValue(QRect(870,40,151,51));
    animation->start();
      ui->ID_Coach->setValidator( new QIntValidator(0, 9999, this));
      ui->ID_Planning->setValidator( new QIntValidator(0, 9999, this));
      ui->Numero_Sem->setValidator( new QIntValidator(0, 9999, this));
      ui->NB_reservation->setValidator( new QIntValidator(0, 9999, this));
      ui->Numero_Sem->setValidator( new QIntValidator(0, 9999, this));

      ui->Nom->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
      ui->Prenom->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
      ui->Nom_Coach->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
      ui->Specialite->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));

      qsrand(qrand());
        ui->ID_Coach->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
          ui->ID_Planning->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
              QSqlQuery qry;
                  qry.prepare("SELECT ID_Coach FROM coach ");
                  qry.exec();
                  qry.first();
                  int groupID_Coach = qry.record().indexOf("ID_Coach");
                   ui->ID_Coach_modf_sup->addItem(qry.value(0).toString());
                  while (qry.next()) {
                        ui->ID_Coach_modf_sup->addItem(qry.value(groupID_Coach).toString());
}
                  QSqlQuery query;
                      query.prepare("SELECT ID_Planning FROM Programs");
                      query.exec();
                      query.first();
                      int groupID_Planning = query.record().indexOf("ID_Planning");
                       ui->ID_Programs_modf_sup->addItem(query.value(0).toString());
                      while (query.next()) {
                            ui->ID_Programs_modf_sup->addItem(query.value(groupID_Planning).toString());
    }
                      QSqlQuery querr;
                          querr.prepare("SELECT Email FROM Coach");
                          querr.exec();
                          querr.first();
                          int groupmail = querr.record().indexOf("Email");
                           ui->mail->addItem(querr.value(0).toString());
                          while (querr.next()) {
                                ui->mail->addItem(querr.value(groupmail).toString());
        }
                          QSqlQuery quers;
                              quers.prepare("SELECT Nom FROM Coach");
                              quers.exec();
                              quers.first();
                              int groupnom= quers.record().indexOf("Nom");
                               ui->nomcombo->addItem(quers.value(0).toString());
                              while (quers.next()) {
                                    ui->nomcombo->addItem(quers.value(groupnom).toString());
            }
                              ui->ABPR->addItem("1");

                              ui->ABPR->addItem("0");


}
CoachProgram::~CoachProgram()
{
    delete ui;
}


void CoachProgram::on_Ajouter1_clicked()
{
    int ID_Coach=ui->ID_Coach->text().toInt();
    QString Nom=ui->Nom->text();
    QString Prenom=ui->Prenom->text();
    QString Specialite=ui->Specialite->text();
    QDate Date_Naiss =ui->Date_Naiss->date();
    QString Email=ui->Email->text();
    int AB_PR=ui->ABPR->currentText().toInt();
    coach r(ID_Coach,Nom,Prenom,Specialite,Date_Naiss,Email,AB_PR);
    bool test=r.Ajouter1();
    QMessageBox msgbox;

        if(!test)
             return msgbox.setText("Ajout avec succes");
        else
            return msgbox.setText("Echec d ajout");
        msgbox.exec();
        ui->ID_Coach_modf_sup->clear();
        QSqlQuery qry;
            qry.prepare("SELECT ID_Coach FROM coach ");
            qry.exec();
            qry.first();
             ui->ID_Coach_modf_sup->addItem(qry.value(0).toString());
             int groupID_COACH = qry.record().indexOf("ID_COACH");
            while (qry.next()) {
                  ui->ID_Coach_modf_sup->addItem(qry.value(groupID_COACH).toString());
    }
}

void CoachProgram::on_Afficher1_clicked()
{
    ui->nomcombo->clear();
    QSqlQuery quers;
        quers.prepare("SELECT Nom FROM Coach");
        quers.exec();
        quers.first();
        int groupnom= quers.record().indexOf("Nom");
         ui->nomcombo->addItem(quers.value(0).toString());
        while (quers.next()) {
              ui->nomcombo->addItem(quers.value(groupnom).toString());
}
    ui->mail->clear();
    QSqlQuery querr;
        querr.prepare("SELECT Email FROM Coach");
        querr.exec();
        querr.first();
        int groupmail = querr.record().indexOf("Email");
         ui->mail->addItem(querr.value(0).toString());
        while (querr.next()) {
              ui->mail->addItem(querr.value(groupmail).toString());
}
    ui->ID_Coach_modf_sup->clear();
    QSqlQuery qry;
        qry.prepare("SELECT ID_Coach FROM coach ");
        qry.exec();
        qry.first();
        int groupID_Coach = qry.record().indexOf("ID_Coach");
         ui->ID_Coach_modf_sup->addItem(qry.value(0).toString());
        while (qry.next()) {
              ui->ID_Coach_modf_sup->addItem(qry.value(groupID_Coach).toString());
}
    ui->tableView_2->setModel(re1.Afficher1());
}

void CoachProgram::on_Modifier1_clicked()
{
    modifierCoach dm;
        QMessageBox msg;
       dm.setID_Coach(ui->ID_Coach_modf_sup->currentText().toInt());


           QSqlQuery qry;
           int ID_Coach_modf_sup=ui->ID_Coach_modf_sup->currentText().toInt();
             QString ID_Coach_modf_sup_STRING= QString::number(ID_Coach_modf_sup);
             qry.prepare("SELECT * from coach where ID_Coach='"+ID_Coach_modf_sup_STRING+"'");
              if (qry.exec())
                 {
                  while (qry.next()) {
                     QString ac=qry.value(1).toString();
                   dm.setNom(ac);
                   QString sa=qry.value(2).toString();
                 dm.setPrenom(sa);
                 QString ev=qry.value(3).toString();
               dm.setSpecialite(ev);
               QString em=qry.value(5).toString();
             dm.setEmail(em);
             int aw=qry.value(6).toInt();
           dm.setAB_PR(aw);


                   dm.exec();
}
              }
}

void CoachProgram::on_Supprimer1_clicked()
{
    ui->ID_Coach_modf_sup->clear();
    QSqlQuery qry;
        qry.prepare("SELECT ID_Coach FROM coach ");
        qry.exec();
        qry.first();
        int groupID_DEP = qry.record().indexOf("ID_Coach");
         ui->ID_Coach_modf_sup->addItem(qry.value(0).toString());
        while (qry.next()) {
              ui->ID_Coach_modf_sup->addItem(qry.value(groupID_DEP).toString());
}
    coach re1;
       re1.setID_Coach(ui->ID_Coach_modf_sup->currentText().toInt());
       bool test=re1.Supprimer1(re1.getID_Coach());
       QMessageBox msgbox;

           if(!test)
                return msgbox.setText("Ajout avec succes");
           else
               return msgbox.setText("Echec d ajout");
           msgbox.exec();
}

void CoachProgram::on_Ajouter2_clicked()
{
    ui->ID_Programs_modf_sup->clear();
    QSqlQuery query;
        query.prepare("SELECT ID_Planning FROM Programs ");
        query.exec();
        query.first();
        int groupID_Planning = query.record().indexOf("ID_Planning");
         ui->ID_Programs_modf_sup->addItem(query.value(0).toString());
        while (query.next()) {
              ui->ID_Programs_modf_sup->addItem(query.value(groupID_Planning).toString());
}
    int ID_Planning=ui->ID_Planning->text().toInt();
    QDate Date_Planning =ui->Date_Planning->date();
    QTime Heure=ui->Heure->time();
    int Numero_Sem=ui->Numero_Sem->text().toInt();
    int NB_reservation =ui->NB_reservation->text().toInt();
    QString Nom_Coach =ui->Nom_Coach->text();
    programs r  (ID_Planning,Date_Planning,Heure,Numero_Sem,NB_reservation,Nom_Coach);
    bool test=r.Ajouter2();
    QMessageBox msgbox;

        if(!test)
             return msgbox.setText("Ajout avec succes");
        else
            return msgbox.setText("Echec d ajout");
        msgbox.exec();
}

void CoachProgram::on_Afficher2_clicked()
{
    programs re1;
     ui->tableView->setModel(re1.Afficher2());
     ui->ID_Programs_modf_sup->clear();
     QSqlQuery query;
         query.prepare("SELECT ID_Planning FROM Programs ");
         query.exec();
         query.first();
         int groupID_Planning = query.record().indexOf("ID_Planning");
          ui->ID_Programs_modf_sup->addItem(query.value(0).toString());
         while (query.next()) {
               ui->ID_Programs_modf_sup->addItem(query.value(groupID_Planning).toString());
 }
}

void CoachProgram::on_Modifier2_clicked()
{
    modifierProgrammes dm;
        QMessageBox msg;
       dm.setID_Planning(ui->ID_Programs_modf_sup->currentText().toInt());

       QSqlQuery qry;
       int ID_Programs_modf_sup=ui->ID_Programs_modf_sup->currentText().toInt();
         QString ID_Programs_modf_sup_STRING= QString::number(ID_Programs_modf_sup);
         qry.prepare("SELECT * from programs where ID_Planning='"+ID_Programs_modf_sup_STRING+"'");
          if (qry.exec())
             {
              while (qry.next()) {
                 int mm=qry.value(3).toString().toInt();

                 QString mm_STRING= QString::number(mm);
               dm.setNumero_Sem(mm);
               int aa=qry.value(4).toString().toInt();

               QString aa_STRING= QString::number(aa);
             dm.setNB_reservation(aa);

             QString ev=qry.value(5).toString();
           dm.setNom_Coach(ev);


               dm.exec();
}
          }
}

void CoachProgram::on_Supprimer2_clicked()
{
    ui->ID_Programs_modf_sup->clear();
    QSqlQuery query;
        query.prepare("SELECT ID_Planning FROM Programs ");
        query.exec();
        query.first();
        int groupID_Planning = query.record().indexOf("ID_Planning");
         ui->ID_Programs_modf_sup->addItem(query.value(0).toString());
        while (query.next()) {
              ui->ID_Programs_modf_sup->addItem(query.value(groupID_Planning).toString());
}
    programs re1;
       re1.setID_Planning(ui->ID_Programs_modf_sup->currentText().toInt());
       bool test=re1.Supprimer2(re1.getID_Planning());
       QMessageBox msgbox;

           if(!test)
                return msgbox.setText("Ajout avec succes");
           else
               return msgbox.setText("Echec d ajout");
           msgbox.exec();
}

void CoachProgram::on_pushButton_clicked()
{
    qsrand(qrand());
                    ui->ID_Coach->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                    bool alreadyExist = false;
                    {

                       int ID_Coach=ui->ID_Coach->text().toInt();
                    QSqlQuery query;
                    QString ID_String=QString::number(ID_Coach);
                    query.prepare("select ID_Coach from Coach where ID_Coach=:ID_Coach");
                    query.bindValue(":ID_Coach",ID_Coach);
                    if(!query.exec()){
                    // select failed
                    }
                    alreadyExist = query.next();
                    }
                    if(alreadyExist){
                    // update
                        qsrand(qrand());
                                    ui->ID_Coach->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                                    QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                                                QObject::tr("ID Deja exist.\n"), QMessageBox::Cancel);

                    }
                    else{
                    //insert
                        qDebug()<<"n'existe pas";
                    }
    }



void CoachProgram::on_pushButton_2_clicked()
{
    qsrand(qrand());
                    ui->ID_Planning->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                    bool alreadyExist = false;
                    {

                       int ID_Planning=ui->ID_Planning->text().toInt();
                    QSqlQuery query;
                    QString ID_String=QString::number(ID_Planning);
                    query.prepare("select ID_Planning from Coach where ID_Planning=:ID_Planning");
                    query.bindValue(":ID_Planning",ID_Planning);
                    if(!query.exec()){
                    // select failed
                    }
                    alreadyExist = query.next();
                    }
                    if(alreadyExist){
                    // update
                        qsrand(qrand());
                                    ui->ID_Planning->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                                    QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                                                QObject::tr("ID Deja exist.\n"), QMessageBox::Cancel);

                    }
                    else{
                    //insert
                        qDebug()<<"n'existe pas";
                    }
}

void CoachProgram::on_pushButton_4_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


            const int rowCount = ui->tableView_2->model()->rowCount();
            const int columnCount = ui->tableView_2->model()->columnCount();


            out <<  "<html>\n"
                        "<head>\n"

                     <<  QString("<title>%1</title>\n").arg("col1")
                      <<  "</head>\n"
                          "<center><h1> SMART CLUB </h1> </center>"

                          "  <h2>Nos Coach PDF</h2>"
                          "<body   >\n"
                          "<table border=1 cellspacing=0 cellpadding=2 >\n";

            // headers
            out << "<thead><tr >";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tableView_2->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView_2->isColumnHidden(column)) {
                        QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }


}

void CoachProgram::on_pushButton_3_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


            const int rowCount = ui->tableView->model()->rowCount();
            const int columnCount = ui->tableView->model()->columnCount();


            out <<  "<html>\n"
                        "<head>\n"

                     <<  QString("<title>%1</title>\n").arg("col1")
                      <<  "</head>\n"
                          "<center><h1> SMART CLUB </h1> </center>"

                          "  <h2>Programme de semaine PDF</h2>"
                          "<body   >\n"
                          "<table border=1 cellspacing=0 cellpadding=2 >\n";

            // headers
            out << "<thead><tr >";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tableView->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView->isColumnHidden(column)) {
                        QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }
}


void CoachProgram::on_button_5_clicked()
{
    QString domainerech = ui->recherche->text();
           ui->tableView_2->setModel(re1.chercher(domainerech));
}



void CoachProgram::on_button_6_clicked()
{

    QString domainerech = ui->recherche_2->text();
           ui->tableView->setModel(re1.chercher(domainerech));
}

void CoachProgram::on_nomcombo_currentIndexChanged(const QString &arg1)
{
    qDebug()<<arg1;
    QSqlQuery query;
    query.prepare("SELECT AB_PR FROM COACH WHERE NOM='"+arg1+"'");
    query.exec();
    while (query.next()) {

    if(query.value(0).toInt()==1){

        ui->presence->setText("present");
    }else

    {
        ui->presence->setText("absent");}

}
}
