#include "Vehiculo.hpp"

Vehiculo::Vehiculo() {
    placa=nullptr;
    ped=nullptr;
    actcarga=0;
}

Vehiculo::Vehiculo(const class Vehiculo&orig) {
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(const char* placa) {
    if(this->placa != nullptr) delete this->placa;
    this->placa=new char [strlen(placa)+1];
    strcpy(this->placa,placa);
}

void Vehiculo::GetPlaca(char* placa) const {
    if(this->placa == nullptr) placa[0]=0;
    else{
        strcpy(placa,this->placa);
    }
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream&arch){
    char buffer_placa[10],extra;
    arch>>cliente>>extra;
    arch.getline(buffer_placa,10,',');
    SetPlaca(buffer_placa);
    arch>>maxcarga>>extra;
}    
void Vehiculo::imprime(ofstream&arch){
    char placa[30];
    GetPlaca(placa);
    arch<<"Codigo Cliente: "<<cliente<<endl;
    arch<<"Placa: "<<placa<<endl;
    arch<<"Carga Maxima: "<<maxcarga<<endl;
    arch<<"Carga Actual: "<<actcarga<<endl;
}

void Vehiculo::mostarPedidos(ofstream&arch){
    if(ped==nullptr){
        arch<<"No hay pedidos para el Cliente"<<endl;
    }else{
    //impimir pedidos;
    }

}