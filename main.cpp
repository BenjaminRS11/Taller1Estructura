#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Evento.h"
#include "Asistente.h"
#include "Concierto.h"
#include "Catedra.h"
#include "Estudiante.h"
#include "AsistenteConcierto.h"

using namespace std;

// Método para desplegar detalles de los asistentes
// Muestra la Edad Promedio
// Muestra la cantidad de asistentes por tipo de Asistente
void desplegarDetallesAsistentes(vector<Asistente*>& vectorAsistentes) {
    int sumadorEdades = 0;
    int contadorEstudiantes = 0;
    int contadorAsistenteConcierto = 0;
    for(Asistente* asistente : vectorAsistentes) {
        sumadorEdades += asistente->getEdad();
        if(asistente->getTipo() == "estudiante") {
            contadorEstudiantes += 1;
        } else if(asistente->getTipo() == "asistente de concierto") {
            contadorAsistenteConcierto += 1;
        }
    }
    cout<<"Edad Promedio: "<<sumadorEdades/vectorAsistentes.size()<<endl;
    cout<<"Cantidad de asistentes Estudiantes: "<<contadorEstudiantes<<endl;
    cout<<"Cantidad de asistentes de Concierto: "<<contadorAsistenteConcierto<<endl;
}

// Método para desplegar estadísticas de asistencia
// Muestra el número total de asistentes
// Calcula y muestra la asistencia promedio por tipo de evento
void desplegarEstadisticasAsistencia(vector<Evento*>& vectorEventos, vector<Asistente*>& vectorAsistentes) {
    cout<<"Número total de asistentes (en base de datos, con o sin asociar): "<<vectorAsistentes.size()<<endl;
    cout<<"Asistencia promedio por tipo de evento:"<<endl;

    int sumadorAsistConcierto = 0;
    int sumadorAsistCatedra = 0;
    int contadorEventosConcierto = 0;
    int contadorEventosCatedra = 0;
    for(Evento* evento: vectorEventos) {
        if(evento->getTipo() == "Concierto") {
            int asistencia = evento->getAsistencia();
            sumadorAsistConcierto += asistencia;
            contadorEventosConcierto++;
        } else if(evento->getTipo() == "Cátedra") {
            int asistencia = evento->getAsistencia();
            sumadorAsistCatedra += asistencia;
            contadorEventosCatedra++;
        }
    }
    int AsistPromedioConcierto = sumadorAsistConcierto/contadorEventosConcierto;
    int AsistPromedioCatedra = sumadorAsistCatedra/contadorEventosCatedra;
    cout<<"Concierto: "<<AsistPromedioConcierto<<endl;
    cout<<"Catedra: "<<AsistPromedioCatedra<<endl;
}

// Método para desplegar la lista de asistentes por cada evento
// Itera sobre cada evento en el vector de eventos
// y despliega la lista de asistentes de cada evento
void desplegarListaAsistentesPorEvento(vector<Evento*>& vectorEventos) {
    for (Evento* evento : vectorEventos) {
        evento->desplegarListaAsistentes();
    }
}

// Método para desplegar la lista general de eventos
// Imprime un encabezado para la lista de eventos
// Itera sobre cada evento en el vector de eventos
// e imprime el tipo de cada evento
void desplegarListaEventos(vector<Evento*>& vectorEventos) {
    cout<<"LISTA GENERAL DE EVENTOS:\n"<<endl;
    for (Evento* evento : vectorEventos) {
        evento->imprimirTipo();
    }
}

// Método para desplegar las opciones de informes y procesar la selección del usuario
// Cada opción del switch llama a una función correspondiente para desplegar la información requerida
void desplegarOpcionesInformes(vector<Evento*>& vectorEventos, vector<Asistente*>& vectorAsistentes) {
    int opcion = 0;
    do {
        cout<<"    1. Lista de eventos programados\n"<<endl;
        cout<<"    2. Lista de asistentes registrados para cada evento\n"<<endl;
        cout<<"    3. Números sobre la asistencia a los eventos\n"<<endl;
        cout<<"    4. Detalles sobre los asistentes\n"<<endl;
        cout<<"    5. Volver atrás"<<endl;
        cout<<"Seleccione una opción: "<<endl;
        cin>>opcion;
        switch(opcion) {
            case 1:
                desplegarListaEventos(vectorEventos);        
                break;
            case 2:
                desplegarListaAsistentesPorEvento(vectorEventos);
                break;
            case 3:
                desplegarEstadisticasAsistencia(vectorEventos,vectorAsistentes);
                break;
            case 4:
                desplegarDetallesAsistentes(vectorAsistentes);
                break;
            case 5:
                cout<<"Volviendo..."<<endl;  
                break;
            default:
                cout<<"Opción incorrecta, por favor ingrese una opción válida"<<"\n"<<endl;
                cin.clear();
                cin.ignore();
        }
    } while(opcion != 5);
}

// Método para liberar la memoria de los vectores de eventos y asistentes
// Limpia el vector de eventos y de asistentes
void liberarMemoria(vector<Evento*>& vectorEventos, vector<Asistente*>& vectorAsistentes) {
    for (Evento* evento : vectorEventos) {
        delete evento;
    }
    vectorEventos.clear();

    for (Asistente* asistente : vectorAsistentes) {
        delete asistente;
    }
    vectorAsistentes.clear();
}

// Función para dividir una cadena utilizando un delimitador especificado
vector<string> split(const string& str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

// Función para verificar y eliminar eventos duplicados en el vector de eventos
// Si se encuentra un evento duplicado, se elimina y se libera la memoria
void verificarDatosUnicosRepetidos(vector<Evento*>& vectorEventos, vector<Asistente*>& vectorAsistentes) {
    // Eliminar eventos duplicados
    auto itEvento = vectorEventos.begin();
    while (itEvento != vectorEventos.end()) {
        auto itNext = itEvento;
        ++itNext;
        while (itNext != vectorEventos.end()) {
            if ((*itEvento)->getCodigoEvento() == (*itNext)->getCodigoEvento()) {
                delete *itNext;
                itNext = vectorEventos.erase(itNext);
            } else {
                ++itNext;
            }
        }
        ++itEvento;
    }

    // Eliminar asistentes duplicados
    auto itAsistente = vectorAsistentes.begin();
    while (itAsistente != vectorAsistentes.end()) {
        auto itNext = itAsistente;
        ++itNext;
        while (itNext != vectorAsistentes.end()) {
            if ((*itAsistente)->getRut() == (*itNext)->getRut()) {
                delete *itNext;
                itNext = vectorAsistentes.erase(itNext);
            } else {
                ++itNext;
            }
        }
        ++itAsistente;
    }
}

// Función para actualizar los datos de la sesión a un archivo de texto
void actualizarDatosTxt(vector<Evento*>& vectorEventos, vector<Asistente*>& vectorAsistentes) {
    string linea;
    string texto;
    string nuevaLineaEventos;
    string nuevaLineaAsistentes;

    ofstream archivo2("datos.txt");
    for (Evento* evento : vectorEventos)
    {
        nuevaLineaEventos = evento->devolverInfoEventoFormatoTxt();
        archivo2<<nuevaLineaEventos<<"\n";
    }
    for (Asistente* asistente : vectorAsistentes)
    {
        nuevaLineaAsistentes = asistente->devolverInfoAsistenteFormatoTxt();
        archivo2<<nuevaLineaAsistentes<<"\n";
    }
}

// Función para leer datos desde un archivo de texto y cargarlos en los vectores de eventos y asistentes
void leerDatosTxt(vector<Evento*>& vectorEventos, vector<Asistente*>& vectorAsistentes) {
    string linea;
    ifstream archivo("datos.txt");
    char delimitador = ',';
    while(getline(archivo,linea)) { 
         vector<string> partes = split(linea, delimitador); 
         string tipo = partes[0];

         if(tipo == "Concierto") {
            string ubicacion = partes[1];
            string tema = partes[2];
            int duracion = stoi(partes[3]);
            int codigoEvento = stoi(partes[4]);
            string generoMusical = partes[5];
            string artista = partes[6];
            Evento* evento = new Concierto(tipo,ubicacion,tema,duracion,codigoEvento,generoMusical,artista);
            vectorEventos.push_back(evento);
        } else if(tipo == "Cátedra") {
            string ubicacion = partes[1];
            string tema = partes[2];
            int duracion = stoi(partes[3]);
            int codigoEvento = stoi(partes[4]);
            string docente = partes[5];
            Evento* evento = new Catedra(tipo,ubicacion,tema,duracion,codigoEvento,docente);
            vectorEventos.push_back(evento);
        } else if(tipo == "estudiante") {
            string nombre = partes[1];
            string rut = partes[2];
            int edad = stoi(partes[3]);
            string ocupacion = partes[4];
            int semestre = stoi(partes[5]);
            string carrera = partes[6];
            Asistente* asistente = new Estudiante(tipo,nombre,rut,edad,ocupacion,semestre,carrera);
            vectorAsistentes.push_back(asistente);
        } else if(tipo == "asistente de concierto") {
            string nombre = partes[1];
            string rut = partes[2];
            int edad = stoi(partes[3]);
            string ocupacion = partes[4];
            string tipoEntrada = partes[5];
            Asistente* asistente = new AsistenteConcierto(tipo,nombre,rut,edad,ocupacion,tipoEntrada);
            vectorAsistentes.push_back(asistente);
        }
    }
    archivo.close();
}

// Función para cargar eventos predefinidos en el vector de eventos
void cargarEventos(vector<Evento*>& vectorEventos) {    
    vectorEventos.push_back(new Concierto("Concierto","Estadio Sanchez Rumuroso","Entretenimiento",90,3245,"Rock","Queen"));
    vectorEventos.push_back(new Concierto("Concierto","Teatro Caupolicán","Entretenimiento",90,3244,"Rock","Guns N' Roses"));
    vectorEventos.push_back(new Concierto("Concierto","Estadio Santa Laura","Entretenimiento",80,2145,"Rock","Nirvana"));
    vectorEventos.push_back(new Concierto("Concierto","Estadio Monumental","Entretenimiento",90,5335,"Rock","Iron Maiden"));
    vectorEventos.push_back(new Concierto("Concierto","Estadio San Carlos de Apoquindo","Entretenimiento",100,1145,"Rock","Metallica"));
    vectorEventos.push_back(new Concierto("Concierto","Estadio Bicentenario de la Florida","Entretenimiento",70,3111,"Pop","Bruno Mars"));
    vectorEventos.push_back(new Concierto("Concierto","Movistar Arena","Entretenimiento",60,7772,"Urbano Latino","Arcángel"));
    vectorEventos.push_back(new Concierto("Concierto","Estadio Ester Roa Rebolledo","Entretenimiento",60,4445,"Urbano Latino","Ozuna"));
    vectorEventos.push_back(new Catedra("Cátedra","UCN G6-54","Educación",80,1113,"Jorge Soto"));
    vectorEventos.push_back(new Catedra("Cátedra","UCN G6-47","Educación",80,1213,"Pedro Fuentes"));
    vectorEventos.push_back(new Catedra("Cátedra","UCN G1-06","Educación",80,1413,"Sergio González"));
    vectorEventos.push_back(new Catedra("Cátedra","UCN X1-030","Educación",80,5113,"Juan Véliz"));
    vectorEventos.push_back(new Catedra("Cátedra","UCN X1-029","Educación",80,1613,"Vicente Sepúlveda"));
    vectorEventos.push_back(new Catedra("Cátedra","UCN G4-21","Educación",80,1883,"Benjamín Rojas"));
    vectorEventos.push_back(new Catedra("Cátedra","UCN G4-23","Educación",80,1173,"Sebastián Echeverría"));
    vectorEventos.push_back(new Catedra("Cátedra","UCN G4-17","Educación",80,1693,"Gonzalo Pérez"));
}

// Función para cargar eventos predefinidos en el vector de asistentes
void cargarAsistentes(vector<Asistente*>& vectorAsistentes) {
    vectorAsistentes.push_back(new Estudiante("estudiante","Pepe","21.333.434-3",20,"Estudiante",4,"ICCI"));
    vectorAsistentes.push_back(new Estudiante("estudiante","Sebastián","21.133.134-3",20,"Estudiante",4,"ICCI"));
    vectorAsistentes.push_back(new Estudiante("estudiante","Juan","21.323.232-2",19,"Estudiante",4,"ITI"));
    vectorAsistentes.push_back(new Estudiante("estudiante","Javier","21.366.634-9",20,"Estudiante",4,"ITI"));
    vectorAsistentes.push_back(new Estudiante("estudiante","Cristofer","21.776.779-0",19,"Estudiante",4,"ICI"));
    vectorAsistentes.push_back(new Estudiante("estudiante","Pablo","21.655.433-1",20,"Estudiante",4,"ICI"));
    vectorAsistentes.push_back(new AsistenteConcierto("asistente de concierto","Sergio","20.333.333-3",21,"n/a","VIP"));
    vectorAsistentes.push_back(new AsistenteConcierto("asistente de concierto","Benjamín","21.233.222-3",21,"Emprendedor","Normal"));
    vectorAsistentes.push_back(new AsistenteConcierto("asistente de concierto","Vicente","20.663.797-4",21,"Emprendedor","Normal"));
    vectorAsistentes.push_back(new AsistenteConcierto("asistente de concierto","David","20.323.323-7",21,"Jugador de Fútbol","VIP"));
    vectorAsistentes.push_back(new AsistenteConcierto("asistente de concierto","Jeremy","21.878.293-1",21,"Emprendedor","VIP"));
    vectorAsistentes.push_back(new AsistenteConcierto("asistente de concierto","Pedro","21.878.293-1",21,"Emprendedor","VIP"));
    vectorAsistentes.push_back(new AsistenteConcierto("asistente de concierto","Jer","21.878.293-1",21,"Panadero","Normal"));
}

// Función para buscar un evento por su código en el vector de eventos
Evento* buscarEvento(int inputCodigoEvento, vector<Evento*>& vectorEventos) {
    for (Evento* e : vectorEventos){
        if(e->getCodigoEvento() == inputCodigoEvento) {
            return e;
        }
    }  
    return nullptr; 
}

// Permite registrar un nuevo asistente y asociarlo a un evento existente. El usuario proporciona la información del asistente
// incluyendo el tipo y los detalles personales, así como el código del evento al que se asociará.
void registrarAsistente(vector<Asistente*>& vectorAsistentes, vector<Evento*>& vectorEventos) {
     int inputTipo, inputEdad, inputCodigoEvento;
     string inputNombre, inputRut, inputOcupacion;
     cout<<"\nIngrese tipo de asistente: \n1) Estudiante\n2) Asistente de Concierto\nSelecciona una opción:"<<endl;
     cin>>inputTipo;
     cout<<"\n--- EVENTOS DISPONIBLES ---"<<endl;

     for (Evento* evento : vectorEventos)
     {
        cout<<"Tipo evento: "<<evento->getTipo()<<" ; Tema: "<<evento->getTema()<<" ; Código: "<<evento->getCodigoEvento()<<" ; Ubicación: "<<evento->getUbicacion()<<endl;
     }

     cout<<"\nIngrese código de evento para asociar el asistente: "<<endl;
     cin>>inputCodigoEvento;
     Evento* e = buscarEvento(inputCodigoEvento, vectorEventos);

     if(e != nullptr) {
        if(inputTipo == 1) {
                cout<<"Ingrese nombre: "<<endl;
                cin.ignore();
                getline(cin, inputNombre);
                cout<<"Ingrese rut (con puntos y guión): "<<endl;
                getline(cin,inputRut);
                cout<<"Ingrese edad: "<<endl;
                cin>>inputEdad;
                int inputSemestre;
                string inputCarrera;
                cout<<"Ingrese semestre (numérico): "<<endl;
                cin>>inputSemestre;
                cout<<"Ingrese carrera: "<<endl;
                cin.ignore(); 
                getline(cin, inputCarrera);
                cout<<"\n"<<endl;
                Asistente* asistente = new Estudiante("estudiante",inputNombre,inputRut,inputEdad,"Estudiante",inputSemestre,inputCarrera);
                vectorAsistentes.push_back(asistente);
                e->asociarAsistente(asistente);
            } else if (inputTipo == 2) {
                cout<<"Ingrese nombre: "<<endl;
                cin.ignore();
                getline(cin, inputNombre);
                cout<<"Ingrese rut (con puntos y guión): "<<endl;
                getline(cin,inputRut);
                cout<<"Ingrese edad: "<<endl;
                cin>>inputEdad;
                cout<<"Ingrese ocupación: "<<endl;
                cin.ignore();
                getline(cin, inputOcupacion);
                string inputTipoEntrada;
                cout<<"Ingrese tipo de entrada (VIP o normal): "<<endl;
                cin>>inputTipoEntrada;
                cout<<"\n"<<endl;
                Asistente* asistente = new AsistenteConcierto("asistente de concierto",inputNombre,inputRut,inputEdad,inputOcupacion,inputTipoEntrada);
                vectorAsistentes.push_back(asistente);
                e->asociarAsistente(asistente);
            }
     } else {
        cout<<"Código de evento no válido\n"<<endl;
     }
 }

// Función para desplegar una lista de todos los asistentes registrados
void desplegarListaAsistentes(vector<Asistente*>& vectorAsistentes) {
    cout<<"LISTA GENERAL DE ASISTENTES:\n"<<endl;
    for(Asistente* asistente : vectorAsistentes) {
        asistente->imprimirTipo();
    }
}

// Genera un código aleatorio para un evento
int generarCodigoEventoAleatorio() {
    int valorRandom = 0;
    valorRandom = 1000 + rand() % 8999;
    return valorRandom;
}

// Permite al usuario agregar un nuevo evento al sistema, eligiendo entre dos tipos: Concierto o Cátedra. Para evitar duplicados
// se genera un código de evento aleatorio único. Luego, se solicitan los detalles específicos del evento
void tipoEvento(vector<Evento*>& vectorEventos, vector<int> codigosEventos) {
    int inputTipo;
    cout<<"\nIngrese tipo de evento: \n1) Concierto\n2) Cátedra\nSelecciona una opción:"<<endl;
    cin>>inputTipo;
    if(inputTipo == 1) {
        string inputUbicacion, inputTema;
        int inputDuracion;
        bool esCodigoRepetido = false;
        int codigoEventoAleatorio = generarCodigoEventoAleatorio();
        do{
            esCodigoRepetido = false;
            if(codigosEventos.empty()){
                codigosEventos.push_back(codigoEventoAleatorio);
            } 
            else {
                for (int i = 0; i < codigosEventos.size() ; i++) {
                    if(codigosEventos[i] == codigoEventoAleatorio) {
                        esCodigoRepetido = true;
                        codigoEventoAleatorio = generarCodigoEventoAleatorio();
                        break;
                    }
                }
            }
        } while(esCodigoRepetido == true);

        cout<<"Ingrese ubicación: "<<endl;
        cin.ignore();
        getline(cin, inputUbicacion);
        cout<<"Ingrese tema: "<<endl;
        getline(cin, inputTema);
        cout<<"Ingrese duración (minutos): "<<endl;
        cin>>inputDuracion;
        string inputGeneroMusical, inputArtista;
        cout<<"Ingrese género musical: "<<endl;
        cin.ignore();
        getline(cin, inputGeneroMusical);
        cout<<"Ingrese artista: "<<endl;
        getline(cin, inputArtista);
        Evento* evento = new Concierto("Concierto",inputUbicacion,inputTema,inputDuracion,codigoEventoAleatorio,inputGeneroMusical,inputArtista);
        vectorEventos.push_back(evento);
    }
    else if(inputTipo == 2) {
        string inputUbicacion, inputTema;
        int inputDuracion;
        int codigoEventoAleatorio = generarCodigoEventoAleatorio();

        cout<<"Ingrese ubicación: "<<endl;
        cin.ignore();
        getline(cin, inputUbicacion);
        cout<<"Ingrese tema: "<<endl;
        getline(cin, inputTema);
        cout<<"Ingrese duración (minutos): "<<endl;
        cin>>inputDuracion;
        string inputDocente, inputCapacidadSala;
        cout<<"Ingrese docente: "<<endl;
        cin.ignore();
        getline(cin, inputDocente);
        cout<<"Ingrese capacidad de sala: "<<endl;
        getline(cin, inputCapacidadSala);
        Evento* evento = new Catedra("Cátedra",inputUbicacion,inputTema,inputDuracion,codigoEventoAleatorio,inputDocente);
        vectorEventos.push_back(evento);
    }
}

// Menú para que el usuario pueda interactuar con las opciones principales del programa
void menu(vector<Evento*>& vectorEventos, vector<Asistente*>& vectorAsistentes, vector<int> codigosEventos) {      
    int opcion = 0;
    cout<<"--- Bienvenido/a al Menú ---"<<endl;
    do {
        cout<<"1. Crear evento"<<endl;
        cout<<"2. Registrar asistente"<<endl;
        cout<<"3. Consultar lista de asistentes"<<endl;
        cout<<"4. Generar informes"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Seleccione una opción: "<<endl;
        cin>>opcion;
        switch(opcion) {
            case 1:
                tipoEvento(vectorEventos,codigosEventos);          
                break;
            case 2:
                registrarAsistente(vectorAsistentes, vectorEventos);
                break;
            case 3:
                desplegarListaAsistentes(vectorAsistentes);
                break;
            case 4:
                desplegarOpcionesInformes(vectorEventos,vectorAsistentes);
                break;
            case 5:
                cout<<"Saliendo..."<<endl;
                break;
            default:
                cout<<"Opción incorrecta, por favor ingrese una opción válida"<<"\n"<<endl;
                cin.clear();
                cin.ignore();
        }
    } while(opcion != 5);    
}


int main() {
    vector<Evento*> vectorEventos;
    vector<Asistente*> vectorAsistentes;
    vector<int> codigosEventos;
    leerDatosTxt(vectorEventos,vectorAsistentes);
    cargarEventos(vectorEventos);
    cargarAsistentes(vectorAsistentes);
    verificarDatosUnicosRepetidos(vectorEventos,vectorAsistentes);
    menu(vectorEventos, vectorAsistentes,codigosEventos);
    actualizarDatosTxt(vectorEventos,vectorAsistentes);
    liberarMemoria(vectorEventos,vectorAsistentes);
    return 0;
}   