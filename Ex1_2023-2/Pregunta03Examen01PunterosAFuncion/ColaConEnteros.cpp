#include "ColaConEnteros.h"
#include "AperturaDeArchivos.h"

void cargaEnteros(void *&cola,void*(*lee)(ifstream &arch), const char *filename){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,filename);
    void *dato;
    generacola(cola);
    while(true){
        dato=lee(arch);
        if(dato==nullptr) break;
        encola(cola,dato);
    }
}

void *leenumero(ifstream &arch){
    int *num=new int;
    int n;
    arch>>n;
    if(arch.eof()) return  nullptr;
    *num=n;
    return num;
}
void mostrarEnteros(void *&cola,void (*imprimenumero)(ofstream &arch,void *dato), const char *filename){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,filename);
    void *dato;
    while(!colavacia(cola)){
        dato=desencola(cola);
        imprimenumero(arch,dato);
    }

}
void imprimenumero(ofstream &arch,void *dato){
    arch<<*(int *)dato<<" | ";
}