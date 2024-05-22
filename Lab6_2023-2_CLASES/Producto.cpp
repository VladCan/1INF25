#include "Producto.hpp"

Producto::Producto() {
    codigo = nullptr;
    cantidad_clientes_no_servidos=0;
    cantidad_clientes_servidos=0;
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescriopcion(const char* descriopcion) {
    if (this->descriopcion != nullptr) delete this->descriopcion;
    this->descriopcion = new char [strlen(descriopcion) + 1];
    strcpy(this->descriopcion, descriopcion);
}

void Producto::GetDescriopcion(char* descriopcion) const {
    if (this->descriopcion == nullptr) descriopcion[0] = 0;
    else {
        strcpy(descriopcion, this->descriopcion);
    }
}

void Producto::SetCodigo(const char* codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char [strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Producto::GetCodigo(char* codigo) const {
    if (this->codigo == nullptr) codigo[0] = 0;
    else {
        strcpy(codigo, this->codigo);
    }
}

bool Producto::operator+=(Pedido &p) {
    if(stock>0){
        clientes_servidos[cantidad_clientes_servidos]=p.GetDni_cliente();
        p.SetPrecio_producto(this->precio);
        cantidad_clientes_servidos++;
        this->stock--;
        return true;
    }else{
        clientes_no_servidos[cantidad_clientes_no_servidos]=p.GetDni_cliente();
        cantidad_clientes_no_servidos++;
        return false;
    }
}
void Producto::operator<<(ofstream &arch) {
    char buffer_cod[10],buffer_des[100];
    GetCodigo(buffer_cod);
    GetDescriopcion(buffer_des);
    arch<<buffer_cod<<setw(10+strlen(buffer_des))<<buffer_des<<setw(65-strlen(buffer_des))<<GetPrecio()<<setw(10)<<GetStock()<<endl;
    arch<<"Clientes atendidos: ";
    for(int i=0;i<cantidad_clientes_servidos;i++)
        arch<<clientes_servidos[i]<<setw(10)<<"";
    arch<<endl;
    arch<<"Clientes no atendidos: ";
    for(int i=0;i<cantidad_clientes_no_servidos;i++)
        arch<<clientes_no_servidos[i]<<setw(10)<<"";
    arch<<endl;
}

bool operator>>(ifstream &arch, Producto&prod) {
    char buffer_cod[10],buffer_des[100],c;
    double precio;
    int stock;
    arch.getline(buffer_cod,10,',');
    if(arch.eof()) return false;
    arch.getline(buffer_des,100,',');
    arch>>precio>>c>>stock>>ws;
    prod.SetCodigo(buffer_cod);
    prod.SetDescriopcion(buffer_des);
    prod.SetPrecio(precio);
    prod.SetStock(stock);
    return true;
}

