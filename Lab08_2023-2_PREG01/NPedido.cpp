#include "NPedido.hpp"

NPedido::NPedido() {
    codigo=nullptr;
    sig=nullptr;
}

NPedido::NPedido(const class NPedido&orig) {
}

NPedido::~NPedido() {
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(const char* codigo) {
    if(this->codigo != nullptr) delete this->codigo;
    this->codigo=new char [strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void NPedido::GetCodigo(char* codigo) const {
    if(this->codigo == nullptr) codigo[0]=0;
    else{
        strcpy(codigo,this->codigo);
    }
}
