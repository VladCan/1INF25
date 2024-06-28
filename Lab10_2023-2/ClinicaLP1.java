import java.util.Scanner;
import java.util.ArrayList;
class ClinicaLP1{
	private ArrayList<Medico> medicos;
	private ArrayList<Paciente> pacientes;
	
	public ClinicaLP1(){
		medicos= new ArrayList<Medico>();
		pacientes= new ArrayList<Paciente>();
	}
	public void leerMedicos(Scanner arch){
		int codigo;
		Medico medico;
		while(true){
			codigo = arch.nextInt();
			if(codigo==0) break;
			medico= new Medico(codigo);
			medico.leerDatosMedico(arch);
			medicos.add(medico);
		}
	}
	public void leerPacientes(Scanner arch){
		int dni;
		Paciente paciente;
		while(true){
			dni = arch.nextInt();
			if(dni==0) break;
			paciente= new Paciente(dni);
			paciente.leerDatosPaciente(arch);
			pacientes.add(paciente);
		} 	
	}
	public void actualizar(Scanner arch){
		int codigo;
		int dni;
		int inicio,fin;
		double tiempo,tarifa;
		while(arch.hasNext()){
			dni = arch.nextInt();
			codigo = arch.nextInt();
			inicio=leerHora(arch);
			fin=leerHora(arch);
			tiempo=(fin-inicio)/3600;
			tarifa=actualizarMedico(codigo,tiempo);
			actualizarPaciente(dni,tiempo,tarifa);
		}
	}
	public double actualizarMedico(int codigo,double tiempo){
		double tarifa=0;
		for(Medico m:medicos)
			if(m.getCodigo()==codigo){
				m.setTiempoTotal(m.getTiempoTotal()+tiempo);
				m.setIngresosTotales(m.getIngresosTotales()+m.getTarifa()*tiempo);
				m.setCantidadDeConsultas(m.getCantidadDeConsultas()+1);
				tarifa = m.getTarifa();
				break;
			}
			return tarifa;
	}
	public void actualizarPaciente(int dni,double tiempo,double tarifa){
		for(Paciente p:pacientes)
			if(p.getDni()==dni){
				p.setTiempoTotal(p.getTiempoTotal()+tiempo);
				p.setGastosTotales(p.getGastosTotales()+tarifa*tiempo);
				p.setCantidadDeConsultas(p.getCantidadDeConsultas()+1);
				break;
			}
		
	}
	public int leerHora(Scanner arch){
		int h,m,s;
		h = arch.nextInt();
		m = arch.nextInt();
		s = arch.nextInt();
		return h*3600+m*60+s;
	}
	public void imprimirMedicos(){
		System.out.println("       Lista de Medicos");
		imprimeLinea('=',50);
		for(Medico m:medicos)
			m.imprimeDatosMedico();
	}
	public void imprimirPacientes(){
		System.out.println("       Lista de Pacientes");
		imprimeLinea('=',50);
			for(Paciente p:pacientes)
				p.imprimeDatosPaciente();
	}
	public void imprimeLinea(char c,int n){
		for(int i=0;i<n;i++){
			System.out.print(c);
		}
		System.out.println();
	}
}
	