#include "Almacen.hpp"
Almacen::Almacen() {
    cantidad_clientes = 0;
    cantidad_productos = 0;
}

void Almacen::setCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::getCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::setCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::getCantidad_clientes() const {
    return cantidad_clientes;
}

void Almacen::cargar_clientes() {
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli, "Clientes.csv");
    while (archCli >> arreglo_clientes[cantidad_clientes]) cantidad_clientes++;
}

void Almacen::cargar_productos() {
    ifstream archProd;
    AperturaDeUnArchivoDeTextosParaLeer(archProd, "Productos.csv");
    while (archProd >> arreglo_productos[cantidad_productos]) cantidad_productos++;
}

void Almacen::cargar_pedidos() {
    ifstream archPed;
    Pedido p;
    int posCliente, posProducto;
    char cod_p[10];
    AperturaDeUnArchivoDeTextosParaLeer(archPed, "Pedidos.csv");
    while (archPed >> p) {
        posCliente = indiceCliente(p.GetDni_cliente());
        p.GetCodigo(cod_p);
        posProducto = iniceProducto(cod_p);
        if (posCliente != -1 and posProducto !=-1) {
            arreglo_productos[posProducto] += p;
            arreglo_clientes[posCliente] += p;
        }
    }
}

void Almacen::mostrar_datos() {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, "ReporteAlmacen.txt");
    arch << setw(57) << "Reporte del Almacen" << endl;
    escribirLinea(100,'=',arch);
    arch << setw(57) << "Datos de Clientes" << endl;
    escribirLinea(100,'-',arch);
    arch << setw(5) << "DNI" << setw(25) << "NOMBRE" << setw(48) << "TELEFONO" << endl;
    escribirLinea(100,'=',arch);
    for (int i = 0; i < cantidad_clientes; i++)
        arch<<arreglo_clientes[i];
    escribirLinea(100,'=',arch);
    arch << setw(57) << "Datos de Productos" << endl;
    escribirLinea(100,'-',arch);
    arch << setw(5) << "CODIGO" << setw(25) << "DESCRIPCION" << setw(51) << "PRECIO" << setw(10) << "STOCK" << endl;
    escribirLinea(100,'=',arch);
    for (int i = 0; i < cantidad_productos; i++){
        //arreglo_productos[i].operator <<(arch);
        arch<<arreglo_productos[i];
    }
        
}

int Almacen::indiceCliente(int dni) {
    for (int i = 0; i < getCantidad_clientes(); i++)
        if (arreglo_clientes[i].GetDni() == dni) return i;
    return -1;

}

int Almacen::iniceProducto(char *codigo) {
    char buffer[10];
    for (int i = 0; i < getCantidad_productos(); i++) {
        arreglo_productos[i].GetCodigo(buffer);
        if (!strcmp(buffer, codigo)) return i;
    }
    return -1;
}
void escribirLinea(int n,char c,ofstream&arch){
    for(int i=0;i<n;i++){
        arch<<c;
    }
    arch<<endl;
}