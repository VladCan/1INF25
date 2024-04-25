/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 22 de abril de 2024, 21:37
 */


#include <cinttypes>

#include "PunterosGenericos.hpp"
#include "MuestraPunteros.h"


using namespace std;


int main(int argc, char** argv) {
    void *productos, *clientes;
    cargaproductos(productos);
    imprimeproductos(productos);
    cargaclientes(clientes);
    imprimeclientes(clientes);
    cargapedidos(productos,clientes);
    imprimerepfinal(clientes);
    imprimereporte(clientes);
    //Ordenamiento qsort
    int cantClientes=calcularCantidad(clientes);
    qsort(clientes,cantClientes,sizeof(void *),cmp_void_name);
    imprimerepfinal(clientes);

    return 0;
}

