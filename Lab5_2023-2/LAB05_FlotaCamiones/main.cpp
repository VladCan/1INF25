/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 29 de abril de 2024, 18:04
 */

#include "PilaConEnteros.hpp"
#include "PilaConRegistros.hpp"
#include "FlotaGenerica.hpp" 

using namespace std;

int main(int argc, char** argv) {

        int numcamiones;
        double pesomaximo;
        void *flota;
        numcamiones = 5;
        pesomaximo = 10;
        cargacamiones(flota, numcamiones, pesomaximo, leenumero, calculanumero, "numeros.txt");
        qsort(flota, numcamiones, sizeof (void*), cmpnumero);
        muestracamiones(flota, numcamiones, imprimenumero, "reportenum.txt");
        numcamiones = 100;
        pesomaximo = 400;
        cargacamiones(flota, numcamiones, pesomaximo, leeregistro, calcularegistro, "pedidos3.csv");
        qsort(flota, numcamiones, sizeof (void*), cmpregistro);
        muestracamiones(flota, numcamiones, imprimeregistro, "reporteregistro.txt");
        return 0;
    }

