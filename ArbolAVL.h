//
// Created by jacob on 23/10/2023.
//

#ifndef ARBOLAVL_ARBOLAVL_H
#define ARBOLAVL_ARBOLAVL_H
#include "VDinamico.h"

template <typename T>
class NodoAVL{
public:
    NodoAVL<T> *izq, *der;
    T dato;
    char bal;
    NodoAVL(T& ele);
};



template<typename T>
NodoAVL<T>::NodoAVL(T &ele): izq(nullptr),der(nullptr),bal(0),dato(ele) {
}





template <typename T>
class Avl{
private:
    NodoAVL<T>* replicaPreorden(NodoAVL<T>*&a,NodoAVL<T>*b);
    void borradoPostorden(NodoAVL<T>*& a);
    void rotIzqda(NodoAVL<T>* &p);
    void rotDecha(NodoAVL<T>* &p);
    int inserta(NodoAVL<T>* &c,T& dato);
    void recorridoInorden(VDinamico<T*>& v,NodoAVL<T>* &p);
    void contarElementos(NodoAVL<T>*& n,int& a);
    NodoAVL<T>* buscaClave(T& ele,NodoAVL<T> *&p);
    void buscaIterando(T& ele,NodoAVL<T> *&p,NodoAVL<T>*& retorno);
    void alturaRec(int& cont,int& alt,NodoAVL<T>* &p);


public:
    NodoAVL<T>* raiz;
    Avl();
    Avl(const Avl<T>& otro);
    ~Avl();
    Avl<T>& operator= (Avl<T>& otro);
    bool inserta(T& dato);
    VDinamico<T*>& recorreInorden();
    int numElementos();
    T* buscaRec(T& dato);
    T* buscaIt(T& dato);
    int altura();





};

template<typename T>
void Avl<T>::alturaRec(int &cont, int &alt, NodoAVL<T> *&p) {
    if(p) {
        cont++;
        alturaRec(cont, alt, p->izq);
        alturaRec(cont, alt, p->der);
        if (alt < cont) {
            alt = cont;
        }
        cont--;
    }
}


template<typename T>
int Avl<T>::altura() {
    int contador=-1;
    int altura=0;
    alturaRec(contador,altura,raiz);
    return altura;

}

template<typename T>
void Avl<T>::buscaIterando(T &ele, NodoAVL<T> *&p,NodoAVL<T>*& retorno) {

if(p){
    buscaIterando(ele,p->izq,retorno);
    if(ele==p->dato){
        retorno=p;
    }
    buscaIterando(ele,p->der,retorno);
}
}

template<typename T>
T *Avl<T>::buscaIt(T &dato) {
    NodoAVL<T>* toret= nullptr;
    buscaIterando(dato,raiz,toret);
    return &toret->dato;

}

template<typename T>
NodoAVL<T> *Avl<T>::buscaClave(T &ele, NodoAVL<T> *&p) {
    if (!p) {
        return nullptr;
    }
    else if (ele < p->dato){
        return buscaClave (ele, p->izq);
    }

    else if (ele > p-> dato){
        return buscaClave (ele, p->der);
    }

    else {
        return p;
    }

}

template<typename T>
T *Avl<T>::buscaRec(T &dato) {
Nodo<T> *p = buscaClave(dato,raiz);
return (&p->dato);
}

template<typename T>
void Avl<T>::contarElementos(NodoAVL<T> *&n, int& a) {
if(n){
    contarElementos(n->izq,a);
    a++;
    contarElementos(n->der,a);
}
}

template<typename T>
int Avl<T>::numElementos() {
    int toret=0;
    contarElementos(raiz,toret);
    return toret;
}

template<typename T>
void Avl<T>::recorridoInorden(VDinamico<T*> &v, NodoAVL<T> *&p) {
    if(p) {
        recorridoInorden(v, p->izq);
        v.inserta(&(p->dato));
        recorridoInorden(v, p->der);
    }
}


template<typename T>
VDinamico<T*>& Avl<T>::recorreInorden() {
    VDinamico<T*>* toret=(new VDinamico<T*>());
    recorridoInorden((*toret),raiz);
    return (*toret) ;
}

template<typename T>
bool Avl<T>::inserta(T &dato) {
    return inserta(raiz,dato);
}

template<typename T>
int Avl<T>::inserta(NodoAVL<T> *&c, T &dato) {
    NodoAVL<T> *p = c;
    int deltaH = 0;
    if (!p){
        p = new NodoAVL<T>(dato);
        c = p; deltaH=1;
    }
    else if (dato > p->dato){
        if (inserta(p->der, dato)){
            p->bal--;
            if (p->bal == -1) deltaH=1;
            else if (p->bal == -2) {
                if (p->der->bal == 1) rotDecha(p->der);
                rotIzqda(c);
            } } }
    else if (dato < p->dato){
        if (inserta(p->izq, dato)){
            p->bal++;
            if (p->bal==1) deltaH = 1;
            else if (p->bal == 2){
                if (p->izq->bal == -1) rotIzqda(p->izq);
                rotDecha(c);
            } } }
    return deltaH;
}



template<typename T>
void Avl<T>::rotDecha(NodoAVL<T> *&p) {
    NodoAVL<T> *q = p, *l;
    p = l = q->izq;
    q->izq = l->der;
    l->der = q;
    q->bal--;
    if (l->bal > 0) {
        q->bal -= l->bal;
    }
    l->bal--;
    if(q->bal < 0) {
        l->bal -= -q->bal;
    }
}

template<typename T>
void Avl<T>::rotIzqda(NodoAVL<T> *&p) {
    NodoAVL<T> *q = p, *r;
    p = r = q->der;
    q->der = r->izq;
    r->izq = q;
    q->bal++;
    if (r->bal < 0) {
        q->bal += -r->bal;
    r->bal++;
    }
    if(q->bal > 0){
        r->bal += q->bal;
    }
}

template<typename T>
Avl<T> &Avl<T>::operator=(Avl<T> &otro) {
    if(this!=&otro){
    borradoPostorden(raiz);
    replicaPreorden(raiz,otro.raiz);
        }
    return (*this) ;
}

template<typename T>
void Avl<T>::borradoPostorden(NodoAVL<T> *&a) {
if(a){
    borradoPostorden(a->izq);
    borradoPostorden(a->der);
    delete a;
}
}

template<typename T>
Avl<T>::~Avl() {
    borradoPostorden(raiz);
}

template<typename T>
NodoAVL<T> *Avl<T>::replicaPreorden(NodoAVL<T> *&a,NodoAVL<T>*b) {
if(b) {
    a = new Nodo<T>(b->dato);
    replicaPreorden(a->izq, b->izq);
    replicaPreorden(a->der, b->der);
}
    return a;
}



template<typename T>
Avl<T>::Avl(const Avl<T> &otro) {
    raiz=replicaPreorden(raiz,otro.raiz);
}


template<typename T>
Avl<T>::Avl():raiz(nullptr) {
}


#endif //ARBOLAVL_ARBOLAVL_H
