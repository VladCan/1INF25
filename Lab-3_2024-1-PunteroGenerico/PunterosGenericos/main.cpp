/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 25 de abril de 2024, 22:17
 */


#include "funciones.hpp"
#include "PunteroGenerico.hpp"
using namespace std;

int main(int argc, char** argv) {
    void *Libro;
    
    leerLibros(Libro);
    imprimirLibro(Libro);
    return 0;
}

