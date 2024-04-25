#include "funciones.hpp"

using namespace std;

void incrementarCapacidadProductos(ifstream &arch, int &n, int &c, char ***&productos, int *&stocks, double *&precios) {
    c += INCREMENTO;
    char *** aux_productos = new char **[c] {};
    int *aux_stocks = new int [c] {};
    double *aux_precios = new double [c] {};
    if (n == 0) {
        n++;
        agregaraDatos(arch, n, aux_productos, aux_stocks, aux_precios);
    } else {
        for (int i = 0; i < n; i++) {
            aux_precios[i] = precios[i];
            aux_productos[i] = productos[i];
            aux_stocks[i] = stocks[i];
        }
    }
    liberarMemoriaProducto(productos, stocks, precios);
    asignarProductos(productos, stocks, precios, aux_productos, aux_precios, aux_stocks);
}

void liberarMemoriaProducto(char ***&productos, int *&stocks, double *&precios) {
    delete precios;
    delete productos;
    delete stocks;
}

void asignarProductos(char ***&productos, int *&stocks, double *&precios, char *** aux_productos, double *aux_precios, int *aux_stocks) {
    precios = aux_precios;
    productos = aux_productos;
    stocks = aux_stocks;
}

void agregaraDatos(ifstream &arch, int &cantidad, char ***&productos, int *&stocks, double *&precios) {
    char codigo[8], nombre[100], c;
    int stock;
    double precio;
    arch.getline(codigo, 8, ',');
    arch.getline(nombre, 100, ',');
    arch >> precio >> c >> stock>>ws;
    productos[cantidad - 1] = escribirDatosProducto(codigo, nombre);
    stocks[cantidad - 1] = stock;
    precios[cantidad - 1] = precio;
    cantidad++;

}

char **escribirDatosProducto(char *codigo, char *nombre) {
    char **datosProducto = new char *[2] {
    };
    datosProducto[0] = escribir_str(codigo);
    datosProducto[1] = escribir_str(nombre);
    return datosProducto;
}

char *escribir_str(char *buffer) {
    char *str = new char[strlen(buffer) + 1] {
    };
    strcpy(str, buffer);
    return str;
}

void escribirLine(ofstream &arch, int n, char c) {
    for (int i = 0; i < n; i++) {
        arch << n;
    }
    arch << endl;
}

void leerFecha(ifstream &arch, int &fecha) {
    int dd, mm, aaaa;
    char c;
    arch >> dd >> c >> mm >> c >> aaaa>>ws;
    fecha = aaaa * 10000 + mm * 100 + dd;
}

int buscarFecha(int *fechaPedidos, int fecha, int cantidad_fechas) {
    for (int i = 0; i < cantidad_fechas; i++) {
        if (fechaPedidos[i] == fecha) {
            return i;
        }
    }
    return -1;
}

void incrementarCapacidadFechas(int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos, int *&cantidades_pedidos, int *&capacidades_pedidos, int &cantidad_fechas, int &capacidad_fechas, int fecha) {
    capacidad_fechas += INCREMENTO;
    int *aux_fechas = new int [capacidad_fechas] {};
    char*** aux_codigoPedidos = new char** [capacidad_fechas] {};
    int*** aux_dniCantPedidos = new int** [capacidad_fechas] {};
    int *aux_cantidadPedidos = new int [capacidad_fechas] {};
    int *aux_capacidadPedidos = new int [capacidad_fechas] {};
    if (cantidad_fechas == 0) cantidad_fechas++;
    else {
        for (int i = 0; i < cantidad_fechas; i++) {
            aux_fechas[i] = fechaPedidos[i];
            aux_cantidadPedidos[i] = cantidades_pedidos[i];
            aux_capacidadPedidos[i] = capacidades_pedidos[i];
            aux_codigoPedidos[i] = codigoPedidos[i];
            aux_dniCantPedidos[i] = dniCantPedidos[i];
        }
    }
    aux_fechas[cantidad_fechas - 1] = fecha;
    liberarMemoriaPedidos(fechaPedidos, cantidades_pedidos, capacidades_pedidos, codigoPedidos, dniCantPedidos);
    asignarPedidos(fechaPedidos, cantidades_pedidos, capacidades_pedidos, codigoPedidos, dniCantPedidos,
            aux_fechas, aux_cantidadPedidos, aux_capacidadPedidos, aux_codigoPedidos, aux_dniCantPedidos);
}

void liberarMemoriaPedidos(int *&fechaPedidos, int *&cantidades_pedidos, int *&capacidades_pedidos, char ***&codigoPedidos, int ***&dniCantPedidos) {
    delete fechaPedidos;
    delete cantidades_pedidos;
    delete capacidades_pedidos;
    delete codigoPedidos;
    delete dniCantPedidos;
}

void incrementarCapacidadPedido(char **&codigoPedidos, int **&dniCantPedidos, int &cantidades_pedidos, int &capacidades_pedidos) {
    char **aux_codigoPedidos;
    int **aux_dniCantPedidos;
    capacidades_pedidos += INCREMENTO;
}

void asignarPedidos(int *&fechaPedidos, int *&cantidades_pedidos, int *&capacidades_pedidos, char ***&codigoPedidos, int ***&dniCantPedidos,
        int * aux_fechas, int *aux_cantidadPedidos, int *aux_capacidadPedidos, char ***aux_codigoPedidos, int ***aux_dniCantPedidos) {

    fechaPedidos = aux_fechas;
    cantidades_pedidos = aux_cantidadPedidos;
    capacidades_pedidos = aux_capacidadPedidos;
    codigoPedidos = aux_codigoPedidos;
    dniCantPedidos = aux_dniCantPedidos;

}

void agregarFecha(int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos, int *&cantidades_pedidos, int *&capacidades_pedidos, int &cantidad_fechas, int &capacidad_fechas, int fecha, int &pos) {
    if (cantidad_fechas == capacidad_fechas) {
        incrementarCapacidadFechas(fechaPedidos, codigoPedidos, dniCantPedidos, cantidades_pedidos, capacidades_pedidos, cantidad_fechas, capacidad_fechas, fecha);
    } else {
        fechaPedidos[cantidad_fechas] = fecha;
        codigoPedidos[cantidad_fechas] = nullptr;
        cantidades_pedidos[cantidad_fechas] = 0;
        capacidades_pedidos[cantidad_fechas] = 0;
        dniCantPedidos[cantidad_fechas] = nullptr;
        cantidad_fechas++;
    }
    pos = cantidad_fechas - 1;
}

void incrementarCapacidadPedido(char **&codigoPedidos, int **&dniCantPedidos, int &cantidades, int &capacidades, int dni, int cant_solicitada, char *codigo) {
    capacidades += INCREMENTO;
    char **aux_codigoPedido = new char *[capacidades] {};
    int **aux_dniCantPedidos = new int *[capacidades] {};
    if (cantidades == 0) {
        cantidades++;
    } else {
        for (int i = 0; i < cantidades; i++) {
            aux_codigoPedido[i] = codigoPedidos[i];
            aux_dniCantPedidos[i] = dniCantPedidos[i];
        }
    }
    aux_codigoPedido[cantidades - 1] = escribir_str(codigo);
    aux_dniCantPedidos[cantidades - 1] = escribirDatosDni(dni, cant_solicitada);
    delete codigoPedidos;
    delete dniCantPedidos;
    codigoPedidos = aux_codigoPedido;
    dniCantPedidos = aux_dniCantPedidos;
}

void agregarPedido(char **&codigoPedidos, int **&dniCantPedidos, int &cantidades_pedidos, int & capacidades_pedidos, char*codigo, int dni, int cant_solicitada) {
    if (cantidades_pedidos == capacidades_pedidos) {
        incrementarCapacidadPedido(codigoPedidos, dniCantPedidos, cantidades_pedidos, capacidades_pedidos, dni, cant_solicitada, codigo);
    } else {
        codigoPedidos[cantidades_pedidos - 1] = escribir_str(codigo);
        int *datosDni = new int [2] {
        };
        datosDni[0] = dni;
        datosDni[1] = cant_solicitada;
        dniCantPedidos[cantidades_pedidos - 1] = datosDni;
    }
    cantidades_pedidos++;
}

int *escribirDatosDni(int dni, int cantidad) {
    int *datos = new int [2];
    datos[0] = dni;
    datos[1] = cantidad;
    return datos;
}

void escribirFecha(ofstream &arch, int fecha) {
    arch.fill('0');
    arch << "FECHA: ";
    int dd, mm, aaaa;
    aaaa = fecha / 10000;
    mm = (fecha - aaaa * 10000) / 100;
    dd = (fecha - aaaa * 10000) % 100;
    arch << setw(2) << dd << '/' << setw(2) << mm << '/' << aaaa << endl;
    arch.fill(' ');
}

void escribirLinea(ofstream &arch, int n, char c) {
    for (int i = 0; i < n; i++) {
        arch << c;
    }
    arch << endl;
}

void escribirProductos(ofstream &arch, char **codigoPedidos, int **dniCantPedidos) {
    int i = 0;
    int dni, cantidad;
    while (true) {
        if (codigoPedidos[i] == nullptr) break;
        obtenerDatos(dniCantPedidos[i], dni, cantidad);
        arch << setw(3) << i + 1 << ")" << setw(20) << codigoPedidos[i] << setw(18) << dni << setw(10) << cantidad << endl;
        i++;
    }
}

void obtenerDatos(int *dniCantPedidos, int &dni, int &cantida) {
    dni = dniCantPedidos[0];
    cantida = dniCantPedidos[1];
}

int buscarProducto(char ***productos, char *codigoPedidos) {
    char **codigo;
    for (int i = 0; productos[i]; i++) {
        codigo = productos[i];
        if (!strcmp(codigo[0], codigoPedidos)) {
            return i;
        }
    }
    return -1;
}

void escribirProductosEntregados(ofstream &arch, char **codigoPedidos, int **dniCantPedidos, char ***productos, int *&stock,double *precio) {
    int i = 0, pos,dni, cantidad;
    char **codigo;
    for(int i=0;codigoPedidos[i]!=nullptr;i++) {
        obtenerDatos(dniCantPedidos[i], dni, cantidad);
        pos = buscarProducto(productos, codigoPedidos[i]);
        if (pos != -1) {
            codigo=productos[pos];
            arch << setw(3) << i + 1 << ")"<< setw(18) << dni  << setw(20) << codigoPedidos[i] << setw(strlen(codigo[1])+5)<<codigo[1]<<setw(65-strlen(codigo[1]))<<cantidad<<setw(15)<<precio[pos];                       
            if (stock[pos] > 0) {
               arch  <<setw(20)<<precio[pos]*cantidad<<endl;
                 stock[pos] -= cantidad;
            } else {
            arch<<setw(20)<< "Sin stock" << endl;
            }
        }
    }
}