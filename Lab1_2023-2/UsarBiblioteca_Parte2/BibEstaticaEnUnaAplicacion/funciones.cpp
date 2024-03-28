#include "funciones.hpp"
#define ancho 200
void escribirLinea(ofstream &arch,char c, int n){
    for(int i=0;i<n;i++){
        arch<<c;
    }
    arch<<endl;

}
void cabeceraCliente(ofstream &arch){
    arch<<right<<setw(ancho/2 + 20/2)<<"Reporte de Clientes"<<endl;
    escribirLinea(arch,'=',ancho);
    arch<<setw(6)<<"DNI"<<setw(25)<<"Nombre"<<setw(32)<<"Telefono"<<setw(17)<<"Monto Total"<<endl;
    escribirLinea(arch,'-',ancho);
}

void cabeceraProductos(ofstream &arch){
    arch<<right<<setw(ancho/2 + 20/2)<<"Reporte de Productos"<<endl;
    escribirLinea(arch,'=',ancho);
    arch<<setw(7)<<"Codigo"<<setw(25)<<"Descripcion"<<setw(50)<<"Precio"<<setw(20)<<"Stock Final"<<endl;
    escribirLinea(arch,'=',ancho);
}