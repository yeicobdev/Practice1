//
// Created by jacob on 20/10/2023.
//

#include "Ruta.h"

Ruta::Ruta(const std::string aerolin, Aeropuerto *ori, Aeropuerto *des):aerolinea(aerolin),origin(ori)
,destination(des) {
}

Ruta::Ruta(const Ruta &otro):aerolinea(otro.aerolinea),origin(otro.origin),destination(otro.destination) {
}

Ruta::~Ruta() {
}

std::string Ruta::getAerolinea() {
    return aerolinea;
}

Aeropuerto *Ruta::getOrigen() {
    return origin;
}

Aeropuerto *Ruta::getDestination() {
    return destination;
}

Ruta &Ruta::setAerolinea(const std::string &aerolin) {
    this->aerolinea=aerolin;
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
