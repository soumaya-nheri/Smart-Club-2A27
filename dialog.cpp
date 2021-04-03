#include "dialog.h"
#include "ui_dialog.h"
#include "services.h"
#include "modifier.h"
#include "modifiers.h"
#include "equipements.h"
#include <QMessageBox>
#include "dialog.h"
#include "QSqlQuery"
#include "QSqlRecord"
#include "QTextStream"
#include "QTextDocument"
#include "Qprinter"
#include "Qprintdialog"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLineSeries>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)

{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("SELECT id_equipement FROM equipements");
          query.exec();
          query.first();
          int groupid_equipement = query.record().indexOf("id_equipement");
    ui->combosupeq->addItem(query.value(0).toString());
    ui->combomodeq->addItem(query.value(0).toString());
          while (query.next()) {

                ui->combosupeq->addItem(query.value(groupid_equipement).toString());
                ui->combomodeq->addItem(query.value(groupid_equipement).toString());
}

          QSqlQuery qry;
          qry.prepare("SELECT id_service FROM services");
                qry.exec();
                qry.first();
                int groupid_service = qry.record().indexOf("id_service");
          ui->combosupeq->addItem(query.value(0).toString());
          ui->combosermod->addItem(qry.value(0).toString());
                while (qry.next()) {

                      ui->combosersup->addItem(qry.value(groupid_service).toString());
                      ui->combosermod->addItem(qry.value(groupid_service).toString());
      }


    QRegExp rx("[A-Za-z_ ]+");//[A-Za-z0-9_]
                QRegExp rx1("[0-9_]+");

                QValidator *validator = new QRegExpValidator(rx, this);

                ui->marque->setValidator(validator);
                    ui->model->setValidator(validator);
                    ui->prix->setValidator(validator);
                    ui->etat->setValidator(validator);
                    ui->disponibilite->setValidator(validator);

        ui->tab_equipements->setModel(Etmp.afficher());





}
Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_4_clicked()
{

        QString nom_service=ui->nom_service->text();
         int nbre_materiel=ui->nbre_materiel->text().toInt();
         QString type=ui->type->text();
         srand(time(NULL));
             int a;
             a=rand()%999999 + 100000;
        services e(a,nom_service,nbre_materiel,type);
        bool test=e.ajouter();

        QMessageBox msgbox;

        if(!test)
          return  msgbox.setText("Ajout avec succes");
        else
           return msgbox.setText("Echec d ajout");
        msgbox.exec();
}

void Dialog::on_pushButton_5_clicked()
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

void Dialog::on_pushButton_6_clicked()
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

void Dialog::on_modifiereq_clicked()
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

void Dialog::on_modifierse_2_clicked()
{
    modifiers m;

        QMessageBox msg;
       m.setid_service(ui->combosermod->currentText().toInt());
       if(ui->combosermod->currentText().isEmpty())
          msg.setText("empty");

        else
        m.exec();
}

void Dialog::on_pushButton_clicked()
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

void Dialog::on_pushButton_3_clicked()
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

void Dialog::on_pushButton_2_clicked()
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


void Dialog::on_pushButton_7_clicked()
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



void Dialog::on_pushButton_9_clicked()
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

void Dialog::on_pushButton_8_clicked()
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
}
