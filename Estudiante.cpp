#include "Estudiante.h"

Estudiante::Estudiante(string tipo, string nombre, string rut, int edad, string ocupacion, int semestre, string carrera) 
    : Asistente(tipo, nombre, rut, edad, ocupacion) {
    this-> semestre = semestre;
    this-> carrera = carrera;
}

int Estudiante::getSemestre() {
    return this-> semestre;
}
string Estudiante::getCarrera() {
    return this-> carrera;
}
void Estudiante::imprimirTipo() {
    cout<<"NOMBRE: "<<this->getNombre()<<" ; RUT: "<<this->getRut()<<" ; EDAD: "<<
    this->getEdad()<<" ; OCUPACIÓN: "<<this->getOcupacion()<<" ; SEMESTRE: "<<this->getSemestre()<<" ; CARRERA: "<<this->getCarrera()<<endl;
}
string Estudiante::devolverInfoAsistenteFormatoTxt() {
    string linea;
    string edadStr = to_string(this->getEdad());
    string semestreStr = to_string(this->getSemestre());
    linea += this->getTipo()+","+this->getNombre()+","+this->getRut()+","+edadStr+","+this->getOcupacion()+","+semestreStr+","+this->getCarrera();
    return linea;
}