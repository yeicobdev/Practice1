//
// Created by jacob on 20/10/2023.
//

#ifndef PRACTICE1_RUTA_H
#define PRACTICE1_RUTA_H
#include <iostream>
#include "Aeropuerto.h"

class Ruta {
private:
    std::string aerolinea;
    Aeropuerto* origin;
    Aeropuerto* destination;
public:
    Ruta()=default;
    Ruta(const std::string aerolin,Aeropuerto* ori,Aeropuerto* des);
    Ruta(const Ruta& otro);
    ~Ruta();
    std::string getAerolinea();
    Aeropuerto* getOrigen();
    Aeropuerto* getDestination();
    Ruta& setAerolinea(const std::string& aerolin);
    Ruta& setOrigen(Aeropuerto* origen);
    Ruta& setDestination(Aeropuerto* destino);



};


#endif //PRACTICE1_RUTA_H
