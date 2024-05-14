#include "Pregunta02Examen01PunterosGenericos.h"
#include "Pregunta01Examen01PunterosMultiples.hpp"
using namespace std;

void cargarProductos(void *&p, const char *filename) {
    ifstream arch(filename, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << filename << endl;
        exit(1);
    }
    void **productos = (void **) p;
    void *registro = nullptr;
    int cantidad = 0, capacidad = 0;
    int i = 0;
    while (true) {
        registro = leerRegistro(arch);
        if (registro == nullptr) break;
        if (cantidad == capacidad) incrementarMemoria(productos, cantidad, capacidad);
        productos[cantidad-1]=registro;
        cantidad++;
    }
    p=productos;
    qsort(p,cantidad-1,sizeof(void*),cmp);
}
int cmp(const void *A,const void *B){

    void **IA=(void **)A;
    void **IB=(void **)B;
    void **productoA=(void **)*IA;
    void **productoB=(void **)*IB;
    void **registroA=(void **)productoA[DATOS];
    void **registroB=(void **)productoB[DATOS];
    void *codA=registroA[COD];
    void *codB=registroB[COD];
    
    
    return strcmp((char *)codA,(char *)codB);
     
}
void incrementarMemoria(void **&productos, int &cantidad, int &capacidad) {
    capacidad += INCREMENTO;
    if (cantidad == 0) {
        productos = new void *[capacidad] {};
        cantidad = 1;
    } else {
        void **auxProductos = new void *[capacidad] {};
        for (int i = 0; i < cantidad; i++) {
            auxProductos[i] = productos[i];
        }
        delete productos;
        productos=auxProductos;
    }
}

void *leerRegistro(ifstream &arch) {
    char *codigo, *descripcion, c;
    double *precio = new double;
    int *stock = new int;
    void **registro = new void*[2] {}, **datos = new void *[4] {};
    codigo = leerStr(arch);
    if (codigo == nullptr) return nullptr;
    descripcion = leerStr(arch);
    arch>>*precio >> c>>*stock>>ws;
    datos[COD] = codigo;
    datos[DESC] = descripcion;
    datos[PRECIO] = precio;
    datos[STOCK] = stock;
    registro[DATOS] = datos;
    registro[NUL] = nullptr;
    return registro;
}

char *leerStr(ifstream &arch) {

    char *str;
    char buffer[150];
    arch.getline(buffer, 150, ',');
    if (arch.eof()) return nullptr;
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void pruebaDeCargaDeProductos(void *p) {
    ofstream arch("PruebaProductos.txt",ios::out);
    arch<<"CODIGO"<<setw(17)<<"DESCRIPCION"<<setw(54)<<"PRECIO"<<setw(16)<<"STOCK"<<endl;
    escribirLiena(arch,100,'=');
    void **productos=(void **)p;
    void *registo;
    for(int i=0;productos[i];i++){
        registo=productos[i];
        escribirRegisto(arch,registo);
    }
}
void escribirRegisto(ofstream &arch,void *r){
    void **registo=(void **)r;
    void **datos=(void **)registo[DATOS];
    arch<<(char *)datos[COD]<<setw(strlen((char *)datos[DESC])+5)<<(char *)datos[DESC]<<setw(65-strlen((char *)datos[DESC]))<<*(double *)datos[PRECIO]<<setw(15)<<*(int *)datos[STOCK]<<endl;
}