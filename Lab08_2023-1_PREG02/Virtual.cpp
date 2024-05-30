#include "Virtual.hpp"

Virtual::Virtual(){
    licencia=nullptr;
    total=0.0;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* licencia) {
    if(this->licencia != nullptr) delete this->licencia;
    this->licencia=new char[strlen(licencia)+1];
    strcpy(this->licencia,licencia);
}

void Virtual::GetLicencia(char* licencia) const {
    if(this->licencia==nullptr) licencia[0]=0;
    else{
        strcpy(licencia,this->licencia);
    }
}
void Virtual::actualizar(double monto){
    Alumno::SetTotal(monto+100.0);
    SetTotal(Alumno::GetTotal());
}
void operator >>(ifstream &arch,Virtual&v){
    char nombre[100],c,licencia[10];
    int codigo, escala;
    double descuento;
    arch >> codigo>>c;
    arch.getline(nombre, 100, ',');
    arch >> escala >> c;
    arch.getline(licencia,10,'\n');
    v.SetNombre(nombre);
    v.SetCodigo(codigo);
    v.SetEscala(escala);
    v.SetLicencia(licencia);
}
void operator <<(ofstream &arch,Virtual v){
    char nombre[100];
    char licencia[15];
    v.GetNombre(nombre);
    v.GetLicencia(licencia);
    arch<<v.GetCodigo()<<setw(5+strlen(nombre))<<nombre<<setw(50-strlen(nombre))<<v.GetEscala()<<setw(10+strlen(licencia))<<licencia<<setw(25-strlen(licencia))<<v.GetTotal()<<endl;
}