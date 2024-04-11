#include "AsignacionDinamicaMemoriaExacta.hpp"
#include "funciones.hpp"

void lecturaDeProductos(const char * nombreArch, char ***&productos, int * &stock, double * &precios) {
    ifstream arch(nombreArch, ios::in);
    comprobarApertura(arch, nombreArch);
    char *codigos[200]{}, *nombres[200]{};
    int stocks[200]{}, cantidad = 0;
    double aux_precios[200]{};
    llenarAuxilaresProductos(arch, codigos, nombres, stocks, aux_precios, cantidad);
    codigos[cantidad] = escribir_str("XXXXXXX");
    nombres[cantidad] = escribir_str("XXXXXXX");
    stock = new int[cantidad + 1] {
    };
    precios = new double[cantidad + 1] {
    };
    productos = new char **[cantidad + 1] {
    };
    for (int i = 0; i <= cantidad; i++) {
        stock[i] = stocks[i];
        precios[i] = aux_precios[i];
        productos[i] = new char *[2] {
        };
        llenarProductos(productos[i], codigos[i], nombres[i]);
    }
}

void pruebaDeLecturaDeProductos(const char * nombreArch, char *** productos, int *stock, double * precios) {
    ofstream arch(nombreArch, ios::out);
    comprobarApertura(arch, nombreArch);
    arch << setw(100 / 2 + 23) << "Verificacion de los datos de Archivo Productos" << endl;
    escribirLinea(arch, 100, '=');
    arch << "CODIGO" << setw(17) << "DESCRIPCION" << setw(59) << "PRECIO" << setw(15) << "STOCK FINAL" << endl;
    escribirLinea(arch, 100, '-');
    int i = 0;
    while (precios[i]) {
        escribirProducto(arch, productos[i]);
        arch << precios[i] << setw(10) << stock[i] << endl;
        i++;
    }
    escribirLinea(arch, 100, '=');
}

void lecturaDePedidos(const char * nombreArch, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos) {
    ifstream arch(nombreArch, ios::in);
    comprobarApertura(arch, nombreArch);
    int num_pedidos_fecha[100]{}, fechas[100]{}, fecha, dni, cantidad, cant_ped = 0, **pedidos[100], pos;
    char buffer[8];
    char **codigos[100];
    while (true) {
        arch.getline(buffer, 8, ',');
        if (arch.eof())
            break;
        arch >> dni;
        arch.get();
        arch >> cantidad;
        arch.get();
        leerFecha(arch, fecha);
        pos = buscarFecha(fechas, fecha);
        if (pos == -1) {
            fechas[cant_ped] = fecha;
            codigos[cant_ped] = new char *[50] {
            };
            pedidos[cant_ped] = new int *[50] {
            };
            escribirDatosPedido(codigos[cant_ped], pedidos[cant_ped], num_pedidos_fecha[cant_ped], buffer, dni, cantidad);
            cant_ped++;
        } else {
            escribirDatosPedido(codigos[pos], pedidos[pos], num_pedidos_fecha[pos], buffer, dni, cantidad);
        }
    }
    fechaPedidos = new int [cant_ped + 1] {
    };
    codigoPedidos = new char **[cant_ped + 1] {
    };
    dniCantPedidos = new int **[cant_ped + 1] {
    };
    for (int i = 0; i < cant_ped; i++) {
        fechaPedidos[i] = fechas[i];
        codigoPedidos[i] = new char *[num_pedidos_fecha[i] + 1] {
        };
        escribirDatosPedido(codigoPedidos[i], codigos[i]);
        dniCantPedidos[i] = new int *[num_pedidos_fecha[i] + 1] {
        };
        escribirDatosPedido(dniCantPedidos[i], pedidos[i]);
    }
}

void pruebaDeLecturaDePedidos(const char * nombreArch, int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos) {
    ofstream arch(nombreArch, ios::out);
    comprobarApertura(arch, nombreArch);
    arch << setw(100 / 2 + 23) << "Verificacion de los datos de Archivo Pedidos" << endl;
    escribirLinea(arch, 100, '=');
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

void reporteDeEnvioDePedidos(const char * nombreArch, char ***productos, int * &stock, double * precios, int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos) {
    ofstream arch(nombreArch, ios::out);
    comprobarApertura(arch, nombreArch);
    arch << setw(140 / 2 + 15) << "REPORTE DE ENTREGA DE PEDIDOS" << endl;
    escribirLinea(arch, 140, '=');
    int i = 0;
    while (fechaPedidos[i]) {
        double ingresado = 0.0, perdido = 0.0;
        escribirFecha(arch, fechaPedidos[i]);
        escribirLinea(arch, 140, '=');
        arch << "No." << setw(7) << "DNI" << setw(15) << "Producto" << setw(76) << "Cantidad" << setw(15) << "Precio" << setw(20) << "Total de ingresos" << endl;
        escribirLinea(arch, 140, '-');
        escribirProductos(arch, codigoPedidos[i], dniCantPedidos[i], productos, stock, precios, ingresado, perdido);
        escribirLinea(arch, 140, '-');
        arch << "Total ingresado:" << setw(131 - strlen("Total ingresado:")) << ingresado << endl;
        arch << "Total perdido por falta de stock:" << setw(131 - strlen("Total perdido por falta de stock:")) << perdido << endl;
        escribirLinea(arch, 140, '=');
        i++;
    }

}

