#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>
#include<QTableView>
#include<QSqlRecord>
#include<abonnes.h>
#include"modifier_ab.h"
#include"modifier_abt.h"
#include<QDate>
#include<QTime>
#include<QDebug>
#include<abonnement.h>
#include<programs.h>
#include "QTextStream"
#include "QTextDocument"
#include <QPrinter>
#include <QPrintDialog>
#include<modifierprogrammes.h>
#include<coach.h>
#include<modifiercoach.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
 ui->tableab->setModel(ab.afficher());
 ui->tableabt->setModel(abt.afficher());
 ui->tabprog->setModel(prog.Afficher2());
 ui->tableView_2->setModel(c.Afficher1());
 ui->comboBoxab->clear();
     QSqlQuery qry;
         qry.prepare("SELECT ID_AB FROM ABONNES");
         qry.exec();
         qry.first();
         int groupID_AB = qry.record().indexOf("ID_AB");
          ui->comboBoxab->addItem(qry.value(0).toString());
         while (qry.next()) {
               ui->comboBoxab->addItem(qry.value(groupID_AB).toString());


                 ui->ID_Planning->setValidator( new QIntValidator(0, 9999, this));
                 ui->Numero_Sem->setValidator( new QIntValidator(0, 9999, this));
                 ui->NB_reservation->setValidator( new QIntValidator(0, 9999, this));
                 ui->Numero_Sem->setValidator( new QIntValidator(0, 9999, this));
                 qsrand(qrand());
                     ui->ID_Planning->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                     ui->ID_Coach->setText(QString::number(qrand() % ((High + 1) - Low) + Low));




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
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Ajouter_clicked()
{
    int ID_AB=ui->ID_AB->text().toInt();
     QString NOM=ui->NOM->text();
     QString PRENOM=ui->PRENOM->text();
     int AGE=ui->AGE->text().toInt();
     abonnes ab(ID_AB,NOM,PRENOM,AGE);
     QMessageBox msg;
     bool test=ab.ajout_ab();



     if(test)
     {
         QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                     QObject::tr("id deja exist.\n"), QMessageBox::Cancel);

 }
     else if(ui->ID_AB->text().isEmpty()){

         QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                     QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

     }
     else
        { QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                     QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);}

     ui->tableab->setModel(ab.afficher());
     ui->comboBoxab->clear();
         QSqlQuery qry;
             qry.prepare("SELECT ID_AB FROM ABONNES");
             qry.exec();
             qry.first();
             int groupID_AB = qry.record().indexOf("ID_AB");
              ui->comboBoxab->addItem(qry.value(0).toString());
             while (qry.next()) {
                   ui->comboBoxab->addItem(qry.value(groupID_AB).toString());


}}

void Dialog::on_Supprimer_clicked()
{
    ui->comboBoxab->clear();
        QSqlQuery qry;
            qry.prepare("SELECT ID_AB FROM ABONNES");
            qry.exec();
            qry.first();
            int groupID_AB = qry.record().indexOf("ID_AB");
             ui->comboBoxab->addItem(qry.value(0).toString());
            while (qry.next()) {
                  ui->comboBoxab->addItem(qry.value(groupID_AB).toString());


}
    abonnes ab1;
       ab1.setID_AB(ui->comboBoxab->currentText().toInt());
       bool test=ab1.supprimer(ab1.getID_AB());
       if(!test)
       {
           QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                       QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

   }
       else if(ui->comboBoxab->currentText().isEmpty()){

           QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                       QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

       }
       else
           QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                       QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);


}

void Dialog::on_pushButton_clicked()
{
      ui->tableab->setModel(ab.afficher());
      ui->comboBoxab->clear();
          QSqlQuery qry;
              qry.prepare("SELECT ID_AB FROM ABONNES");
              qry.exec();
              qry.first();
              int groupID_AB = qry.record().indexOf("ID_AB");
               ui->comboBoxab->addItem(qry.value(0).toString());
              while (qry.next()) {
                    ui->comboBoxab->addItem(qry.value(groupID_AB).toString());


  }
}

void Dialog::on_Modifier_clicked()
{
    modifier_ab a;

      a.setID_AB(ui->comboBoxab->currentText().toInt());
      QSqlQuery qry;
      int ID_AB=ui->comboBoxab->currentText().toInt();
        QString ID_AB_STRING= QString::number(ID_AB);
        qry.prepare("SELECT * from ABONNES where ID_AB='"+ID_AB_STRING+"'");
         if (qry.exec())
            {
             while (qry.next()) {
                QString nom=qry.value(1).toString();
              a.setNOM(nom);
              QString prenom=qry.value(2).toString();
            a.setPRENOM(prenom);
              int age=qry.value(3).toString().toInt();
              QString age_STRING= QString::number(age);
            a.setAGE(age);
              a.exec();
   }
   }
}

void Dialog::on_Ajouter_2_clicked()
{
    int ID_ABT=ui->ID_ABT->text().toInt();
     QDate DATE_INS=ui->dateEdit->date();
     qDebug()<<DATE_INS;
     QString TYPE=ui->TYPE->text();
     qDebug()<<TYPE+"dialog";
     qDebug()<<DATE_INS;
     qDebug()<<ID_ABT;

     abonnement abt(ID_ABT,DATE_INS,TYPE);
     QMessageBox msg;
     bool test=abt.ajout_abt();



     if(test)
     {
         QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                     QObject::tr("id deja exist.\n"), QMessageBox::Cancel);

 }
     else if(ui->ID_ABT->text().isEmpty()){

         QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                     QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

     }
     else
        { QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                     QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);}

     ui->tableabt->setModel(abt.afficher());
     ui->comboBoxabt->clear();
         QSqlQuery qry;
             qry.prepare("SELECT ID_ABT FROM ABONNEMENT");
             qry.exec();
             qry.first();
             int groupID_ABT = qry.record().indexOf("ID_ABT");
              ui->comboBoxabt->addItem(qry.value(0).toString());
             while (qry.next()) {
                   ui->comboBoxabt->addItem(qry.value(groupID_ABT).toString());


}}


void Dialog::on_Modifier_2_clicked()
{
    modifier_abt a;

      a.setID_ABT(ui->comboBoxabt->currentText().toInt());
      QSqlQuery qry;
      int ID_ABT=ui->comboBoxabt->currentText().toInt();
        QString ID_ABT_STRING= QString::number(ID_ABT);
        qry.prepare("SELECT * from ABONNEMENT where ID_ABT='"+ID_ABT_STRING+"'");
         if (qry.exec())
            {
             while (qry.next()) {

              QDate DATE_INS=qry.value(1).toDate();
            a.setDATE_INS(DATE_INS);
            QString TYPE=qry.value(2).toString();
          a.setTYPE(TYPE);

              a.exec();
             }}

}

void Dialog::on_Supprimer_2_clicked()
{
    ui->comboBoxabt->clear();
        QSqlQuery qry;
            qry.prepare("SELECT ID_ABT FROM ABONNEMENT");
            qry.exec();
            qry.first();
            int groupID_ABT = qry.record().indexOf("ID_ABT");
             ui->comboBoxabt->addItem(qry.value(0).toString());
            while (qry.next()) {
                  ui->comboBoxabt->addItem(qry.value(groupID_ABT).toString());


}
    abonnement ab1;
       ab1.setID_ABT(ui->comboBoxabt->currentText().toInt());
       bool test=ab1.supprimer(ab1.getID_ABT());
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                       QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);

   }
       else if(ui->comboBoxabt->currentText().isEmpty()){

           QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                       QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                       QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}

void Dialog::on_pushButton_2_clicked()
{
   ui->tableabt->setModel(abt.afficher());
   ui->comboBoxabt->clear();
       QSqlQuery qry;
           qry.prepare("SELECT ID_ABT FROM ABONNEMENT");
           qry.exec();
           qry.first();
           int groupID_ABT = qry.record().indexOf("ID_ABT");
            ui->comboBoxabt->addItem(qry.value(0).toString());
           while (qry.next()) {
                 ui->comboBoxabt->addItem(qry.value(groupID_ABT).toString());
}
}

void Dialog::on_pushButton_3_clicked()
{
    QString domainerech = ui->lineEdit_rech->text();
           ui->tableab->setModel(ab.chercher(domainerech));
}



void Dialog::on_Ajouter2_clicked()
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

void Dialog::on_pushButton_5_clicked()
{

}

void Dialog::on_Supprimerprog_clicked()
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


void Dialog::on_pushButton_15_clicked()
{
    ui->tabprog->setModel(prog.Afficher2());
}

void Dialog::on_pushButton_6_clicked()
{
    qsrand(qrand());
                    ui->ID_Planning->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                    bool alreadyExist = false;
                    {

                       int ID_Planning=ui->ID_Planning->text().toInt();
                    QSqlQuery query;
                    QString ID_String=QString::number(ID_Planning);
                    query.prepare("select ID_Planning from Programs where ID_Planning=:ID_Planning");
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

void Dialog::on_button_6_clicked()
{
    QString domainerech = ui->recherche_2->text();
           ui->tabprog->setModel(prog.chercher(domainerech));
}

void Dialog::on_pushButton_7_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


            const int rowCount = ui->tabprog->model()->rowCount();
            const int columnCount = ui->tabprog->model()->columnCount();


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
                    if (!ui->tabprog->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabprog->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabprog->isColumnHidden(column)) {
                        QString data = ui->tabprog->model()->data(ui->tabprog->model()->index(row, column)).toString().simplified();
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

void Dialog::on_Modifierprog_clicked()
{
    modifierprogrammes dm;
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

void Dialog::on_Ajouter1_clicked()
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

void Dialog::on_Supprimer1_clicked()
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

void Dialog::on_pushButton_9_clicked()
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

void Dialog::on_Modifier1_clicked()
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

void Dialog::on_button_5_clicked()
{
    QString domainerech = ui->recherche->text();
           ui->tableView_2->setModel(c.chercher(domainerech));
}

void Dialog::on_Afficher1_clicked()
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
    ui->tableView_2->setModel(c.Afficher1());
}

void Dialog::on_pushButton_8_clicked()
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

void Dialog::on_presence_selectionChanged()
{

}

void Dialog::on_nomcombo_currentIndexChanged(const QString &arg1)
{
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
