/*
 * Nodo.cpp
 *
 *  Created on: 26 de may. de 2016
 *      Author: desuque
 */

#include "Nodo.h"

using namespace std;

Nodo::Nodo(string nombreArchivo) {
	this->izquierdo = 0;
	this->derecho = 0;
	this->registros = new list<Registro*>;
	this->altura = 1;
	this->nombreArchivo = nombreArchivo;
	bloque = 0;
}

Nodo::Nodo(string nombreArchivo, int idBloque) {
	bloque = new Bloque(nombreArchivo, idBloque);
	Nodo* unNodo = bloque->devolverNodo();

	if (unNodo != 0) {
		this->izquierdo = unNodo->getHijoIzquierdo();
		this->derecho = unNodo->getHijoDerecho();
		this->registros = unNodo->getRegistros();
		this->altura = unNodo->getAltura();
	} else {
		this->izquierdo = 0;
		this->derecho = 0;
		this->registros = 0;
		this->altura = 1;
	}
}

list<Registro*>* Nodo::getRegistros() {
	return registros;
}

int Nodo::getTamanio() {
	Registro* unRegistro;
	int tamanio = 0;

	for(list<Registro*>::iterator list_iter = registros->begin(); list_iter != registros->end(); list_iter++) {
		unRegistro = *list_iter;
		tamanio += unRegistro->getTamanio();
	}

	return tamanio;
}

int Nodo::getMenorID() {
	Registro* regTmp = registros->front();
	return regTmp->getId();
}

int Nodo::getMayorID() {
	Registro* regTmp = registros->back();
	return regTmp->getId();
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

bool comparaRegistros(Registro* a, Registro* b) { return a->getId() < b->getId(); }


bool Nodo::insertar(Registro* unRegistro) {
	if (bloque == 0) {
		bloque = new Bloque(nombreArchivo);
	}
	if (bloque->entra(unRegistro)) {

		registros->push_back(unRegistro);
		registros->sort(comparaRegistros);
		bloque->grabar(this);

		return true;
	} else {

		return false;
	}
}

bool Nodo::estaEnUnderflow() {

	//TODO:
	// return bloque->estaEnUnderflow();
}

bool Nodo::esHoja() {

	return this->altura == 1;
}

bool Nodo::borrarRegistro(int ID) {
	bool encontrado = false;
	Registro* unRegistro;

	for(list<Registro*>::iterator list_iter = registros->begin(); list_iter != registros->end(); list_iter++) {
		unRegistro = *list_iter;
		if (unRegistro->getId() == ID) {
			registros->remove(unRegistro);
			encontrado = true;
			break;
		}
	}

	return encontrado;
}

bool Nodo::existeRegistroConID(int idBuscado) {
	bool encontrado = false;
	Registro* unRegistro;

	for(list<Registro*>::iterator list_iter = registros->begin(); list_iter != registros->end(); list_iter++) {
		unRegistro = *list_iter;
		if (unRegistro->getId() == idBuscado) {
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

Nodo::~Nodo() {
	//TODO Como es una lista de punteros que pidieron memoria, hay que recorrer la lista y borrarlos de a uno
	delete registros;
}

