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
    VDinamico<T>(int n);
    VDinamico<T>(const VDinamico<T>& origen);
    VDinamico<T>(const VDinamico<T>& origen,unsigned int posInicial,unsigned int numElementos);
    VDinamico<T>& operator=(const VDinamico<T>& origen);
    T& operator[](int pos);
    void ordenar();
    void ordenarRev();
    int getTam()const;


            };

void filtroNConstructor(int n){
    if(n<=0)
    {
        throw std::invalid_argument("0 o menor");
    }
}
template<class T>
void filtroMemoriaConstructor(T* p){
    if(p= nullptr){
        throw std::bad_alloc();
    }
}


template<class T>
VDinamico<T>::VDinamico(int n):tam(n) {
    filtroNConstructor(tam);
    mem=new T[tam];
    filtroMemoriaConstructor(mem);
};


template<class T>
int VDinamico<T>::getTam() const {
    return tam;
}

template<class T>
void VDinamico<T>::ordenarRev() {
    for(int i=0;i<tam;i++) {
        for (int j = 0; j < tam - 1; j++) {
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
    for(int i = 0; i<tam; i++)
    {
        flag = false;
        for(int j = 0; j < tam-i-1; j++)
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
    if((pos>=tam)||(pos<0))
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
    if((posInicial<0)||(posInicial>numElementos)||posInicial>=origen.tam)
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
VDinamico<T>::VDinamico(const VDinamico<T> &origen) {
    filtroNConstructor(origen.tam);
    mem=new T[origen.tam];
    filtroMemoriaConstructor(mem);
    for(int i=0;i<tam;i++)
    {
        mem[i]= origen.mem[i];
    }
}


#endif //PRACTICE1_VDINAMICO_H
