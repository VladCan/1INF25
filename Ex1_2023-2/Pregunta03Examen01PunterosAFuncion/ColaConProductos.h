
/* 
 * File:   ColaConProductos.h
 * Author: alulab14
 *
 * Created on 10 de mayo de 2024, 09:22 AM
 */

#ifndef COLACONPRODUCTOS_H
#define COLACONPRODUCTOS_H
#include "ColaGenerica.h"


void procesarPedidos(int **fechaClienteCantidad, char **codigoDelProducto, void *&productos);
void reporteDePedidos(void *productos, const char *filename);
int buscarProducto(void *&p, char *codigo);
bool verificarAtencion(void *dato,void *&producto);
void mostrarPedidosAceptados(void *&cola,ofstream &arch);
#endif /* COLACONPRODUCTOS_H */

