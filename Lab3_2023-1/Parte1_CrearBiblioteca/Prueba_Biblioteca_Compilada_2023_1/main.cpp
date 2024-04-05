
/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 4 de abril de 2024, 11:10
 */

#include "Sobrecarga.hpp"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;


int main(int argc, char** argv) {
    ifstream archCursos,archAlumnos,archMatricula;
    ofstream archReporteCursos,archReporteAlumnos;
    AperturaDeUnArchivoDeTextosParaLeer(archCursos, "Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos, "Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula, "Matricula.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteCursos,"ReporteCursos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteAlumnos,"ReporteAlumnos.txt");
    
    StCurso curso,arrCursos[20];
    StAlumno alumno,alumno2,arrAlunos[20]{};
    StRegistroDeMatricula matricula,matPrueba;
    archCursos>>curso;
    
    archAlumnos>>alumno;
    
    archAlumnos>>alumno2;
    
    archMatricula>>matricula;
    //Inicializa el arreglo de cursos
    
    strcpy(arrCursos[0].codigoDelCurso,"XXXXXX");
    arrCursos+=curso;
    arrAlunos+=alumno;
    arrAlunos+=alumno2;
    
   strcpy(matPrueba.codigoDelCurso,"INF263");
   matPrueba.codigodelAlumno=1260;
   matPrueba.semestreDelAlumno=20211;

    
    arrCursos*=matricula;
    arrAlunos*=matricula;
    arrAlunos*=matPrueba;
    archReporteCursos<<arrCursos[0];
    
    archReporteAlumnos<<arrAlunos[0];
    
    cout<<curso.nombreDelProfesor<<endl;
    cout<<curso.nombreDelCurso<<" "<<curso.creditos<<"  "<<curso.codigoDelCurso<<endl;
    
    cout<<arrAlunos[0].codigo<<" "<<arrAlunos[0].semestre<<" "<<arrAlunos[0].nombre<<" "<<arrAlunos[0].escala<<" "<<arrAlunos[0].modalidad<<endl;
    
    
    cout<<arrAlunos[0].codigo<<" "<<arrAlunos[1].semestre<<" "<<arrAlunos[1].nombre<<" "<<arrAlunos[1].escala<<" "<<arrAlunos[1].porcentaje<<" "<<arrAlunos[1].modalidad<<endl;
    
    cout<<matricula.codigoDelCurso<<" "<<matricula.codigodelAlumno<<" "<<matricula.semestreDelAlumno<<endl;
    return 0;
}

