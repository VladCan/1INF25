#include "FlotaGenerica.hpp"
#include "PilaConEnteros.hpp"
#include "PilaConRegistros.hpp"
#include "AperturaDeArchivos.h"

void cargacamiones(void *&flota, int numcamiones, double pesomaximo, void * (*lee)(ifstream&arch), double (*calcula)(void *), const char *filename) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, filename);
    void **camiones = new void *[numcamiones] {},**pila; 
    double *cero = new double{0};
    for (int i = 0; i < numcamiones; i++) {
        pila = new void*[2] {};
        pila[DATO] = cero;
        pila[CIMA] = nullptr;
        camiones[i] = pila;
    }
    void *dato;
    int i = 0;
    while (true) {
        dato = lee(arch);
        if (dato == nullptr) break;
        if (i < numcamiones) push(camiones, i, dato, calcula, pesomaximo, numcamiones);
    }
    flota=camiones;
}

void push(void **&camiones, int &i, void *dato, double (*calcula)(void *dato), int pesomaximo, int numcamiones) {
    void **pila = (void **) camiones[i],**nuevoNodo = new void *[2];
    nuevoNodo[DATO] = dato;
    nuevoNodo[SIGUIENTE] = nullptr;
    double *nuevoTotal = new double;
    if (pilaVacia(pila)) {
        pila[CIMA] = nuevoNodo;
    } else {
        if (*(double *) pila[TOTAL] + calcula(dato) < pesomaximo) {
            insertarDato(pila, nuevoNodo);
        } else {
            i++;
            if (i == numcamiones) return;
            else {
                pila = (void **) camiones[i];
                insertarDato(pila, nuevoNodo);
            }
        }
    }
    *nuevoTotal = (*(double *) pila[TOTAL] + calcula(dato));
    pila[TOTAL] = nuevoTotal;
}

void muestracamiones(void *flota, int numcamiones, void (*imprime)(ofstream&,void *), const char *filename) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,filename);
    void **camiones=(void **)flota;
    void **pila;
    for(int i=0;i<numcamiones;i++){
        pila=(void **)camiones[i];
        void **rec = (void **) pila[CIMA];
        arch.precision(2);
        arch<<fixed;
        arch<<"Camion "<<i+1<<": "<<"Peso "<<setw(10)<< *(double *)pila[TOTAL]<<endl;
        while(rec){
            imprime(arch,rec[DATO]);;
            rec=(void **)rec[SIGUIENTE];
        }
    }
}

bool pilaVacia(void **pila) {
    return pila[CIMA] == nullptr;
}

void insertarDato(void **&pila, void *nuevoNodo) {
    void **rec = (void **) pila[CIMA];
    if (rec == nullptr) {
        pila[CIMA] = nuevoNodo;
    } else {
        while (rec[SIGUIENTE]) {
            rec = (void **) rec[SIGUIENTE];
        }
        rec[SIGUIENTE] = nuevoNodo;
    }
}