//
// Created by jacob on 09/10/2023.
//

#ifndef PRACTICE1_LISTAENLAZADA_H
#define PRACTICE1_LISTAENLAZADA_H



template <class T>
class Nodo {
public:
    T dato;
    Nodo* sig;

    Nodo(T &adato,Nodo* asig=nullptr);
    Nodo(const Nodo& otro);
    Nodo(const T& dato);
    ~Nodo();
};

template<class T>
Nodo<T>::Nodo(const T &dato):dato(dato) {
}

template<class T>
Nodo<T>::Nodo(const Nodo &otro):dato(otro.dato),sig(otro.sig) {
}

template<class T>
Nodo<T>::~Nodo() {
}

template<class T>
Nodo<T>::Nodo(T &adato, Nodo *asig): dato(adato),sig(asig) {
}


template <class T>
class ListaEnlazada {
private:
    Nodo<T>* cabecera;
    Nodo<T>* cola;
public:
    ListaEnlazada<T>();
    ListaEnlazada<T>(const ListaEnlazada<T>& otro);
    ~ListaEnlazada();
    ListaEnlazada<T>& operator=(ListaEnlazada<T>& otro);


};

template<class T>
ListaEnlazada<T> &ListaEnlazada<T>::operator=(ListaEnlazada<T> &otro) {
    Nodo<T>* w=cabecera;
    while (w){
        cabecera=cabecera->sig;
        delete w;
        w=cabecera;

    }
    cabecera=new Nodo<T>(*otro.cabecera->dato);
    Nodo<T>* p=cabecera;
    Nodo<T>* a=otro.cabecera;


    while (a->sig!=nullptr){
        p->sig=new Nodo<T>(*a->sig->dato);
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
ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada<T> &otro) {
    cabecera=new Nodo<T>(*otro.cabecera->dato);
    Nodo<T>* p=cabecera;
    Nodo<T>* a=otro.cabecera;


while (a->sig!=nullptr){
        p->sig=new Nodo<T>(*a->sig->dato);
        p=p->sig;
        a=a->sig;
}
cola=p;

}



template<class T>
ListaEnlazada<T>::ListaEnlazada():cabecera(nullptr),cola(nullptr) {
}


#endif //PRACTICE1_LISTAENLAZADA_H
