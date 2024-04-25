#include "funciones.hpp"
#include "MetodoIncrementoDeMemoria.hpp"
using namespace std;

void lecturaDeLibros(const char *filename, char ***&libros, int **&stock) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,filename);
    int cantidad=0,capacidad=0,i=0;
    char *codigo;
    while(true){
        codigo=leerCadena(arch,',');
        if(arch.eof()) break;
        if(cantidad==capacidad) incrementarCapacidadLibros(libros,stock,cantidad,capacidad);
        ingresarLibro(arch,libros[cantidad-1],stock[cantidad-1],cantidad,codigo);
        
    }
    
}

void pruebaDeLecturaDeLibros(const char *filename, char *** libros, int ** stock) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,filename);
    arch<<"Codigo"<<setw(20)<<"Titulo"<<setw(70)<<"Autor"<<setw(25)<<"Stock"<<setw(20)<<"Atendidos"<<endl;
    escribirLinea(arch,145,'=');
    for(int i=0;libros[i]!=nullptr;i++){
        escribirLibro(arch,libros[i],stock[i]);
    }
}

void atencionDePedidos(const char *filename, char ***&libros, int **& stock, int **&pedidosClientes, char***& pedidosLibros, bool**&pedidosAtendidos) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,filename);
    int pedido,dni,pos,cantidadClientes=0,capacidadClientes=0,*cantLibrosPedido,*capaLibrosPedido,cantidatPedidos=0,capacidadPedidos=0;
    char c;
    while(true){
        arch>>pedido>>c>>dni>>ws;
        if(arch.eof()) break;
        pos=buscarCliente(pedidosClientes,dni,cantidadClientes);
        if(pos==-1){
            if(cantidadClientes==capacidadClientes) incrementarMemoriaClientes(pedidosClientes,cantidadClientes,capacidadClientes);
            int i=0;
            while(true){
                if(pedido>capacidadPedidos){ 
                    incrementarMemoriaPedidos(pedidosLibros,pedidosAtendidos,cantLibrosPedido,capaLibrosPedido,cantidatPedidos,capacidadPedidos);
                }
                else break;
            }
            cout<<cantLibrosPedido[30]<<endl;
            agregarPedido(arch,pedidosClientes[cantidadClientes-1],pedidosLibros[pedido],pedidosAtendidos[pedido],cantLibrosPedido[pedido],capaLibrosPedido[pedido],libros,stock,dni,pedido);
        }else{
        agregarPedido(arch,pedidosClientes[pos],pedidosLibros[pedido],pedidosAtendidos[pedido],cantLibrosPedido[pedido],capaLibrosPedido[pedido],libros,stock,dni,pedido);

        }
    
    }


}
//
//void pruebaDeLecturaDeLibros(const char *filename, char *** libros, int **stock) {
//}
//
//void reporteDeEntregaDePedidos(const char *filename, int ** pedidosClientes, char ***pedidosLibros, bool ** pedidosAtendidos) {
//}