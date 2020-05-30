//
// Created by valentina on 29/5/20.
//

#include "Menu.h"
#include "Lista.h"
#include <iostream>

using namespace std;

const int OBTENER_FIGURA = 1;
const int BAJA = 2;
const int ALTA = 3;
const int MOSTRAR = 4;
const int SUP_MAX = 5;
const int SUP_MIN = 6;

int Menu:: obtenerOpcion() {
    return opcion;
}

Lista Menu:: obtenerLista() {
    return listaFiguras;
}

void Menu:: mostrarBienvenida() {
    cout << "Bienvenid@!\n";
}

void Menu:: mostrarDespedida() {
    cout << "Hasta la proxima\n";
}

void Menu:: cargarDatos(string archFiguras) {
    listaFiguras.cargarArchivoEnLista(archFiguras);
}

void Menu::mostrarMenu() {
    cout << "\n   1. Obtener una figura de determinada posicion\n"
            "   2. Dar de baja una figura\n"
            "   3. Agregar manualmente una figura\n"
            "   4. Mostrar figuras\n"
            "   5. Mostrar superficie maxima\n"
            "   6. Mostrar superficie minima\n"
            "   0. Salir\n";
}

void Menu:: elegirOpcion() {
    cout << "\n   Ingrese la opcion que desea: ";
    cin >> opcion;
    cout << "\n";
    validarRangoOpcion();
}

void Menu:: validarRangoOpcion(int min, int max) {
    while (opcion < min || opcion > max) {
        cout << "La opcion que eligio esta fuera de rango, por favor reingrese: ";
        cin >> opcion;
    }
}

void Menu:: abrirSubmenu() {
    switch(opcion) {

        case OBTENER_FIGURA: obtenerFigura(); break;

        case BAJA: bajaFigura(); break;

        case ALTA: agregarFigura(); break;

        case MOSTRAR: mostrarFiguras(); break;

        case SUP_MAX: mostrarSupMax(); break;

        case SUP_MIN: mostrarSupMin(); break;
    }
}

void Menu:: obtenerFigura() {

    string nombreFigura;

    int posicion, min = 1, max = listaFiguras.obtenerCantidadElementos();
    cout << "Ingrese una posicion entre " << min << " y " << max << ": ";
    cin >> posicion;
    cout << "\n";

    cout << listaFiguras.obtenerDato(posicion);
    cout << "   Area: " << listaFiguras.obtenerDato(posicion).obtenerArea() << "\n\n";
}

void Menu:: bajaFigura() {
    //NOT WORKING PROPERLY
    int posicion;
    mostrarFiguras();
    cout << "Ingrese el numero del elemento que desea dar de baja: ";
    cin >> posicion;
    listaFiguras.sacar(posicion-1);
}

void Menu:: agregarFigura() {
    Figura* figura;
    Rectangulo rectangulo;
    Triangulo triangulo;
    Circulo circulo;

    cout << "Ingrese el tipo de figura que desea\n"
            "   - (R)ectangulo\n"
            "   - (T)riangulo\n"
            "   - (C)irculo\n";

    //TODO
}

void Menu:: mostrarFiguras() {
    for (int i = 0; i < listaFiguras.obtenerCantidadElementos(); i ++) {
        cout << i+1 << ". " << listaFiguras.obtenerDato(i) <<
                "           Area: " << listaFiguras.obtenerDato(i).obtenerArea() << "\n\n";
    }
}

void Menu:: mostrarSupMax() {
    Figura maxSup = listaFiguras.obtenerDato(0);
    for (int i = 0; i < listaFiguras.obtenerCantidadElementos(); i++) {
        if (maxSup.obtenerArea() < listaFiguras.obtenerDato(i).obtenerArea())
            maxSup = listaFiguras.obtenerDato(i);
    }
    cout << "Mayor superficie: \n" << maxSup <<
            "           Area: " << maxSup.obtenerArea() << "\n\n";
}

void Menu:: mostrarSupMin() {
    Figura minSup = listaFiguras.obtenerDato(0);
    for (int i = 0; i < listaFiguras.obtenerCantidadElementos(); i++) {
        if (minSup.obtenerArea() > listaFiguras.obtenerDato(i).obtenerArea())
            minSup = listaFiguras.obtenerDato(i);
    }
    cout << "Mayor superficie: \n" << minSup <<
         "           Area: " << minSup.obtenerArea() << "\n\n";
}