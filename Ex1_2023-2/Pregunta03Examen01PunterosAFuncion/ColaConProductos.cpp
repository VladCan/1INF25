#include "ColaConProductos.h"
#include "Pregunta02Examen01PunterosGenericos.h"
#include "Pregunta01Examen01PunterosMultiples.hpp"

void procesarPedidos(int **fechaClienteCantidad, char **codigoDelProducto, void *&p){
    void **productos=(void **)p;
    void *dato;
    int pos;
    for(int i=0;fechaClienteCantidad[i];i++){
        dato=fechaClienteCantidad[i];
        pos=buscarProducto(p,codigoDelProducto[i]);
        if(verificarAtencion(dato,productos[pos])){
            void **registro=(void **)productos[pos];
            if(registro[NUL]==nullptr){
                generacola(registro[NUL]);
            }
            encola(registro[NUL],dato);
        }
    }
}

bool verificarAtencion(void *dato,void *&producto){
    int *datosPedido=(int *)dato; 
    void **registro=(void **)producto;
    void **datosProd=(void **)registro[DATOS];
    int stockNuevo=(*(int *)datosProd[STOCK]-datosPedido[CANT]);
    if(stockNuevo<0) return false;
    else {
        *(int *)datosProd[STOCK]=stockNuevo;
        return true;
    }
}
int buscarProducto(void *&p,char *codigo){
    void **productos=(void **)p;
    void **registro;
    void **datos;
    for(int i=0;productos[i];i++){
        registro=(void **)productos[i];
        datos=(void **)registro[DATOS];
        if(strcmp((char *)datos[COD],codigo)==0) return i;
    }
    return -1;
}
void reporteDePedidos(void *p, const char *filename){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,filename);
    void **productos=(void **)p;
    void **registro;
    for(int i=0;productos[i];i++){
        registro=(void **)productos[i];
        arch<<"Producto "<<i+1<<":"<<endl;
        escribirRegisto(arch,productos[i]);
        arch<<"Pedidos aceptados: "<<endl;
        arch<<"Fecha"<<setw(15)<<"DNI"<<setw(15)<<"Cantidad"<<endl;
        if(registro[NUL]!=nullptr) mostrarPedidosAceptados(registro[NUL],arch);
    }

}
void mostrarPedidosAceptados(void *&cola,ofstream &arch){
    int *datos;
    while(!colavacia(cola)){
    datos=(int *)desencola(cola);
    arch<<datos[FECHA]<<setw(15)<<datos[DNI]<<setw(15)<<datos[CANT]<<endl;
}
    
}