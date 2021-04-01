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
comptabilite::comptabilite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comptabilite)
{
    ui->setupUi(this);
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
  ui->ID_DEP2->setValidator( new QIntValidator(0, 9999, this));
  ui->ID_REV2->setValidator( new QIntValidator(0, 9999, this));
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
          ui->comboBox_2->addItem(qry.value(0).toString());

          while (qry.next()) {
                ui->comboBox_2->addItem(qry.value(groupID_DEP).toString());

    }
}

comptabilite::~comptabilite()
{
    delete ui;
}

void comptabilite::on_pushButton_2_clicked()
{
    int ID_REV=ui->ID_REV->text().toInt();
    float CONSOMATION=ui->CONSOMATION->text().toFloat();
    float REV_SPONSOR=ui->REV_SPONSOR->text().toFloat();
    float REV_ABON=ui->REV_ABON->text().toFloat();
    QDate DATE_REV =ui->DATE_REV->date();
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
                    QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);}
    qsrand(qrand());
    ui->ID_REV->setText(QString::number(qrand() % ((High + 1) - Low) + Low));





}

void comptabilite::on_refresh_clicked()
{
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
    re1.setID_REV(ui->ID_REV2->text().toInt());
    bool test=re1.supprimer(re1.getID_REV());
    if(!test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}
    else if(ui->ID_REV2->text().isEmpty()){

        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);


}

void comptabilite::on_pushButton_4_clicked()
{
    modifier_rev R;

    R.setID_REV(ui->ID_REV2->text().toInt());
    QSqlQuery qry;
    int ID_REV=ui->ID_REV2->text().toInt();
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

    int ID_DEP=ui->ID_DEP->text().toInt();
    float ACHAT=ui->ACHAT->text().toFloat();
    float SALAIRE=ui->salaire->text().toFloat();
    float EVENT=ui->event->text().toFloat();
    QDate DATE_DEP =ui->date_dep->date();
    depenses d(ID_DEP,ACHAT,SALAIRE,EVENT,DATE_DEP);
  bool test=d.ajout_dep();
  if(test)
  {
      QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                  QObject::tr("Erreur d'ajout.\n"), QMessageBox::Cancel);

}
  else if(ui->ID_DEP->text().isEmpty()){

      QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                  QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

  }

  else
    {  QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                  QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);}
  qsrand(qrand());
  ui->ID_DEP->setText(QString::number(qrand() % ((High + 1) - Low) + Low));





}

void comptabilite::on_refresh_dep_clicked()
{
    ui->tab_dep->setModel(de.afficher());
    ui->comboBox_2->clear();
    QSqlQuery qry;
        qry.prepare("SELECT ID_DEP FROM DEPENSES");
        qry.exec();
        qry.first();
        int groupID_DEP = qry.record().indexOf("ID_DEP");
         ui->comboBox_2->addItem(qry.value(0).toString());
        while (qry.next()) {
              ui->comboBox_2->addItem(qry.value(groupID_DEP).toString());

  }
}

void comptabilite::on_supp_dep_clicked()
{
    depenses de1;
   de1.setID_DEP(ui->ID_DEP2->text().toInt());
   bool test=de1.supprimer(de1.getID_DEP());
   if(!test)
   {
       QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                   QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}
   else if(ui->ID_DEP2->text().isEmpty()){

       QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                   QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

   }
   else
       QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                   QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);
}


void comptabilite::on_mod_dep_clicked()
{


   modifier_dep R;

   R.setID_DEP(ui->ID_DEP2->text().toInt());
   QSqlQuery qry;
   int ID_DEP=ui->ID_DEP2->text().toInt();
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
{ qsrand(qrand());
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



void comptabilite::on_comboBox_currentIndexChanged(int index)
{
    int a=ui->comboBox->currentText().toInt();
    index=a;


    QString ID_String=QString::number(a);

       ui->ID_REV2->setText(ID_String);
}

void comptabilite::on_comboBox_2_currentIndexChanged(int index)
{
    int b=ui->comboBox_2->currentText().toInt();
    index=b;
    QString ID_String=QString::number(b);

       ui->ID_DEP2->setText(ID_String);


}

void comptabilite::on_somme_consomation_clicked()
{
    QSqlQuery query;
    query.exec("SELECT SUM(CONSOMATION) FROM REVENUES");
        if (query.next()) {
            ui->sommes->setText(query.value(0).toString());
        }
    query.finish();
}

void comptabilite::on_pushButton_7_clicked()
{
    QSqlQuery query;

    query.exec("SELECT SUM(CONSOMATION)+SUM(REV_SPONSOR)+SUM(REV_ABON) FROM REVENUES");
        if (query.next()) {
            ui->ALL_REV->setText(query.value(0).toString());
        }
    query.finish();
}

void comptabilite::on_somme_rev_abon_clicked()
{
    QSqlQuery query;
    query.exec("SELECT SUM(REV_ABON) FROM REVENUES");
        if (query.next()) {
            ui->sommes_3->setText(query.value(0).toString());
        }
    query.finish();
}

void comptabilite::on_somme_rev_sponsor_clicked()
{
    QSqlQuery query;
    query.exec("SELECT SUM(REV_SPONSOR) FROM REVENUES");
        if (query.next()) {
            ui->sommes_2->setText(query.value(0).toString());
        }
    query.finish();
}


void comptabilite::on_pushButton_8_clicked()
{
    using namespace QtCharts;
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from revenues");
    float ch_rev=model->rowCount();
    model->setQuery("select * from depenses");
    float ch_dep=model->rowCount();
    float total=ch_rev+ch_dep;
    QString rev= QString("revenues"+QString::number((ch_rev*100)/total, 'f',2)+"%" );
    QString dep=QString("depenses "+QString::number((ch_dep*100)/total, 'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(rev,ch_rev);
    series->append(dep,ch_dep);
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par Type de REVENUES et DEPENSES ");
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800,500);
    chartView->show();
}

void comptabilite::on_pushButton_9_clicked()
{
    using namespace QtCharts;
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from revenues");
    float ch_rev=model->rowCount();
    model->setQuery("select * from depenses");
    float ch_dep=model->rowCount();
    float total=ch_rev+ch_dep;
    QString rev= QString("revenues"+QString::number((ch_rev*100)/total, 'f',2)+"%" );
    QString dep=QString("depenses "+QString::number((ch_dep*100)/total, 'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(rev,ch_rev);
    series->append(dep,ch_dep);
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par Type de REVENUES et DEPENSES ");
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800,500);
    chartView->show();
}
