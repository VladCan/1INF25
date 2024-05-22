#include "Pedido.hpp"

Pedido::Pedido(){
    codigo=nullptr;
    precio_producto=0.0;
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(const char *codigo) {
    if(this->codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void  Pedido::GetCodigo(char *codigo) const {
    if(this->codigo==nullptr) codigo[0]=0;
    else{
        strcpy(codigo,this->codigo);
    }
}

bool operator >>(ifstream &arch,Pedido&ped){
    char buffer[10];
    int dni;
    arch.getline(buffer,10,',');
    if(arch.eof()) return false;
    arch>>dni>>ws;
    ped.SetCodigo(buffer);
    ped.SetDni_cliente(dni);
    return true;
}