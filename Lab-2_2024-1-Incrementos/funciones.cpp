#include <ios>

#include "funciones.hpp"

void incrementarCapacidadLibros(char ***&libros, int **&stock, int &cantidad, int &capacidad) {
    capacidad += INCREMENTO;
    char ***aux_libros = new char **[capacidad] {};
    int **aux_stock = new int *[capacidad] {};
    if (cantidad == 0) {
        cantidad = 1;
    } else {
        for (int i = 0; i < cantidad; i++) {
            aux_libros[i] = libros[i];
            aux_stock[i] = stock[i];
        }
    }
    delete libros;
    delete stock;
    libros = aux_libros;
    stock = aux_stock;
}
void ingresarLibro(ifstream &arch,char **&libros,int *&stock,int &cantidad,char *codigo){
    libros=new char *[3]{};
    stock=new int [2]{};
    int inicial;
    libros[0]=codigo;
    libros[1]=leerCadena(arch,',');
    libros[2]=leerCadena(arch,',');
    arch>>inicial;
    stock[0]=inicial;
    while(true) {
        if(arch.get()=='\n') break;
    }
        cantidad++;
}
char *leerCadena(ifstream &arch,char c){
    char *str;
    char buffer[100];
    arch.getline(buffer,100,c);
    str=new char [strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}
void escribirLibro(ofstream &arch,char **libros,int *stock){
    arch<<libros[0]<<setw(strlen(libros[1])+5)<<libros[1]<<setw(60-strlen(libros[1]))<<" ";
    arch<<setw(10+strlen(libros[2]))<<libros[2]<<setw(100-strlen(libros[1]))<<setw(37-strlen(libros[2]))<<stock[0]<<setw(18)<<stock[1]<<endl;
}
void escribirLinea(ofstream &arch,int n,char c){
    for(int i=0;i<n;i++){
        arch<<c;
    }
    arch<<endl;
}
int buscarCliente(int **pedidosClientes,int dni,int cantidadClientes){
    int *datosCliente;
    for(int i=0;i<cantidadClientes;i++){
        datosCliente=pedidosClientes[i];
        if(datosCliente[0]==dni) return i;
    }
    return -1;
}
void incrementarMemoriaClientes(int **&pedidosClientes,int &cantidadClientes,int &capacidadClientes){
    capacidadClientes+=INCREMENTO;
    int **aux_pedidosClientes= new int *[capacidadClientes]{};
    if(cantidadClientes==0){
        cantidadClientes=1;
    }else{
        for(int i=0;i<cantidadClientes;i++){
            aux_pedidosClientes[i]=pedidosClientes[i];
        }
    }
    delete pedidosClientes;
     pedidosClientes=aux_pedidosClientes;
}
void agregarPedido(ifstream &arch,int *&pedidosClientes,char **&pedidosLibros,bool *&pedidosAtendidos,int &cantidad,int &capacidad,char ***libros,int **&stock,int dni,int pedido){
    if(cantidad==capacidad) incrementarMemoriaCliente(pedidosClientes,pedidosLibros,pedidosAtendidos,cantidad,capacidad);
    pedidosClientes[0]=dni;
    pedidosClientes[1]=cantidad;
    pedidosClientes[cantidad+1]=pedido;
    char *codigo,buffer[8],c;
    while(true){
        arch.getline(buffer,8);
        c=arch.get();
        if(c=='\n') break;
        arch>>ws;

    }


}

void incrementarMemoriaCliente(int *&pedidosClientes,char **&pedidosLibros,bool *&pedidosAtendidos,int &cantidad,int &capacidad){
    capacidad+=INCREMENTO;
    int *aux_pedidosClientes;
    char **aux_pedidosLibros;
    bool *aux_pedidosAtendidos;
    if(cantidad==0){
        pedidosClientes=new int[capacidad+2]{};
    pedidosLibros=new char *[capacidad]{};
    aux_pedidosAtendidos=new bool[capacidad]{};
        cantidad=1;
    }else{
        int *aux_pedidosClientes=new int[capacidad+2]{};
    char **aux_pedidosLibros=new char *[capacidad]{};
    bool *aux_pedidosAtendidos=new bool[capacidad]{};
        for(int i=0;i<cantidad;i++){
            aux_pedidosClientes[i]=pedidosClientes[i];
            aux_pedidosLibros[i]=pedidosLibros[i];
            aux_pedidosAtendidos[i]=pedidosAtendidos[i];
        }
        delete pedidosClientes;
    delete pedidosLibros;
    delete pedidosAtendidos;
     pedidosClientes=aux_pedidosClientes;
     pedidosLibros=aux_pedidosLibros;
     pedidosAtendidos=aux_pedidosAtendidos;
    }
}
void incrementarMemoriaPedidos(char ***&pedidosLibros,bool **&pedidosAtendidos,int *&cantLibrosPedido,int *&capaLibrosPedido,int &cantidatPedidos,int &capacidadPedidos){
    capacidadPedidos+=INCREMENTO;
    char ***aux_pedidosLibros;
    bool **aux_pedidosAtendidos;
    int *aux_cantLibrosPedido;
    int *aux_capaLibrosPedido;
    if(cantidatPedidos==0){
        pedidosLibros= new char **[capacidadPedidos]{};
        pedidosAtendidos = new bool *[capacidadPedidos]{};
        cantLibrosPedido=new int [capacidadPedidos]{};
        capaLibrosPedido=new int [capacidadPedidos]{};
    }else{
        aux_pedidosLibros= new char **[capacidadPedidos]{};
        aux_pedidosAtendidos = new bool *[capacidadPedidos]{};
        aux_cantLibrosPedido=new int [capacidadPedidos]{};
        aux_capaLibrosPedido=new int [capacidadPedidos]{};
        for(int i=0;i<cantidatPedidos;i++){
            aux_pedidosAtendidos[i]=pedidosAtendidos[i];
            aux_pedidosLibros[i]=pedidosLibros[i];
            aux_cantLibrosPedido[i]=cantLibrosPedido[i];
            aux_capaLibrosPedido[i]=capaLibrosPedido[i];
        }
    delete pedidosLibros;
    delete pedidosAtendidos;
    delete aux_cantLibrosPedido;
    delete aux_capaLibrosPedido;
    pedidosLibros=aux_pedidosLibros;
    pedidosAtendidos=aux_pedidosAtendidos;
    cantLibrosPedido=aux_cantLibrosPedido;
    capaLibrosPedido=aux_capaLibrosPedido;
    }
}
char * leerCodigo(ifstream &arch){
    char *str;
    char buffer[10];
    arch.getline(buffer,8);
    str=new char [strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}