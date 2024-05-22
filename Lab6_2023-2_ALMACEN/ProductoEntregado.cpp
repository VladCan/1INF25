#include "ProductoEntregado.hpp"

ProductoEntregado::ProductoEntregado(){
    codigo=nullptr;
    precio=0.0;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(const char* codigo) {
    if(this->codigo != nullptr) delete this->codigo;
    this->codigo=new char [strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void ProductoEntregado::GetCodigo(char* codigo) const {
    if(this->codigo==nullptr) codigo[0]=0;
    else{
        strcpy(codigo,this->codigo);
    }
}
