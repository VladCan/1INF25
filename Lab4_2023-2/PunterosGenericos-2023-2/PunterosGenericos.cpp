#include <ios>

#include "AperturaDeArchivos.h"
#include "PunterosGenericos.hpp"

using namespace std;

void cargaproductos(void *&productos) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Productos2.csv");
    void *prod[500],*reg,**aux;
    int cantidad=0;//capacidad=0;
    productos=nullptr;
    //prod=nullptr;
    while(true){
        reg=leerRegistroProd(arch);
        if(reg==nullptr) break;
        //if(cantidad == capacidad) incrementarMemoria(prod,cantidad,capacidad);
        prod[cantidad]=reg;
        cantidad++;
        }
    actualizarPuntoVoid(productos,prod,cantidad);
    } 

void cargaclientes(void *&clientes) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Clientes2.csv");
    void *clien[500],*reg;
    int cantidad=0;//,capacidad=0;
    clientes=nullptr;
    while(true){
        reg=leerRegistroClien(arch);
        if(reg==nullptr) break;
        //if(cantidad == capacidad) incrementarMemoria(clien,cantidad,capacidad);
        clien[cantidad]=reg;
        cantidad++;
        }
    actualizarPuntoVoid(clientes,clien,cantidad);
    } 
    

void cargapedidos(void *productos, void *&clientes) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Pedidos2.csv");
    char *codigo,c;
    int dni,*cantidad=new int,posProducto,posCliete;
    void **cliente=(void **)clientes,**producto=(void **)productos;
    while(true){
        codigo=leerCadena(arch,',');
        if(arch.eof()) break;
        arch>>dni>>c>>*cantidad>>ws;
        posCliete=buscarCliente(clientes,dni);
        posProducto=buscarProducto(productos,codigo);
        actualizarCliente(cliente[posCliete],producto[posProducto],cantidad);        
    }
    productos=(void *)producto;
    clientes=(void *)cliente;
}

void imprimereporte(void *clientes) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,"ReporteDePedidos.txt");
    void **cliente=(void **)clientes,**datos=nullptr;
    for(int i=0;cliente[i]!=nullptr;i++){
        datos=(void **)cliente[i];
        escribirLinea(arch,100,'=');
        arch<<"DNI"<<setw(15)<<""<<"Nombre"<<setw(50)<<"Credito"<<endl;
        arch<<*(int*)datos[DNI]<<setw(10)<<""<<(char *)datos[NOMBRE]<<setw(49-strlen((char *)datos[NOMBRE]))<<""<<*(double *)datos[LINEACRED]<<endl;
        escribirLinea(arch,100,'-');
        arch<<"Pedidos atendidos:"<<endl;
        escribirLinea(arch,100,'-');
        arch<<"Codigo"<<setw(15)<<"Cantidad"<<setw(15)<<"Total"<<endl;
        escribirLinea(arch,100,'-');
        if(datos[PEDIDOS]!=nullptr){
             escribirPedidos(arch,datos[PEDIDOS]);
        }
       
    }
}