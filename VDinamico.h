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
        mem=new T[tam];
    };
    VDinamico<T>(const VDinamico<T>& origen);
    VDinamico<T>(const VDinamico<T>& origen,unsigned int posInicial,unsigned int numElementos);
    VDinamico<T>& operator=(const VDinamico<T>& origen);
    T& operator[](int pos);
    void ordenar();
    void ordenarRev();
    int getTam()const;
    void swap(T a,T b);

            };

template<class T>
void VDinamico<T>::swap(T a, T b) {
    T aux=a;
    a=b;
    b=aux;
}

template<class T>
int VDinamico<T>::getTam() const {
    return tam;
}

template<class T>
void VDinamico<T>::ordenarRev() {
    for(int i=0;i<tam;i++) {
        for (int j = 0; j < tam - 1; j++) {
            if (mem[j] < mem[j + 1]) {
                swap(mem[j], mem[j + 1]);
            }
        }
    }
}

template<class T>
void VDinamico<T>::ordenar() {
    bool flag;
    for(int i = 0; i<tam; i++)
    {
        flag = false;
        for(int j = 0; j < tam-i-1; j++)
        {
            if( mem[j] > mem[j+1])
            {
                swap(mem[j],mem[j+1]);
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
