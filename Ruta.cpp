//
// Created by jacob on 20/10/2023.
//

#include "Ruta.h"

Ruta::Ruta(Aerolinea* aerolin, Aeropuerto *ori, Aeropuerto *des):company(aerolin),origin(ori)
,destination(des) {
}

Ruta::Ruta(const Ruta &otro):company(otro.company),origin(otro.origin),destination(otro.destination) {
}

Ruta::~Ruta() {
}

Aerolinea* Ruta::getAerolinea() {
    return company;
}

Aeropuerto *Ruta::getOrigen() {
    return origin;
}

Aeropuerto *Ruta::getDestination() {
    return destination;
}

Ruta &Ruta::setAerolinea(Aerolinea* aerolin) {
    this->company=aerolin;
    return (*this);
}

Ruta &Ruta::setOrigen(Aeropuerto *origen) {
    this->origin=origen;
    return (*this);
}

Ruta &Ruta::setDestination(Aeropuerto *destino) {
    this->destination=destino;
    return (*this);
}


