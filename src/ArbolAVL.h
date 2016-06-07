#ifndef ARBOLAVL_H_
#define ARBOLAVL_H_
#include "Registro.h"
#include <list>

using namespace std;

class Nodo;

#include "Nodo.h"
class ArbolAVL {
private:
	static const int idRaiz = 0;
	Nodo* raiz;
	string nombre;

	Nodo* cargarRaiz(string nombre);
public:
	ArbolAVL(string nombre);

	void insertar(Registro* unRegistro);
	void borrarRegistro(int unID);
	void print();
	Nodo* getRaiz();
	Nodo* buscarNodoPorID(Nodo* unNodo, int idBuscado);
	Nodo* borrarRegistroPorID(Nodo* unNodo, int idBuscado);
	virtual ~ArbolAVL();

private:
	Nodo* insertarEnNodo(Nodo* unNodo, Registro* unRegistro);
	Nodo* crearNodo(Registro* unRegistro);
	Nodo* rotacionDerecha(Nodo *unNodo);
	Nodo* rotacionIzquierda(Nodo *unNodo);
	int getDiferenciaAlturaHijos(Nodo* unNodo);
	void preOrder(Nodo* root);
	void balancear(Nodo* unNodo);

};

#endif /* ARBOLAVL_H */
