#include "LVehiculos.hpp"
#include "Camion.hpp"
#include "Furgon.hpp"
LVehiculos::LVehiculos() {
    lini = nullptr;
    lfin = nullptr;
}

LVehiculos::LVehiculos(const class LVehiculos&orig) {

}

LVehiculos::~LVehiculos() {
}

void LVehiculos::leer_inserta(char tipo, ifstream &arch) {
    Vehiculo *nuevo;
    if(tipo=='F'){
        nuevo=new class Furgon;
    }
    else if(tipo=='C'){
        nuevo=new class Camion;
    }
    nuevo->lee(arch);
    insertar(nuevo);
}
void LVehiculos::insertar(Vehiculo *nuevo) {
    NodoLista *nuevoNodo;
    nuevoNodo = new NodoLista;
    nuevoNodo->unidad=nuevo;
    if (lini == nullptr) {
        lini = nuevoNodo;
        lfin = nuevoNodo;
    } else {
        lfin->sig = nuevoNodo;
        lfin = nuevoNodo;
    }
}

void LVehiculos::mostrarLista(ofstream&arch){
    NodoLista *rec;
    rec=lini;
    while (rec!=nullptr) {
        rec->unidad->imprime(arch);
        rec=rec->sig;
    }


}



