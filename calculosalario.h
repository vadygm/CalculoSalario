#ifndef CALCULOSALARIO_H
#define CALCULOSALARIO_H

#include <QObject>

class Calculosalario : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float salario READ salario)
    Q_PROPERTY(float descuento READ descuento)
    Q_PROPERTY(float salarioNeto READ salarioNeto)
private:
    /*VARIABLE MIEMBRO*/
    int m_horas;                //Numero de horas trabajadas
    QString m_nombre;           //Nombre del trabajador
    char m_jornada;             //Jornadas de trabajo(V=vespertina, m=matutina, n=nocturna)
    float m_salario;            //Valor calculado del salario
    float m_descuento;          //Valor del descuento
    float m_salarioNeto;        //Valor salario neto
    /*CONSTANTES*/
    float const VALOR_HORA_MATUTINO     =5.15;
    float const VALOR_HORA_VESPERTINO   =8.50;
    float const VALOR_HORA_NOCTURNO     =12.65;
    float const PORCENTAJE_DECUENTO     =9.5;
public:
    explicit Calculosalario(QObject *parent = nullptr);
    Calculosalario(QString nombre,int horas, char jornada);

    void calcular();
    float descuento() const;
    float salarioNeto() const;
    float salario() const;

signals:

};

#endif // CALCULOSALARIO_H
