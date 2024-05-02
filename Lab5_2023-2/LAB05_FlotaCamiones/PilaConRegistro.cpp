#include "FlotaGenerica.hpp"
#include "PilaConRegistros.hpp"
void *leeregistro(ifstream &arch){
    char buffer[8],c,*codigo;
    int *dni=new int,*cant=new int;
    double *peso=new double;
    arch.getline(buffer,8,',');
    if(arch.eof()) return nullptr;
    codigo=new char[strlen(buffer)+1];
    strcpy(codigo,buffer);
    arch>>*dni>>c>>*cant>>c>>*peso>>ws;
    void **registro=new void *[4]{};
    registro[COD]=codigo;
    registro[DNI]=dni;
    registro[CANT]=cant;
    registro[PESO]=peso;
    return registro;
}
double calcularegistro(void *dato){
    void **registro=(void **)dato;
    
    double *peso=(double*)registro[PESO];
    return *peso;
}
int cmpregistro(const void *a,const void *b){
    void **IA = (void **) a;
    void **IB = (void **) b;
    void **camionA = (void **) *IA;
    void **camionB = (void **) *IB;
    double *TotalA = (double *) camionA[TOTAL];
    double *TotalB = (double *) camionB[TOTAL];
    return *TotalB - *TotalA;
}
void imprimeregistro(ofstream &arch,void *dato){
    void **registro=(void **)dato;
    arch<<setw(15)<<(char *)registro[COD]<<setw(5)<<*(int *)registro[CANT]<<setw(10)<<*(double *)registro[PESO]<<endl;
}