#include "Cliente.hpp"

Cliente::Cliente() {
    nombre = nullptr;
    cantidad_productos_entregados = 0;
    monto_total = 0.0;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(const char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Cliente::GetNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = 0;
    else {
        strcpy(nombre, this->nombre);
    }
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::operator+=(Pedido p) {
    char buffer[10];
    p.GetCodigo(buffer);
    productos_entregados[cantidad_productos_entregados].SetPrecio(p.GetPrecio_producto());
    productos_entregados[cantidad_productos_entregados].SetCodigo(buffer);
    cantidad_productos_entregados++;
    monto_total += p.GetPrecio_producto();
}
void Cliente::encontrarPriducto(int i,ProductoEntregado &ProdE){
    ProdE=productos_entregados[i];
}

void operator<<(ofstream &arch,Cliente cli) {
    ProductoEntregado prodE;
    char buffer[200];
    cli.GetNombre(buffer);
    arch << cli.GetDni() << setw(10 + strlen(buffer)) << buffer << setw(60 - strlen(buffer)) <<cli.GetTelefono();
    arch <<setw(25)<<"Productos entregados: ";
    if(cli.GetCantidad_productos_entregados()==0) arch<<"NO SE LE ENTREGARON PRODUCTOS";
    for (int i = 0; i <cli.GetCantidad_productos_entregados(); i++) {
        cli.encontrarPriducto(i,prodE);
        prodE.GetCodigo(buffer);
        arch<<buffer<<setw(15)<<"";
    }
    arch<<endl;
}
bool operator>>(ifstream &arch, Cliente&cli) {
    int dni, telefono;
    char buffer[200], c;
    arch>>dni;
    if (arch.eof()) return false;
    arch>>c;
    arch.getline(buffer, 200, ',');
    arch>>telefono;
    cli.SetDni(dni);
    cli.SetNombre(buffer);
    cli.SetTelefono(telefono);
    return true;
}
