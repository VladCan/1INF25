/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.hpp
 * Author: VLADYMIR
 *
 * Created on 2 de mayo de 2024, 15:23
 */

#ifndef BIBLIOTECALISTAGENERICA_HPP
#define BIBLIOTECALISTAGENERICA_HPP
#include "Utils.hpp"
enum LISTA{INI,FIN};
    void creaLista(void *&lista, void *(*lee)(ifstream &arch), int(*compara)(void *,void *), const char *filename);
    void uneLista(void *&lista1,void *&lista2);
    void imprimeLista(void *lista, void(*imprime)(ofstream &arch,void *), const char *filename);
    void insertaLista(void **&lista,void *dato,int(*compara)(void *, void *));
    bool listavacia(void **&lista);
    
    //, , listavacia, uneLista e imprimeLista.
#endif /* BIBLIOTECALISTAGENERICA_HPP */

