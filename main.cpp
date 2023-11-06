#include "VuelaFlight.h"
#include <fstream>
#include <string>
#include <sstream>

/**  @author Jacobo Pancorbo Bianquetti jpb00023@red.ujaen.es      */
int main() {

    std::cout<<"Prueba 1"<<std::endl;
    VuelaFlight *center = new VuelaFlight();


    std::cout << "Lectura de Aereopuertos: " << std::endl;
    std::ifstream is1;
    std::stringstream columnas1;
    std::string fila1;
    int cont1 = 0;


    std::string id = "";
    std::string iata = "";
    std::string tipo = "";
    std::string nombre = "";
    std::string latitud_str = "";
    std::string longitud_str = "";
    std::string continente = "";
    std::string iso_pais = "";

    float latitud, longitud;

    is1.open("C://Users//jacob//OneDrive//Escritorio//EEDD//Practice1//aeropuertos_v2.csv"); //carpeta de proyecto
    if (is1.good()) {

        clock_t t_ini = clock();

        while (getline(is1, fila1)) {

            //Â¿Se ha leÃ­do una nueva fila?
            if (fila1 != "") {

                columnas1.str(fila1);
                //id;iata_code;type;name;latitude_deg;longitude_deg;continent;iso_country
                //formato de fila: id;iata;tipo;nombre;latitud;longitud;continente;iso_pais

                getline(columnas1, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas1, iata, ';');
                getline(columnas1, tipo, ';');
                getline(columnas1, nombre, ';');
                getline(columnas1, latitud_str, ';');
                getline(columnas1, longitud_str, ';');
                getline(columnas1, continente, ';');
                getline(columnas1, iso_pais, ';');

                //  Transformamos la latitud y longitud a float
                latitud = std::stof(latitud_str);
                longitud = std::stof(longitud_str);

                fila1 = "";
                columnas1.clear();
                center->getAeropuertos().insertar(
                        *(new Aeropuerto(id, iata, tipo, nombre, (*new UTM(latitud, longitud)), continente, iso_pais)),
                        cont1);

            }
            cont1++;
        }

        is1.close();

        std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
        std::cout << "Tamano Fisico: " << center->getAeropuertos().getTamFis() << std::endl;
        std::cout << "Tamano Logico: " << center->getAeropuertos().getTamLog() << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
    //ordenamos el vector
    center->getAeropuertos().ordenar();


    std::cout << "Lectura de Aereolineas: " << std::endl;
    std::ifstream is3;
    std::stringstream columnas3;
    std::string fila3;
    int cont3 = 0;


    std::string id2_str = "";
    std::string icao = "";
    std::string nombre2 = "";
    std::string pais = "";
    std::string activo_str = "";

    unsigned int id2;
    bool activo;


    is3.open("C://Users//jacob//OneDrive//Escritorio//EEDD//Practice1//aerolineas_v1.csv"); //carpeta de proyecto
    if (is3.good()) {

        clock_t t_ini = clock();

        while (getline(is3, fila3)) {

            if (fila3 != "") {

                columnas3.str(fila3);


                getline(columnas3, id2_str, ';');
                getline(columnas3, icao, ';');
                getline(columnas3, nombre2, ';');
                getline(columnas3, pais, ';');
                getline(columnas3, activo_str, ';');


                id2 = std::stoi(id2_str);
                if (activo_str == "Y") {
                    activo = true;
                }

                if (activo_str == "N") {
                    activo = false;
                }
                fila3 = "";
                columnas3.clear();
                center->getWork().inserta(*(new Aerolinea(id2, icao, nombre2, pais, activo)));

            }
            cont3++;
        }

        is3.close();

        std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
        std::cout << "Elementos Arbol: " << center->getWork().numElementos() << std::endl;
        std::cout << "Altura Arbol: " << center->getWork().altura() << std::endl;

    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }


    std::cout << "Lectura de Rutas: " << std::endl;
    std::ifstream is2;
    std::stringstream columnas2;
    std::string fila2;
    int cont2 = 0;


    std::string iatarut = "";
    std::string aero1 = "";
    std::string aero2 = "";


    is2.open("C://Users//jacob//OneDrive//Escritorio//EEDD//Practice1//rutas_v1.csv"); //carpeta de proyecto
    if (is2.good()) {

        clock_t t_ini = clock();

        while (getline(is2, fila2)) {

            //Â¿Se ha leÃ­do una nueva fila?
            if (fila2 != "") {

                columnas2.str(fila2);


                getline(columnas2, iatarut, ';');
                getline(columnas2, aero1, ';');
                getline(columnas2, aero2, ';');


                fila2 = "";
                columnas2.clear();
                center->anadeConecta(iatarut, aero1, aero2);

            }
            cont2++;
        }

        is2.close();

        std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;

    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
    std::cout << "Cabecera: " << center->getRutas().getCabecera()->dato.getAerolinea()->getIcao() << std::endl;
    std::cout << "Cola: " << center->getRutas().getCola()->dato.getAerolinea()->getIcao() << std::endl;
    std::cout << "Numero de nodos: " << center->getRutas().tam() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout<<"Prueba 2"<<std::endl;
    center->buscaAereolinea("RYR")->muestraInfo();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout<<"Prueba 3"<<std::endl;
    VDinamico<Aerolinea*>* aerolineasActivas = center->buscaAereolineasActivas();
    for (int i = 0; i < aerolineasActivas->getTamLog(); i++) {
        std::cout << aerolineasActivas->operator[](i)->getIcao() << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout<<"Prueba 4"<<std::endl;
   for(int i=0;i< center->buscaAereolinea("IBE")->getAeropuertosOrig()->getTamLog();i++){
       std::cout<<center->buscaAereolinea("IBE")->getAeropuertosOrig()->operator[](i)->getIata()<<" ";
   }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout<<"Prueba 5"<<std::endl;
for(int i=0;i<center->buscaAereolinea("IBE")->getRutas("AGP")->getTamLog();i++){
    std::cout<<center->buscaAereolinea("IBE")->getRutas("AGP")->operator[](i)->getAerolinea()->getNombre()
    <<" | "<<center->buscaAereolinea("IBE")->getRutas("AGP")->operator[](i)->getOrigen()->getIata()
    <<" | "<<center->buscaAereolinea("IBE")->getRutas("AGP")->operator[](i)->getDestination()->getIata()<<std::endl;
}

    delete center;



    return 0;

}
