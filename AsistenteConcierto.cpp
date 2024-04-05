#include "AsistenteConcierto.h"

AsistenteConcierto::AsistenteConcierto(string tipo, string nombre, string rut, int edad, string ocupacion, string tipoEntrada) 
    : Asistente(tipo, nombre, rut, edad, ocupacion) {
    this-> tipoEntrada = tipoEntrada;
}

string AsistenteConcierto::getTipoEntrada() {
    return this-> tipoEntrada;
}
void AsistenteConcierto::imprimirTipo() {
    cout<<"NOMBRE: "<<this->getNombre()<<" ; RUT: "<<this->getRut()<<" ; EDAD: "<<this->getEdad()<<" ; OCUPACIÓN: "<<this->getOcupacion()<<
    " ; TIPO ENTRADA: "<<this->getTipoEntrada()<<endl;
}
string AsistenteConcierto::devolverInfoAsistenteFormatoTxt() {
    string linea;
    string edadStr = to_string(this->getEdad());
    linea += this->getTipo()+","+this->getNombre()+","+this->getRut()+","+edadStr+","+this->getOcupacion()+","+this->getTipoEntrada();
    return linea;
}