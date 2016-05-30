/*
 * Nodo.cpp
 *
 *  Created on: 26 de may. de 2016
 *      Author: desuque
 */

#include "Nodo.h"

using namespace std;

Nodo::Nodo() {
	//NULL no es estandar papa, 0 es null.
	this->izquierdo = 0;
	this->derecho = 0;
	this->cantidadDeElementos = 0;
	this->registros = new list<Registro*>;
	this->altura = 1;

	//Esto es para la persistencia, 8===D
	this->bytes_libres = 3000;
}

list<Registro*>* Nodo::getRegistros() {
	return registros;
}

int Nodo::getMenorID() {
	Registro* regTmp = registros->front();
	return regTmp->id;
}

int Nodo::getMayorID() {
	Registro* regTmp = registros->back();
	return regTmp->id;
}

Nodo* Nodo::getHijoIzquierdo() {
	return this->izquierdo;
}

Nodo* Nodo::getHijoDerecho() {
	return this->derecho;
}

int Nodo::getAltura() {
	return this->altura;
}

void Nodo::modificarHijoIzquierdo(Nodo* nuevoNodo) {
	this->izquierdo = nuevoNodo;
}

void Nodo::modificarHijoDerecho(Nodo* nuevoNodo) {
	this->derecho = nuevoNodo;
}

void Nodo::modificarAltura(int nuevaAltura) {
	this->altura = nuevaAltura;
}

bool comparaRegistros(Registro* a, Registro* b) { return a->id < b->id; }


bool Nodo::insertar(Registro* unRegistro) {
	//TODO probablemente no sea con el tamaño de la lista, sino
	//con la cantidad de bytes_libres

	if (cantidadDeElementos < this->maxElementos) {
		registros->push_front(unRegistro);
		cantidadDeElementos++;
		registros->sort(comparaRegistros);
		return true;
	}
	return false;
}

bool Nodo::borrarRegistro(int ID) {
	bool encontrado = false;
	Registro* unRegistro;

	for(list<Registro*>::iterator list_iter = registros->begin(); list_iter != registros->end(); list_iter++) {
		unRegistro = *list_iter;
		if (unRegistro->id == ID) {
			registros->remove(unRegistro);
			encontrado = true;
			cantidadDeElementos--;
			break;
		}
	}

	return encontrado;
}

bool Nodo::buscarID(int idBuscado) {
	bool encontrado = false;
	Registro* unRegistro;

	for(list<Registro*>::iterator list_iter = registros->begin(); list_iter != registros->end(); list_iter++) {
		unRegistro = *list_iter;
		if (unRegistro->id == idBuscado) {
			encontrado = true;
			break;
		}
	}
	return encontrado;
}

Registro* Nodo::getRegistroConMayorID() {
	return registros->back();
}

Registro* Nodo::getRegistroConMenorID() {
	return registros->front();
}

int Nodo::getCantidadDeRegistros() {
	return cantidadDeElementos;
}

Nodo::~Nodo() {
	//TODO Como es una lista de punteros que pidieron memoria, hay que recorrer la lista y borrarlos de a uno
	delete registros;
}

