#include <iostream>
#include "VDinamico.h"
#include <cstdlib>
int main() {
    try {
        VDinamico<int> *p = new VDinamico<int>(20);
        for (int i = 0; i < p->getTam(); i++) {
            (*p)[i] = rand();
        }
        for (int i = 0; i < p->getTam(); i++) {
            std::cout << (*p)[i] << " ";
        }
        std::cout << std::endl;
        p->ordenar();
        for (int i = 0; i < p->getTam(); i++) {
            std::cout << (*p)[i] << " ";
        }
        std::cout << std::endl;
        p->ordenarRev();
        for (int i = 0; i < p->getTam(); i++) {
            std::cout << (*p)[i] << " ";
        }
        delete p;
    }catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

}
