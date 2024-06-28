import java.util.Scanner;
class Principal{
	public static void main(String [] args){
		ClinicaLP1 clinica=new ClinicaLP1();
		Scanner arch = new Scanner(System.in);		
		clinica.leerMedicos(arch);
		clinica.leerPacientes(arch);
		clinica.actualizar(arch);
		clinica.imprimirMedicos();
		clinica.imprimirPacientes();
	}
	
}