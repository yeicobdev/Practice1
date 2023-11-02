//
// Created by jacob on 20/10/2023.
//

#ifndef PRACTICE1_RUTA_H
#define PRACTICE1_RUTA_H
#include <iostream>
#include "Aeropuerto.h"
class Aerolinea;



class Ruta {
private:
    Aerolinea* company;
    Aeropuerto* origin;
    Aeropuerto* destination;


public:
    Ruta()=default;
    Ruta(Aerolinea* aerolin,Aeropuerto* ori,Aeropuerto* des);
    Ruta(const Ruta& otro);
    ~Ruta();
    Aerolinea* getAerolinea();
    Aeropuerto* getOrigen();
    Aeropuerto* getDestination();
    Ruta& setAerolinea(Aerolinea* aerolin);
    Ruta& setOrigen(Aeropuerto* origen);
    Ruta& setDestination(Aeropuerto* destino);




};


#endif //PRACTICE1_RUTA_H
