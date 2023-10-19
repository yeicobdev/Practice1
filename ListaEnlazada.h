//
// Created by jacob on 09/10/2023.
//

#ifndef PRACTICE1_LISTAENLAZADA_H
#define PRACTICE1_LISTAENLAZADA_H



template <class T>
class Nodo;
template<class T>
class ListaEnlazada;

template <class T>
class Iterador{

    Nodo<T>* nodo;
    friend class ListaEnlazada<T>;
public:
    Iterador()=default;

    Iterador(Nodo<T>* aNodo);
    bool fin();
    void siguiente();
    T& dato();
    T& operator* ();
    Iterador<T>& setNodo(Nodo<T>* nodo);
    Nodo<T>* getNodo();


};

template<class T>
Nodo<T>* Iterador<T>::getNodo() {
    return nodo;
}

template<class T>
Iterador<T> &Iterador<T>::setNodo(Nodo<T> *anodo) {
    this->nodo=anodo;
    return (*this);
}

template<class T>
T &Iterador<T>::operator*() {
    return nodo->dato;
}

template<class T>
T &Iterador<T>::dato() {
    return nodo->dato;
}

template<class T>
void Iterador<T>::siguiente() {
    nodo=nodo->sig;
}

template<class T>
bool Iterador<T>::fin() {
    return nodo == nullptr;
}

template<class T>
Iterador<T>::Iterador(Nodo<T> *aNodo):nodo(aNodo) {
}


template <class T>
class Nodo {
public:
    T dato;
    Nodo* sig;
    Nodo()=default;
    Nodo(const T &adato, Nodo* asig=nullptr);
    Nodo(const Nodo& otro);
    ~Nodo();
};



template<class T>
Nodo<T>::Nodo(const Nodo &otro):dato(otro.dato),sig(otro.sig) {
}

template<class T>
Nodo<T>::~Nodo() {
}

template<class T>
Nodo<T>::Nodo(const  T &adato, Nodo *asig): dato(adato),sig(asig) {
}









template <class T>
class ListaEnlazada {
private:
    Nodo<T>* cabecera;
    Nodo<T>* cola;
public:
    ListaEnlazada<T>();
    ListaEnlazada<T>(ListaEnlazada<T>& otro);
    ~ListaEnlazada();
    ListaEnlazada<T>& operator=(ListaEnlazada<T>& otro);
    T& inicio();
    T& fin();
    void insertaInicio(const T& dato);
    void insertaFin(const T& dato);
    Nodo<T>* getCabecera();
    Nodo<T>* getCola();
    void inserta(const Iterador<T>&i,const T& dato);
    void insertaDetras(const Iterador<T>& i,const T& dato);
    void borraInicio();
    void borraFinal();
    void borra( Iterador<T>& i);
    int tam();
    ListaEnlazada<T>& concatena(ListaEnlazada<T>& l);
    ListaEnlazada<T>& operator+(ListaEnlazada<T>& l);


};

template<class T>
ListaEnlazada<T> &ListaEnlazada<T>::operator+(ListaEnlazada<T> &l) {
    return concatena(l);
}

template<class T>
ListaEnlazada<T> &ListaEnlazada<T>::concatena(ListaEnlazada<T> &l) {
    ListaEnlazada<T>* toret=new ListaEnlazada(*this);
    ListaEnlazada<T>* b=new ListaEnlazada(l);
    toret->cola->sig=b->cabecera;
    toret->cola=b->cola;
    return (*toret);

}

template<class T>
int ListaEnlazada<T>::tam() {
    int toret=0;
    Iterador<int>* i= new Iterador(cabecera);
    while (!i->fin()){
        toret++;
        i->siguiente();
    }
    delete i;
    return toret;
}

//para poder borrar muchos datos a seguidos he considerado que en esta funcion el iterador  apunte al nodo
//siguiente al borrado
template<class T>
void ListaEnlazada<T>::borra( Iterador<T> &i) {
    Nodo<T>* anterior= nullptr;
    if(cabecera!=cola){
        anterior=cabecera;
        while (anterior->sig!= i.nodo){
            anterior=anterior->sig;
        }
        anterior->sig=i.nodo->sig;

        delete i.nodo;
        i.nodo=anterior->sig;
    }
}

template<class T>
void ListaEnlazada<T>::borraFinal() {
    Nodo<T>* anterior= nullptr;
    if(cabecera!=cola){
        anterior=cabecera;
        while(anterior->sig!=cola){
            anterior=anterior->sig;
        }
    }
    delete cola;
    cola=anterior;
    if(anterior!= nullptr){
        anterior->sig= nullptr;

    }
    else{
        cabecera= nullptr;
    }
}

template<class T>
void ListaEnlazada<T>::borraInicio() {
    Nodo<T>* borrado=cabecera;
    cabecera=cabecera->sig;
    delete borrado;
    if(cabecera== nullptr){
        cola=nullptr;
    }
}

template<class T>
void ListaEnlazada<T>::insertaDetras(const Iterador<T> &i, const T &dato) {
    Nodo<T>* nuevo=new Nodo<T>(dato,i.nodo->sig);
    if (cola==i.nodo){
        Nodo<T>* aux=cola;
        cola=nuevo;
        aux->sig=cola;
        return;
    }
    i.nodo->sig=nuevo;
}

template<class T>
void ListaEnlazada<T>::inserta(const Iterador<T> &i, const T &dato) {
    Nodo<T>* nuevo=new Nodo<T>(dato,i.nodo);
    if(i.nodo==cabecera){
        Nodo<T>* aux=cabecera;
        cabecera=nuevo;
        nuevo->sig=aux;
        return;

    }

    if(cabecera!=cola){
        Nodo<T>* anterior= nullptr;
        anterior=cabecera;
        while (anterior->sig!=i.nodo){
            anterior=anterior->sig;
        }
        anterior->sig=nuevo;
        return;
    }

    if(cabecera== nullptr){
        cabecera=cola=nuevo;
        return;
    }
}

template<class T>
Nodo<T>* ListaEnlazada<T>::getCola() {
    return cola;
}

template<class T>
Nodo<T>* ListaEnlazada<T>::getCabecera() {
    return cabecera;
}

template<class T>
void ListaEnlazada<T>::insertaFin(const T &dato) {
    if(cola==nullptr){
        cola=new Nodo<T>(dato);
        cabecera=cola;
        return;
    }
    cola->sig=new Nodo<T>(dato);
    cola=cola->sig;
}

template<class T>
void ListaEnlazada<T>::insertaInicio(const T &dato) {
    if(cabecera== nullptr){
        cabecera=new Nodo<T>(dato);
        cola=cabecera;
        return;
    }
    Nodo<T>* p=cabecera;
    cabecera=new Nodo<T>(dato,p);
}


template<class T>
T &ListaEnlazada<T>::fin() {
    return cola->dato;
}

template<class T>
T &ListaEnlazada<T>::inicio() {
    return cabecera->dato;
}

template<class T>
ListaEnlazada<T> &ListaEnlazada<T>::operator=(ListaEnlazada<T> &otro) {
    Nodo<T>* w=cabecera;
    while (w){
        cabecera=cabecera->sig;
        delete w;
        w=cabecera;

    }
    cabecera=new Nodo<T>(otro.cabecera->dato);
    Nodo<T>* p=cabecera;
    Nodo<T>* a=otro.cabecera;


    while (a->sig!=nullptr){
        p->sig=new Nodo<T>(a->sig->dato);
        p=p->sig;
        a=a->sig;
    }
    cola=p;
    return (*this);
}

template<class T>
ListaEnlazada<T>::~ListaEnlazada() {
    Nodo<T>* p=cabecera;
    while (p){
        cabecera=cabecera->sig;
        delete p;
        p=cabecera;

    }

}

template<class T>
ListaEnlazada<T>::ListaEnlazada(ListaEnlazada<T> &otro) {
    cabecera=new Nodo<T>(otro.cabecera->dato);
    Nodo<T>* p=cabecera;
    Nodo<T>* a=otro.cabecera;


    while (a->sig!=nullptr){
        p->sig=new Nodo<T>(a->sig->dato);
        p=p->sig;
        a=a->sig;
    }
    cola=p;

}



template<class T>
ListaEnlazada<T>::ListaEnlazada():cabecera(nullptr),cola(nullptr) {
}


#endif //PRACTICE1_LISTAENLAZADA_H
