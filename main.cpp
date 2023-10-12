#include "Aeropuerto.h"
#include "VDinamico.h"
#include <fstream>
#include <string>
#include <sstream>

/**  @author Jacobo Pancorbo Bianquetti jpb00023@red.ujaen.es      */
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

        while (( getline(is, fila ) )&&(contador<5000)){

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
                aeropuertos.insertar( *new Aeropuerto(id,ident,tipo,nombre, *(new UTM(latitud,longitud)),continente,iso_pais),contador);

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
    std::cout<<std::endl;
    std::cout<<std::endl;
    aeropuertos.ordenarRev();
    for(int i=0;i<30;i++)
    {
        std::cout<<(aeropuertos[i]).getId()<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    aeropuertos.ordenar();
    for(int i=0;i<30;i++)
    {
        std::cout<<(aeropuertos[i]).getId()<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Tamano fisico antes de borrar: "<<aeropuertos.getTamFis()<<std::endl;
    std::cout<<"Tamano logico antes de borrar: "<<aeropuertos.getTamLog()<<std::endl;
    int borrados=0;
    for( int i=0;i<aeropuertos.getTamLog();i++)
    {
        if(aeropuertos[i].getContinente()=="NA")
        {
            aeropuertos.borrar(i);
            borrados++;
        }
    }
    std::cout<<"Tamano fisico despues de borrar: "<<aeropuertos.getTamFis()<<std::endl;
    std::cout<<"Tamano logico despues de borrar: "<<aeropuertos.getTamLog()<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    Aeropuerto* a1=new Aeropuerto("345166");
    std::cout<<"345166: "<<aeropuertos.busquedaBin(*a1)<<std::endl;
    delete a1;
    Aeropuerto* a2=new Aeropuerto("9999");
    std::cout<<"9999: "<<aeropuertos.busquedaBin(*a2)<<std::endl;
    delete a2;
    Aeropuerto* a3=new Aeropuerto("0000");
    std::cout<<"0000: "<<aeropuertos.busquedaBin(*a3)<<std::endl;
    delete a3;



    return 0;

}
