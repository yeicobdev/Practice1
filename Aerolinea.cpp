//
// Created by jacob on 01/11/2023.
//

#include "Aerolinea.h"

Aerolinea::Aerolinea(const unsigned int &id, const std::string &icao, const std::string &nombre,
                     const std::string &pais, const bool &activo):id(id),icao(icao),nombre(nombre),
                     pais(pais),activo(activo){
}

Aerolinea::Aerolinea(const Aerolinea &otra):id(otra.id),icao(otra.icao),nombre(otra.nombre),
pais(otra.pais),activo(otra.activo){
}

Aerolinea::~Aerolinea() {
}

unsigned int Aerolinea::getId() {
    return id;
}

std::string Aerolinea::getIcao() {
    return icao;
}

std::string Aerolinea::getNombre() {
    return nombre;
}

std::string Aerolinea::getPais() {
    return pais;
}

bool Aerolinea::getActivo() {
    return activo;
}

Aerolinea &Aerolinea::setId(const unsigned int &id) {
    this->id=id;
    return (*this);
}

Aerolinea &Aerolinea::setIcao(const std::string &icao) {
    this->icao=icao;
    return (*this);
}

Aerolinea &Aerolinea::setNombre(const std::string &nombre) {
    this->nombre=nombre;
    return (*this);
}

Aerolinea &Aerolinea::setPais(const std::string &pais) {
    this->pais=pais;
    return (*this);
}

Aerolinea &Aerolinea::setActivo(const bool &activo) {
    this->activo=activo;
    return (*this);
}

bool Aerolinea::operator==(Aerolinea &otra) {
    return (icao==otra.icao);
}

bool Aerolinea::operator<(Aerolinea &otra) {
    return (icao<otra.icao);
}

bool Aerolinea::operator>(Aerolinea &otra) {
    return (icao>otra.icao);
}
