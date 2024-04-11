#include "AsignacionDinamicaMemoriaExacta.hpp"
#include "funciones.hpp"

void lecturaDeProductos(const char * nombreArch, char ***&productos, int * &stock, double * &precios) {
    ifstream arch(nombreArch, ios::in);
    comprobarApertura(arch, nombreArch);
    char *codigos[200]{}, *nombres[200]{};
    int stocks[200]{}, cantidad = 0;
    double aux_precios[200]{};
    llenarAuxilaresProductos(arch,codigos,nombres,stocks,aux_precios,cantidad);
    codigos[cantidad] = escribir_str("XXXXXXX");
    nombres[cantidad] = escribir_str("XXXXXXX");
    stock = new int[cantidad + 1];
    precios = new double[cantidad + 1];
    productos = new char **[cantidad + 1];
    for (int i = 0; i <= cantidad; i++) {
        stock[i] = stocks[i];
        precios[i] = aux_precios[i];
        productos[i] = new char *[2];
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
    int num_pedidos_fecha[600]{}, fechas[600]{}, fecha, fechas_sin_repetir[600]{}, dni[600], cantidad[600]{}, cant_ped = 0, cant_fecha_sin_rep = 0;
    char *codigos[600], buffer[8];
    while (true) {
        arch.getline(buffer, 8, ',');
        if (arch.eof())
            break;
        arch >> dni[cant_ped];
        arch.get();
        arch >> cantidad[cant_ped];
        arch.get();
        leerFecha(arch, fecha);
        codigos[cant_ped] = escribir_str(buffer);
        if (buscarFecha(fechas, fecha) != -1) {
            num_pedidos_fecha[buscarFecha(fechas, fecha)]++;
        } else {
            fechas_sin_repetir[cant_fecha_sin_rep] = fecha;
            num_pedidos_fecha[cant_ped]++;
            cant_fecha_sin_rep++;
        }
        fechas[cant_ped] = fecha;
        cant_ped++;
    }
    fechaPedidos = new int [cant_fecha_sin_rep + 1]{};
    codigoPedidos = new char ** [cant_fecha_sin_rep + 1]{};
    dniCantPedidos = new int ** [cant_fecha_sin_rep + 1]{};
    for (int i = 0; i < cant_fecha_sin_rep; i++) {
        fechaPedidos[i]=fechas_sin_repetir[i];
        codigoPedidos[i] = new char *[num_pedidos_fecha[i] + 1]{};
        dniCantPedidos[i] = new int *[num_pedidos_fecha[i] + 1]{};
        }
    int p;
    for(int i=0;i<cant_ped;i++){
        p=buscarFecha(fechas_sin_repetir,fechas[i]);
        completarPedidos(codigoPedidos[p],codigos[i],dniCantPedidos[p],dni[i],cantidad[i]);
    }
}

void pruebaDeLecturaDePedidos(const char * nombreArch, int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos) {
    ofstream arch(nombreArch, ios::out);
    comprobarApertura(arch, nombreArch);
    arch << setw(100 / 2 + 23) << "Verificacion de los datos de Archivo Pedidos" << endl;
    escribirLinea(arch, 100, '=');
    arch << "CODIGO" << setw(17) << "DESCRIPCION" << setw(59) << "PRECIO" << setw(15) << "STOCK FINAL" << endl;
    escribirLinea(arch, 100, '-');
   int i=0;
    while(fechaPedidos[i]){
        arch<<fechaPedidos[i]<<endl;
        escribirLinea(arch, 100, '=');
        
        i++;
    }
    
}

void reporteDeEnvioDePedidos(const char * nombreArch, char ***productos, int * stock, double * precios, int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos) {
}

