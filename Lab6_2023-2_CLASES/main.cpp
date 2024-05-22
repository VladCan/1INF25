/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: VLADYMIR
 * 
 * Created on 21 de mayo de 2024, 18:38
 */

#include "Utils.hpp"
#include "Cliente.hpp"
#include "Producto.hpp"
#include "Pedido.hpp"
using namespace std;
void escribirLinea(int n,char c,ofstream&arch){
    for(int i=0;i<n;i++)
        arch<<c;
    arch<<endl;
}
int main(int argc, char** argv) {
    ifstream archCli, archProd, archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archCli, "Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProd, "Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed, "Pedidos.csv");
    ofstream archOutCli, archOutProd;
    AperturaDeUnArchivoDeTextosParaEscribir(archOutCli, "PruebaClientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archOutProd, "PruebaProductos.txt");
    int cantClientes = 0;
    Cliente cli[200];
    while (archCli >> cli[cantClientes])cantClientes++;
    int cantProductos = 0;
    Producto prod[200];
    while (archProd >> prod[cantProductos])cantProductos++;

    Pedido ped;
    char buffer[10], codigo[10];
    while (archPed >> ped) {
        ped.GetCodigo(buffer);
        for (int i = 0; i < cantProductos; i++) {
            prod[i].GetCodigo(codigo);
            if (!strcmp(buffer, codigo)) {
                if (prod[i] += ped){
                     for (int i = 0; i < cantClientes; i++) {
                         if(cli[i].GetDni()==ped.GetDni_cliente()){
                             cli[i]+=ped;
                             break;
                         }
                     }
                }
                break;

                }
        }
    }
    archOutCli << setw(57) << "Datos de Clientes" << endl;
    escribirLinea(100,'-',archOutCli);
    archOutCli << setw(5) << "DNI" << setw(25) << "NOMBRE" << setw(48) << "TELEFONO" << endl;
    escribirLinea(100,'=',archOutCli);
    for (int i = 0; i < cantClientes; i++)
        cli[i].operator <<(archOutCli);
    archOutProd << setw(57) << "Datos de Productos" << endl;
    escribirLinea(100,'-',archOutProd);
    archOutProd << setw(5) << "CODIGO" << setw(25) << "DESCRIPCION" << setw(51) << "PRECIO" << setw(10) << "STOCK" << endl;
    escribirLinea(100,'=',archOutProd);
    for (int i = 0; i < cantProductos; i++)
        prod[i].operator <<(archOutProd);

    return 0;
}

