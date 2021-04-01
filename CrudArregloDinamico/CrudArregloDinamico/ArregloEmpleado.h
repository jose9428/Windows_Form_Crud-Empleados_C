#pragma once
#include "Empleado.h"

class ArregloEmpleado
{
private:
	Empleado** arreglo;
	int num;

public:
	ArregloEmpleado();
	~ArregloEmpleado();
	void Agregar(Empleado *e);
	void Actualizar(Empleado *e , int indice);
	void Eliminar(int indice);
	int getNum();
	Empleado* Obtener(int indice);
};

ArregloEmpleado::ArregloEmpleado()
{
	num = 0;
	arreglo = new Empleado * [num];

	Agregar(new Empleado("Juan Carlos" , "Rodriguez" ,"A", 2000 , 3500));
	Agregar(new Empleado("Carla", "Salvatierra","C" ,2012, 2850));
	Agregar(new Empleado("Manuel", "Quispe Guevara","B", 2018, 2100));
}

ArregloEmpleado::~ArregloEmpleado()
{
}

void ArregloEmpleado::Agregar(Empleado* e) {
	Empleado** aux = new Empleado * [num+1];

	for (int i = 0; i < num;i++) {
		aux[i] = arreglo[i];
	}

	aux[num] = e;
	num++;

	if (arreglo != nullptr) {
		delete arreglo;
	}

	arreglo = aux;

}

void ArregloEmpleado::Actualizar(Empleado* e , int indice) {
	Empleado* aux = Obtener(indice);

	e->setCodigo(aux->getCodigo());

	arreglo[indice] = e;
}

void ArregloEmpleado::Eliminar(int indice) {
	Empleado** aux = new Empleado * [num - 1];

	 delete arreglo[indice];

	for (int i = 0; i < num - 1;i++) {
		if (i < indice) {
			aux[i] = arreglo[i];
		}
		else {
			aux[i] = arreglo[i + 1];
		}
	}

	if (arreglo != nullptr) {
		delete arreglo;
	}

	num--;
	arreglo = aux;
}

int ArregloEmpleado::getNum() {
	return this->num;
}

Empleado* ArregloEmpleado::Obtener(int indice) {
	return arreglo[indice];
}