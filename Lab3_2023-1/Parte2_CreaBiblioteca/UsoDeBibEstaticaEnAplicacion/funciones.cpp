#include "funciones.hpp"

using namespace std;

void leerCursos(StCurso *arrCursos) {
    ifstream archCursos;
    StCurso curso;
    AperturaDeUnArchivoDeTextosParaLeer(archCursos, "Cursos.txt");
    while (true) {
        if (archCursos >> curso) {
            arrCursos += curso;
        } else {
            break;
        }

    }

}

void leerAlumnos(StAlumno *arrAlumnos) {
    ifstream archAlumnos;
    StAlumno alumno;
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos, "Alumnos.txt");
    while (true) {
        if (archAlumnos >> alumno) {
            arrAlumnos += alumno;
        } else {
            break;
        }
    }

}

void leerMatriculaYcompletar(StCurso *arrCursos, StAlumno *arrAlumnos) {
    ifstream archMatricula;
    StRegistroDeMatricula matricula;
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula, "Matricula.txt");
    while (true) {
        if (archMatricula >> matricula) {
            arrAlumnos *= matricula;
            arrCursos *= matricula;
        } else {
            break;
        }
    }
}

void calculoDeCostos(StCurso *arrCursos, StAlumno *arrAlumnos) {
    ifstream archEscala;
    AperturaDeUnArchivoDeTextosParaLeer(archEscala, "Escalas.txt");
    int i = 0, posAlum;
    double precioEscala;
    while (true) {
        if (strcmp(arrCursos[i].codigoDelCurso, "XXXXXX")) {
            for (int j = 0; j < arrCursos[i].numeroDeAlumnos; j++) {
                posAlum = buscarAlumno(arrAlumnos, arrCursos[i].alumnos[j]);
                if (posAlum != -1) {
                    precioEscala = buscarEscala(archEscala, arrAlumnos[posAlum].escala);
                    arrAlumnos[posAlum].costoTotal += precioEscala * arrCursos[i].creditos;
                    arrCursos[i].ingresos += precioEscala * arrCursos[i].creditos;
                }


            }
            i++;
        } else {
            break;
        }
    }

}

int buscarAlumno(StAlumno *arrAlum, int codigo) {
    int i = 0, codAlum;
    while (arrAlum[i].semestre) {
        codAlum = arrAlum[i].codigo + arrAlum[i].semestre * 10000;
        if (codAlum == codigo) {
            return i;
        }
        i++;
    }
    return -1;
}

double buscarEscala(ifstream &archEscala, int escala) {
    int e;
    double precio;
    while (true) {
        archEscala.get();
        if (archEscala.eof()) {
            archEscala.seekg(0);
            return 0;
        }
        archEscala >> e >> precio>>ws;
        if (e == escala) {
            archEscala.seekg(0);
            return precio;
        }
    }
}

void emitirReporte(ofstream &arch, StCurso *arrCursos, StAlumno *arrAlumnos) {
    arch << setw(50) << "Reporte de Alumnos" << endl;
    escribirLinea(arch, 100, '=');
    escribirLinea(arch, 100, '-');
    int i = 0;
    while (arrAlumnos[i].semestre) {
        arch << arrAlumnos[i];
        escribirLinea(arch, 100, '-');
        i++;
    }
    escribirLinea(arch, 100, '=');

    arch << setw(50) << "Reporte de Cursos" << endl;
    escribirLinea(arch, 100, '=');
    i = 0;
    while (strcmp(arrCursos[i].codigoDelCurso,"XXXXXX")) {
        arch << arrCursos[i];
        escribirLinea(arch, 100, '-');
        i++;
    }



}

void escribirLinea(ofstream &arch, int n, char c) {
    for (int i = 0; i < n; i++) {
        arch << c;
    }
    arch << endl;
}