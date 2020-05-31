//
// Created by valentina on 26/5/20.
//

#ifndef TRABAJOPRACTICO3FIGURAS_RECTANGULO_H
#define TRABAJOPRACTICO3FIGURAS_RECTANGULO_H

#include "Figura.h"

class Rectangulo : public Figura {
    // Atributos
    private:
        double altura, base;

    // Metodos
    public:
        // Descrpcion:
        // PRE:
        // POST:
        Rectangulo(double baseOut = 0, double alturaOut = 0);

        // Descrpcion:
        // PRE:
        // POST:
        virtual double calcularArea();
        virtual void mostrar();
};


#endif //TRABAJOPRACTICO3FIGURAS_RECTANGULO_H
