#include "Catedra.h"

Catedra::Catedra(string tipo, string ubicacion, string tema, int duracion, int codigoEvento, string docente) 
    : Evento(tipo, ubicacion, tema, duracion, codigoEvento) {
    this-> docente = docente;
}

string Catedra::getDocente() {
    return this-> docente;
}

string Catedra::devolverInfoEventoFormatoTxt() {
    string linea;
    string duracionStr = to_string(this->getDuracion());
    string codigoEventoStr = to_string(this->getCodigoEvento());
    linea += this->getTipo()+","+this->getUbicacion()+","+this->getTema()+","+duracionStr+","+codigoEventoStr+","+this->getDocente();
    return linea;
}

void Catedra::imprimirTipo() {
    cout<<"TIPO: "<<this->getTipo()<<" ; UBICACIÓN: "<<this->getUbicacion()<<" ; TEMA: "<<this->getTema()<<" ; DURACIÓN: "<<this->getDuracion()<<
    " ; CODIGO EVENTO: "<<this->getCodigoEvento()<<" ; DOCENTE: "<<this->getDocente()<<endl;
}

void Catedra::desplegarListaAsistentes() {
    for (Asistente* asistente : this->asistentes)
    {   
        cout<<"EVENTO "<<this->getUbicacion()<<" ; Código: "<<this->getCodigoEvento()<<"\n    NOMBRE: "<<asistente->getNombre()<<" ; RUT: "<<asistente->getRut()<<
        " ; EDAD: "<<asistente->getEdad()<<" ; OCUPACIÓN: "<<asistente->getOcupacion()<<endl;
    }
}
