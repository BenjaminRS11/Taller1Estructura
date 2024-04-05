#include "Asistente.h"

Asistente::Asistente(string tipo, string nombre, string rut, int edad, string ocupacion) {
    this-> tipo = tipo;
    this-> nombre = nombre;
    this-> rut = rut;
    this-> edad = edad;
    this-> ocupacion = ocupacion;
}

//Asistente::~Asistente(){}

string Asistente::getTipo() {
    return this-> tipo;
}
string Asistente::getNombre() {
    return this-> nombre;
}
string Asistente::getRut() {
    return this-> rut;
}
int Asistente::getEdad() {
    return this-> edad;
}
string Asistente::getOcupacion() {
    return this-> ocupacion;
}
void Asistente::imprimirTipo(){}

string Asistente::devolverInfoAsistenteFormatoTxt() { string vacio; return vacio;}