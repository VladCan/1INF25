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
    ifstream archP("Pedidos3.csv",ios::in);
    if(!archP.is_open()){
        cout<<"Error al abrir Vehiculos.csv"<<endl;
        exit(1);
    }
    int codCliente;
    char extra;
    while(true){
        archP>>codCliente>>extra;
        if(archP.eof()) break;
        lista.buscarClienteYagregarPedido(codCliente,archP);
    }
}

void Flota::muestracarga() {
    ofstream arch("Reporte Vehiculos.txt",ios::out);
    if(!arch.is_open()){
        cout<<"Error al abrir Vehiculos.txt"<<endl;
        exit(1);
    }
    arch<<setw(25)<<"Reporte Flota"<<endl;
    escribeLinea(arch,36,'=');
    lista.mostrarLista(arch);
}
void Flota::escribeLinea(ofstream&arch, int n, char c){
    for(int i=0;i<n;i++)
        arch<<c;
    arch<<endl;
}