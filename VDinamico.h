//
// Created by jacob on 18/09/2023.
//

#ifndef PRACTICE1_VDINAMICO_H
#define PRACTICE1_VDINAMICO_H
template <class T>
class VDinamico{
    T* mem=nullptr;
    long int tam;
public:
    VDinamico<T>(unsigned int n):tam(n){
    };
    VDinamico<T>(const VDinamico<T>& origen);
    VDinamico<T>(const VDinamico<T>& origen,unsigned int posInicial,unsigned int numElementos);
    VDinamico<T>& operator=(const VDinamico<T>& origen);

            };

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
