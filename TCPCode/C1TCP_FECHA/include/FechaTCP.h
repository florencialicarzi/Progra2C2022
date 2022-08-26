#ifndef FECHATCP_H
#define FECHATCP_H


class FechaTCP
{
    private:
            int diaRelativo;
            int calcDiaRelativo(int dia, int mes, int anio);
            int validarFecha();

    public:
            FechaTCP();
            Fecha sumarDias();
            Fecha restarDias();
            int diferenciaDias();
            int diaSemana();
}

#endif // FECHATCP_H
