//
// Created by jacob on 20/10/2023.
//

#ifndef PRACTICE1_VUELAFLIGHT_H
#define PRACTICE1_VUELAFLIGHT_H
#include "VDinamico.h"
#include "ListaEnlazada.h"
#include "Aeropuerto.h"
#include "Ruta.h"

class VuelaFlight {
private:
    VDinamico<Aeropuerto>* aereopuertos;
    ListaEnlazada<Ruta>* rutas;
public:
    VuelaFlight();
    ~VuelaFlight();
};


#endif //PRACTICE1_VUELAFLIGHT_H
