import java.util.Scanner;
class Medico{
	private int codigo;
	private String nombre;
	private String especialidad;
	private double tarifa;
	private double tiempoTotal;
	private double ingresosTotales;
	private int cantidadDeConsultas;	
	public Medico(){

	}
	public Medico(int codigo){
		this.codigo=codigo;
		this.tiempoTotal=0;
		this.ingresosTotales=0;
		this.cantidadDeConsultas=0;
	}
	
	public Medico(int codigo,String nombre,String especialidad,double tarifa,
	double tiempoTotal,double ingresosTotales,int cantidadDeConsultas){
		this.codigo=codigo;
		this.nombre=nombre;
		this.especialidad=especialidad;
		this.tarifa=tarifa;
		this.tiempoTotal=tiempoTotal;
		this.ingresosTotales=ingresosTotales;
		this.cantidadDeConsultas=cantidadDeConsultas;
	}
	
	public void setCodigo(int codigo){
		this.codigo=codigo;
	}
	public int getCodigo(){
		return this.codigo;
	}
	public void setNombre(String nombre){
		this.nombre=nombre;
	}
	public String getNombre(){
		return this.nombre;
	}
	public void setEspecialidad(String especialidad){
		this.especialidad=especialidad;
	}
	public String getEspecialidad(){
		return this.especialidad;
	}
	public void setTarifa(double tarifa){
		this.tarifa=tarifa;
	}
	public double getTarifa(){
		return this.tarifa;
	}
	public void setTiempoTotal(double tiempoTotal){
		this.tiempoTotal=tiempoTotal;
	}
	public double getTiempoTotal(){
		return this.tiempoTotal;
	}
	public void setIngresosTotales(double ingresosTotales){
		this.ingresosTotales=ingresosTotales;
	}
	
	public double getIngresosTotales(){
		return this.ingresosTotales;
	}
	public void setCantidadDeConsultas(int cantidadDeConsultas){
		this.cantidadDeConsultas=cantidadDeConsultas;
	}
	public int getCantidadDeConsultas(){
		return this.cantidadDeConsultas;
	}
	public void leerDatosMedico(Scanner arch){
		double a;
		double b;
		nombre=arch.next();
		especialidad=arch.next();
		a=arch.nextDouble();
		b=arch.nextDouble();
		tarifa=a+b/100;
	}
	public void imprimeDatosMedico(){
		System.out.println("Codigo:                "+codigo);
		System.out.println("Nombre:                "+nombre);
		System.out.println("Especialidad:          "+especialidad);
		System.out.println("Timpro Total:          "+tiempoTotal);
		System.out.println("Ingresos Totales:      "+ingresosTotales);
		System.out.println("Cantidad de Consultas: "+cantidadDeConsultas);
		System.out.println("----------------------------------------------------");
	}
}