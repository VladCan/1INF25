#include <cmath>

#include "funciones.hpp"

using namespace std;

char *leerCadena(ifstream &arch, char c) {
    char *str;
    char buffer[100];
    arch.getline(buffer, 100, c);
    str = new char [strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void *leerRegistroProd(ifstream &arch) {
    void **registro;
    char *codigo,*descripcion, c,*tipo;
    double *precio=new double;
    codigo=leerCadena(arch,',');
    if(arch.eof()) return nullptr;
    descripcion = leerCadena(arch, ',');
    arch>>*precio>> c;
    tipo=leerCadena(arch,'\n');
    registro = new void *[4] {};
    registro[CODIGO] = codigo;
    registro[DESCRIPCION] = descripcion;
    registro[PRECIO] = precio;
    registro[TIPO] = tipo;
    //cout<<(char *)registro[CODIGO]<<setw(5)<<""<<descripcion<<" "<<setw(5)<<*precio<<setw(5)<<tipo<<endl;
    return registro;
}
void actualizarPuntoVoid(void *&punteroGenerico,void **auxiliar,int cantidad){
    void **aux;
    aux=new void *[cantidad+1]{};
       for(int i=0;i<cantidad;i++)
           aux[i]=auxiliar[i];
    punteroGenerico=(void *)aux;
}
/*void incrementarMemoria(void **&p,int n,int c){
    c+=INCREMENTO;
    void **aux;
    aux=nullptr;
    if(n==0){
        p=new void*[c]{};
        n=1;
    }else{
        aux=new void *[c]{};
        for(int i=0;i<n;i++){
            aux[i]=p[i];
        }
        delete p;
        p=aux;
    }    
}*/

void *leerRegistroClien(ifstream &arch){
    void **registro;
    int *dni=new int,telefono;
    double *lineaCred=new double;
    char *nombre, c,*tipo;
    arch>>*dni>>c;
    if(arch.eof()) return nullptr;
    nombre = leerCadena(arch, ',');
    arch>>telefono>>c>>*lineaCred>>ws;
    registro = new void *[4] {};
    registro[DNI] = dni;
    registro[NOMBRE] = nombre;
    registro[PEDIDOS] = nullptr;
    registro[LINEACRED] = lineaCred;
    //cout<<*(int *)registro[DNI]<<setw(5)<<""<<nombre<<" "<<setw(5)<<""<<telefono<<setw(5)<<""<<lineaCred<<endl;
    return registro;
}
int buscarCliente(void *clientes,int dni){
    void **registro=(void **)clientes;
    void **datos;
    for(int i=0;registro[i]!=nullptr;i++){
        datos=(void **)registro[i];
        if(*(int *)datos[DNI]==dni) return i;
    }
    return -1;
}
int buscarProducto(void *productos,char *codigo){
    void **registro=(void **)productos;
    void **datos;
    for(int i=0;registro[i]!=nullptr;i++){
        datos=(void **)registro[i];
        if(!(strcmp((char *)datos[CODIGO],codigo))) return i;
    }
    return -1;
}
void actualizarCliente(void *&cliente,void *&producto,int *cant){
    int posProducto;
    void **datosCliente=(void **)cliente;
    void **datosProducto=(void **)producto;
    void **pedido=new void *[3]{};
    double *total=new double;
    double *linea=(double *)datosCliente[LINEACRED];
    *total=(*(double *)datosProducto[PRECIO])*(*cant);
    double *resta=new double;
    *resta=*linea-*total;
    if(*(char *)datosProducto[TIPO]=='N' or *resta>0){   
            pedido[CODPROD]=datosProducto[CODIGO];
            pedido[CANTIDADPROD]=cant;
            pedido[TOTAL]=total;
            agregarPedido(datosCliente,pedido);
            if(*(char *)datosProducto[TIPO]=='S') datosCliente[LINEACRED]=resta; 
        }
    cliente=datosCliente;
    producto=datosProducto;
}
    void agregarPedido(void **&datosCliente,void **pedido){
    void **aux=nullptr,**pedidos=nullptr;
    int cantPedidos=0;
    if(datosCliente[PEDIDOS]==nullptr){
        pedidos=new void *[2]{};
        pedidos[0]=(void *)pedido;
    }else{
        aux=(void **)datosCliente[PEDIDOS];
        while(aux[cantPedidos]!=nullptr) cantPedidos++;
        pedidos=new void *[cantPedidos+2]{};
        for(int i=0;aux[i]!=nullptr;i++)
            pedidos[i]=aux[i];
        pedidos[cantPedidos]=(void *)pedido;
    }
    datosCliente[PEDIDOS]=(void *)pedidos;
}
void escribirLinea(ofstream &arch,int n,char c){
    for(int i=0;i<n;i++){
        arch<<c;
    }
    arch<<endl;
}
void escribirPedidos(ofstream &arch,void *pedido){
    void **pedidos=nullptr,**datos=nullptr;
    pedidos=(void **)pedido;
    for(int i=0;pedidos[i]!=nullptr;i++){
        datos=(void **)pedidos[i];
        arch<<(char *)datos[CODPROD]<<setw(8)<<""<<*(int *)datos[CANTIDADPROD]<<setw(20)<<*(double *)datos[TOTAL]<<endl;
    }

}