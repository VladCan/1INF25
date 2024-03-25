#include "AperturaDeArchivos.h"
#include "Sobrecargandos.hpp"
#include "Estructuras.h"

using namespace std;

ifstream & operator>>(ifstream &arch, struct Cliente &cli) {
    char buffer[60];
    int telefono=0, dni;
    bool retu = true;
    char c;
    arch>>dni;
    if (arch.eof()) {
        retu = false;
        // return false;
    };
    arch.get();
    arch.get(buffer, 60, ',');
    arch>>c;
    arch>>telefono;
    cli.dni = dni;
    cli.telefono = telefono;
    strcpy(cli.nombre, buffer);
    cli.cantidadProductosEntrgados = 0;
    cli.montoTotal = 0;
    // return true;
}

ifstream & operator>>(ifstream &arch, struct Producto &prod) {
    char cod[10];
    char buffer[60];
    bool retu = true;
    char c;
    arch.getline(cod, 10, ',');

    if (arch.eof()) {
        retu = false;
        // return false;
    };
    arch.getline(buffer, 60, ',');
    arch >> prod.precio;
    arch>>c;
    arch >> prod.stock;
    strcpy(prod.codigo, cod);
    strcpy(prod.descripcion, buffer);
    prod.cantidadClientesNoServidos = 0;
    prod.cantidadClientesServidos = 0;
    // prod.clientesNoServidos={};
    // prod.clientesServidos={};
    // return true;
}

ifstream & operator>>(ifstream &arch, struct Pedido &ped) {
    char buffer[10];
    bool retu = true;
    arch.getline(buffer, 10, ',');
    if (arch.eof()) {
        retu = false;
        // return false;
    };
    arch >> ped.dniCliente;
    strcpy(ped.CodigoProducto, buffer);
    ped.precioProducto = 0;
    // return true;
}

Cliente & operator+=(struct Cliente *arrCli, const struct Pedido &ped) {
    int i = 0;
    while (true) {
        if (arrCli[i].dni == ped.dniCliente) {
            strcpy(arrCli[i].productosEntregados[arrCli[i].cantidadProductosEntrgados].codigo, ped.CodigoProducto);
            arrCli[i].productosEntregados[arrCli[i].cantidadProductosEntrgados].precio = ped.precioProducto;
            arrCli[i].cantidadProductosEntrgados++;
            arrCli[i].montoTotal += ped.precioProducto;
        }
        i++;
    }
}

Producto & operator+=(struct Producto *arrProd, struct Pedido &ped) {
    int i = 0;
    while (true) {
        if (!strcmp(arrProd[i].codigo, ped.CodigoProducto)) {
            if (arrProd[i].stock > 0) {
                arrProd[i].clientesServidos[arrProd[i].cantidadClientesServidos] = ped.dniCliente;
                arrProd[i].cantidadClientesServidos++;
                ped.precioProducto=arrProd[i].precio;
            } else {
                arrProd[i].clientesNoServidos[arrProd[i].cantidadClientesNoServidos] = ped.dniCliente;
                arrProd[i].cantidadClientesNoServidos++;
            }
            arrProd[i].stock--;
            


        }

    }


}


ofstream & operator << (ofstream &arch, const struct Cliente &cli){
    arch<<cli.dni<<setw(strlen(cli.nombre)+5)<<cli.nombre<<setw(10)<<cli.telefono;
    if(cli.montoTotal==0){
        arch<<setw(35)<<"NO SE LE ENTREGARON PRODUCTOS"<<endl;
    }else{
        arch<<setw(15)<<cli.montoTotal;
        for(int i=0;i<cli.cantidadProductosEntrgados;i++){
            arch<<setw(10)<<cli.productosEntregados[i].codigo;
        }
        
    }
    arch<<endl;
}

ofstream & operator << (ofstream &arch, const struct Producto &prod){
    arch<<prod.codigo<<setw(strlen(prod.descripcion)+3)<<prod.descripcion<<setw(10)<<prod.precio<<setw(10)<<prod.stock<<endl;
    arch<<"Clientes atendidos:";
    if(prod.cantidadClientesServidos==0) arch<<"NO SE ATENDIERON PEDIDOS"<<endl;
    else{
        for(int i=0;i<prod.cantidadClientesServidos;i++){
            arch<<setw(12)<<prod.clientesServidos[i];
        }
        arch<<endl;
    }
    arch<<"Clientes no atendidos:";
    if(prod.cantidadClientesNoServidos==0) arch<<"NO HAY CLIENTES SIN ATENDER"<<endl;
    else{
        for(int i=0;i<prod.cantidadClientesNoServidos;i++){
            arch<<setw(12)<<prod.clientesNoServidos[i];
        }
        arch<<endl;
    }

}