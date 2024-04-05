#pragma once
#include <iostream>
#include "Asistente.h"

using namespace std;

class AsistenteConcierto : public Asistente {
    private:
        string tipoEntrada;
    public:
        AsistenteConcierto(string, string, string, int, string, string);
        string getTipoEntrada();
        void imprimirTipo();
        string devolverInfoAsistenteFormatoTxt();
};