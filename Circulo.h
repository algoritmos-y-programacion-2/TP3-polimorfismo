//
// Created by valentina on 26/5/20.
//

#ifndef TRABAJOPRACTICO3FIGURAS_CIRCULO_H
#define TRABAJOPRACTICO3FIGURAS_CIRCULO_H

#include "Figura.h"

class Circulo : public Figura {
    //Atributos
    private:
        double radio;

    // Metodos
    public:

        // Descrpcion:
        // PRE:
        // POST:
        Circulo(double radioOut = 0);

        // Descrpcion:
        // PRE:
        // POST:
        virtual double calcularArea();
        virtual void mostrar();


};


#endif //TRABAJOPRACTICO3FIGURAS_CIRCULO_H
