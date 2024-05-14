#include "ColaGenerica.h"
#include "Pregunta02Examen01PunterosGenericos.h"
#include "Pregunta01Examen01PunterosMultiples.hpp"

void generacola(void *&tad) {
    void **cola = (void **) tad;
    int *num = new int;
    *num = 0;
    cola = new void *[3] {
    };
    cola[CABEZA] = nullptr;
    cola[COLA] = nullptr;
    cola[CANT_COLA] = num;
    tad = cola;
}

void encola(void *&tad, void *dato) {
    void **cola = (void **) tad;
    void **nuevoNodo = new void *[2] {
    };
    void **aux;
    int *n;
    nuevoNodo[REG] = dato;
    nuevoNodo[SIG] = nullptr;
    if (colavacia(tad)) {
        cola[CABEZA] = nuevoNodo;
        cola[COLA] = nuevoNodo;
    } else {
        aux = (void **) cola[COLA];
        aux[SIG] = nuevoNodo;
        cola[COLA] = aux[SIG];
    }
    n = longitud(tad);
    (*n)++;
    cola[CANT_COLA] = n;
    tad = cola;
}

void* desencola(void *&tad) {
    int *n;
    void **cola = (void **) tad;
    void **rec = (void **) cola[CABEZA];
    void **sig =nullptr;
    if(rec[SIG]!=nullptr) sig=(void **)rec[SIG];
    else sig=nullptr;
    cola[CABEZA]=sig;
    n = longitud(tad);
    (*n)--;
    cola[CANT_COLA] = n;  
    tad = cola;
    return rec[REG];
}

bool colavacia(void *tad) {
    void **cola = (void **) tad;
    return cola[CABEZA] == nullptr;
}

int *longitud(void *tad) {
    void **cola = (void **) tad;
    return (int *) cola[CANT_COLA];
}