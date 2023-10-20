#include "Aeropuerto.h"
#include "VuelaFlight.h"
#include <fstream>
#include <string>
#include <sstream>

/**  @author Jacobo Pancorbo Bianquetti jpb00023@red.ujaen.es      */
int main() {
    //Prueba 1
ListaEnlazada<int>* listaPrueba=new ListaEnlazada<int>;
for(int i=101;i<201;i++){
    listaPrueba->insertaFin(i);
}
for(int i=98;i>0;i--){
    listaPrueba->insertaInicio(i);
}
Iterador<int>* iteradorPrueba=new Iterador<int>(listaPrueba->getCabecera());
while(iteradorPrueba->dato()!=101){
    iteradorPrueba->siguiente();
}
listaPrueba->inserta(*iteradorPrueba,100);
iteradorPrueba->setNodo(listaPrueba->getCabecera());
while(iteradorPrueba->dato()!=98){
    iteradorPrueba->siguiente();
}
listaPrueba->insertaDetras(*iteradorPrueba,99);
iteradorPrueba->setNodo(listaPrueba->getCabecera());
std::cout<<"Hacemos las inserciones: "<<std::endl;
while(!iteradorPrueba->fin())
{
    std::cout<<iteradorPrueba->dato()<<" ";
    iteradorPrueba->siguiente();
}
std::cout<<std::endl;
std::cout<<"Borramos los 10 primeros y los 10 Ultimos datos:"<<std::endl;
for(int i=0;i<10;i++)
{
    listaPrueba->borraInicio();
}
for(int i=0;i<10;i++)
{
    listaPrueba->borraFinal();
}
iteradorPrueba->setNodo(listaPrueba->getCabecera());
while(!iteradorPrueba->fin())
{
    std::cout<<iteradorPrueba->dato()<<" ";
    iteradorPrueba->siguiente();
}
std::cout<<std::endl;
std::cout<<"Borramos los multiplos de 10:"<<std::endl;
iteradorPrueba->setNodo(listaPrueba->getCabecera());
while(!iteradorPrueba->fin()){
    if(((iteradorPrueba->dato())%10)==0)
    {
        listaPrueba->borra(*iteradorPrueba);//mi funcion borra hace que se pase al siguiente nodo automáticamente
    }else{
        iteradorPrueba->siguiente();
    }

}
iteradorPrueba->setNodo(listaPrueba->getCabecera());
while(!iteradorPrueba->fin())
{
    std::cout<<iteradorPrueba->dato()<<" ";
    iteradorPrueba->siguiente();
}
delete listaPrueba;
delete iteradorPrueba;
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;

//Prueba 2
    std::cout<<"Aereopuertos: "<<std::endl;

    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    int contador=0;

    std::string id = "";
    std::string iata="";
    std::string tipo="";
    std::string nombre="";
    std::string latitud_str="";
    std::string longitud_str="";
    std::string continente="";
    std::string iso_pais="";

    float latitud, longitud;

    is.open("C://Users//jacob//OneDrive//Escritorio//EEDD//Practice1//aeropuertos_v2.csv"); //carpeta de proyecto
    if ( is.good() ) {

        clock_t t_ini = clock();

        while ( getline(is, fila ) ) {

            //Â¿Se ha leÃ­do una nueva fila?
            if (fila!="") {

                columnas.str(fila);
                //id;iata_code;type;name;latitude_deg;longitude_deg;continent;iso_country
                //formato de fila: id;iata;tipo;nombre;latitud;longitud;continente;iso_pais

                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas,iata,';');
                getline(columnas,tipo,';');
                getline(columnas,nombre,';');
                getline(columnas,latitud_str,';');
                getline(columnas,longitud_str,';');
                getline(columnas,continente,';');
                getline(columnas,iso_pais,';');

                //  Transformamos la latitud y longitud a float
                latitud=std::stof(latitud_str);
                longitud=std::stof(longitud_str);

                fila="";
                columnas.clear();

                std::cout << ++contador
                          << " Aeropuerto: ( ID=" << id
                          << " iata=" << iata << " Tipo=" << tipo << " Nombre=" << nombre
                          << " Posicion=(" << latitud << ", " << longitud << ")"
                          << " Continente=" << continente << " Pais=" << iso_pais
                          << ")" << std::endl;
            }
        }

        is.close();

        std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
    return 0;

}
