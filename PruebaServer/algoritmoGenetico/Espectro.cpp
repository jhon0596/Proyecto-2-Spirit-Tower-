//
// Created by jrodr on 20/7/2020.
//

#include "Espectro.h"
#include "Utilities.h"
Espectro::Espectro(std::string nm) {
    this->unTag=nm;

    //"Rart","Rarq","Rm","Rf","vel"
    this->gen =1;
    std::bitset<6> vr((unsigned)Utilities::random(1, 10));
    std::bitset<6> vp((unsigned)Utilities::random(1, 10));
    std::bitset<6> ataque((unsigned)Utilities::random(1, 10));
    std::bitset<6> defensa((unsigned)Utilities::random(1,10));
    std::bitset<6> rv((unsigned)Utilities::random(1,10));



    std::string mystring =defensa.to_string();
    mystring.append(ataque.to_string());
    mystring.append( rv.to_string());
    mystring.append(vp.to_string());
    mystring.append( vr.to_string());



    std::bitset<30> set18(mystring);

    atributo[0]=vr.to_ulong();
    atributo[1]=vp.to_ulong();
    atributo[2]=rv.to_ulong();
    atributo[3]=ataque.to_ulong();
    atributo[4]=defensa.to_ulong();

    this->atributos =(int)set18.to_ulong();
    this->vida = calcFitn()*5;

}



Espectro::Espectro(std::string nm, int vr, int vp, int rv, int ataque, int defensa)
{
    this->unTag=nm;
    std::bitset<6> vrBin(vr);
    std::bitset<6> vpBin(vp);
    std::bitset<6> ataqueBin(ataque);
    std::bitset<6> defensaBin(defensa);
    std::bitset<6> rvBin(rv);


    std::string mystring =defensaBin.to_string();
    mystring.append(ataqueBin.to_string());
    mystring.append( rvBin.to_string());
    mystring.append(vpBin.to_string());
    mystring.append( vrBin.to_string());
    std::bitset<30> set18(mystring);
    atributo[0]=vrBin.to_ulong();
    atributo[1]=vpBin.to_ulong();
    atributo[2]=rvBin.to_ulong();
    atributo[3]=ataqueBin.to_ulong();
    atributo[4]=defensaBin.to_ulong();




    this->atributos =(int)set18.to_ulong();
    this->vida = calcFitn()*5;


}

std::string Espectro::display() {

    std::bitset<30> set18(this->atributos);
    std::string sal="";
    sal.append(this->unTag+" ");
    int j=0, caract=0;
    std::bitset<6> tmp;
    for(int i=0;i<set18.size();i++){

        if(j<6){
            tmp[j]=set18[i];
            j++;

        }else{
            j=0;
            sal.append(this->txt[caract]+" ");
            sal.append(std::to_string(tmp.to_ulong())+" ");
            this->atributo[caract]=tmp.to_ulong();
            tmp.reset();
            tmp[j]=set18[i];
            j++,caract++;

        }


    }


    sal.append("fitness "+std::to_string(calcFitn()));
    //std::cout << set18<< std::endl;
    return sal;
}



void Espectro::fillSPECIAL() {
    std::bitset<30> set18((unsigned)this->atributos);

    int j=0, caract=0;
    std::bitset<6> tmp;
    for(int i=0;i<set18.size()+1;i++){

        if(j<6){
            tmp[j]=set18[i];
            j++;

        }else{
            j=0;
            this->atributo[caract]=tmp.to_ulong();
            tmp.reset();
            tmp[j]=set18[i];
            j++,caract++;

        }


    }
}

float Espectro::calcFitn() {
    int atr[5];

    std::bitset<30> set18(this->atributos);


    int j=0, atrFlg=0;
    std::bitset<6> tmp;
    for(int i=0;i<set18.size();i++){

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

    float fit=0;


    fit= (atr[0]+atr[1]+atr[2]+atr[3])/4;



    return fit;
}

Espectro::Espectro() {

}