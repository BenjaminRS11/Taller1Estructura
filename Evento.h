#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "Asistente.h"

using namespace std;

class Evento {
    protected:
        string tipo;
        string ubicacion;
        string tema;
        int duracion;
        int codigoEvento;
        vector<Asistente*> asistentes; 

    public:
        Evento(string, string, string, int, int);
        ~Evento();
        string getTipo();
        string getUbicacion();
        string getTema();
        int getDuracion();
        int getCodigoEvento();
        int generarCodigoEventoAleatorio();
        void asociarAsistente(Asistente*);
        virtual string devolverInfoEventoFormatoTxt();
        virtual void imprimirTipo();
        void desplegarListaAsistentes();
        int getAsistencia();
};