//
// Created by jacob on 01/10/2023.
//

#ifndef PRACTICE1_AEROPUERTO_H
#define PRACTICE1_AEROPUERTO_H
#include "UTM.h"

class Aeropuerto {
private:
    std::string id;
    std::string iata;
    std::string tipo;
    std::string nombre;
    UTM posicion;
    std::string continente;
    std::string iso_pais;
public:
    Aeropuerto()=default;
    Aeropuerto(const std::string& id,const std::string& iata,const std::string& tipo,const std::string& nombre,
               const UTM& posicion,const std::string& continente,const std::string& iso_pais);
    Aeropuerto(const Aeropuerto& otro);
    Aeropuerto(const std::string& iata2);
    ~Aeropuerto();
    std::string getId()const;
    std::string getIata()const;
    std::string getTipo()const;
    std::string getNombre()const;
    std::string getContinente()const;
    std::string getIsoPais()const;
    UTM& getPosicion();
    Aeropuerto& setId(const std::string& id);
    Aeropuerto& setIata(const std::string& iata);
    Aeropuerto& setTipo(const std::string& tipo);
    Aeropuerto& setNombre(const std::string& nombre);
    Aeropuerto& setPosicion(const UTM& posicion);
    Aeropuerto& setContinente(const std::string& continente);
    Aeropuerto& setIsoPais(const std::string& iso_pais);
    Aeropuerto& operator=(const Aeropuerto& otro);
    bool operator==(const Aeropuerto& otro);
    bool operator <(const Aeropuerto& otro);
    bool operator >(const Aeropuerto& otro);
    bool operator <=(const Aeropuerto& otro);
    bool operator >=(const Aeropuerto& otro);





};


#endif //PRACTICE1_AEROPUERTO_H
