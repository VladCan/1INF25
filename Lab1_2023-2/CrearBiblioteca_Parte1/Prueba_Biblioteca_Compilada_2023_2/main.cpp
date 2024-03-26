/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 24 de marzo de 2024, 20:29
 */
#include "Sobrecargandos.hpp"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"


using namespace std;


int main(int argc, char** argv) {

    ifstream archClientes,archProducto, archPedido;
    ofstream archReporteCliente,archReporteProducto;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProducto,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedido,"Pedidos.csv");
    
    
    struct Cliente cliente;
    struct Producto producto;
    struct Pedido pedido;
    archClientes>>cliente;
    archProducto>>producto;
    archPedido>>pedido;
    
    
    cout<<cliente.dni<<" "<<cliente.nombre<<endl;
    cout<<producto.codigo<<" "<<producto.descripcion<<endl;
    cout<<pedido.dniCliente<<endl;
    return 0;
}

