#include "Sobrecargados.hpp"
#define ANCHO 50
ifstream & operator>>(ifstream &arch, Estructura_ClienteRegistrado &Cli) {
    char buffer[60];
    char c, m;
    arch >> Cli.dni>>ws;
    arch.get(buffer, 60, ' ');
    m = buffer[strlen(buffer) - 2];
    if (m == '-') {
        c = buffer[strlen(buffer) - 1];
        switch (c) {
            case 'A':
                strcpy(Cli.categoria, "Cliente muy frecuente");
                buffer[strlen(buffer) - 2] = '\0';
                break;
            case 'B':
                strcpy(Cli.categoria, "Cliente frecuente");
                buffer[strlen(buffer) - 2] = '\0';
                break;
            case 'C':
                strcpy(Cli.categoria, "Cliente ocacional");
                buffer[strlen(buffer) - 2] = '\0';
                break;
        }


    } else {
        strcpy(Cli.categoria, "Cliente nuevo");

    }
    arch >> Cli.telefono;
    strcpy(Cli.nombre, buffer);
    Cli.numeroDePedidos = 0;
    Cli.montoTotalGastado = 0;
    return arch;
}

void operator+=(Estructura_ClienteRegistrado *arr, const Estructura_ClienteRegistrado Cli) {

    int i = 0;
    while (true) {
        if (arr[i].dni == 0) {
            strcpy(arr[i].categoria, Cli.categoria);
            arr[i].dni = Cli.dni;
            arr[i].montoTotalGastado = Cli.montoTotalGastado;
            strcpy(arr[i].nombre, Cli.nombre);
            arr[i].numeroDePedidos = Cli.numeroDePedidos;
            arr[i].telefono = Cli.telefono;
            for(int j=0;j<Cli.numeroDePedidos;j++){
                arr[i].pedidosRealizados[j]=Cli.pedidosRealizados[j];
            }
            
            break;
        }
        else{
            i++;
        }
    }
    arr[i + 1].dni = 0;


}

void operator += (Estructura_ClienteRegistrado &Cli, const Estructura_PedidoRealizado Ped){
    int i=Cli.numeroDePedidos;
    
    Cli.pedidosRealizados[i].cantidad=Ped.cantidad;
    strcpy(Cli.pedidosRealizados[i].codigo,Ped.codigo);
    Cli.pedidosRealizados[i].descuento=Ped.descuento;
    Cli.pedidosRealizados[i].fecha=Ped.fecha;
    Cli.pedidosRealizados[i].precioUnitario=Ped.precioUnitario;
    
    Cli.montoTotalGastado+=Ped.cantidad*Ped.precioUnitario;
    Cli.numeroDePedidos++;
    
}
void operator += (Estructura_ProductosEnAlmacen *arr, const Estructura_ProductosEnAlmacen Prod){
    
    int i=0;
    while(true){
        if(!strcmp(arr[i].codigo,Prod.codigo)){
            break;
        }
        if(!strcmp(arr[i].codigo,"X")){
            strcpy(arr[i].codigo,Prod.codigo);
            strcpy(arr[i].descripcion,Prod.descripcion);
            arr[i].descuento=Prod.descuento;
            arr[i].precioUnitario=Prod.precioUnitario;
            strcpy(arr[i+1].codigo,"X");
            break;
        }
        i++;
    }

}

ofstream & operator <<(ofstream &arch,const Estructura_ClienteRegistrado Cli){
    arch<<setw(5)<<"DNI"<<setw(32)<<"NOMBRE"<<endl;
    arch<<Cli.dni<<setw(strlen(Cli.nombre)+2)<<Cli.nombre<<endl;
    arch<<Cli.categoria<<endl;
    arch<<"No."<<setw(9)<<"CODIGO"<<setw(10)<<"CANTIDAD"<<setw(10)<<"FECHA"<<endl;
    int i=0;
    for(int i=0;i<Cli.numeroDePedidos;i++){
        if(!strcmp(Cli.pedidosRealizados[i].codigo,"X")){
            break;
        }else{
            arch<<i+1<<")"<<setw(8)<<Cli.pedidosRealizados[i].codigo<<setw(10)<<Cli.pedidosRealizados[i].cantidad;
            arch<<setw(10);
            int dd,mm,aaaa,fecha;
            fecha=Cli.pedidosRealizados[i].fecha;
            dd=fecha/1000000;
            fecha=fecha-dd*1000000;
            mm=fecha/10000;
            aaaa=fecha-mm*10000;
            arch<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<setfill(' ')<<"/"<<aaaa<<endl;
            
        }
    }
    arch<<"Monto total comprado: "<<Cli.montoTotalGastado;

}

ofstream & operator <<(ofstream &arch,const Estructura_ProductosEnAlmacen *arr){
    arch<<setw(ANCHO/2+20)<<"PRODUCTOS ALMACENADOS"<<endl;
    arch<<"No."<<setw(ANCHO/5+3)<<"Codigo"<<setw(ANCHO/5+5)<<"Descripcion"<<setw(ANCHO/5+8)<<"Precio Unitario"<<setw(ANCHO/5+5)<<"Descuento"<<endl;
    int i=0;
    while(true){
        if(!strcmp(arr[i].codigo,"X")){
            break;
        }
        arch<<i+1<<")"<<setw(ANCHO/5+4)<<arr[i].codigo<<setw(ANCHO/5)<<arr[i].descripcion;
        arch<<setw(23-strlen(arr[i].descripcion))<<arr[i].precioUnitario<<setw(ANCHO/5+8)<<arr[i].descuento<<endl;
        i++;
        
    }


}