#include "funciones.hpp"
#define ancho 200
void escribirLinea(ofstream &arch,char c, int n){
    for(int i=0;i<n;i++){
        arch<<c;
    }
    arch<<endl;

}
void cabecera(ofstream &arch){
    arch<<right<<setw(ancho/2 + 20/2)<<"Reporte de Clientes"<<endl;
    escribirLinea(arch,'=',100);
    arch<<setw(10)<<" "<<"DNI"<<setw(30)<<" "<<"Nombre"<<setw(20)<<"Telefono"<<endl;
}