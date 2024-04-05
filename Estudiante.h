#pragma once
#include <iostream>
#include "Asistente.h"

using namespace std;

class Estudiante : public Asistente {
    private:
        int semestre;
        string carrera;
    public:
        Estudiante(string, string, string, int, string, int, string);
        int getSemestre();
        string getCarrera();
        void imprimirTipo();
        string devolverInfoAsistenteFormatoTxt();
};