#include "Aeropuerto.h"
#include "VDinamico.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
int main() {
VDinamico<Aeropuerto> aeropuertos=VDinamico<Aeropuerto>();
    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    std::string id = "";
    std::string ident="";
    std::string tipo="";
    std::string nombre="";
    std::string latitud_str="";
    std::string longitud_str="";
    std::string continente="";
    std::string iso_pais="";
    int contador=0;
    is.open("C://Users//jacob//OneDrive//Escritorio//EEDD//Practice1//aeropuertos.csv");
    if ( is.good() ) {

        clock_t t_ini = clock();

        while ( getline(is, fila ) ){

            if (fila!="") {

                columnas.str(fila);

                //formato de fila: id;ident;tipo;nombre;latitud;longitud;continente;iso_pais

                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas,ident,';');
                getline(columnas,tipo,';');
                getline(columnas,nombre,';');
                getline(columnas,latitud_str,';');
                getline(columnas,longitud_str,';');
                getline(columnas,continente,';');
                getline(columnas,iso_pais,';');

                //  Transformamos la latitud y longitud a float
                float latitud=std::stof(latitud_str);
                float longitud=std::stof(longitud_str);
                aeropuertos.insertar(Aeropuerto(id,ident,tipo,nombre, *(new UTM(latitud,longitud)),continente,iso_pais),contador);

                fila="";
                columnas.clear();

            }
            contador++;
        }

        is.close();

        std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }

    return 0;

}
