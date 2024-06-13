#include "Alumno.hpp"

Alumno::Alumno(){
    nombre=nullptr;
    codigo=0;
    escala=0;
    total=0.0;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Alumno::GetNombre(char* nombre) const {
    if(this->nombre==nullptr) nombre[0]=0;
    else{
        strcpy(nombre,this->nombre);
    }
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}
