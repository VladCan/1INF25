#include "AsignacionDinamicaMemoriaExacta.hpp"
#include "funciones.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void lecturaDeProductos(const char *filename, char ***&productos, int *&stock, double *&precios) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, filename);
    int cantidad = 0, capacidad = 0;
    while (true) {

        if (arch.eof()) break;
        if (cantidad == capacidad) incrementarCapacidadProductos(arch, cantidad, capacidad, productos, stock, precios);
        else {
            agregaraDatos(arch, cantidad, productos, stock, precios);
        }
    }
}

void pruebaDeLecturaDeProductos(const char *filename, char ***productos, int *stock, double *precios) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, filename);
    char **datosProducto;
    for (int i = 0; productos[i] != nullptr; i++) {
        datosProducto = productos[i];
        arch << datosProducto[0] << setw(strlen(datosProducto[1]) + 5) << datosProducto[1];
        arch << setw(75 - strlen(datosProducto[1])) << precios[i] << setw(5) << stock[i] << endl;

    }
}

void lecturaDePedidos(const char *filename, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, filename);
    char codigo[8], c;
    int dni, fecha, cant_solicitada, *capacidades_pedidos, *cantidades_pedidos;
    int cantidad_fechas = 0, capacidad_fechas = 0, pos;
    while (true) {
        arch.getline(codigo, 8, ',');
        if (arch.eof()) break;
        arch >> dni >> c >> cant_solicitada>>c;
        leerFecha(arch, fecha);
        pos = buscarFecha(fechaPedidos, fecha, cantidad_fechas);
        if (pos == -1) {
            agregarFecha(fechaPedidos, codigoPedidos, dniCantPedidos, cantidades_pedidos, capacidades_pedidos, cantidad_fechas, capacidad_fechas, fecha, pos);
            agregarPedido(codigoPedidos[pos], dniCantPedidos[pos], cantidades_pedidos[pos], capacidades_pedidos[pos], codigo, dni, cant_solicitada);
        } else {
             agregarPedido(codigoPedidos[pos], dniCantPedidos[pos], cantidades_pedidos[pos], capacidades_pedidos[pos], codigo, dni, cant_solicitada);
        }
    }
}

void pruebaDeLecturaDePedidos(const char *filename, int * fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos) {
    ofstream arch;
    char **codigos;
    int **dni;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, filename);
  int i = 0;
    while (fechaPedidos[i]) {
        escribirFecha(arch, fechaPedidos[i]);
        escribirLinea(arch, 100, '=');
        arch << setw(20) << "PRODUCTO" << setw(15) << "DNI" << setw(15) << "CANTIDAD" << endl;
        escribirLinea(arch, 100, '-');
        escribirProductos(arch, codigoPedidos[i], dniCantPedidos[i]);
        escribirLinea(arch, 100, '=');
        i++;
    }

}

void reporteDeEnvioDePedidos(const char *filename, char ***productos, int *stock, double *precios, int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, filename);

}

