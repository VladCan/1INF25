#include "Pregunta01Examen01PunterosMultiples.hpp"

void cargarPedidos(int **&fechaClienteCantidad, char **&codigoDelProducto, const char *filename) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,filename);
    int cantidad=0,capacidad=0,dni,cant,fecha;
    char *codigo,c;
    while(true){
        int *datosFecha=new int[3]{};
        codigo=leerCodigo(arch);
        if(codigo==nullptr) break;
        arch>>datosFecha[DNI]>>c>>datosFecha[CANT]>>c;
        datosFecha[FECHA]=leerFecha(arch);
        if(cantidad==capacidad) incrementrarMemoria(fechaClienteCantidad,codigoDelProducto,cantidad,capacidad);
        fechaClienteCantidad[cantidad-1]=datosFecha;
        codigoDelProducto[cantidad-1]=codigo;
        cantidad++;
    }
    ordenarAcendente(fechaClienteCantidad,codigoDelProducto,0,cantidad-2);
}
char *leerCodigo(ifstream &arch){
    char *str;
    char buffer[8];
    arch.getline(buffer,8,',');
    if(arch.eof()) return nullptr;
    str=new char [strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}
int leerFecha(ifstream &arch){
    int dd,mm,aaaa;
    char c;
    arch>>dd>>c>>mm>>c>>aaaa>>ws;
    return aaaa*10000+mm*100+dd;
}
void incrementrarMemoria(int **&fechaClienteCantidad, char **&codigoDelProducto,int &cantidad,int &capacidad){
    capacidad+=INCREMENTO;
    if(cantidad==0){
        fechaClienteCantidad=new int *[capacidad]{};
        codigoDelProducto=new char *[capacidad]{};
        cantidad=1;
    }
    else{
        int **aux_fecha =new int*[capacidad]{};
        char **aux_codigo=new char *[capacidad]{};
        for(int i=0;i<cantidad;i++){
            aux_fecha[i]=fechaClienteCantidad[i];
            aux_codigo[i]=codigoDelProducto[i];
        }
        delete fechaClienteCantidad;
        delete codigoDelProducto;
        fechaClienteCantidad=aux_fecha;
        codigoDelProducto=aux_codigo;
    }
}

void pruebaDeCargaDePedidos(int **fechaClienteCantidad, char **codigoDelProducto, const char *filename) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,filename);
    arch<<setw(8)<<"FECHA"<<setw(15)<<"DNI"<<setw(16)<<"CODIGO"<<setw(20)<<"CANTIDAD"<<endl;
    escribirLiena(arch,65,'=');
    int *datos;
    for(int i=0;codigoDelProducto[i];i++){
        datos=fechaClienteCantidad[i];
        escribirFecha(arch,datos[FECHA]);
        arch<<setw(15)<<datos[DNI]<<setw(15)<<codigoDelProducto[i]<<setw(15)<<datos[CANT]<<endl;
    }
}
void cambiar(int *&fechaClienteCantidadI,int *&fechaClienteCantidadK, char *&codigoDelProductoI,char *&codigoDelProductoK){
    int *auxInt;
    char *auxChar;
    auxInt=fechaClienteCantidadI;
    auxChar=codigoDelProductoI;
    fechaClienteCantidadI=fechaClienteCantidadK;
    codigoDelProductoI=codigoDelProductoK;
    fechaClienteCantidadK=auxInt;
    codigoDelProductoK=auxChar;
            
}
void ordenarAcendente(int **&fechaClienteCantidad, char **&codigoDelProducto,int izq,int der){
    int limite,pos;
    int *datos1,*datos2;
    if(izq>=der) return;
    pos=(izq+der)/2;
    cambiar(fechaClienteCantidad[izq],fechaClienteCantidad[pos],codigoDelProducto[izq],codigoDelProducto[pos]);
    limite=izq;
    for(int i=izq+1;i<=der;i++){
        datos1=fechaClienteCantidad[i];
        datos2=fechaClienteCantidad[izq];
        if(datos1[FECHA]<datos2[FECHA] or (datos1[DNI]<datos2[DNI] and datos1[FECHA]==datos2[FECHA])){
            limite++;
            cambiar(fechaClienteCantidad[limite],fechaClienteCantidad[i],codigoDelProducto[limite],codigoDelProducto[i]);
        }
    }
    cambiar(fechaClienteCantidad[limite],fechaClienteCantidad[izq],codigoDelProducto[limite],codigoDelProducto[izq]);
    ordenarAcendente(fechaClienteCantidad,codigoDelProducto,izq,limite-1);
    ordenarAcendente(fechaClienteCantidad,codigoDelProducto,limite+1,der);
}
void escribirFecha(ofstream &arch,int fecha){
    int dd,mm,aaaa;
    dd=(fecha)%100;
    mm=((fecha-dd)/100)%100;
    aaaa=fecha/10000;

    arch.fill('0');
    arch<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<aaaa;
    arch.fill(' ');
}
void escribirLiena(ofstream &arch,int n,char c){
    for(int i=0;i<n;i++){
        arch<<c;
    }
    arch<<endl;       
}