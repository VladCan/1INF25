#include "funciones.hpp"

void comprobarApertura(ifstream &arch, const char*nombreArch) {
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombreArch << endl;
        exit(1);
    }
}

void comprobarApertura(ofstream &arch, const char*nombreArch) {
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombreArch << endl;
        exit(1);
    }
}

void llenarProductos(char **&productos, char *codigo, char *nombre) {
    productos[0] = escribir_str(codigo);
    productos[1] = escribir_str(nombre);
}
void llenarAuxilaresProductos(ifstream &arch,char **codigos,char **nombres,int *stocks,double *aux_precios,int &cantidad){
    char buffer[8], buffer2[100];
    double precio;
    int stock;
    while (true) {
        arch.getline(buffer, 8, ',');
        if (arch.eof()) break;
        arch.getline(buffer2, 100, ',');
        arch>>precio;
        arch.get();
        arch >> stock>>ws;
        codigos[cantidad] = escribir_str(buffer);
        nombres[cantidad] = escribir_str(buffer2);
        stocks[cantidad] = stock;
        aux_precios[cantidad] = precio;
        cantidad++;
    }
}

char *escribir_str(const char *buffer) {
    char *str;
    str = new char [strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void escribirLinea(ofstream &arch, int n, char c) {
    for (int i = 0; i < n; i++) {
        arch << c;
    }
    arch << endl;
}

void escribirProducto(ofstream &arch, char **producto) {
    arch << producto[0] << setw(strlen(producto[1]) + 5) << producto[1] << setw(70 - strlen(producto[1]));
}

void leerFecha(ifstream &arch, int &fecha) {
    int dd, mm, aaaa;
    char c;
    arch >> dd >> c >> mm >> c >> aaaa>>ws;
    fecha = aaaa * 10000 + mm * 100 + dd;
}

int buscarFecha(int *fechas, int fecha) {
    int i = 0;
    while (fechas[i]) {
        if (fechas[i] == fecha)
            return i;
        i++;
    }
    return -1;

}

void completarPedidos(char **&codigoPedidos, char *codigo, int **&dniCantPedidos, int dni, int cantidad) {
    int i = 0;
    while (true) {
        if (codigoPedidos[i] == nullptr) {
            codigoPedidos[i] = escribir_str(codigo);
            dniCantPedidos[i] = escribir_int(dni, cantidad);
            break;
        }
        i++;
    }
}

int *escribir_int(int dni, int cantidad) {
    int *datos = new int [2];
    datos[0] = dni;
    datos[1] = cantidad;
    return datos;
}
