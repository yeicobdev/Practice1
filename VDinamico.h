//
// Created by jacob on 18/09/2023.
//

#ifndef PRACTICE1_VDINAMICO_H
#define PRACTICE1_VDINAMICO_H
#include <algorithm>
template <class T>
class VDinamico{
    T* mem=nullptr;
    long int tam;
public:
    VDinamico<T>(unsigned int n):tam(n){
        mem=new T[n];
    };
    VDinamico<T>(const VDinamico<T>& origen);
    VDinamico<T>(const VDinamico<T>& origen,unsigned int posInicial,unsigned int numElementos);
    VDinamico<T>& operator=(const VDinamico<T>& origen);
    T& operator[]( int pos);
    ~VDinamico<T>();
    void ordenar();
    void ordenarRev();
    int getTam()const;
            };

template<class T>
int VDinamico<T>::getTam() const {
    return tam;
}

template<class T>
void VDinamico<T>::ordenarRev() {
    for(int i=0;i<tam;i++) {
        for (int q = 0; q < tam - 1; q++) {
            if (mem[q] < mem[q + 1]) {
                T aux = mem[q];
                mem[q] = mem[q + 1];
                mem[q + 1] = aux;
            }
        }
    }
}

template<class T>
void VDinamico<T>::ordenar() {
for(int i=0;i<tam-1;i++)
{
    for(int j=i+1;j<tam-i;j++)
    {
        if(mem[i]>mem[j])
        {
            T aux=mem[i];
            mem[i]=mem[j];
            mem[j]=aux;
        }
    }
}
}

template<class T>
VDinamico<T>::~VDinamico<T>() {
delete[] mem;
}

template<class T>
T& VDinamico<T>::operator[](int pos) {
    return mem[pos];
}

template<class T>
VDinamico<T>& VDinamico<T>::operator=(const VDinamico<T> &origen) {
    if(&origen!=this)
    {
        delete[]mem;
        tam=origen.tam;
        mem=new T[tam];
        for(int i=0;i<tam;i++)
        {
            mem[i]=origen.mem[i];
        }
    }
    return *this;
}

template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen, unsigned int posInicial, unsigned int numElementos) {
    mem=new T[numElementos];
    for(int i=0;i<numElementos;i++)
    {
        mem[i]= origen.mem[i+posInicial];
    }
}

template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen) {
    mem=new T[origen.tam];
for(int i=0;i<tam;i++)
{
    mem[i]= origen.mem[i];
}
}


#endif //PRACTICE1_VDINAMICO_H
