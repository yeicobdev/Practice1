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

VuelaFlight* center=new VuelaFlight();



    std::cout<<"Lectura de Aereopuertos: "<<std::endl;
    std::ifstream is1;
    std::stringstream  columnas1;
    std::string fila1;
    int cont1=0;


    std::string id = "";
    std::string iata="";
    std::string tipo="";
    std::string nombre="";
    std::string latitud_str="";
    std::string longitud_str="";
    std::string continente="";
    std::string iso_pais="";

    float latitud, longitud;

    is1.open("C://Users//jacob//OneDrive//Escritorio//EEDD//Practice1//aeropuertos_v2.csv"); //carpeta de proyecto
    if ( is1.good() ) {

        clock_t t_ini = clock();

        while ( (getline(is1, fila1 ))&&cont1<10000) {

            //Â¿Se ha leÃ­do una nueva fila?
            if (fila1!="") {

                columnas1.str(fila1);
                //id;iata_code;type;name;latitude_deg;longitude_deg;continent;iso_country
                //formato de fila: id;iata;tipo;nombre;latitud;longitud;continente;iso_pais

                getline(columnas1, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas1,iata,';');
                getline(columnas1,tipo,';');
                getline(columnas1,nombre,';');
                getline(columnas1,latitud_str,';');
                getline(columnas1,longitud_str,';');
                getline(columnas1,continente,';');
                getline(columnas1,iso_pais,';');

                //  Transformamos la latitud y longitud a float
                latitud=std::stof(latitud_str);
                longitud=std::stof(longitud_str);

                fila1="";
                columnas1.clear();
                center->getAeropuertos()->insertar(*(new Aeropuerto(id,iata,tipo,nombre,(*new UTM(latitud,longitud)),continente,iso_pais)),cont1);

            }
            cont1++;
        }

        is1.close();

        std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
        std::cout<< "Tamano Fisico: "<< center->getAeropuertos()->getTamFis()<<std::endl;
        std::cout<< "Tamano Logico: "<< center->getAeropuertos()->getTamLog()<<std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }

    //ordenar segun codigo iata
    center->getAeropuertos()->ordenar();
    std::cout<<"Vector ordenado: "<<std::endl;

    for(int i=0;i<40;i++){
       std::cout<<center->getAeropuertos()->operator[](i).getIata()<<" ";
    }
std::cout<<std::endl;



    std::cout<<"Lectura de Rutas: "<<std::endl;
    std::ifstream is2;
    std::stringstream  columnas2;
    std::string fila2;
    int cont2=0;



    std::string iatarut="";
    std::string aero1="";
    std::string aero2="";



    is2.open("C://Users//jacob//OneDrive//Escritorio//EEDD//Practice1//rutas_v1.csv"); //carpeta de proyecto
    if ( is2.good() ) {

        clock_t t_ini = clock();

        while ( (getline(is2, fila2 ))&&cont2<10000) {

            //Â¿Se ha leÃ­do una nueva fila?
            if (fila2!="") {

                columnas2.str(fila2);


                getline(columnas2,iatarut,';');
                getline(columnas2,aero1,';');
                getline(columnas2,aero2,';');



                fila2="";
                columnas2.clear();
                center->getRutas()->insertaInicio(*(new Ruta(iatarut,new Aeropuerto(aero1),new Aeropuerto(aero2))));

            }
            cont2++;
        }

        is2.close();

        std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;

    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
    std::cout<<"Cabecera: "<<center->getRutas()->getCabecera()->dato.getAerolinea()<<std::endl;
    std::cout<<"Cola: "<<center->getRutas()->getCola()->dato.getAerolinea()<<std::endl;
    std::cout<<"Numero de nodos: "<<center->getRutas()->tam()<<std::endl;

    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Conectamos todos los aereopuertos que se pueda"<<std::endl;
    center->conecta();
    std::cout<<center->getconectados()->getCabecera()->dato.getOrigen()->getIata()<<std::endl;
    std::cout<<center->getconectados()->getCabecera()->dato.getDestination()->getIata()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Rutas entre NUP y ATT:"<<std::endl;
    int NUPpos=center->getAeropuertos()->busquedaBin(*center->getconectados()->getCabecera()->dato.getOrigen());
    int ATTpos=center->getAeropuertos()->busquedaBin(*center->getconectados()->getCabecera()->dato.getDestination());
    Aeropuerto airport1=center->getAeropuertos()->operator[](NUPpos);
    Aeropuerto airport2=center->getAeropuertos()->operator[](ATTpos);
    std::cout<<center->buscaRutasOriDes(airport1,airport2).getAerolinea()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"Rutas entre GRX y GB:"<<std::endl;

    Aeropuerto* airport3= new Aeropuerto("GRX");
    Aeropuerto* airport4= new Aeropuerto("GB");
    std::cout<<center->buscaRutasOriDes(*airport3,*airport4).getAerolinea()<<std::endl;
    delete airport3;
    delete airport4;

    center->addNuevaRuta(*new Ruta("IBE",new Aeropuerto("CDG"),new Aeropuerto("IBE")));
    delete center;


    return 0;

}
