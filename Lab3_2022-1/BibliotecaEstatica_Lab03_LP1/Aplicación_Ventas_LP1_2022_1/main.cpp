/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 3 de abril de 2024, 22:08
 */

#include "funciones.hpp"

using namespace std;


int main(int argc, char** argv) {
    
    ifstream archClientes;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.txt");
    Estructura_ClienteRegistrado cliente,arrCliente[50];
    
    while(true){
        archClientes>>cliente;
        if(archClientes.eof())
            break;
        arrCliente+=cliente;
    }
    cout<<arrCliente[17].dni<<endl;
    
    
    
    
    
    
    return 0;
}

