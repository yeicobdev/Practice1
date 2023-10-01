//
// Created by jacob on 01/10/2023.
//

#ifndef PRACTICE1_UTM_H
#define PRACTICE1_UTM_H
#include <iostream>

class UTM {
private:
    float latitud;
    float longitud;
public:
    UTM()=default;
    UTM(const float& lat,const float& lon);
    UTM(const UTM& otro);
    ~UTM();
    float getLatitud()const;
    float getLontitud()const;
    UTM& setLatitud(const float& lat);
    UTM& setLongitud(const float& lon);
UTM& operator=(const UTM& otro);

};


#endif //PRACTICE1_UTM_H
