#include "principal.h"
#include "ui_principal.h"
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>

#include "calculosalario.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->actionCalcular, SIGNAL(triggered(bool)),
            this, SLOT(on_cmdCalcular_released()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::imprimir()
{
    //Obtener datos de la ui
    QString nombre=this->ui->inNombre->text();
    int horas=this->ui->inHoras->value();
    char jornada='m';
    if(this->ui->inMatutina->isChecked()){
        jornada='m';
    }else if(this->ui->inVespertina->isChecked()){
        jornada='v';
    }else{
        jornada='n';
    }
    //Crear objeto para calcular
    Calculosalario rolPago(nombre,horas,jornada);
    rolPago.calcular();

    QString nombres = ui->inNombre->text();
    QString hora = hora.number(horas);
    QString salario = salario.number(rolPago.salario());
    QString descuento = descuento.number(rolPago.descuento());
    QString salNeto = salNeto.number(rolPago.salarioNeto());
    QString Dato = "Trabajador: "+ nombre +"\n"
                    "Horas: "+ hora +"\n"
                    "Salatio: "+ salario +"$\n"
                    "Descuento(IVA): "+ descuento +"$\n"
                    "Salario neto: "+ salNeto +"$\n"
                    "**************************************\n";
    ui->outResultados->setPlainText(Dato);
}

void Principal::guardar()
{
    QString temportal=QDir::home().absolutePath()+"/sin_titulo.cfg";
    qDebug()<<temportal;
    QString nombreArchivo = QFileDialog::getSaveFileName(this, ("Guardar Configuracion "),
                                                      temportal,
                                                      ("Archivos de configuracion (*.cfg)"));
     QFile data(nombreArchivo);
     if (data.open(QFile::WriteOnly | QFile::Truncate)) {
      QTextStream out(&data);
      out<<ui->outResultados->toPlainText();
      qDebug() << "Archivo almacenado en:" << nombreArchivo;
      //Cerrando el archivo
      data.close();
     }

}

void Principal::abrir()
{

    QString temportal=QDir::home().absolutePath();
    qDebug()<<temportal;
    QString nombreArchivo = QFileDialog::getOpenFileName(this, ("Abrir Archivo"),
                                                      temportal,
                                                     ("Archivos de configuracion (*.cfg)"));
    QFile Archivo(nombreArchivo);
    if(!Archivo.open(QIODevice::ReadOnly| QIODevice::Text)){

        return;
     }
    QTextStream in(&Archivo);
    QString parrafo=in.readAll();
    ui->outResultados->setPlainText(parrafo);

}

void Principal::on_cmdCalcular_released()
{
    imprimir();
}

void Principal::on_actionGuardar_triggered()
{
    guardar();
    QMessageBox::information(this, tr("Aviso"),tr("Guardado Exitosamente"));
}

void Principal::on_actionAbrir_triggered()
{
    abrir();
}




