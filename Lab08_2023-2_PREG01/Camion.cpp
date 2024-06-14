#include "Camion.hpp"

Camion::Camion() {
}

Camion::Camion(const class Camion&orig) {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}
void Camion::lee(ifstream&arch){
    Vehiculo::lee(arch);
    char extra;
    arch>>ejes>>extra;
    arch>>llantas>>ws;
}
void Camion::imprime(ofstream&arch){
    arch<<"Camion: "<<endl;
    Vehiculo::imprime(arch);
    arch<<"#Ejes "<<ejes<<endl;
    arch<<"#Llantas "<<llantas<<endl;
    Vehiculo::mostarPedidos(arch);
}