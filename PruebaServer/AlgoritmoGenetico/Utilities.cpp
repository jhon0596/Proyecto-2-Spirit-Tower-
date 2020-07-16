//
// Created by jrodr on 15/7/2020.
//

#include "Utilities.h"
int Utilities::random(int min, int max) {
    bool flag=true;
    int nume=0;
    while(flag){
        if(nume<min){
            std::random_device rd;
            std::mt19937 num(rd());
            std::uniform_int_distribution<> dist(min,max);
            nume=dist(num);

        }else{flag=false;}


    }




    return nume;
}

float Utilities::random(float min, float max) {
    std::random_device rd;
    std::mt19937 num(rd());
    std::uniform_real_distribution<> dist(min,max);
    return dist(num);
}

int Utilities::randoms(int min, int max) {
    srand(time(NULL));
    int num;
    num =min+rand()%(max-1);



    return num;
}