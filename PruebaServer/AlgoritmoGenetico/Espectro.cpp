//
// Created by jrodr on 14/7/2020.
//

#include "Espectro.h"
#include "Utilities.h"

void Espectro::fillSPECIAL() {
    /*special[0]=this->velRuta;
    special[1]=this->velPersecusion;
    special[2]= this->radioVision;
    special[3]=this->tipo;
    special[4]=this->nivel;
    special[5]=this->fitness;*/
}

Espectro::Espectro(std::string nm) {
    this->unTag=nm;

    std::bitset<6> velRuta((unsigned)Utilities::random(1,10));
    std::bitset<6> velPersecusion((unsigned)Utilities::random(7,15));
    std::bitset<6> radioVision((unsigned)Utilities::random(1,5));
    std::bitset<6> tipo((unsigned)Utilities::random(1,4));
    std::bitset<6> nivel((unsigned)Utilities::random(1,4));



    std::string mystring =velRuta.to_string();
    mystring.append( velPersecusion.to_string());
    mystring.append(radioVision.to_string());
    mystring.append(tipo.to_string());
    mystring.append( nivel.to_string());
    std::bitset<30> set18(mystring);


    this->atributos =(int)set18.to_ulong();
    this->resistencia = calcFitn();

}
Espectro::Espectro(std::string nm, std::string gen) {

    this->unTag=nm;



    std::bitset<6> velRuta(gen,24,6,'0','1');
    std::bitset<6> velPersecusion(gen,18,6,'0','1');
    std::bitset<6> radioVision(gen,12,6,'0','1');
    std::bitset<6> tipo(gen,6,6,'0','1');
    std::bitset<6> nivel(gen,0,6,'0','1');



    std::string mystring =velRuta.to_string();
    mystring.append( velPersecusion.to_string());
    mystring.append(radioVision.to_string());
    mystring.append(tipo.to_string());
    mystring.append( nivel.to_string());
    std::bitset<30> set18(mystring);


    this->atributos =(int)set18.to_ulong();
    this->resistencia = calcFitn();

}
std::string Espectro::display() {
    std::bitset<30> set18(this->atributos);
    std::string sal="";
    sal.append(this->unTag+" ");
    int j=0, caract=0;
    std::bitset<6> tmp;
    for(int i=0;i<set18.size()+1;i++){

        if(j<6){
            tmp[j]=set18[i];
            j++;

        }else{
            j=0;
            //sal.append(this->txt[caract]+" ");
            //sal.append(std::to_string(tmp.to_ulong())+" ");
            atributo[caract]=tmp.to_ulong();
            tmp.reset();
            tmp[j]=set18[i];
            j++,caract++;

        }


    }


    sal.append("fitness "+std::to_string(calcFitn()));
    //std::cout << set18<< std::endl;
    return sal;







}

float Espectro::calcFitn() {
    int atr[5];

    std::bitset<30> set18(this->atributos);


    int j=0, atrFlg=0;
    std::bitset<6> tmp;
    for(int i=0;i<set18.size()+1;i++){

        if(j<6){//pregunta si j es  mayor a 6
            tmp[j]=set18[i];
            j++;

        }else{
            j=0;

            atr[atrFlg]=(unsigned) tmp.to_ulong();
            tmp.reset();
            tmp[j]=set18[i];
            j++,atrFlg++;

        }


    }



    //(((velR+velP)*tipo)+nivel+ rv) formula del fitness


    return std::abs((((atr[0]+atr[1])*atr[3])+atr[4]+atr[2]));


}
