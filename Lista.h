#ifndef TRABAJOPRACTICO3FIGURAS_LISTA_H
#define TRABAJOPRACTICO3FIGURAS_LISTA_H

#include "Nodo.h"

template <typename Tipo>
class Lista {

    // Atributos
    private:
        Nodo<Tipo>* primero;
        int elementos;

    // Metodos
    public:

        // PRE: -
        // POST: Crea una lista con 0 elementos
        Lista();

        //Lista(const Lista<Tipo> &lista);

        // PRE: La lista debe estar creada
        // POST: Libera la memoria que ocupaba la lista
        ~Lista();

        // PRE: La lista debe estar creada y ser distinta de vacia, 0 < posicion <= elementos
        // POST: Devuelve el dato de la posicion recibida por parametro
        Tipo obtenerDato(int posicion);

        // PRE: -
        // POST: Devuelve la cantidad de elementos
        int obtenerCantidadElementos();

        // PRE: datoExterno debe ser valido, y 0 < posicion <= elementos
        // POST: Agrega el dato recibido como parametro en la posicion recibida como parametro
        void agregarEnPosicion(Tipo datoExterno, int posicionExterno);

        // PRE: datoExterno debe ser valido
        // POST: Agrega el dato recibido como parametro al final de la lista
        void agregarAlFinal(Tipo datoExterno);

        // PRE: datoExterno debe ser valido
        // POST: Agrega el dato recibido como parametro al principio de la lista
        void agregarAlPrincipio(Tipo datoExterno);

        // PRE: La lista debe estar creada y ser distinta de vacía
        // POST: Saca el elemento de la posicion recibida como parametro de la lista
        void sacar(int posicion);

        // PRE: -
        // POST: Devuelve true si la lista esta vacia, de lo contrario false
        bool vacia();

        // PRE: -
        // POST: Muestra por pantalla los datos de todos los nodos
        void mostrarDatosNodos();

    private:
        // PRE: 0 < posicion <= elementos
        // POST: Devuelve un puntero de tipo nodo correspondiente con la posicion
        Nodo<Tipo>* obtenerNodo(int posicion);

        //void copiarDatos(Lista<Tipo>* lista, int inicio, int final);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename Tipo>
Lista<Tipo>:: Lista () {
    primero = 0;
    elementos = 0;
}
/*
template<typename Tipo>
Lista<Tipo>:: Lista(const Lista<Tipo> &lista) {
    elementos = lista.elementos;
    if (elementos > 0) {
        lista.copiarDatos(lista, 0, elementos);
    }
}
*/
template <typename Tipo>
Lista<Tipo>:: ~Lista() {
    while (!vacia())
        sacar(0);
}

// <-------------------- Obtenciones
template <typename Tipo>
Tipo Lista<Tipo>:: obtenerDato(int posicion) {
    return obtenerNodo(posicion)->obtenerDato();
}

template <typename Tipo>
int Lista<Tipo>:: obtenerCantidadElementos() {
    return elementos;
}

template <typename Tipo>
Nodo<Tipo>* Lista<Tipo>:: obtenerNodo(int posicion) {
    Nodo<Tipo>* aux = primero;
    int i = 0;
    while (i < posicion) {
        aux = aux->obtenerSiguiente();
        i++;
    }
    return aux;
}
// -------------------->

template <typename Tipo>
bool Lista<Tipo>:: vacia() {
    return primero == 0;
}

template <typename Tipo>
void Lista<Tipo>:: agregarAlFinal(Tipo datoExterno) {
    if (elementos == 0)
        agregarEnPosicion(datoExterno, elementos);
    else
        agregarEnPosicion(datoExterno, elementos - 1);
}

template <typename Tipo>
void Lista<Tipo>:: agregarAlPrincipio(Tipo datoExterno) {
    agregarEnPosicion(datoExterno, 0);
}

template <typename Tipo>
void Lista<Tipo>:: agregarEnPosicion(Tipo datoExterno, int posicion) {
    Nodo<Tipo>* nuevoNodo = new Nodo<Tipo>(datoExterno);

    if (posicion == 0) {
        nuevoNodo->asignarSiguiente(primero);
        primero = nuevoNodo;
    }
    else {
        Nodo<Tipo>* anterior = obtenerNodo(posicion - 1);
        nuevoNodo->asignarSiguiente(anterior->obtenerSiguiente());
        anterior->asignarSiguiente(nuevoNodo);
    }
    elementos++;
}

template <typename Tipo>
void Lista<Tipo>:: sacar(int posicion) {
    Nodo<Tipo>* borrar = primero;

    if (posicion == 0) {
        primero = borrar->obtenerSiguiente();
    }

    else {
        Nodo<Tipo>* anterior = obtenerNodo(posicion - 1);
        borrar = anterior->obtenerSiguiente();
        anterior->asignarSiguiente(borrar->obtenerSiguiente());
    }
    delete borrar;
    elementos--;
}
/*
template <typename Tipo>
void Lista<Tipo>:: copiarDatos(Lista<Tipo>* lista, int inicio, int final) {
    if (elementos > 0) {
        for (int i = inicio; i < final; i++)
            agregarEnPosicion(lista->obtenerDato(i), i);
    }
}
*/
template <typename Tipo>
void Lista<Tipo>:: mostrarDatosNodos() {
    if (!vacia()) {
        for (int i = 0; i < elementos; i++) {
            obtenerNodo(i)->mostrarNodo();
        }
    }
}
#endif //TRABAJOPRACTICO3FIGURAS_LISTA_H