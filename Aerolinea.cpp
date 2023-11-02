//
// Created by jacob on 01/11/2023.
//

#include "Aerolinea.h"

Aerolinea::Aerolinea(const unsigned int &id, const std::string &icao, const std::string &nombre,
                     const std::string &pais, const bool &activo) : id(id), icao(icao), nombre(nombre),
                                                                    pais(pais), activo(activo) {
}

Aerolinea::Aerolinea(const Aerolinea &otra) : id(otra.id), icao(otra.icao), nombre(otra.nombre),
                                              pais(otra.pais), activo(otra.activo) {
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
    this->id = id;
    return (*this);
}

Aerolinea &Aerolinea::setIcao(const std::string &icao) {
    this->icao = icao;
    return (*this);
}

Aerolinea &Aerolinea::setNombre(const std::string &nombre) {
    this->nombre = nombre;
    return (*this);
}

Aerolinea &Aerolinea::setPais(const std::string &pais) {
    this->pais = pais;
    return (*this);
}

Aerolinea &Aerolinea::setActivo(const bool &activo) {
    this->activo = activo;
    return (*this);
}

bool Aerolinea::operator==(Aerolinea &otra) {
    return (icao == otra.icao);
}

bool Aerolinea::operator<(Aerolinea &otra) {
    return (icao < otra.icao);
}

bool Aerolinea::operator>(Aerolinea &otra) {
    return (icao > otra.icao);
}

Aerolinea::Aerolinea(const std::string &icao) : icao(icao) {
}

VDinamico<Ruta *> &Aerolinea::getAerorutes() {
    return aerorutes;
}

VDinamico<Aeropuerto> &Aerolinea::getAeropuertosOrig() {
    VDinamico<Aeropuerto> *toret = new VDinamico<Aeropuerto>();
    for (int i = 0; i < aerorutes.getTamLog(); i++) {
        toret->inserta(*(aerorutes.operator[](i)->getOrigen()));
    }
    return *toret;
}

VDinamico<Ruta> &Aerolinea::getRutas(const std::string &iataAeropuerto) {
    VDinamico<Ruta> *toret = new VDinamico<Ruta>();
    for (int i = 0; i < aerorutes.getTamLog(); i++) {
        if ((aerorutes.operator[](i)->getOrigen()->getIata() == iataAeropuerto) ||
            (aerorutes.operator[](i)->getDestination()->getIata() == iataAeropuerto)) {
            toret->inserta(*(aerorutes.operator[](i)));
        }
    }
    return *toret;
}

void Aerolinea::muestraInfo() {
    std::cout << "Informacion de: " << nombre << std::endl;
    std::cout << "Icao: " << icao << std::endl;
    std::cout << "Id: " << id << std::endl;
    std::cout << "Pais: " << pais << std::endl;
    std::cout << "Activo: " << activo << std::endl;
    std::cout << "Opera en las rutas (10 primeras): " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Aerolinea: " << aerorutes.operator[](i)->getAerolinea()->nombre << " | Origen: "
                  << aerorutes.operator[](i)->getOrigen()->getIata() << " | Destino: "
                  << aerorutes.operator[](i)->getDestination()->getIata() << std::endl;
    }
}
