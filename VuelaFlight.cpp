//
// Created by jacob on 20/10/2023.
//

#include "VuelaFlight.h"

VuelaFlight::VuelaFlight():aereopuertos(new VDinamico<Aeropuerto>()),rutas(new ListaEnlazada<Ruta>()) {
}

VuelaFlight::~VuelaFlight() {
    delete aereopuertos;
    delete rutas;

}

ListaEnlazada<Ruta> *VuelaFlight::getRutas() {
    return rutas;
}

VDinamico<Aeropuerto> *VuelaFlight::getAeropuertos() {
    return aereopuertos;
}

VuelaFlight &VuelaFlight::setAeropuertos(VDinamico<Aeropuerto> *a) {
    this->aereopuertos=a;
    return (*this);
}

VuelaFlight &VuelaFlight::setRutas(ListaEnlazada<Ruta> *r) {
    this->rutas=r;
    return (*this);
}

void VuelaFlight::conecta() {
Iterador<Ruta> i=  Iterador<Ruta>();
rutasConectadas=new ListaEnlazada<Ruta>();
i.setNodo(rutas->getCabecera());
while(!i.fin()){
int ori=aereopuertos->busquedaBin(*(i.dato().getOrigen()));

if(ori!=-1){
    i.dato().setOrigen(&(aereopuertos->operator[](ori)));

}
int des=aereopuertos->busquedaBin(*(i.dato().getDestination()));

if(des!=-1){
    i.dato().setDestination(&(aereopuertos->operator[](des)));

}
if((ori!=-1)&&(des!=-1))
{
    rutasConectadas->insertaInicio(*new Ruta("",i.dato().getOrigen(),i.dato().getDestination()));
}
    i.siguiente();
}

}

ListaEnlazada<Ruta>* VuelaFlight::getconectados() {
    return rutasConectadas;
}

Ruta &VuelaFlight::buscaRutasOriDes(Aeropuerto &air1,Aeropuerto &air2) {
Iterador<Ruta> i=Iterador<Ruta>();
i.setNodo(rutas->getCabecera());

while(!i.fin()){
    if((air1==(*i.dato().getOrigen()))&&(air2==(*i.dato().getDestination()))){
        return i.dato();
    }
    i.siguiente();
}
return (*new Ruta("No hay ruta",nullptr,nullptr));
}

ListaEnlazada<Ruta> &VuelaFlight::rutasOrigen(const Aeropuerto &air1) {
    ListaEnlazada<Ruta>* toret=new ListaEnlazada<Ruta>();
    Iterador<Ruta> i=Iterador<Ruta>();
    i.setNodo(rutas->getCabecera());
    while(!i.fin()){
        if(&air1==i.dato().getOrigen()){
            toret->insertaInicio(i.dato());
        }
        i.siguiente();
    }
    return (*toret);
}

VDinamico<Aeropuerto>& VuelaFlight::buscarAeropuertoPais(const std::string &pais) {
    VDinamico<Aeropuerto>* toret=new VDinamico<Aeropuerto>();
    for(int i=0;i<aereopuertos->getTamLog();i++){
        if(pais==aereopuertos->operator[](i).getIsoPais()){
            toret->insertar(*new Aeropuerto(aereopuertos->operator[](i)))  ;
        }
    }
return (*toret);
}

void VuelaFlight::addNuevaRuta(const Ruta &rut) {
rutas->insertaInicio(rut);
}
