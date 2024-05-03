#include "ListaConEnteros.hpp"

void * leenum(ifstream &arch) {
    int num, dd, mm, aaaa;
    int *fecha = new int;
    char c,buffer[20];
    arch >> num>>c;
    if (arch.eof()) return nullptr;
    arch.getline(buffer,20,',');
    arch >> dd >> c >> mm >>c>> aaaa>>c>>num;
    *fecha = aaaa * 10000 + mm * 100 + dd;
    return fecha;
}

int cmpnum(void *dato, void *nuevo) {
    int *datoInt = (int *) dato;
    int *nuevoDato = (int *) nuevo;
    if (*nuevoDato == *datoInt) return 0;
    else if (*nuevoDato<*datoInt) return 1;
    else  return -1;
}

void imprimenum(ofstream &arch, void *) {
}