#include "Furgon.hpp"

Furgon::Furgon() {
    filas=0;
    puertas=0;
}

Furgon::Furgon(const class Furgon&orig) {
}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::lee(ifstream&arch) {
    Vehiculo::lee(arch);
    char extra;
    arch >> filas>>extra;
    arch >> puertas>>ws;
}

void Furgon::imprime(ofstream&arch) {
    arch <<"Furgon: " << endl;
    Vehiculo::imprime(arch);
    arch <<setw(20)<<left<<  "#Filas: " << filas << endl;
    arch <<setw(20)<<left<<  "#Puertas: " << puertas << endl;
    arch <<setw(20)<<left<<  "Pedidos :"<< endl;
    escribeLinea(arch,36,'-');
    Vehiculo::mostarPedidos(arch);
    escribeLinea(arch,36,'=');


}