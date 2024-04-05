#include "Sobrecarga.hpp"
#include "Estructuras.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>


using namespace std;

bool operator>>(ifstream &arch, StCurso &Curso) {

    char buffer[7];
    char nomCur[100];
    double cred;
    int codigoProf;
    char nomProf[100];
    arch.getline(buffer, 7, ' ');
    if (arch.eof()) {
        return false;
    }
    arch>>ws;
    arch.getline(nomCur, 100, ' ');
    arch >> cred >> codigoProf>>ws;
    arch.getline(nomProf, 100);

    strcpy(Curso.codigoDelCurso, buffer);
    strcpy(Curso.nombreDelCurso, nomCur);
    Curso.creditos = cred;
    Curso.codigoDelProfesor = codigoProf;
    strcpy(Curso.nombreDelProfesor, nomProf);
    Curso.numeroDeAlumnos = 0;
    Curso.ingresos = 0;
    return true;

}

bool operator>>(ifstream &arch, StAlumno &Alum) {
    char buffer[50];
    char c;
    arch >> Alum.semestre;
    if (arch.eof()) {
        return false;
    };
    arch.get();
    arch >> Alum.codigo>>ws;
    arch.getline(buffer, 50, ' ');
    arch>>ws;
    c = arch.get();
    if (c == 'G') {
        strcpy(Alum.modalidad, "Presencial");
        arch >> Alum.escala;
    } else {

        if (c == 'S') {
            strcpy(Alum.modalidad, "Semi Presencial");
            arch >> Alum.porcentaje>>ws;
            arch.get();
            arch >> ws >> Alum.escala;
        }

        if (c == 'V') {
            strcpy(Alum.modalidad, "Virtual");
            arch>>ws;
            arch.get();
            arch >> Alum.escala;
        }
    }
    strcpy(Alum.nombre, buffer);
    Alum.numeroDeCursos = 0;
    Alum.costoTotal = 0;
    return true;

}

bool operator>>(ifstream &arch, StRegistroDeMatricula &Matri) {
    char buffer[7];
    int semestre;
    int codigo;
    arch.getline(buffer, 7, ' ');
    arch>>semestre;
    if (arch.eof()) {
        return false;
    }
    arch.get();
    arch>>codigo>>ws;

    strcpy(Matri.codigoDelCurso, buffer);
    Matri.codigodelAlumno = codigo;

    Matri.semestreDelAlumno = semestre;

    return true;
}

void operator+=(StCurso *arr, const StCurso Cur) {

    int i = 0;
    while (true) {
        if (!strcmp(arr[i].codigoDelCurso, "XXXXXX")) {
            arr[i] = Cur;
            strcpy(arr[i + 1].codigoDelCurso, "XXXXXX");
            break;
        }
        i++;

    }
}

void operator+=(StAlumno *arr, const StAlumno Alun) {
    int i = 0;
    while (true) {
        if (arr[i].semestre == 0) {
            arr[i] = Alun;
            arr[i + 1].semestre = 0;
            break;
        }
        i++;
    }
}

void operator*=(StCurso *arr, const StRegistroDeMatricula Matri) {
    int i = 0;
    while (true) {
        if (!strcmp(arr[i].codigoDelCurso, "XXXXXX")) break;
        if (!strcmp(arr[i].codigoDelCurso, Matri.codigoDelCurso)) {
            arr[i].alumnos[arr[i].numeroDeAlumnos] = Matri.semestreDelAlumno * 10000 + Matri.codigodelAlumno;
            arr[i].numeroDeAlumnos++;
            return;
        }
        i++;
    }
}

void operator*=(StAlumno *arr, const StRegistroDeMatricula Matri) {
    int i = 0;
    while (arr[i].semestre != 0) {
        if (arr[i].codigo == Matri.codigodelAlumno and arr[i].semestre == Matri.semestreDelAlumno) {
            char *cur = new char [strlen(Matri.codigoDelCurso) + 1];
            strcpy(cur, Matri.codigoDelCurso);
            arr[i].cursos[arr[i].numeroDeCursos] = cur;
            arr[i].numeroDeCursos++;
            return;
        }
        i++;
    }

}

ofstream &operator<<(ofstream & arch, const StCurso Curso) {
    arch << "CODIGO" << setw(11) << "NOMBRE" << setw(15) << "CREDITOS" << endl;
    arch << Curso.codigoDelCurso << setw(5 + strlen(Curso.nombreDelCurso)) << Curso.nombreDelCurso << setw(15) << Curso.creditos << endl;
    arch << "PROFESOR: " << Curso.nombreDelProfesor << setw(50 - strlen(Curso.nombreDelProfesor)) << "[" << Curso.codigoDelProfesor << "]" << endl;
    arch << "Alumnos matriculados:" << endl;
    arch << "Semestre" << setw(15) << "Codigo" << endl;
    for (int i = 0; i < Curso.numeroDeAlumnos; i++) {
        arch << Curso.alumnos[i] / 10000 << setw(10) << Curso.alumnos[i] % 10000 << endl;
    }
    arch << "Numero de Alumnos: " << Curso.numeroDeAlumnos << endl;
    arch << "Total ingresados: " << Curso.ingresos<<endl;

}

ofstream &operator<<(ofstream & arch, const StAlumno Alum) {
    arch << "SEMESTRE" << setw(14) << "CODIGO" << setw(12) << "NOMBRE" << setw(28) << "MODAIDAD" << setw(15) << "ESCALA" << endl;
    arch << Alum.semestre << setw(15) << Alum.codigo << setw(50 - strlen(Alum.nombre)) << Alum.nombre << setw(15) << Alum.modalidad;
    if (Alum.porcentaje != 0) {
        arch << "COM " << Alum.porcentaje << "%" << setw(15) << Alum.escala << endl;

    } else {
        arch << setw(18) << Alum.escala << endl;
    }
    arch << "Codigos de cursos matriculados:" << endl;
    for (int i = 0; i < Alum.numeroDeCursos; i++) {
        arch << setw(10) << Alum.cursos[i] << endl;
    }
    arch << "Numero de cursos: " << Alum.numeroDeCursos << endl;
    arch << "Costo Total: " << Alum.costoTotal << endl;
}
