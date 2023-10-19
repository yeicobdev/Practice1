#include "Aeropuerto.h"
#include "VDinamico.h"
#include "ListaEnlazada.h"
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

    return 0;

}
