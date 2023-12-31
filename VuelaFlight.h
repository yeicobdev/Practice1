//
// Created by jacob on 20/10/2023.
//

#ifndef PRACTICE1_VUELAFLIGHT_H
#define PRACTICE1_VUELAFLIGHT_H
#include "VDinamico.h"
#include "ListaEnlazada.h"
#include "ArbolAVL.h"
#include "Aeropuerto.h"
#include "Ruta.h"
#include "Aerolinea.h"



class VuelaFlight {
private:
    VDinamico<Aeropuerto> aereopuertos;
    ListaEnlazada<Ruta> rutas;
    Avl<Aerolinea> work;


public:
    VuelaFlight();
    VDinamico<Aeropuerto>& getAeropuertos();
    ListaEnlazada<Ruta>& getRutas();
    Avl<Aerolinea>& getWork();
    VuelaFlight& setAeropuertos(VDinamico<Aeropuerto>& a);
    VuelaFlight& setRutas(ListaEnlazada<Ruta>& r);
    Ruta* buscaRutasOriDes(Aeropuerto& air1,Aeropuerto& air2);
    ListaEnlazada<Ruta*> rutasOrigen(const Aeropuerto& air1);
    VDinamico<Aeropuerto*> buscarAeropuertoPais(const std::string& pais);
    void addNuevaRuta(Aeropuerto* air1,Aeropuerto* air2,Aerolinea* nombre);
    VuelaFlight& anadeConecta(const std::string& ruta,const std::string& air1,const std::string& air2 );
    Aerolinea* buscaAereolinea(const std::string& icaoAerolinea);
    VDinamico<Aerolinea*>* buscaAereolineasActivas();
    ~VuelaFlight();
};


#endif //PRACTICE1_VUELAFLIGHT_H
