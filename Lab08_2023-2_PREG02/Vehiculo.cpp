#include "Vehiculo.hpp"

Vehiculo::Vehiculo() {
    placa = nullptr;
    ped = nullptr;
    actcarga = 0;
}

Vehiculo::Vehiculo(const class Vehiculo&orig) {
    ped = nullptr;
    placa = nullptr;
    *this=orig;
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
    if (this->placa != nullptr) delete this->placa;
    this->placa = new char [strlen(placa) + 1];
    strcpy(this->placa, placa);
}

void Vehiculo::GetPlaca(char* placa) const {
    if (this->placa == nullptr) placa[0] = 0;
    else {
        strcpy(placa, this->placa);
    }
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}
void Vehiculo::operator =(const class Vehiculo&v){
    char buffer_placa[10];
    cliente=v.cliente;
    actcarga=v.actcarga;
    maxcarga=v.maxcarga;
    ped=v.ped;
    v.GetPlaca(buffer_placa);
    SetPlaca(buffer_placa);  
}


void Vehiculo::lee(ifstream&arch) {
    char buffer_placa[10], extra;
    arch >> cliente>>extra;
    arch.getline(buffer_placa, 10, ',');
    SetPlaca(buffer_placa);
    arch >> maxcarga>>extra;
}

void Vehiculo::imprime(ofstream&arch) {
    char placa[30];
    GetPlaca(placa);
    arch << setw(20) << left << "Codigo Cliente: " << cliente << endl;
    arch << setw(20) << left << "Placa: " << placa << endl;
    arch << setw(20) << left << "Carga Maxima: " << maxcarga << endl;
    arch << setw(20) << left << "Carga Actual: " << actcarga << endl;
}

void Vehiculo::mostarPedidos(ofstream&arch) {
    if (ped == nullptr) {
        arch << "No hay pedidos para el Cliente" << endl;
    } else {
        imprimePedidos(arch);
    }
}

void Vehiculo::agregarPedido(ifstream&archP) {
    NPedido *p;
    p = new NPedido;
    p->leer(archP);
    if (GetMaxcarga() > GetActcarga() + p->peso) {
        push(p);
        SetActcarga(this->actcarga + p->peso);
    } else {
        cout << "Pasa la carga maxima" << endl;
    }
}

bool Vehiculo::pilaVacia() {
    return ped == nullptr;
}

void Vehiculo::push(NPedido * p) {
    if (pilaVacia()) {
        ped = p;
    } else {
        p->sig = ped;
        ped = p;
    }
}

void Vehiculo::imprimePedidos(ofstream&arch) {
    NPedido *aux;
    aux = ped;
    imprimeRecurcivo(arch, aux);

}

void Vehiculo::imprimeRecurcivo(ofstream&arch, NPedido *aux) {
    if (aux == nullptr)
        return;
    else {
        aux->imprime(arch);
        imprimeRecurcivo(arch, aux->sig);
    }
}

void Vehiculo::escribeLinea(ofstream&arch, int n, char c) {
    for (int i = 0; i < n; i++)
        arch << c;
    arch << endl;
}
