#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
    void imprimir();
    void guardar();
    void abrir();



private slots:
    void on_cmdCalcular_released();

    void on_actionGuardar_triggered();
    void on_actionAbrir_triggered();



private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
