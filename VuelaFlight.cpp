//
// Created by jacob on 20/10/2023.
//

#include "VuelaFlight.h"

VuelaFlight::VuelaFlight() : aereopuertos(VDinamico<Aeropuerto>()), rutas(ListaEnlazada<Ruta>()) {
}

VuelaFlight::~VuelaFlight() {

}

ListaEnlazada<Ruta> &VuelaFlight::getRutas() {
    return rutas;
}

VDinamico<Aeropuerto> &VuelaFlight::getAeropuertos() {
    return aereopuertos;
}

VuelaFlight &VuelaFlight::setAeropuertos(VDinamico<Aeropuerto> &a) {
    this->aereopuertos = a;
    return (*this);
}

VuelaFlight &VuelaFlight::setRutas(ListaEnlazada<Ruta> &r) {
    this->rutas = r;
    return (*this);
}


Ruta &VuelaFlight::buscaRutasOriDes(Aeropuerto &air1, Aeropuerto &air2) {
    Iterador<Ruta> i = Iterador<Ruta>();
    i.setNodo(rutas.getCabecera());

    while (!i.fin()) {
        if ((air1 == (*i.dato().getOrigen())) && (air2 == (*i.dato().getDestination()))) {
            return i.dato();
        }
        i.siguiente();
    }
    return (*new Ruta(nullptr, nullptr, nullptr));
}

ListaEnlazada<Ruta> &VuelaFlight::rutasOrigen(const Aeropuerto &air1) {
    ListaEnlazada<Ruta> *toret = new ListaEnlazada<Ruta>();
    Iterador<Ruta> i = Iterador<Ruta>();
    i.setNodo(rutas.getCabecera());
    while (!i.fin()) {
        if (&air1 == i.dato().getOrigen()) {
            toret->insertaInicio(i.dato());
        }
        i.siguiente();
    }
    return (*toret);
}

VDinamico<Aeropuerto> &VuelaFlight::buscarAeropuertoPais(const std::string &pais) {
    VDinamico<Aeropuerto> *toret = new VDinamico<Aeropuerto>();
    for (int i = 0; i < aereopuertos.getTamLog(); i++) {
        if (pais == aereopuertos.operator[](i).getIsoPais()) {
            toret->insertar(*new Aeropuerto(aereopuertos.operator[](i)));
        }
    }
    return (*toret);
}


Avl<Aerolinea> &VuelaFlight::getWork() {
    return work;
}

void VuelaFlight::addNuevaRuta(Aeropuerto *air1, Aeropuerto *air2, Aerolinea *nombre) {
    rutas.insertaInicio(*new Ruta(nombre, air1, air2));

}

VuelaFlight &
VuelaFlight::anadeConecta(const std::string &aereolinea, const std::string &air1, const std::string &air2) {
    Aerolinea aerolineaprovisional = Aerolinea(aereolinea);
    Aeropuerto origenProvisional = Aeropuerto(air1);
    Aeropuerto destinoProvisional = Aeropuerto(air2);
    int posOrigen = aereopuertos.busquedaBin(origenProvisional);
    int posDestino = aereopuertos.busquedaBin(destinoProvisional);
    Aeropuerto *orig, *des;
    Aerolinea *aerol = work.buscaRec(aerolineaprovisional);
    if (posOrigen == -1) {
        orig = nullptr;
    } else {
        orig = &(aereopuertos.operator[](posOrigen));
    }
    if (posDestino == -1) {
        des = nullptr;
    } else {
        des = &(aereopuertos.operator[](posDestino));
    }
    Ruta* rutaInsertada=rutas.insertaInicio(*new Ruta(aerol, orig, des));
    aerol->getAerorutes().inserta(rutaInsertada);
    return (*this);
}

Aerolinea &VuelaFlight::buscaAereolinea(const std::string &icaoAerolinea) {
    Aerolinea aerolineaprov=Aerolinea(icaoAerolinea);
    return *(work.buscaRec(aerolineaprov));

}

VDinamico<Aerolinea> &VuelaFlight::buscaAereolineasActivas() {
   VDinamico<Aerolinea>* toret= new VDinamico<Aerolinea>();
   VDinamico<Aerolinea*> datos=work.recorreInorden();
   for(int i=0;i<datos.getTamLog();i++){
       if(datos.operator[](i)->getAerorutes().getTamLog()!=0){
        toret->inserta(*datos.operator[](i));
       }
   }
   return *toret;
}
