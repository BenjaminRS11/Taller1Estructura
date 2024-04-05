#include "Evento.h"


Evento::Evento(string tipo, string ubicacion, string tema, int duracion, int codigoEvento) {
    this-> tipo = tipo;
    this-> ubicacion = ubicacion;
    this-> tema = tema;
    this-> duracion = duracion;
    this-> codigoEvento = codigoEvento;
}

Evento::~Evento(){} // destructor


string Evento::getTipo() {
    return this-> tipo;
}
string Evento::getUbicacion() {
    return this-> ubicacion;
}
string Evento::getTema() {
    return this-> tema;
}
int Evento::getDuracion() {
    return this-> duracion;
}
int Evento::getCodigoEvento() {
    return this-> codigoEvento;
}
void Evento::asociarAsistente(Asistente* asistente) {
    this->asistentes.push_back(asistente);
}
string Evento::devolverInfoEventoFormatoTxt() { string vacio; return vacio;}

void Evento::imprimirTipo(){}

void Evento::desplegarListaAsistentes() {
}

int Evento::getAsistencia() {
    int numero = this->asistentes.size();
    return numero;
}