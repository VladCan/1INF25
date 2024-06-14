#include "Furgon.hpp"

Furgon::Furgon() {
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
    arch << "Furgon: " << endl;
    Vehiculo::imprime(arch);
    arch << "#Filas: " << filas << endl;
    arch << "#Puertas: " << puertas << endl;
    arch<<"--------------------------------"<<endl;
    Vehiculo::mostarPedidos(arch);
    arch<<"================================="<<endl;


}