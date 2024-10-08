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

void llenarAuxilaresProductos(ifstream &arch, char **codigos, char **nombres, int *stocks, double *aux_precios, int &cantidad) {
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

void llenarPedidosAux(ifstream &arch,int *fechas,int &cant_ped,char ***codigos,int ***pedidos,int *num_pedidos_fecha){
    char buffer[8],c;
    int dni,cantidad,fecha,pos;
    while (true) {
        arch.getline(buffer, 8, ',');
        if (arch.eof()) break;
        arch >> dni>>c>> cantidad>>c;
        leerFecha(arch, fecha);
        pos = buscarFecha(fechas, fecha);
        if (pos == -1) {
            fechas[cant_ped] = fecha;
            codigos[cant_ped] = new char *[50] {};
            pedidos[cant_ped] = new int *[50] {};
            escribirDatosPedido(codigos[cant_ped], pedidos[cant_ped], num_pedidos_fecha[cant_ped], buffer, dni, cantidad);
            cant_ped++;
        } else {
            escribirDatosPedido(codigos[pos], pedidos[pos], num_pedidos_fecha[pos], buffer, dni, cantidad);
        }
    }
}

void escribirDatosPedido(char **&codigos, int **&pedidos, int &num, char *buffer, int dni, int catidad) {
    codigos[num] = escribir_str(buffer);
    pedidos[num] = escribir_int(dni, catidad);
    num++;
}


void escribirDatosPedido(char **&codigoPedidos, char **codigos,int **&dniCantPedidos, int **pedidos) {
    for(int i=0;codigos[i] != nullptr;i++){
        codigoPedidos[i] = codigos[i];
        dniCantPedidos[i] = pedidos[i];
    }
    delete codigos;
    delete pedidos;
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

void escribirFecha(ofstream &arch, int fecha) {
    arch.fill('0');
    arch << "Fecha: ";
    int dd, mm, aaaa;
    aaaa = fecha / 10000;
    mm = (fecha - aaaa * 10000) / 100;
    dd = (fecha - aaaa * 10000) % 100;
    arch << setw(2) << dd << '/' << setw(2) << mm << '/' << aaaa << endl;
    arch.fill(' ');
}

void escribirProductos(ofstream &arch, char **codigoPedidos, int **dniCantPedidos) {
    int i = 0;
    int dni, cantida;
    while (true) {
        if (codigoPedidos[i] == nullptr) break;
        obtenerDatos(dniCantPedidos[i], dni, cantida);
        arch << setw(20) << codigoPedidos[i] << setw(18) << dni << setw(10) << cantida << endl;
        i++;
    }
}

void obtenerDatos(int *dniCantPedidos, int &dni, int &cantida) {
    dni = dniCantPedidos[0];
    cantida = dniCantPedidos[1];
}

void escribirProductos(ofstream &arch, char **codigoPedidos, int **dniCantPedidos, char ***productos, int *&stock, double *precios, double &ingresado, double &perdido) {
    int pos,dni, cantidad;
    for(int i=0;codigoPedidos[i] != nullptr;i++){
        arch << setw(2) << i + 1 << ')';
        obtenerDatos(dniCantPedidos[i], dni, cantidad);
        pos = buscarProducto(productos, codigoPedidos[i]);
        arch << setw(10) << dni << setw(10);
        escribirProducto(arch, productos[pos]);
        arch << cantidad << setw(18) << precios[pos];
        stock[pos] -= cantidad;
        if (stock[pos] < 0) {
            perdido += precios[pos] * cantidad;
            arch << setw(15) << "SIN STOCK" << endl;
        } else {
            arch << setw(15) << precios[pos] * cantidad << endl;
            ingresado += precios[pos] * cantidad;
        }
    }
}

int buscarProducto(char ***productos, char *codigoPedidos) {
    int i = 0;
    while (true) {
        if (productos[i] == nullptr) {
            return -1;
        } else {
            if (compararCodigoProducto(productos[i], codigoPedidos) == 0) {
                return i;
            }
            i++;
        }
    }
}

int compararCodigoProducto(char **producto, char *codigoPedidos) {
    return strcmp(producto[0], codigoPedidos);
}