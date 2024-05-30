#include "Presencial.hpp"

Presencial::Presencial(){
    total=0.0;
    
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}
void Presencial::actualizar(double monto){
    double recargo;
    recargo=monto*GetRecargo();
    Alumno::SetTotal(monto+recargo);
    SetTotal(Alumno::GetTotal());
}
void operator >>(ifstream &arch,Presencial&p){
    char nombre[100],c;
    int codigo,escala;
    double recargo;
    arch>>codigo>>c;
    arch.getline(nombre,100,',');
    arch>>escala>>c>>recargo>>ws;
    p.SetNombre(nombre);
    p.SetCodigo(codigo);
    p.SetEscala(escala);
    p.SetRecargo(recargo/100);
}
void operator <<(ofstream &arch,Presencial p){
    char nombre[100];
    p.GetNombre(nombre);
    arch<<p.GetCodigo()<<setw(5+strlen(nombre))<<nombre<<setw(50-strlen(nombre))<<p.GetEscala()<<setw(25)<<""<<setw(10)<<p.GetTotal()<<endl;
}