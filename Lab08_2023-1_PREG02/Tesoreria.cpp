#include "Tesoreria.hpp"

Tesoreria::Tesoreria() {

}

void Tesoreria::cargaescalas() {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "escalas.csv");
    int escala, i = 0;
    double precio;
    while (true) {
        arch>>escala;
        if (arch.eof()) break;
        arch.get();
        arch>>precio;
        lescala[i].SetCodigo(escala);
        lescala[i].SetPrecio(precio);
        i++;
    }
}

void Tesoreria::cargaalumnos() {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Alumnos.csv");
    char modalidad;
    int n_P = 0, n_S = 0, n_V = 0;
    while (true) {
        modalidad = arch.get();
        if (arch.eof()) break;
        arch.get();
        if (modalidad == 'P') {
            Presencial p;
            arch>>p;
            lpresencial[n_P] = p;
            n_P++;
        } else if (modalidad == 'S') {
            Semipresencial s;
            arch>>s;
            lsemipresencial[n_S] = s;
            n_S++;
        } else if (modalidad == 'V') {
            Virtual v;
            arch>>v;
            lvirtual[n_V] = v;
            n_V++;
        }

    }
}

void Tesoreria::actualiza(double creditos) {
    double precio;
    int escala;
    for (int p = 0; lpresencial[p].GetCodigo() != 0; p++) {
        //lpresencial[p].actualizar(buscarPrecioEscala(lpresencial[p].GetEscala()));
        escala = lpresencial[p].GetEscala();
        precio = buscarPrecioEscala(escala);
        lpresencial[p].actualizar(precio*creditos);
    }
    for (int s = 0; lsemipresencial[s].GetCodigo() != 0; s++) {
        escala = lsemipresencial[s].GetEscala();
        precio = buscarPrecioEscala(escala);
        lsemipresencial[s].actualizar(precio*creditos);
    }
    for (int v = 0; lvirtual[v].GetCodigo() != 0; v++) {
        escala = lvirtual[v].GetEscala();
        precio = buscarPrecioEscala(escala);
        lvirtual[v].actualizar(precio*creditos);
    }
}

void Tesoreria::imprime() {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,"ReorteAlumnos.txt");
    arch<<setw(50-10)<<"Reporte de Alumnos"<<endl;
    ecribirLinea(arch,100,'=');
    arch<<"Codigo"<<setw(15)<<"Nombre"<<setw(45)<<"Escala"<<setw(16)<<"Licencia"<<setw(15)<<"Total"<<endl;
    ecribirLinea(arch,100,'=');
    for(int v=0;lvirtual[v].GetCodigo()!=0;v++){
        arch<<lvirtual[v];
    }
    for(int p=0;lpresencial[p].GetCodigo()!=0;p++){
        arch<<lpresencial[p];
    }
    for(int s=0;lsemipresencial[s].GetCodigo()!=0;s++){
        arch<<lsemipresencial[s];
    }
    
}

double Tesoreria::buscarPrecioEscala(int escala) {
    for (int i = 0; lescala[i].GetCodigo() != 0; i++) {
        if (lescala[i].GetCodigo() == escala) return lescala[i].GetPrecio();
    }
        return -1;
}
void ecribirLinea(ofstream &arch,int n,char c){
    for(int i=0;i<n;i++){
        arch<<c;
    }
    arch<<endl;
}

