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
