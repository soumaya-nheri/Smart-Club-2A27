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
#include<calculatrice.h>
#include<QPrintPreviewWidget>
#include<QSqlRelationalTableModel>
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
#include<QMediaPlayer>
#include<mainwindow.h>

comptabilite::comptabilite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comptabilite)

{

    ui->setupUi(this);

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
 auto dv = new QDoubleValidator(0.0, 5.0, 2);
 ui->CONSOMATION->setValidator(dv);
  ui->REV_ABON->setValidator(dv);
   ui->REV_SPONSOR->setValidator(dv);
   ui->ACHAT->setValidator(dv);
    ui->salaire->setValidator(dv);
    ui->event->setValidator(dv);
  ui->ID_DEP->setValidator( new QIntValidator(0, 9999, this));
  ui->ID_REV->setValidator( new QIntValidator(0, 9999, this));
  High = 9999;
  Low = 0;
  qsrand(qrand());
  ui->ID_DEP->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
  ui->ID_REV->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
  //COMBOBOX VALUES TAKEN
  QSqlQuery query;
      query.prepare("SELECT ID_REV FROM REVENUES");
      query.exec();
      query.first();
      int groupID_REV = query.record().indexOf("ID_REV");
ui->comboBox->addItem(query.value(0).toString());
      while (query.next()) {

            ui->comboBox->addItem(query.value(groupID_REV).toString());

}
      //COMBOBOX VALUES TAKEN
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
                          "<center><h1> SMART CLUB </h1> </center>"

                          "  <h2>EXTRAITS services PDF</h2>"
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
    slice0->setPen(QPen(Qt::darkBlue, 2));
    slice0->setBrush(Qt::blue);
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
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
    slice0->setPen(QPen(Qt::darkBlue, 2));
    slice0->setBrush(Qt::blue);
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
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
