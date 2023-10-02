//
// Created by jacob on 01/10/2023.
//

#include "Aeropuerto.h"

Aeropuerto::Aeropuerto(const std::string &id, const std::string &ident, const std::string &tipo,
                       const std::string &nombre, const UTM &posicion, const std::string &continente,
                       const std::string &iso_pais):id(id),ident(ident),tipo(tipo),nombre(nombre)
                       ,posicion(posicion),continente(continente),iso_pais(iso_pais) {
}

Aeropuerto::Aeropuerto(const Aeropuerto &otro):id(otro.id),ident(otro.ident),tipo(otro.tipo),
nombre(otro.nombre),posicion(otro.posicion),continente(otro.continente),iso_pais(otro.iso_pais) {
}

Aeropuerto::~Aeropuerto() {

}

std::string Aeropuerto::getId() const {
    return id;
}

std::string Aeropuerto::getIdent() const {
    return ident;
}

std::string Aeropuerto::getTipo() const {
    return tipo;
}

std::string Aeropuerto::getNombre() const {
    return nombre;
}

UTM &Aeropuerto::getPosicion() {
    return posicion;
}

Aeropuerto &Aeropuerto::setId(const std::string &id) {
    this->id=id;
    return *this;
}

Aeropuerto &Aeropuerto::setIdent(const std::string &ident) {
    this->ident=ident;
    return *this;
}

Aeropuerto &Aeropuerto::setTipo(const std::string &tipo) {
    this->tipo=tipo;
    return *this;
}

Aeropuerto &Aeropuerto::setNombre(const std::string &nombre) {
    this->nombre=nombre;
    return *this;
}

Aeropuerto &Aeropuerto::setPosicion(const UTM &posicion) {
    this->posicion=posicion;
    return *this;
}

Aeropuerto &Aeropuerto::setContinente(const std::string &continente) {
    this->continente=continente;
    return *this;
}

Aeropuerto &Aeropuerto::setIsoPais(const std::string &iso_pais) {
    this->iso_pais=iso_pais;
    return *this;
}

Aeropuerto &Aeropuerto::operator=(const Aeropuerto &otro) {
    this->id=otro.id;
    this->ident=otro.ident;
    this->tipo=otro.tipo;
    this->nombre=otro.nombre;
    this->posicion=otro.posicion;
    this->continente=otro.continente;
    this->iso_pais=otro.iso_pais;
    return *this;
}

bool Aeropuerto::operator==(const Aeropuerto &otro) {
return (id==otro.id);
}

bool Aeropuerto::operator<(const Aeropuerto &otro) {
    return (id<otro.id);
}

bool Aeropuerto::operator<=(const Aeropuerto &otro) {
    return (id<=otro.id);
}

bool Aeropuerto::operator>(const Aeropuerto &otro) {
    return (id>otro.id);
}

bool Aeropuerto::operator>=(const Aeropuerto &otro) {
    return (id>=otro.id);
}

std::string Aeropuerto::getContinente() const {
    return continente;
}

std::string Aeropuerto::getIsoPais() const {
    return iso_pais;
}

Aeropuerto::Aeropuerto(const std::string &id):id(id) {
}
