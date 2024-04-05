#pragma once
#include "Evento.h"
#include <iostream>

using namespace std;

class Concierto : public Evento {
    private:
        string generoMusical;
        string artista;
    public:
        Concierto(string, string, string, int, int, string, string);
        string getGeneroMusical();
        string getArtista();
        string devolverInfoEventoFormatoTxt();
        void imprimirTipo();
};