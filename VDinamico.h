//
// Created by jacob on 18/09/2023.
//

#ifndef PRACTICE1_VDINAMICO_H
#define PRACTICE1_VDINAMICO_H
#include <math.h>



int potencia2(int n) {
    int potencia=2;
    if(n<=0)
    {
        throw std::invalid_argument("n invalido");
    }
    while (n>potencia){
        potencia = pow(potencia,2);
    }
    return potencia;
}



template<class T>
void filtroMemoriaConstructor(T* p){
    if(p == nullptr){
        throw std::bad_alloc();
    }
}

template <class T>
class VDinamico{
    T* mem=nullptr;
    long int tamFis;
    long int tamLog;
public:
    VDinamico<T>();
    VDinamico<T>(int n);
    VDinamico<T>(const VDinamico<T>& origen);
    VDinamico<T>(const VDinamico<T>& origen,unsigned int posInicial,unsigned int numElementos);
    VDinamico<T>& operator=(const VDinamico<T>& origen);
    T& operator[](int pos);
    void ordenar();
    void ordenarRev();
    int getTam()const;
    void insertar(const T& dato,unsigned int pos =UINT_MAX);
    void posicionValida(const int& n);
    void borrar(unsigned int pos =UINT_MAX);


            };

template<class T>
void VDinamico<T>::borrar(unsigned int pos) {
    if(pos==UINT_MAX){
        delete mem[tamLog-1];
        tamLog--;
        return;
    }
    delete mem[pos];
    mem[pos]=nullptr;
    for(int i=pos;i<tamLog;i++)
    {
        mem[i]=mem[i+1];
    }
    tamLog--;

}

template<class T>
void VDinamico<T>::posicionValida(const int &n) {
if((n>tamLog)||(n<0))
{
    throw std::invalid_argument("Pos invalida");
}
}


template<class T>
void VDinamico<T>::insertar(const T &dato, unsigned int pos) {
    posicionValida(pos);

    if(pos==UINT_MAX){
        tamLog++;
        mem[tamLog-1]=dato;
        return;

    }

    if(tamFis==tamLog)
    {
        T* memaux=new T[ tamFis= potencia2(tamLog)];
        for(int i=0;i<tamLog;i++)
        {
            memaux[i]=mem[i];
        }
        delete[] mem;
        mem=memaux;


    }



    mem[pos]=dato;
    tamLog++;

}




template<class T>
VDinamico<T>::VDinamico():tamFis(1),tamLog(0) {
    mem=new T[tamFis];
    filtroMemoriaConstructor(mem);

}





template<class T>
VDinamico<T>::VDinamico(int n): tamLog(n){
    tamFis=potencia2(tamLog);
    mem=new T[tamFis];
    filtroMemoriaConstructor(mem);
};


template<class T>
int VDinamico<T>::getTam() const {
    return tamLog;
}

template<class T>
void VDinamico<T>::ordenarRev() {
    for(int i=0;i<tamLog;i++) {
        for (int j = 0; j < tamLog - 1; j++) {
            if (mem[j] < mem[j + 1]) {
                T aux=mem[j];
                mem[j]=mem[j+1];
                mem[j+1]=aux;}
        }
        }
    }


template<class T>
void VDinamico<T>::ordenar() {
    bool flag;
    for(int i = 0; i<tamLog; i++)
    {
        flag = false;
        for(int j = 0; j < tamLog-i-1; j++)
        {
            if( mem[j] > mem[j+1])
            {
                T aux=mem[j];
                mem[j]=mem[j+1];
                mem[j+1]=aux;
                flag = true;
            }
        }
        if(!flag)
        {
            break;
        }
    }
}

template<class T>
T &VDinamico<T>::operator[](int pos) {
    if((pos>=tamLog)||(pos<0))
    {
        throw std::invalid_argument("pos invalida");
    }
    return mem[pos];
}

template<class T>
VDinamico<T>& VDinamico<T>::operator=(const VDinamico<T> &origen) {
    if(&origen!=this)
    {
        delete[]mem;
        tamFis=origen.tamFis;
        tamLog=origen.tamLog;
        mem=new T[tamFis];
        for(int i=0;i<tamLog;i++)
        {
            mem[i]=origen.mem[i];
        }
    }
    return *this;
}

template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen, unsigned int posInicial, unsigned int numElementos):tamLog(numElementos),tamFis(potencia2(numElementos)) {
    if((posInicial<0)||(posInicial>numElementos)||posInicial>=origen.tamLog)
    {
        throw std::invalid_argument("Fallo en posInicial");
    }
    if((numElementos>origen.tam)||(numElementos<=0)){
        throw std::invalid_argument("Fallo en numElementos");
    }
    mem=new T[numElementos];
    filtroMemoriaConstructor(mem);
    for(int i=0;i<numElementos;i++)
    {
        mem[i]= origen.mem[i+posInicial];
    }
}

template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen):tamLog(origen.tamLog),tamFis(origen.tamFis) {
    mem=new T[tamFis];
    filtroMemoriaConstructor(mem);
    for(int i=0;i<tamLog;i++)
    {
        mem[i]= origen.mem[i];
    }
}


#endif //PRACTICE1_VDINAMICO_H
