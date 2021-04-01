#pragma once
#include "string"

using namespace std;

class Empleado
{
private:
	int codigo;
	string nombre;
	string apellido;
	string categoria;
	int anioIngreso;
	double sueldo;

public:
	static int cuenta;
	Empleado(string nombre , string apellido , string categoria , int anioIng , double sueldo);
	~Empleado();

	int getCodigo();
	string getNombre();
	string getApellido();
	int getAnioIngreso();
	double getSueldo();
	string getCategoria();

	void setCodigo(int codigo);
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setAnioIngreso(int anioIngreso);
	void setSueldo(double sueldo);
	void setCategoria(string categoria);
};

int Empleado::cuenta = 100;

Empleado::Empleado(string nombre, string apellido, string categoria, int anioIng, double sueldo)
{
	this->codigo = cuenta++;
	this->nombre = nombre;
	this->apellido = apellido;
	this->anioIngreso = anioIng;
	this->sueldo = sueldo;
	this->categoria = categoria;
}

Empleado::~Empleado()
{
}

int Empleado::getCodigo() { return this->codigo; };
string Empleado::getNombre() { return this->nombre; };
string Empleado::getApellido() { return this->apellido; };
int Empleado::getAnioIngreso() { return this->anioIngreso; };
double Empleado::getSueldo() { return this->sueldo; };
string Empleado ::getCategoria() { return this->categoria; };

void Empleado::setCodigo(int codigo) { this->codigo = codigo; };
void Empleado::setNombre(string nombre) { this->nombre = nombre; };
void Empleado::setApellido(string apellido) { this->apellido = apellido; };
void Empleado::setAnioIngreso(int anioIngreso) { this->anioIngreso = anioIngreso; };
void Empleado::setSueldo(double sueldo) { this->sueldo = sueldo; };
void Empleado::setCategoria(string categoria) { this->categoria = categoria; };