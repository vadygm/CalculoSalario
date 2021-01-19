#include "calculosalario.h"

float Calculosalario::descuento() const
{
    return m_descuento;
}

float Calculosalario::salarioNeto() const
{
    return m_salarioNeto;
}

float Calculosalario::salario() const
{
    return m_salario;
}

Calculosalario::Calculosalario(QObject *parent) : QObject(parent)
{

}

Calculosalario::Calculosalario(QString nombre, int horas, char jornada):QObject(nullptr)
{
    this->m_nombre=nombre;
    this->m_horas=horas;
    this->m_jornada=jornada;
}

void Calculosalario::calcular()
{
            float valorHora=0;
            switch (this->m_jornada) {
            case 'v':
                valorHora=VALOR_HORA_VESPERTINO;
            break;
            case 'm':
                valorHora=VALOR_HORA_MATUTINO;
            break;
            case 'n':
                valorHora=VALOR_HORA_NOCTURNO;
            break;
            default:
            break;
}
            m_salario       = m_horas * valorHora;
            m_descuento     = m_salario * PORCENTAJE_DECUENTO /100;
            m_salarioNeto   = m_salario - m_descuento;
}
