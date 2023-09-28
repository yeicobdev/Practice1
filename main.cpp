#include <iostream>
#include "VDinamico.h"
#include <cstdlib>
int main() {
    try {
        VDinamico<int> *p = new VDinamico<int>();
        for (int i = 0; i < 20; i++) {
             p->insertar(rand(),i);
        }
        for (int i = 0; i < 20; i++) {
            std::cout << (*p)[i] << " ";
        }
        std::cout << std::endl;
        p->ordenar();
        for (int i = 0; i < 20; i++) {
            std::cout << (*p)[i] << " ";
        }
        std::cout << std::endl;
        p->ordenarRev();
        for (int i = 0; i < 20; i++) {
            std::cout << (*p)[i] << " ";
        }
        delete p;
    }catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

}
