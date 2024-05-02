#include <cmath>

#include "funciones.hpp"


void *leerRegistroLibro(ifstream &arch){
    char *codigo,*titulo,*autor,c;
    double *precio=new double;
    int *cantidad=new int;
    void **registro=new void *[5]{};
    codigo=leerCadena(arch,',');
    if(arch.eof()) return nullptr;
    titulo=leerCadena(arch,',');
    autor=leerCadena(arch,',');
    arch>>*cantidad>>c>>*precio>>ws;
    registro[COD]=codigo;
    registro[TITULO]=titulo;
    registro[AUTOR]=autor;
    registro[CANT]=cantidad;
    registro[PRECIO]=precio;
    return registro;
}
char * leerCadena(ifstream &arch,int c){
    char *str;
    char buffer[150];
    arch.getline(buffer,150,c);
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}