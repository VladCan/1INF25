#include <iostream>

#include "BibliotecaListaGenerica.hpp"
#include "ListaConEnteros.hpp"

void creaLista(void *&lista, void *(*lee)(ifstream &arch), int(*compara)(void *, void *), const char *filename) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, filename);
    void **lis=new void *[2];
    lis[INI]=nullptr;
    lis[FIN]=nullptr;
    void *dato;
    int d;
    while (true) {
        dato = lee(arch);
        if (dato == nullptr) break;
        insertaLista(lis, dato, compara);
    }
    lista=lis;
}

void uneLista(void *&lista1, void *&lista2) {
    void **lis1=(void **)lista1;
    void **lis2=(void **)lista2;
    void **rec1=(void **)lis1[INI];
    void *anterior1=nullptr;
    void *anterior2=nullptr;
    while(rec){
        void **rec2=(void **)lis2[INI];
        if(*(int *)rec1[DATO]<=*(int *)rec2[DATO]){
            anterior1=rec1[SIG];
            rec1[SIG]=rec2;
            lis2[INI]=rec2[SIG];
            rec2[SIG]=anterior1;
            
        }
    
        
    }
    
}

void imprimeLista(void *lista, void(*imprime)(ofstream &arch, void *), const char *filename) {
}

void insertaLista(void **&lista, void *dato, int(*compara)(void *, void *)) {
    void **nuevoNodo = new void *[2],**anterior=nullptr;
    nuevoNodo[DATO] = dato;
    if (listavacia(lista)) {
        nuevoNodo[SIG] = nullptr;
        lista[INI] = nuevoNodo;
        lista[FIN]=nuevoNodo;
    } else { 
        void **rec =(void**)lista[INI];
        while (rec) {
            if(compara(rec[DATO],dato)==1){
                if(anterior==nullptr){
                    nuevoNodo[SIG]=lista[INI];
                    lista[INI]=nuevoNodo;
                    return;
                }else{
                    nuevoNodo[SIG]=rec;
                    anterior[SIG]=nuevoNodo;
                    return;
                }      
            }
            anterior=rec;
            rec=(void **)rec[SIG];
        }
        nuevoNodo[SIG]=nullptr;
        anterior[SIG]=nuevoNodo;
        lista[FIN]=nuevoNodo;
    }
}

bool listavacia(void **&lista) {
    return lista[INI] == nullptr;
}