#include "Flota.hpp"

Flota::Flota() {

}

Flota::Flota(const class Flota&) {
}

Flota::~Flota() {
}

void Flota::cargaflota() {
    ifstream arch("Vehiculos.csv",ios::in);
    if(!arch.is_open()){
        cout<<"Error al abrir Vehiculos.csv"<<endl;
        exit(1);
    }
    char tipo,extra;
    while(true){
        arch>>tipo>>extra;
        lista.leer_inserta(tipo,arch);
        if(arch.eof()) break; 
    }
}

void Flota::cargapedidos() {
}

void Flota::muestracarga() {
    ofstream arch("Reporte Vehiculos.txt",ios::out);
    if(!arch.is_open()){
        cout<<"Error al abrir Vehiculos.txt"<<endl;
        exit(1);
    }
    arch<<setw(40)<<"Reporte Flota"<<endl;
    arch<<"==========================================="<<endl;
    lista.mostrarLista(arch);
}