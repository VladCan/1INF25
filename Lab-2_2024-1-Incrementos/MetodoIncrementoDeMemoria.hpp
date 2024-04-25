

/* 
 * File:   MetodoIncrementoDeMemoria.hpp
 * Author: VLADYMIR
 *
 * Created on 18 de abril de 2024, 16:51
 */

#ifndef METODOINCREMENTODEMEMORIA_HPP
#define METODOINCREMENTODEMEMORIA_HPP


void lecturaDeLibros(const char *filename,char ***&libros,int **&stock);
void pruebaDeLecturaDeLibros(const char *filename,char *** libros,int ** stock);
void atencionDePedidos(const char *filename, char ***&libros,int **& stock, int **&pedidosClientes,char***& pedidosLibros,bool**&pedidosAtendidos);
void pruebaDeLecturaDeLibros(const char *filename,char *** libros, int **stock);
void reporteDeEntregaDePedidos(const char *filename,int ** pedidosClientes, char ***pedidosLibros,bool ** pedidosAtendidos);

#endif /* METODOINCREMENTODEMEMORIA_HPP */

