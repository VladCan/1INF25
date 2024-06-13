#include "Semipresencial.hpp"

Semipresencial::Semipresencial() {
    descunto = 0.0;
    total = 0.0;
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescunto(double descunto) {
    this->descunto = descunto;
}

double Semipresencial::GetDescunto() const {
    return descunto;
}
void Semipresencial::actualizar(double monto){
    double descuento;
    descuento=monto*GetDescunto();
    Alumno::SetTotal(monto-descuento);
    SetTotal(Alumno::GetTotal());
}
void operator>>(ifstream &arch, Semipresencial&s) {
    char nombre[100], c;
    int codigo, escala;
    double descuento;
    arch >> codigo>>c;
    arch.getline(nombre, 100, ',');
    arch >> escala >> c >> descuento>>ws;
    s.SetNombre(nombre);
    s.SetCodigo(codigo);
    s.SetEscala(escala);
    s.SetDescunto(descuento / 100);
}
void operator <<(ofstream &arch,Semipresencial s){
    char nombre[100];
    s.GetNombre(nombre);
    arch<<s.GetCodigo()<<setw(5+strlen(nombre))<<nombre<<setw(50-strlen(nombre))<<s.GetEscala()<<setw(10)<<s.GetTotal()<<endl;
}