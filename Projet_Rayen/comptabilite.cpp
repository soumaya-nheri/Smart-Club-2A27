#include "comptabilite.h"
#include "ui_comptabilite.h"
#include"revenues.h"
#include<QMessageBox>
#include<modifier_rev.h>
#include<depenses.h>
#include<modifier_dep.h>
#include<QMediaPlayer>
#include<QPrinter>
#include<QPrintDialog>
#include<QPrintPreviewWidget>
#include<QSqlRecord>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLineSeries>
#include<QTextDocument>
#include<mainwindow.h>
#include"equipements.h"
#include"modifier.h"
#include"services.h"
#include"modifiers.h"
#include"coach.h"
#include"modifiercoach.h"
#include"programs.h"
#include"modifierprogrammes.h"
#include"abonnement.h"
#include"abonnes.h"
#include"modifier_abt.h"
#include"modifier_ab.h"
#include"sponsor.h"
#include"historique.h"
#include <QFileDialog>
comptabilite::comptabilite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comptabilite)

{

    ui->setupUi(this);

    ui->formLayout_2->addWidget(affichestat());
    ui->ID_Coach_2->setValidator( new QIntValidator(0, 9999, this));
    ui->ID_AB->setValidator( new QIntValidator(0, 9999, this));
    ui->ID_ABT->setValidator( new QIntValidator(0, 9999, this));
    ui->AGE->setValidator( new QIntValidator(0, 9999, this));
    ui->ID_Planning_2->setValidator( new QIntValidator(0, 9999, this));
    ui->Numero_Sem_2->setValidator( new QIntValidator(0, 9999, this));
    ui->NB_reservation_2->setValidator( new QIntValidator(0, 9999, this));
    ui->Numero_Sem_2->setValidator( new QIntValidator(0, 9999, this));
    ui->nbre_materiel->setValidator( new QIntValidator(0, 9999, this));
    ui->le_id_spons_2->setValidator( new QIntValidator(0, 9999, this));

    ui->Nom_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->Prenom_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->Nom_Coach_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->Specialite_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->marque->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->model->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->etat->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->nom_service->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->type->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->TYPE->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->NOM->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->PRENOM->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->le_nom_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->le_nom_update_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->le_lieu_event_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->le_lieu_update_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->le_descr_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->le_descr_update_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->le_pub_spons_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->le_pub_update_2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));




    auto dv = new QDoubleValidator(0.0, 5.0, 2);
    ui->REV_ABON->setValidator(dv);
     ui->REV_SPONSOR->setValidator(dv);
     ui->ACHAT->setValidator(dv);
      ui->salaire->setValidator(dv);
      ui->event->setValidator(dv);
      ui->prix->setValidator(dv);
    ui->ID_DEP->setValidator( new QIntValidator(0, 9999, this));
    ui->ID_REV->setValidator( new QIntValidator(0, 9999, this));
    ui->le_prix_spons_2->setValidator( new QIntValidator(0, 9999, this));
 ui->le_prix_update_2->setValidator( new QIntValidator(0, 9999, this));
    qsrand(qrand());
      ui->ID_Coach_2->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
        ui->ID_Planning_2->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
            QSqlQuery qry;
                qry.prepare("SELECT ID_Coach FROM coach ");
                qry.exec();
                qry.first();
                int groupID_Coach = qry.record().indexOf("ID_Coach");
                 ui->ID_Coach_modf_sup_2->addItem(qry.value(0).toString());
                while (qry.next()) {
                      ui->ID_Coach_modf_sup_2->addItem(qry.value(groupID_Coach).toString());
}
                QSqlQuery query;
                    query.prepare("SELECT ID_Planning FROM Programs");
                    query.exec();
                    query.first();
                    int groupID_Planning = query.record().indexOf("ID_Planning");
                     ui->ID_Programs_modf_sup_2->addItem(query.value(0).toString());
                    while (query.next()) {
                          ui->ID_Programs_modf_sup_2->addItem(query.value(groupID_Planning).toString());
  }
                    QSqlQuery querr;
                        querr.prepare("SELECT Email FROM Coach");
                        querr.exec();
                        querr.first();
                        int groupmail = querr.record().indexOf("Email");
                         ui->mail_2->addItem(querr.value(0).toString());
                        while (querr.next()) {
                              ui->mail_2->addItem(querr.value(groupmail).toString());
      }
                        QSqlQuery quers;
                            quers.prepare("SELECT Nom FROM Coach");
                            quers.exec();
                            quers.first();
                            int groupnom= quers.record().indexOf("Nom");
                             ui->nomcombo_2->addItem(quers.value(0).toString());
                            while (quers.next()) {
                                  ui->nomcombo_2->addItem(quers.value(groupnom).toString());
          }
                            ui->ABPR_2->addItem("1");

                            ui->ABPR_2->addItem("0");



    player->setMedia(QUrl("qrc:/images/Drake - Whats Next.mp3"));
        player->setVolume(100);
        player->play();
    QSqlQuery queryt;
    queryt.prepare("SELECT id_equipement FROM equipements");
          queryt.exec();
          queryt.first();
          int groupid_equipement = queryt.record().indexOf("id_equipement");
    ui->combosupeq->addItem(queryt.value(0).toString());
    ui->combomodeq->addItem(queryt.value(0).toString());
          while (queryt.next()) {

                ui->combosupeq->addItem(queryt.value(groupid_equipement).toString());
                ui->combomodeq->addItem(queryt.value(groupid_equipement).toString());
}

          QSqlQuery qrd;
          qrd.prepare("SELECT id_service FROM services");
                qrd.exec();
                qrd.first();
                int groupid_service = qrd.record().indexOf("id_service");
          ui->combosupeq->addItem(qrd.value(0).toString());
          ui->combosermod->addItem(qrd.value(0).toString());
                while (qrd.next()) {

                      ui->combosersup->addItem(qrd.value(groupid_service).toString());
                      ui->combosermod->addItem(qrd.value(groupid_service).toString());
      }



        ui->tab_equipements->setModel(Etmp.afficher());

    ui->stackedWidget->setCurrentIndex(0);

        Animation=new QPropertyAnimation(ui->welcome,"geometry");
        Animation->setDuration(5000);
        Animation->setStartValue(ui->welcome->geometry());
        Animation->setEndValue(QRect(700,20,316,73));
        QEasingCurve curve;
        curve.setType(QEasingCurve::InOutBounce);
        Animation->setEasingCurve(curve);
        Animation->start();
    ui->tab_rev->setModel(re.afficher());
 ui->tab_dep->setModel(de.afficher());

 ui->CONSOMATION->setValidator(dv);
  High = 9999;
  Low = 0;
  qsrand(qrand());
  ui->ID_DEP->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
  ui->ID_REV->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
  //COMBOBOX VALUES TAKEN
  QSqlQuery queryS;
      queryS.prepare("SELECT ID_REV FROM REVENUES");
      queryS.exec();
      queryS.first();
      int groupID_REV = queryS.record().indexOf("ID_REV");
ui->comboBox->addItem(queryS.value(0).toString());
      while (queryS.next()) {

            ui->comboBox->addItem(queryS.value(groupID_REV).toString());

}
      //COMBOBOX VALUES TAKEN
      QSqlQuery aez;
          aez.prepare("SELECT ID_DEP FROM DEPENSES");
          aez.exec();
          aez.first();
          int groupID_DEP = aez.record().indexOf("ID_DEP");
          ui->comboBox_dep->addItem(aez.value(0).toString());

          while (aez.next()) {
                ui->comboBox_dep->addItem(aez.value(groupID_DEP).toString());

    }
}


comptabilite::~comptabilite()
{
    delete ui;
}

void comptabilite::on_pushButton_2_clicked()
{

    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    int ID_REV=ui->ID_REV->text().toInt();
    float CONSOMATION=ui->CONSOMATION->text().toFloat();
    float REV_SPONSOR=ui->REV_SPONSOR->text().toFloat();
    float REV_ABON=ui->REV_ABON->text().toFloat();    
    QDate DATE_REV =ui->DATE_REV->date();
    if(ui->CONSOMATION->text().isEmpty() and ui->REV_SPONSOR->text().isEmpty() and ui->REV_ABON->text().isEmpty()){
        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("Il faut au moin un champ remplit \n"), QMessageBox::Cancel);

    }
    else{
    revenues r(ID_REV,CONSOMATION,REV_SPONSOR,REV_ABON,DATE_REV);
    QMessageBox msg;
    bool test=r.ajout_rev();


    if(test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                    QObject::tr("id deja exist.\n"), QMessageBox::Cancel);

}
    else if(ui->ID_REV->text().isEmpty()){

        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    }

    else
       { QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                    QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);
    ui->tab_rev->setModel(re.afficher());
    ui->CONSOMATION->setText("");
    ui->REV_SPONSOR->setText("");
    ui->REV_ABON->setText("");
        }
    }
    qsrand(qrand());
    ui->ID_REV->setText(QString::number(qrand() % ((High + 1) - Low) + Low));





}

void comptabilite::on_refresh_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    ui->tab_rev->setModel(re.afficher());
    ui->comboBox->clear();
    QSqlQuery query;
        query.prepare("SELECT ID_REV FROM REVENUES");
        query.exec();
        query.first();
        int groupID = query.record().indexOf("ID_REV");
         ui->comboBox->addItem(query.value(0).toString());
        while (query.next()) {
              ui->comboBox->addItem(query.value(groupID).toString());


}
}

void comptabilite::on_pushButton_3_clicked()
{
    revenues re1;
    re1.setID_REV(ui->comboBox->currentText().toInt());
    bool test=re1.supprimer(re1.getID_REV());
    if(!test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}
    else if(ui->comboBox->currentText().isEmpty()){

        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);


    ui->tab_rev->setModel(re.afficher());
    ui->comboBox->clear();
    QSqlQuery query;
        query.prepare("SELECT ID_REV FROM REVENUES");
        query.exec();
        query.first();
        int groupID = query.record().indexOf("ID_REV");
         ui->comboBox->addItem(query.value(0).toString());
        while (query.next()) {
              ui->comboBox->addItem(query.value(groupID).toString());


}
}

void comptabilite::on_pushButton_4_clicked()
{
      ui->tab_rev->setModel(re.afficher());
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    modifier_rev R;

    R.setID_REV(ui->comboBox->currentText().toInt());
    QSqlQuery qry;
    int ID_REV=ui->comboBox->currentText().toInt();
    qDebug()<<ID_REV;
      QString ID_REV_STRING= QString::number(ID_REV);
      qry.prepare("SELECT * from REVENUES where ID_REV='"+ID_REV_STRING+"'");
      qDebug()<<qry.exec();
       if (qry.exec())
          {
           while (qry.next()) {
              float ac=qry.value(1).toString().toFloat();
              QString ac_STRING= QString::number(ac);
            R.setCONSOMATION(ac);
            float sa=qry.value(2).toString().toFloat();
            QString sa_STRING= QString::number(sa);
          R.setREV_SPONSOR(sa);
          float ev=qry.value(3).toString().toFloat();
          QString ev_STRING= QString::number(ev);
        R.setREV_ABON(ev);
            QDate da=qry.value(4).toDate();
        R.setDATE_REV(da);

            R.exec();
 }
 }
}

void comptabilite::on_pushButton_clicked()
{

    QMediaPlayer *son;
    son=new QMediaPlayer();
    son->setMedia(QUrl("qrc:/images/click.mp3"));
    son->setVolume(50);
    son->play();

    int ID_DEP=ui->ID_DEP->text().toInt();
    float ACHAT=ui->ACHAT->text().toFloat();
    float SALAIRE=ui->salaire->text().toFloat();
    float EVENT=ui->event->text().toFloat();
    QDate DATE_DEP =ui->date_dep->date();
    if(ui->ACHAT->text().isEmpty() and ui->salaire->text().isEmpty() and ui->event->text().isEmpty()){
        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("Il faut au moin un champ remplit \n"), QMessageBox::Cancel);
    }
    else{
    depenses d(ID_DEP,ACHAT,SALAIRE,EVENT,DATE_DEP);
  bool test=d.ajout_dep();
  if(test)
  {
      QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                  QObject::tr("Erreur d'ajout.\n"), QMessageBox::Cancel);

}
  else if(ui->ACHAT->text().isEmpty() and ui->salaire->text().isEmpty() and ui->event->text().isEmpty()){
      QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                  QObject::tr("Il faut au moin un champ remplit \n"), QMessageBox::Cancel);
  }
  else if(ui->ID_DEP->text().isEmpty()){

      QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                  QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

  }

  else
    {  QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                  QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);
      ui->tab_dep->setModel(de.afficher());
      ui->ACHAT->setText("");
      ui->salaire->setText("");
      ui->event->setText("");
  }
    }
  qsrand(qrand());
  ui->ID_DEP->setText(QString::number(qrand() % ((High + 1) - Low) + Low));





}

void comptabilite::on_refresh_dep_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    ui->tab_dep->setModel(de.afficher());
    ui->comboBox_dep->clear();
    QSqlQuery qry;
        qry.prepare("SELECT ID_DEP FROM DEPENSES");
        qry.exec();
        qry.first();
        int groupID_DEP = qry.record().indexOf("ID_DEP");
         ui->comboBox_dep->addItem(qry.value(0).toString());
        while (qry.next()) {
              ui->comboBox_dep->addItem(qry.value(groupID_DEP).toString());

  }
}

void comptabilite::on_supp_dep_clicked()
{

    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    depenses de1;
   de1.setID_DEP(ui->comboBox_dep->currentText().toInt());
   bool test=de1.supprimer(de1.getID_DEP());
   if(!test)
   {
       QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                   QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}
   else if(ui->comboBox_dep->currentText().isEmpty()){

       QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                   QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

   }
   else
       QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                   QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);
                   ui->tab_dep->setModel(de.afficher());
                   ui->comboBox_dep->clear();
                   QSqlQuery qry;
                       qry.prepare("SELECT ID_DEP FROM DEPENSES");
                       qry.exec();
                       qry.first();
                       int groupID_DEP = qry.record().indexOf("ID_DEP");
                        ui->comboBox_dep->addItem(qry.value(0).toString());
                       while (qry.next()) {
                             ui->comboBox_dep->addItem(qry.value(groupID_DEP).toString());
                       }


}


void comptabilite::on_mod_dep_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();


   modifier_dep R;

   R.setID_DEP(ui->comboBox_dep->currentText().toInt());
   QSqlQuery qry;
   int ID_DEP=ui->comboBox_dep->currentText().toInt();
   qDebug()<<ID_DEP;
     QString ID_DEP_STRING= QString::number(ID_DEP);
     qry.prepare("SELECT * from DEPENSES where ID_DEP='"+ID_DEP_STRING+"'");
     qDebug()<<qry.exec();
      if (qry.exec())
         {
          while (qry.next()) {
             float ac=qry.value(1).toString().toFloat();
             QString ac_STRING= QString::number(ac);
           R.setACHAT(ac);
           float sa=qry.value(2).toString().toFloat();
           QString sa_STRING= QString::number(sa);
         R.setSALAIRE(sa);
         float ev=qry.value(3).toString().toFloat();
         QString ev_STRING= QString::number(ev);
       R.setEVENT(ev);
           R.exec();
}
}

}




void comptabilite::on_pushButton_5_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    qsrand(qrand());
                ui->ID_DEP->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                bool alreadyExist = false;
                {
                int ID_DEP=ui->ID_DEP->text().toInt();
                QSqlQuery query;
                QString ID_String=QString::number(ID_DEP);
                query.prepare("select ID_DEP from depenses where ID_DEP=:ID_DEP");
                query.bindValue(":ID_DEP",ID_DEP);
                if(!query.exec()){
                // select failed
                }
                alreadyExist = query.next();
                }
                if(alreadyExist){
                // update
                    qsrand(qrand());
                                ui->ID_DEP->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                                QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                                            QObject::tr("ID Deja exist.\n"), QMessageBox::Cancel);

                }
                else{
                //insert
                    qDebug()<<"n'existe pas";
                }
}

void comptabilite::on_pushButton_6_clicked()
{QMediaPlayer *son;
    son=new QMediaPlayer();
    son->setMedia(QUrl("qrc:/images/click.mp3"));
    son->setVolume(50);
    son->play();
    qsrand(qrand());
            ui->ID_REV->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
            bool alreadyExist = false;
            {

               int ID_REV=ui->ID_REV->text().toInt();
            QSqlQuery query; QString ID_String=QString::number(ID_REV);
            query.prepare("select ID_REV from revenues where ID_REV=:ID_REV");
            query.bindValue(":ID_REV",ID_REV);
            if(!query.exec()){
            // select failed
            }
            alreadyExist = query.next();
            }
            if(alreadyExist){
            // update
                qsrand(qrand());
                            ui->ID_REV->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                            QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                                        QObject::tr("ID Deja exist.\n"), QMessageBox::Cancel);

            }
            else{
            //insert
                qDebug()<<"n'existe pas";
            }
}

void comptabilite::on_print_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    QString strStream;
            QTextStream out(&strStream);


            const int rowCount = ui->tab_dep->model()->rowCount();
            const int columnCount = ui->tab_dep->model()->columnCount();


            out <<  "<html>\n"
                        "<head>\n"

                     <<  QString("<title>%1</title>\n").arg("col1")
                      <<  "</head>\n"
                          "<center><h1> SMART CLUB</h1></center>"

                          "  <h2>TABLE DES DEPENSES</h2>"
                          "<body   >\n"
                          "<table border=1 cellspacing=0 cellpadding=2 >\n";

            // headers
            out << "<thead><tr >";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_dep->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tab_dep->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tab_dep->isColumnHidden(column)) {
                        QString data = ui->tab_dep->model()->data(ui->tab_dep->model()->index(row, column)).toString().simplified();
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

void comptabilite::on_somme_consomation2_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    QSqlQuery query;
    query.exec("SELECT SUM(CONSOMATION) FROM REVENUES");
        if (query.next()) {
            ui->somme_consomation->setText(query.value(0).toString());
        }
    query.finish();
}

void comptabilite::on_pushButton_7_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    QSqlQuery query;

    query.exec("SELECT SUM(CONSOMATION)+SUM(REV_SPONSOR)+SUM(REV_ABON) FROM REVENUES");
        if (query.next()) {
            ui->ALL_REV->setText(query.value(0).toString());
        }
    query.finish();
}

void comptabilite::on_somme_rev_abon2_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    QSqlQuery query;
    query.exec("SELECT SUM(REV_ABON) FROM REVENUES");
        if (query.next()) {
            ui->somme_rev_abon->setText(query.value(0).toString());
        }
    query.finish();
}

void comptabilite::on_somme_rev_sponsor2_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    QSqlQuery query;
    query.exec("SELECT SUM(REV_SPONSOR) FROM REVENUES");
        if (query.next()) {
            ui->somme_rev_sponsor->setText(query.value(0).toString());
        }
    query.finish();
}


void comptabilite::on_pushButton_8_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    using namespace QtCharts;

    QSqlQuery query;
    query.exec("SELECT SUM(ACHAT) FROM depenses");
        if (query.next()) {
            ui->somme_achat->setText(query.value(0).toString());
        }

    query.finish();
    QSqlQuery qry;
    qry.exec("SELECT SUM(SALAIRE) FROM depenses");
        if (qry.next()) {
            ui->somme_salaire->setText(qry.value(0).toString());
        }

    qry.finish();
    QSqlQuery qrys;
    qrys.exec("SELECT SUM(EVENT) FROM DEPENSES");
        if (qrys.next()) {
            ui->somme_event->setText(qrys.value(0).toString());
        }

    qrys.finish();


    float ch_ach=ui->somme_achat->text().toFloat();
    float ch_sal=ui->somme_salaire->text().toFloat();
    float ch_eve=ui->somme_event->text().toFloat();
    float total=ch_ach+ch_sal+ch_eve;
    QString ach= QString("ACHAT"+QString::number((ch_ach*100)/total, 'f',2)+"%" );
    QString sal=QString("SALAIRE"+QString::number((ch_sal*100)/total, 'f',2)+"%" );
    QString eve=QString("EVENEMENT "+QString::number((ch_eve*100)/total, 'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(ach,ch_ach);
    series->append(sal,ch_sal);
    series->append(eve,ch_eve);
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    slice0->setPen(QPen(Qt::darkBlue, 2));
    slice0->setBrush(Qt::blue);
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
    slice2->setPen(QPen(Qt::darkRed, 2));
    slice2->setBrush(Qt::red);
    QChart *chart = new QChart();
    chart->setWindowTitle("STATISTIQUES DES DEPENSES");
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par Type de Depenses");
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setWindowTitle("STATISTIQUES DES Depenses");
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800,500);
    chartView->show();
    chartView->activateWindow();
    chartView->raise();

}
void comptabilite::on_pushButton_9_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    using namespace QtCharts;

    QSqlQuery query;
    query.exec("SELECT SUM(CONSOMATION) FROM REVENUES");
        if (query.next()) {
            ui->somme_consomation->setText(query.value(0).toString());
        }

    query.finish();
    QSqlQuery qry;
    qry.exec("SELECT SUM(REV_SPONSOR) FROM REVENUES");
        if (qry.next()) {
            ui->somme_rev_sponsor->setText(qry.value(0).toString());
        }

    qry.finish();
    QSqlQuery qrys;
    qrys.exec("SELECT SUM(REV_ABON) FROM REVENUES");
        if (qrys.next()) {
            ui->somme_rev_abon->setText(qrys.value(0).toString());
        }

    qrys.finish();


    float ch_cons=ui->somme_consomation->text().toFloat();
    float ch_spon=ui->somme_rev_sponsor->text().toFloat();
    float ch_abon=ui->somme_rev_abon->text().toFloat();
    float total=ch_cons+ch_spon+ch_abon;
    QString cons= QString("CONSOMATION"+QString::number((ch_cons*100)/total, 'f',2)+"%" );
    QString spon=QString("REVENUES DES SPONSORS "+QString::number((ch_spon*100)/total, 'f',2)+"%" );
    QString abon=QString("REVENUES DES ABONNÉS "+QString::number((ch_abon*100)/total, 'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(cons,ch_cons);
    series->append(spon,ch_spon);
    series->append(abon,ch_abon);
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    slice0->setPen(QPen(Qt::darkBlue, 2));
    slice0->setBrush(Qt::blue);
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
    slice2->setPen(QPen(Qt::darkRed, 2));
    slice2->setBrush(Qt::red);
    QChart *chart = new QChart();
    chart->setWindowTitle("STATISTIQUES DES REVENUES");
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par Type de REVENUES");
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setWindowTitle("STATISTIQUES DES REVENUES");
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800,500);
    chartView->show();
    chartView->activateWindow();
    chartView->raise();
}

void comptabilite::on_pushButton_11_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    QSqlQuery query;
    query.exec("SELECT SUM(ACHAT) FROM Depenses");
        if (query.next()) {
            ui->somme_achat->setText(query.value(0).toString());
        }
    query.finish();
}

void comptabilite::on_pushButton_10_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    QSqlQuery query;
    query.exec("SELECT SUM(SALAIRE) FROM Depenses");
        if (query.next()) {
            ui->somme_salaire->setText(query.value(0).toString());
        }
    query.finish();
}

void comptabilite::on_pushButton_12_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    QSqlQuery query;
    query.exec("SELECT SUM(EVENT) FROM Depenses");
        if (query.next()) {
            ui->somme_event->setText(query.value(0).toString());
        }
    query.finish();
}

void comptabilite::on_somme_dep_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    QSqlQuery query;

    query.exec("SELECT SUM(ACHAT)+SUM(SALAIRE)+SUM(EVENT) FROM DEPENSES");
        if (query.next()) {
            ui->DEP_ALL->setText(query.value(0).toString());
        }
    query.finish();
}

void comptabilite::on_pushButton_15_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    using namespace QtCharts;

    QSqlQuery query;
    query.exec("SELECT SUM(ACHAT)+SUM(SALAIRE)+SUM(EVENT) FROM DEPENSES");
        if (query.next()) {
            ui->DEP_ALL->setText(query.value(0).toString());
        }

    query.finish();

    QSqlQuery qry;
    qry.exec("SELECT SUM(CONSOMATION)+SUM(REV_SPONSOR)+SUM(REV_ABON) FROM REVENUES");
        if (qry.next()) {
            ui->ALL_REV->setText(qry.value(0).toString());
        }

    qry.finish();

    float ch_rev=ui->ALL_REV->text().toFloat();
    float ch_dep=ui->DEP_ALL->text().toFloat();
    float total=ch_rev+ch_dep;
    QString rev= QString("Revenues"+QString::number((ch_rev*100)/total, 'f',2)+"%" );
    QString dep=QString("Depenses "+QString::number((ch_dep*100)/total, 'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(rev,ch_rev);
    series->append(dep,ch_dep);
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    slice0->setBrush(Qt::blue);
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 4));
    slice1->setBrush(Qt::green);
    QChart *chart = new QChart();
    chart->setWindowTitle("STATISTIQUES GLOBAL");
    chart->addSeries(series);
    chart->setTitle("Pourcentage REVENUES/DEPENSES");
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setWindowTitle("STATISTIQUES GLOBAL");
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800,500);
    chartView->show();
    chartView->activateWindow();
    chartView->raise();

}

void comptabilite::on_pushButton_13_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    using namespace QtCharts;

    QSqlQuery query;
    query.exec("SELECT SUM(ACHAT)+SUM(SALAIRE)+SUM(EVENT) FROM DEPENSES");
        if (query.next()) {
            ui->DEP_ALL->setText(query.value(0).toString());
        }

    query.finish();

    QSqlQuery qry;
    qry.exec("SELECT SUM(CONSOMATION)+SUM(REV_SPONSOR)+SUM(REV_ABON) FROM REVENUES");
        if (qry.next()) {
            ui->ALL_REV->setText(qry.value(0).toString());
        }

    qry.finish();

    float ch_rev=ui->ALL_REV->text().toFloat();
    float ch_dep=ui->DEP_ALL->text().toFloat();
    float total=ch_rev+ch_dep;
    QString rev= QString("Revenues"+QString::number((ch_rev*100)/total, 'f',2)+"%" );
    QString dep=QString("Depenses "+QString::number((ch_dep*100)/total, 'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(rev,ch_rev);
    series->append(dep,ch_dep);
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    slice0->setPen(QPen(Qt::darkBlue, 4));
    slice0->setBrush(Qt::blue);
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    slice1->setBrush(Qt::green);
    QChart *chart = new QChart();
    chart->setWindowTitle("STATISTIQUES GLOBAL");
    chart->addSeries(series);
    chart->setTitle("Pourcentage REVENUES/DEPENSES");
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setWindowTitle("STATISTIQUES GLOBAL");
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800,500);
    chartView->show();
    chartView->activateWindow();
    chartView->raise();

}

void comptabilite::on_pushButton_17_clicked()
{
    QString marque=ui->marque->text();
     QString model=ui->model->text();
     QString prix=ui->prix->text();
     QString etat=ui->etat->text();
     QString disponibilite=ui->disponibilite->text();
     srand(time(NULL));
         int b;
         b=rand()%999999 + 100000;
    equipements e(b,marque,model,prix,etat,disponibilite);
    bool test=e.ajouter();

    QMessageBox msgbox;

    if(!test)
      return  msgbox.setText("Ajout avec succes");
    else
       return msgbox.setText("Echec d ajout");
    msgbox.exec();
}

void comptabilite::on_pushButton_16_clicked()
{
    equipements e1;
    e1.setid_equipement(ui->combosupeq->currentText().toInt());
       bool test=e1.supprimer(e1.getid_equipement());
       QMessageBox msgbox;
       if(!test)

          return msgbox.setText("Suppression avec succes");

       else
          return msgbox.setText("Echec de suppression");
       msgbox.exec();
}

void comptabilite::on_pushButton_14_clicked()
{
    ui->tab_equipements->setModel(Etmp.afficher());
    ui->combosupeq->clear();
    ui->combomodeq->clear();

        QSqlQuery query;
            query.prepare("SELECT id_equipement FROM equipements");
            query.exec();
            query.first();
            int groupID = query.record().indexOf("id_equipement");
             ui->combosupeq->addItem(query.value(0).toString());
              ui->combomodeq->addItem(query.value(0).toString());
            while (query.next()) {
                  ui->combosupeq->addItem(query.value(groupID).toString());
                   ui->combomodeq->addItem(query.value(groupID).toString());
}
}

void comptabilite::on_modifiereq_clicked()
{
    modifier m;

        QMessageBox msg;
         m.setid_equipement(ui->combomodeq->currentText().toInt());

       if(ui->combomodeq->currentText().isEmpty())
       {
          msg.setText("empty");

       }
        else
           ui->combomodeq->clear();
       m.setid_equipement(ui->combosupeq->currentText().toInt());
        m.exec();
}

void comptabilite::on_pushButton_18_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tab_equipements->model()->rowCount();
        const int columnCount = ui->tab_equipements->model()->columnCount();


        out <<  "<html>\n"
                    "<head>\n"

                 <<  QString("<title>%1</title>\n").arg("col1")
                  <<  "</head>\n"
                      "<center><h1> SMART CLUB </h1> </center>"

                      "  <h2>EXTRAITS equipements PDF</h2>"
                      "<body   >\n"
                      "<table border=1 cellspacing=0 cellpadding=2 >\n";

        // headers
        out << "<thead><tr >";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tab_equipements->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tab_equipements->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tab_equipements->isColumnHidden(column)) {
                    QString data = ui->tab_equipements->model()->data(ui->tab_equipements->model()->index(row, column)).toString().simplified();
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

void comptabilite::on_pushButton_19_clicked()
{
    using namespace QtCharts;
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from equipements where marque='matrix' ");
        float tt_matrix=model->rowCount();
        model->setQuery("select * from equipements where marque!='matrix' or marque!='Unica'  ");
        float tt_autre=model->rowCount();
        model->setQuery("select * from equipements where marque='Unica' ");
        float tt_Unica=model->rowCount();


        float total=tt_matrix+tt_autre+tt_Unica;
        QString matrix= QString("matrix "+QString::number((tt_matrix*100)/total, 'f',2)+"%" );
        QString autre=QString("autre "+QString::number((tt_autre*100)/total, 'f',2)+"%" );
        QString Unica=QString("Unica "+QString::number((tt_Unica*100)/total, 'f',2)+"%" );

        QPieSeries *series = new QPieSeries();
        series->append(matrix,tt_matrix);
        series->append(autre,tt_autre);
        series->append(Unica,tt_Unica );
        // Add label to 1st slice
        QPieSlice *slice0 = series->slices().at(0);
        slice0->setLabelVisible();
        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
        slice1->setPen(QPen(Qt::darkGreen, 2));
        slice1->setBrush(Qt::green);
        // Add labels to rest of slices
        QPieSlice *slice2 = series->slices().at(2);
        slice2->setLabelVisible();
        // Create the chart widget
        QChart *chart = new QChart();
        // Add data to chart with title and hide legend
        chart->addSeries(series);
        chart->setTitle("Voir les poucentage par rapport aux marques ");
        chart->legend()->hide();
        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(800,500);
        chartView->show();
        chartView->activateWindow();
        chartView->raise();
}

void comptabilite::on_pushButton_20_clicked()
{
    player->stop();
    player->setMedia(QUrl("qrc:/images/Drake - Whats Next.mp3"));
        player->setVolume(100);
        player->play();
}

void comptabilite::on_pushButton_21_clicked()
{
     player->stop();
}

void comptabilite::on_pushButton_43_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void comptabilite::on_pushButton_44_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void comptabilite::on_pushButton_23_clicked()
{
    QString nom_service=ui->nom_service->text();
     int nbre_materiel=ui->nbre_materiel->text().toInt();
     QString type=ui->type->text();
     srand(time(NULL));
         int a;
         a=rand()%999999 + 100000;
    services e(a,nom_service,nbre_materiel,type);
    bool test=e.ajouter();

    if(test)
        {
            QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                        QObject::tr("id deja exist.\n"), QMessageBox::Cancel);

    }



        else if(ui->nom_service->text().isEmpty() or ui->nbre_materiel->text().isEmpty() or ui->type->text().isEmpty()){
            QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                        QObject::tr("Il faut rmplir les champs \n"), QMessageBox::Cancel);
        }
        else
           { QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                        QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);
}
    QDate date_cre;
    QDate date_mod;
    historique h(a,date_cre,date_mod);
    bool test1=h.ajout_his();
}

void comptabilite::on_pushButton_24_clicked()
{
    services e1;
       e1.setid_service(ui->combosersup->currentText().toInt());
       bool test=e1.supprimer(e1.getid_service());
       QMessageBox msgbox;
       if(!test)
          return msgbox.setText("Suppression avec succes");
       else
          return msgbox.setText("Echec de suppression");
       msgbox.exec();
}

void comptabilite::on_pushButton_22_clicked()
{

    ui->tab_service->setModel(Etmp1.afficher());
    ui->combosersup->clear();
    ui->combosermod->clear();

    QSqlQuery qry;
        qry.prepare("SELECT id_service FROM services");
        qry.exec();
        qry.first();
        int groupID = qry.record().indexOf("id_service");
         ui->combosersup->addItem(qry.value(0).toString());
          ui->combosermod->addItem(qry.value(0).toString());
        while (qry.next()) {
              ui->combosersup->addItem(qry.value(groupID).toString());
               ui->combosermod->addItem(qry.value(groupID).toString());
}
}

void comptabilite::on_modifierse_2_clicked()
{
    modifiers m;

        QMessageBox msg;
       m.setid_service(ui->combosermod->currentText().toInt());
       if(ui->combosermod->currentText().isEmpty())
          msg.setText("empty");

        else
        m.exec();

}

void comptabilite::on_pushButton_25_clicked()
{
    QString strStream;
        QTextStream out(&strStream);


        const int rowCount = ui->tab_service->model()->rowCount();
        const int columnCount = ui->tab_service->model()->columnCount();


        out <<  "<html>\n"
                    "<head>\n"

                 <<  QString("<title>%1</title>\n").arg("col1")
                  <<  "</head>\n"
                      "<center><h1> SMART CLUB </h1> </center>"

                      "  <h2>EXTRAITS services PDF</h2>"
                      "<body   >\n"
                      "<table border=1 cellspacing=0 cellpadding=2 >\n";

        // headers
        out << "<thead><tr >";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tab_service->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tab_service->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tab_service->isColumnHidden(column)) {
                    QString data = ui->tab_service->model()->data(ui->tab_service->model()->index(row, column)).toString().simplified();
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

void comptabilite::on_pushButton_28_clicked()
{
    player->stop();
    player->setMedia(QUrl("qrc:/images/Drake - Whats Next.mp3"));
        player->setVolume(100);
        player->play();
}

void comptabilite::on_pushButton_27_clicked()
{
    player->stop();

}

void comptabilite::on_pushButton_26_clicked()
{
    QString domainerech = ui->lineEdit_rech->text();
       ui->tab_service->setModel(Etmp1.chercher(domainerech));
}

void comptabilite::on_Ajouter1_2_clicked()
{
    int ID_Coach=ui->ID_Coach_2->text().toInt();
    QString Nom=ui->Nom_2->text();
    QString Prenom=ui->Prenom_2->text();
    QString Specialite=ui->Specialite_2->text();
    QDate Date_Naiss =ui->Date_Naiss_2->date();
    QString Email=ui->Email_2->text();
    int AB_PR=ui->ABPR_2->currentText().toInt();
    coach r(ID_Coach,Nom,Prenom,Specialite,Date_Naiss,Email,AB_PR);
    bool test=r.Ajouter1();
    QMessageBox msgbox;

        if(!test)
             return msgbox.setText("Ajout avec succes");
        else
            return msgbox.setText("Echec d ajout");
        msgbox.exec();
        ui->ID_Coach_modf_sup_2->clear();
        QSqlQuery qry;
            qry.prepare("SELECT ID_Coach FROM coach ");
            qry.exec();
            qry.first();
             ui->ID_Coach_modf_sup_2->addItem(qry.value(0).toString());
             int groupID_COACH = qry.record().indexOf("ID_COACH");
            while (qry.next()) {
                  ui->ID_Coach_modf_sup_2->addItem(qry.value(groupID_COACH).toString());
    }
}

void comptabilite::on_Supprimer1_2_clicked()
{
    ui->ID_Coach_modf_sup_2->clear();
    QSqlQuery qry;
        qry.prepare("SELECT ID_Coach FROM coach ");
        qry.exec();
        qry.first();
        int groupID_DEP = qry.record().indexOf("ID_Coach");
         ui->ID_Coach_modf_sup_2->addItem(qry.value(0).toString());
        while (qry.next()) {
              ui->ID_Coach_modf_sup_2->addItem(qry.value(groupID_DEP).toString());
}
    coach re1;
       re1.setID_Coach(ui->ID_Coach_modf_sup_2->currentText().toInt());
       bool test=re1.Supprimer1(re1.getID_Coach());
       QMessageBox msgbox;

           if(!test)
                return msgbox.setText("Ajout avec succes");
           else
               return msgbox.setText("Echec d ajout");
           msgbox.exec();
}

void comptabilite::on_Afficher1_2_clicked()
{
    ui->nomcombo_2->clear();
    QSqlQuery quers;
        quers.prepare("SELECT Nom FROM Coach");
        quers.exec();
        quers.first();
        int groupnom= quers.record().indexOf("Nom");
         ui->nomcombo_2->addItem(quers.value(0).toString());
        while (quers.next()) {
              ui->nomcombo_2->addItem(quers.value(groupnom).toString());
}
    ui->mail_2->clear();
    QSqlQuery querr;
        querr.prepare("SELECT Email FROM Coach");
        querr.exec();
        querr.first();
        int groupmail = querr.record().indexOf("Email");
         ui->mail_2->addItem(querr.value(0).toString());
        while (querr.next()) {
              ui->mail_2->addItem(querr.value(groupmail).toString());
}
    ui->ID_Coach_modf_sup_2->clear();
    QSqlQuery qry;
        qry.prepare("SELECT ID_Coach FROM coach ");
        qry.exec();
        qry.first();
        int groupID_Coach = qry.record().indexOf("ID_Coach");
         ui->ID_Coach_modf_sup_2->addItem(qry.value(0).toString());
        while (qry.next()) {
              ui->ID_Coach_modf_sup_2->addItem(qry.value(groupID_Coach).toString());
}
    ui->tableView_3->setModel(re1.Afficher1());
}

void comptabilite::on_Modifier1_2_clicked()
{
    modifiercoach dm;
        QMessageBox msg;
       dm.setID_Coach(ui->ID_Coach_modf_sup_2->currentText().toInt());


           QSqlQuery qry;
           int ID_Coach_modf_sup=ui->ID_Coach_modf_sup_2->currentText().toInt();
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

void comptabilite::on_button_7_clicked()
{
    QString domainerech = ui->recherche_3->text();
           ui->tableView_3->setModel(re1.chercher(domainerech));
}

void comptabilite::on_pushButton_57_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


            const int rowCount = ui->tableView_3->model()->rowCount();
            const int columnCount = ui->tableView_3->model()->columnCount();


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
                    if (!ui->tableView_3->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView_3->isColumnHidden(column)) {
                        QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
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

void comptabilite::on_nomcombo_2_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;
    query.prepare("SELECT AB_PR FROM COACH WHERE NOM='"+arg1+"'");
    query.exec();
    while (query.next()) {

    if(query.value(0).toInt()==1){

        ui->presence_2->setText("present");
    }else

    {
        ui->presence_2->setText("absent");}

}
}

void comptabilite::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void comptabilite::on_pushButton_56_clicked()
{
    qsrand(qrand());
                    ui->ID_Coach_2->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                    bool alreadyExist = false;
                    {

                       int ID_Coach=ui->ID_Coach_2->text().toInt();
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
                                    ui->ID_Coach_2->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
                                    QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                                                QObject::tr("ID Deja exist.\n"), QMessageBox::Cancel);

                    }
                    else{
                    //insert
                        qDebug()<<"n'existe pas";
                    }
}

void comptabilite::on_Ajouter2_2_clicked()
{
    ui->ID_Programs_modf_sup_2->clear();
    QSqlQuery query;
        query.prepare("SELECT ID_Planning FROM Programs ");
        query.exec();
        query.first();
        int groupID_Planning = query.record().indexOf("ID_Planning");
         ui->ID_Programs_modf_sup_2->addItem(query.value(0).toString());
        while (query.next()) {
              ui->ID_Programs_modf_sup_2->addItem(query.value(groupID_Planning).toString());
}
    int ID_Planning=ui->ID_Planning_2->text().toInt();
    QDate Date_Planning =ui->Date_Planning_2->date();
    QTime Heure=ui->Heure_2->time();
    int Numero_Sem=ui->Numero_Sem_2->text().toInt();
    int NB_reservation =ui->NB_reservation_2->text().toInt();
    QString Nom_Coach =ui->Nom_Coach_2->text();
    programs r  (ID_Planning,Date_Planning,Heure,Numero_Sem,NB_reservation,Nom_Coach);
    bool test=r.Ajouter2();
    QMessageBox msgbox;

        if(!test)
             return msgbox.setText("Ajout avec succes");
        else
            return msgbox.setText("Echec d ajout");
        msgbox.exec();
}

void comptabilite::on_Supprimer2_clicked()
{
    ui->ID_Programs_modf_sup_2->clear();
    QSqlQuery query;
        query.prepare("SELECT ID_Planning FROM Programs ");
        query.exec();
        query.first();
        int groupID_Planning = query.record().indexOf("ID_Planning");
         ui->ID_Programs_modf_sup_2->addItem(query.value(0).toString());
        while (query.next()) {
              ui->ID_Programs_modf_sup_2->addItem(query.value(groupID_Planning).toString());
}
    programs re1;
       re1.setID_Planning(ui->ID_Programs_modf_sup_2->currentText().toInt());
       bool test=re1.Supprimer2(re1.getID_Planning());
       QMessageBox msgbox;

           if(!test)
                return msgbox.setText("Ajout avec succes");
           else
               return msgbox.setText("Echec d ajout");
           msgbox.exec();
}

void comptabilite::on_Modifier2_clicked()
{
    modifierprogrammes dm;
        QMessageBox msg;
       dm.setID_Planning(ui->ID_Programs_modf_sup_2->currentText().toInt());

       QSqlQuery qry;
       int ID_Programs_modf_sup=ui->ID_Programs_modf_sup_2->currentText().toInt();
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

void comptabilite::on_Afficher2_clicked()
{
    ui->tableView->setModel(prog.Afficher2());
}

void comptabilite::on_button_8_clicked()
{
    QString domainerech = ui->recherche_4->text();
           ui->tableView->setModel(prog.chercher(domainerech));
}

void comptabilite::on_pushButton_60_clicked()
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

void comptabilite::on_pushButton_61_clicked()
{

}

void comptabilite::on_pushButton_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void comptabilite::on_Ajouter_2_clicked()
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


}
}

void comptabilite::on_Supprimer_2_clicked()
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

void comptabilite::on_pushButton_34_clicked()
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

void comptabilite::on_Modifier_clicked()
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

void comptabilite::on_Supprimer_clicked()
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

void comptabilite::on_pushButton_33_clicked()
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

void comptabilite::on_Modifier_2_clicked()
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

void comptabilite::on_Ajouter_clicked()
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



}
}

void comptabilite::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void comptabilite::on_pushButton_35_clicked()
{

    int id_spons=ui->le_id_spons_2->text().toInt();

    float prix_spons=ui->le_prix_spons_2->text().toDouble();
    QString pub_spons=ui->le_pub_spons_2->text();

    Sponsor A(id_spons,prix_spons,pub_spons);
    QMessageBox msg1;
    bool test =A.ajouter();


    if(test)
    {  msg1.setText("Ajout avec succés");
 ui->cb_sponsors_2->setModel(S.afficher_id_sponsors());
   ui->tablesponsor_2->setModel(S.afficher());


   ui->cb_sponsor_ids_2->setModel(S.afficher_id_sponsors());
    ui->cb_ids_events_supp_2->setModel(E.afficher_id_events());
     ui->cb_ids_sponsor_supp_2->setModel(S.afficher_id_sponsors());
    }
    else
     msg1.setText("Echec d'ajout");
    msg1.exec();
}

void comptabilite::on_pushButton_38_clicked()
{
    Sponsor S1; S1.setid_spons(ui->cb_ids_sponsor_supp_2->currentText().toInt());
    bool test=S1.supprimer(S1.getid_spons());
    QMessageBox msg1;
    if(test)
    {  msg1.setText("supprimer avec succés");
        ui->cb_ids_sponsor_supp_2->setModel(S.afficher_id_sponsors());
          ui->tablesponsor_2->setModel(S.afficher());
           ui->cb_ids_events_supp_2->setModel(E.afficher_id_events());
            ui->cb_ids_sponsor_supp_2->setModel(S.afficher_id_sponsors());

                ui->cb_sponsor_ids_2->setModel(S.afficher_id_sponsors());
    }
    else
     msg1.setText("Echec de suppression");
    msg1.exec();
}

void comptabilite::on_pushButton_37_clicked()
{
    Sponsor S1,S;
        S.setprix_spons( ui->le_prix_update_2->text().toDouble());
        S.setpub_spons( ui->le_pub_update_2->text());
        S.setid_spons(ui->cb_sponsor_ids_2->currentText().toInt());
        bool test=S1.update(S);
        QMessageBox msg1;
        if(test)
        {  msg1.setText("update avec succés");
              ui->tablesponsor_2->setModel(S.afficher());
        }
        else
         msg1.setText("Echec d'update");
        msg1.exec();
}

void comptabilite::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void comptabilite::on_pb_ajouter_2_clicked()
{
    int id=ui->le_id_2->text().toInt();

    QString lieu_event=ui->le_lieu_event_2->text();
    QString nom=ui->le_nom_2->text();
    QString description=ui->le_lieu_event_2->text();

    QDate date=ui->dateEdit_2->date();

    QString dateString = date.toString();

    int id_spons=ui->cb_sponsors_2->currentText().toInt();
    QString cat=ui->cb_categorie_2->currentText();
    QString type=ui->cb_type_2->currentText();
    Evenement E(id,lieu_event,nom,description,date,id_spons,cat,type);

    QMessageBox msg1;
    bool test =E.ajouter();

    if(test)
    {  msg1.setText("Ajout avec succés ");
          ui->tableevent_2->setModel(E.afficher());
  ui->cb_ids_events_supp_2->setModel(E.afficher());
  ui->cb_event_ids_2->setModel(E.afficher());
    }
    else
     msg1.setText("Echec d'ajout");
    msg1.exec();
}

void comptabilite::on_pb_supprimer_2_clicked()
{
    Evenement E1; E1.setid(ui->cb_ids_events_supp_2->currentText().toInt());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msg1;
    if(test)
    {  msg1.setText("supprimer avec succés");
          ui->tableevent_2->setModel(E.afficher());
    }
    else
     msg1.setText("Echec de suppression");
    msg1.exec();
}

void comptabilite::on_pushButton_42_clicked()
{
    Evenement E1,E;

        E1.setid(ui->cb_event_ids_2->currentText().toInt());
        E1.setnom( ui->le_nom_update_2->text());
        E1.setlieu_event( ui->le_lieu_update_2->text());
        E1.setdescr(ui->le_descr_update_2->text());
        QDate dateString= ui->le_date_update_2->date();
         E1.setdate(dateString);
         QString cat=ui->cb_categorie_update_2->currentText();
         QString type=ui->cb_type_update_2->currentText();
         E1.setcat(cat);
         E1.settype(type);
        bool test=E1.update(E1);
        QMessageBox msg1;
        if(test)
        {  msg1.setText("update avec succés");
              ui->tableevent_2->setModel(E1.afficher());
        }
        else
         msg1.setText("Echec d'update");
        msg1.exec();
}

void comptabilite::on_pushButton_40_clicked()
{
    QString strStream;
                QTextStream out(&strStream);


                const int rowCount = ui->tablesponsor_2->model()->rowCount();
                const int columnCount = ui->tablesponsor_2->model()->columnCount();


                out <<  "<html>\n"
                            "<head>\n"

                         <<  QString("<title>%1</title>\n").arg("col1")
                          <<  "</head>\n"
                              "<center><h1> SMART CLUB </h1> </center>"

                              "  <h2>EVENEMENTS</h2>"
                              "<body   >\n"
                              "<table border=1 cellspacing=0 cellpadding=2 >\n";

                // headers
                out << "<thead><tr >";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tablesponsor_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tablesponsor_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tablesponsor_2->isColumnHidden(column)) {
                            QString data = ui->tablesponsor_2->model()->data(ui->tablesponsor_2->model()->index(row, column)).toString().simplified();
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

void comptabilite::on_pushButton_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
QChartView * comptabilite::affichestat()
{



  QPieSeries *series1 = new QPieSeries();
  series1->setName("Nat");

  series1->append("Judo", E.pourcentage("National","Judo"));
  series1->append("Karaté", E.pourcentage("National","Karate"));
  series1->append("Gymnastique",E.pourcentage("National","Gymnastique") );
  series1->append("Tekwando", E.pourcentage("National","Tekwando"));
  series1->append("Autres", E.pourcentage("National","Autres"));
  QPieSeries *series2 = new QPieSeries();
  series2->setName("Inter");
  series2->append("Judo", E.pourcentage("International","Judo"));
  series2->append("Karaté", E.pourcentage("International","Karate"));
  series2->append("Gymnastique", E.pourcentage("International","Gymnastique") );
  series2->append("Tekwando", E.pourcentage("International","Tekwando"));
  series2->append("Autres", E.pourcentage("International","Autres"));



  //![2]
  DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
  donutBreakdown->setAnimationOptions(QChart::AllAnimations);
  donutBreakdown->setTitle("Total Events per Type");
  donutBreakdown->legend()->setAlignment(Qt::AlignRight);
  donutBreakdown->addBreakdownSeries(series1, Qt::red);
  donutBreakdown->addBreakdownSeries(series2, Qt::darkGreen);
  //donutBreakdown->addBreakdownSeries(series3, Qt::darkBlue);
  //![2]

  //![3]

  QChartView *chartView = new QChartView(donutBreakdown);
  chartView->setRenderHint(QPainter::Antialiasing);
  chartView->resize(800,500);

return chartView;



}


void comptabilite::on_pushButton_45_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images (*.png *.jpg *.jpeg"));
    if (QString::compare(filename,QString())!=0)
    {
      QImage label_image;
      bool valid =label_image.load(filename);
      if (valid)
      {   label_image= label_image.scaledToWidth(ui->label_88->width(),Qt::SmoothTransformation);
   ui->label_88->setPixmap(QPixmap::fromImage(label_image));
      }
}
}

void comptabilite::on_pushButton_46_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
     ui->tablehis->setModel(HI.afficher());
}

void comptabilite::on_cb_event_ids_2_currentIndexChanged(int index)
{
    Evenement E1;
     Evenement *E=E1.recherche_by_id(ui->cb_event_ids_2->currentText().toInt());
    ui->le_nom_update_2->setText((E->getnom()));
    ui->le_lieu_update_2->setText(E->getlieu_event());
     ui->le_descr_update_2->setText(E->getdescr());

     if(E->getcat()=="National")

         ui->cb_categorie_update_2->setCurrentIndex(0);
     else
          ui->cb_categorie_update_2->setCurrentIndex(1);

     if(E->gettype()=="Gymnastique")

         ui->cb_type_update_2->setCurrentIndex(2);

     if(E->gettype()=="Judo")

         ui->cb_type_update_2->setCurrentIndex(0);
     if(E->gettype()=="Karaté")

         ui->cb_type_update_2->setCurrentIndex(1);
     if(E->gettype()=="Autres")

         ui->cb_type_update_2->setCurrentIndex(4);
     if(E->gettype()=="Tekwando")

         ui->cb_type_update_2->setCurrentIndex(3);
         //  ui->le_date_update->date();

     QDate f=E->getdate();

       ui->le_date_update_2->setDate(f);

}

void comptabilite::on_cb_sponsor_ids_2_currentIndexChanged(const QString &arg1)
{
    Sponsor S;
     Sponsor  *S1=S.recherche_by_id(ui->cb_sponsor_ids_2->currentText().toInt());
    ui->le_prix_update_2->setText(QString::number(S1->getprix_spons()));
    ui->le_pub_update_2->setText(S1->getpub_spons());
}

void comptabilite::on_le_recherche_sp_2_textChanged(const QString &arg1)
{
    QString rech=ui->le_recherche_sp_2->text();

     ui->tablesponsor_2->setModel(S.afficher_by_recherche(rech));
}

void comptabilite::on_le_recherche_2_textChanged(const QString &arg1)
{
    QString rech=ui->le_recherche_2->text();

     ui->tableevent_2->setModel(E.afficher_by_recherche(rech));
}

void comptabilite::on_pushButton_47_clicked()
{
   ui->tab_dep->setModel(de.tri_ACHAT());

}

void comptabilite::on_pushButton_48_clicked()
{
    ui->tab_dep->setModel(de.tri_ACHATASC());

}

void comptabilite::on_pushButton_49_clicked()
{
    ui->tab_dep->setModel(de.tri_SALAIREDESC());
}

void comptabilite::on_pushButton_50_clicked()
{
    ui->tab_dep->setModel(de.tri_SALAIREASC());

}

void comptabilite::on_pushButton_51_clicked()
{
    ui->tab_dep->setModel(de.tri_EVENTDESC());
}

void comptabilite::on_pushButton_52_clicked()
{
    ui->tab_dep->setModel(de.tri_EVENTASC());
}

void comptabilite::on_pushButton_53_clicked()
{
    ui->tab_dep->setModel(de.tri_datedepDESC());

}

void comptabilite::on_pushButton_54_clicked()
{
    ui->tab_dep->setModel(de.tri_datedepASC());
}

void comptabilite::on_pushButton_55_clicked()
{
ui->stackedWidget->setCurrentIndex(6);
}

void comptabilite::on_rech_depp_textChanged(const QString &arg1)
{
    QString domainerech = ui->rech_depp->text();
           ui->tab_dep->setModel(de.chercher_Dep(domainerech));
}

void comptabilite::on_print_2_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();
    QString strStream;
            QTextStream out(&strStream);


            const int rowCount = ui->tab_rev->model()->rowCount();
            const int columnCount = ui->tab_rev->model()->columnCount();


            out <<  "<html>\n"
                        "<head>\n"

                     <<  QString("<title>%1</title>\n").arg("col1")
                      <<  "</head>\n"
                          "<center><h1> SMART CLUB</h1></center>"

                          "  <h2>TABLE DES REVENUES</h2>"
                          "<body   >\n"
                          "<table border=1 cellspacing=0 cellpadding=2 >\n";

            // headers
            out << "<thead><tr >";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_rev->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tab_rev->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tab_rev->isColumnHidden(column)) {
                        QString data = ui->tab_rev->model()->data(ui->tab_dep->model()->index(row, column)).toString().simplified();
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

void comptabilite::on_pushButton_66_clicked()
{
    ui->tab_rev->setModel(re.tri_CONSOMATIONDESC());
}

void comptabilite::on_pushButton_553_clicked()
{
ui->tab_rev->setModel(re.tri_CONSOMATIONASC());
}

void comptabilite::on_pushButton_65_clicked()
{
    ui->tab_rev->setModel(re.tri_REV_SPONSORDESC());

}

void comptabilite::on_pushButton_64_clicked()
{
    ui->tab_rev->setModel(re.tri_REV_SPONSORASC());

}

void comptabilite::on_pushButton_67_clicked()
{
    ui->tab_rev->setModel(re.tri_REV_ABONDESC());

}

void comptabilite::on_pushButton_62_clicked()
{
    ui->tab_rev->setModel(re.tri_REV_ABONASC());

}

void comptabilite::on_pushButton_63_clicked()
{
    ui->tab_rev->setModel(re.tri_DATE_REVDESC());

}

void comptabilite::on_pushButton_58_clicked()
{
    ui->tab_rev->setModel(re.tri_DATE_REVASC());

}


void comptabilite::on_rech_depp_2_textChanged(const QString &arg1)
{
    QString domainerech = ui->rech_depp_2->text();
           ui->tab_rev->setModel(re.chercher_rev(domainerech));
}

void comptabilite::on_pushButton_68_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


            const int rowCount = ui->tableevent_2->model()->rowCount();
            const int columnCount = ui->tableevent_2->model()->columnCount();


            out <<  "<html>\n"
                        "<head>\n"

                     <<  QString("<title>%1</title>\n").arg("col1")
                      <<  "</head>\n"
                          "<center><h1> SMART CLUB</h1></center>"

                          "  <h2>TABLE DES EVENEMENTS</h2>"
                          "<body   >\n"
                          "<table border=1 cellspacing=0 cellpadding=2 >\n";

            // headers
            out << "<thead><tr >";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tableevent_2->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableevent_2->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableevent_2->isColumnHidden(column)) {
                        QString data = ui->tab_rev->model()->data(ui->tableevent_2->model()->index(row, column)).toString().simplified();
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

void comptabilite::on_pushButton_69_clicked()
{
    ui->tableView->setModel(prog.tri_NUMSEMDESC());

}


void comptabilite::on_pushButton_70_clicked()
{
    ui->tableView->setModel(prog.tri_NUMSEMASC());

}

void comptabilite::on_pushButton_71_clicked()
{
    ui->tableView->setModel(prog.tri_NBRESDESC());

}

void comptabilite::on_pushButton_72_clicked()
{
    ui->tableView->setModel(prog.tri_NBRESASC());
}

void comptabilite::on_pushButton_75_clicked()
{
    QString domainerech = ui->rech_abt->text();
           ui->tableabt->setModel(abt.chercher_ABT(domainerech));
}

void comptabilite::on_pushButton_73_clicked()
{
    ui->tableabt->setModel(abt.tri_IDDESC());

}

void comptabilite::on_pushButton_74_clicked()
{
    ui->tableabt->setModel(abt.tri_IDASC());

}

void comptabilite::on_pushButton_76_clicked()
{
    ui->tableab->setModel(ab.tri_IDABDESC());

}

void comptabilite::on_pushButton_84_clicked()
{
    ui->tableab->setModel(ab.tri_IDABASC());

}


void comptabilite::on_pushButton_93_clicked()
{
    QString domainerech = ui->rech_abt_4->text();
           ui->tableab->setModel(ab.chercher_AB(domainerech));
}
