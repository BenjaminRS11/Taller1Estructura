#pragma once
#include <iostream>

using namespace std;

class Asistente {
    private:
        string tipo;
        string nombre;
        string rut;
        int edad;
        string ocupacion;
    public:
        Asistente(string, string, string, int, string);
        string getTipo();
        string getNombre();
        string getRut();
        int getEdad();
        string getOcupacion();
        virtual void imprimirTipo();
        virtual string devolverInfoAsistenteFormatoTxt();
};