#pragma once
#include "Evento.h"
#include <iostream>

using namespace std;

class Catedra : public Evento {
    private:
        string docente;
    public:
        Catedra(string, string, string, int, int, string);
        string getDocente();
        string devolverInfoEventoFormatoTxt();
        void imprimirTipo();
};