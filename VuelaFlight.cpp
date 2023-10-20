//
// Created by jacob on 20/10/2023.
//

#include "VuelaFlight.h"

VuelaFlight::VuelaFlight():aereopuertos(new VDinamico<Aeropuerto>()),rutas(new ListaEnlazada<Ruta>()) {
}

VuelaFlight::~VuelaFlight() {
    delete aereopuertos;
    delete rutas;

}
