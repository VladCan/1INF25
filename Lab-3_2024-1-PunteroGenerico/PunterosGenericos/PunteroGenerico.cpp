#include <cmath>

#include "funciones.hpp"
#include "PunteroGenerico.hpp"

void leerLibros(void *&Libro){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Libros.csv");
    void **libros;
    void **aux=new void *[300]{};
    void *reg;
    int cantLib=0;
    while(true){
        reg=leerRegistroLibro(arch);
        if(reg==nullptr) break;
        aux[cantLib]=reg;
        cantLib++;
    }
    libros=new void *[cantLib+1]{};
    for(int i=0;i<cantLib;i++){
        libros[i]=aux[i];
    }
    Libro=libros;
}
void imprimirLibro(void *Libro){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,"ReporteLibros.txt");
    void **libros=(void **)Libro;
    void **datos;
    for(int i=0;libros[i];i++){
        datos=(void **)libros[i];
        arch<<(char *)datos[COD]<<setw(5)<<""<<(char *)datos[TITULO]<<setw(60-strlen((char *)datos[TITULO]))<<""<<(char *)datos[AUTOR];
        arch<<setw(50-strlen((char *)datos[AUTOR]))<<*(int *)datos[CANT]<<setw(10)<<""<<*(double *)datos[PRECIO]<<endl;
    }
}