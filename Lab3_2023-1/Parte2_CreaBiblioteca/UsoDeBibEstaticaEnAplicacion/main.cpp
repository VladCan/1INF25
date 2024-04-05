/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 4 de abril de 2024, 15:11
 */


#include "funciones.hpp"

using namespace std;
int main(int argc, char** argv) {

    StCurso arrCursos[15];
    StAlumno arrAlumnos[100];
    //Inicializar arreglo
    strcpy(arrCursos[0].codigoDelCurso, "XXXXXX");
    arrAlumnos[0].semestre=0;
    leerCursos(arrCursos);
    leerAlumnos(arrAlumnos);
    leerMatriculaYcompletar(arrCursos,arrAlumnos);
    calculoDeCostos(arrCursos,arrAlumnos);
    ofstream Reporte; 
    AperturaDeUnArchivoDeTextosParaEscribir(Reporte,"Reporte.txt");
    emitirReporte(Reporte,arrCursos,arrAlumnos);
    
    
    return 0;
}

