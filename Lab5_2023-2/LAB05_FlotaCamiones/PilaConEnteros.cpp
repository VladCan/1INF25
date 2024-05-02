#include "FlotaGenerica.hpp"
#include "PilaConEnteros.hpp"

void *leenumero(ifstream &arch) {
    double *num = new double;
    arch>>*num;
    if (arch.eof()) return nullptr;
    return num;
}

double calculanumero(void *valor) {
    double *val = new double;
    val = (double *) valor;
    return *val;
}

void imprimenumero(ofstream&arch, void *dato) {
    double *num;
    num = (double *) dato;
    arch <<setw(10)<<*num << endl;

}

int cmpnumero(const void *a, const void *b) {
    void **IA = (void **) a;
    void **IB = (void **) b;
    void **camionA = (void **) *IA;
    void **camionB = (void **) *IB;
    double *TotalA = (double *) camionA[TOTAL];
    double *TotalB = (double *) camionB[TOTAL];
    return *TotalB - *TotalA;
}

