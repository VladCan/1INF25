/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 2 de mayo de 2024, 15:17
 */

#include "BibliotecaListaGenerica.hpp"
#include "ListaConEnteros.hpp"
#include "ListaConRegistro.hpp"

using namespace std;

int main(int argc, char** argv) {
    void *lista1, *lista2;
    creaLista(lista1, leenum, cmpnum, "RegistroDeFaltas1.csv");
    creaLista(lista2, leenum, cmpnum, "RegistroDeFaltas2.csv");
    //    uneLista(lista1, lista2);
    //    imprimeLista(lista1, imprimenum, "Repnum.txt");
    //    creaLista(lista1, leeregistro, cmpregistro, "RegistroDeFaltas1.csv");
    //    creaLista(lista2, leeregistro, cmpregistro, "RegistroDeFaltas2.csv");
    //    uneLista(lista1, lista2);
    //    imprimeLista(lista1, imprimeregistro, ”Repfalta.txt”);

    return 0;
}

