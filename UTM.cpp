//
// Created by jacob on 01/10/2023.
//

#include "UTM.h"

UTM::UTM(const float &lat, const float &lon):latitud(lat),longitud(lon) {
}

UTM::UTM(const UTM &otro):latitud(otro.latitud),longitud(otro.longitud) {
}

UTM::~UTM() {
}

float UTM::getLatitud() const {
    return latitud;
}

float UTM::getLontitud() const {
    return longitud;
}

UTM &UTM::setLatitud(const float &lat) {
    this->latitud=lat;
    return *this;
}

UTM &UTM::setLongitud(const float &lon) {
    this->longitud=lon;
    return *this;
}

UTM &UTM::operator=(const UTM &otro) {
    this->longitud=otro.longitud;
    this->latitud=otro.latitud;
    return *this;
}
