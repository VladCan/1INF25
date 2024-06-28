import java.util.Scanner;
class Paciente{
	private int dni;
	private String nombre;
	private String distrito;
	private double tiempoTotal;
	private double gastosTotales;
	private int cantidadDeConsultas;	
	public Paciente(){

	}
	public Paciente(int dni){
		this.dni=dni;
		this.tiempoTotal=0;
		this.gastosTotales=0;
		this.cantidadDeConsultas=0;
	}
	public Paciente(int dni,String nombre,String distrito,
	double tiempoTotal,double gastosTotales,int cantidadDeConsultas){
		this.dni=dni;
		this.nombre=nombre;
		this.distrito=distrito;
		this.tiempoTotal=tiempoTotal;
		this.gastosTotales=gastosTotales;
		this.cantidadDeConsultas=cantidadDeConsultas;
	}
	public void setDni(int dni){
		this.dni=dni;
	}
	public int getDni(){
		return this.dni;
	}
	public void setNombre(String nombre){
		this.nombre=nombre;
	}
	public String getNombre(){
		return this.nombre;
	}
	public void setDistrito(String distrito){
		this.distrito=distrito;
	}
	public String getDistrito(){
		return this.distrito;
	}
	public void setTiempoTotal(double tiempoTotal){
		this.tiempoTotal=tiempoTotal;
	}
	public double getTiempoTotal(){
		return this.tiempoTotal;
	}
	public void setGastosTotales(double gastosTotales){
		this.gastosTotales=gastosTotales;
	}
	public double getGastosTotales(){
		return this.gastosTotales;
	}
	public void setCantidadDeConsultas(int cantidadDeConsultas){
		this.cantidadDeConsultas=cantidadDeConsultas;
	}
	public int getCantidadDeConsultas(){
		return this.cantidadDeConsultas;
	}
	public void leerDatosPaciente(Scanner arch){
		nombre=arch.next();
		distrito=arch.next();
	}
	public void imprimeDatosPaciente(){
		System.out.println("Dni:                   "+dni);
		System.out.println("Nombre:                "+nombre);
		System.out.println("Distrito:              "+distrito);
		System.out.println("Timpro Total:          "+tiempoTotal);
		System.out.println("Gastos Totales:        "+gastosTotales);
		System.out.println("Cantidad de Consultas: "+cantidadDeConsultas);
		System.out.println("----------------------------------------------------");
	}
	
}