//
// Created by jacob on 01/11/2023.
//

#ifndef PRACTICE1_AEROLINEA_H
#define PRACTICE1_AEROLINEA_H
#include <iostream>

class Aerolinea {
private:
    unsigned int id;
    std::string icao;
    std::string nombre;
    std::string pais;
    bool activo;
public:
    Aerolinea()=default;
    Aerolinea(const unsigned int& id,const std::string& icao,
              const std::string& nombre,const std::string& pais,const bool& activo);
    Aerolinea(const Aerolinea& otra);
    ~Aerolinea();
    unsigned int getId();
    std::string getIcao();
    std::string getNombre();
    std::string getPais();
    bool getActivo();
    Aerolinea& setId(const unsigned int& id);
    Aerolinea& setIcao(const std::string& icao);
    Aerolinea& setNombre(const std::string& nombre);
    Aerolinea& setPais(const std::string& pais);
    Aerolinea& setActivo(const bool& activo);
    bool operator==(Aerolinea& otra);
    bool operator<(Aerolinea& otra);
    bool operator>(Aerolinea& otra);

};


#endif //PRACTICE1_AEROLINEA_H
