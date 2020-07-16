//
// Created by jrodr on 14/7/2020.
//

#include "algoritmoGenetico.h"
void algoritmoGenetico::swap(NodoEspectro *a, NodoEspectro *b)
{
    Espectro* temp = a->getEspectro();
    a->setEspectro(b->getEspectro()) ;
    b->setEspectro(temp);
}

void algoritmoGenetico::bubbleSort(ListaEspectros *start)
{
    int swapped, i;
    NodoEspectro *ptr1;
    NodoEspectro *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start->head;

        while (ptr1->getNext() != lptr)
        {
            if (ptr1->getEspectro()->calcFitn() < ptr1->getNext()->getEspectro()->calcFitn())
            {
                swap(ptr1, ptr1->getNext());
                swapped = 1;
            }
            ptr1 = ptr1->getNext();
        }
        lptr = ptr1;
    }
    while (swapped);
}
algoritmoGenetico::algoritmoGenetico() {


}
void algoritmoGenetico::cruzarPoblacion(ListaEspectros *listaEspectros)  {
    int MutationRate = 25; // We are going to use this for mutation of genes 1000 = 100% 1 = .01% mutation rate
    int InversionRate = 5;
    srand(time(NULL));

    //create a population and initialize it with random DNA, also set the fitness to 0
    LE = listaEspectros;

    //we will use a variable to keep track of how many generations there have been
    Generation ++;
    //we sort the List so, we have the best gladiator upfront
    bubbleSort(LE);

    ListaEspectros* LPadres = new ListaEspectros();
    NodoEspectro* temp1 = LE->head;
    for (int i=0;i<10;i++){
        LPadres->add(temp1->getgladiador());
        temp1 = temp1->getNext();
    }

    for (int i=0;i<5;i++){

        Espectro* glad1 = LPadres->head->getEspectro();
        Espectro* glad2 = LPadres->head->getNext()->getEspectro();
        LPadres->head = LPadres->head->getNext()->getNext();
        int manu = LPadres->getSize();
        manu--;
        manu--;
        LPadres->setSize(manu);

        std::bitset<30> btG1(glad1->atributos);
        std::bitset<30> btG2(glad2->atributos);
        int arry[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        int j=0;
        std::bitset<6> tmp;
        for(int l=0;l<31;l++){
            if(l<=12){
                if(j<6){
                    tmp[j]=btG1[l];
                    j++;

                }else{
                    j=0;
                    if(l<=6){
                        for(int m = 0;m<6;m++){
                            arry[m] = tmp[m];
                        }
                    }else if(l>6 && l<=12){
                        for(int m = 0;m<6;m++){
                            arry[m+6] = tmp[m];
                        }
                    }

                    tmp.reset();
                    tmp[j]=btG1[l];
                    j++;
                }
            }else{
                if(j<6){
                    tmp[j]=btG2[l];
                    j++;

                }else{
                    j=0;
                    if(l>12 && l<=18){
                        for(int m = 0;m<6;m++){
                            arry[m+12] = tmp[m];
                        }
                    }else if(l>18 && l<=24){
                        for(int m = 0;m<6;m++){
                            arry[m+18] = tmp[m];
                        }
                    }else if(l>24 && l<=31){
                        for(int m = 0;m<6;m++){
                            arry[m+24] = tmp[m];
                        }
                    }

                    tmp.reset();
                    tmp[j]=btG2[l];
                    j++;

                }
            }
        }

        std::bitset<30> nuevoGen;
        for(int n=0;n<31;n++){
            nuevoGen[n] = arry[n];
        }

        int muta = (unsigned)Utilities::random(0,1000);
        if( muta < MutationRate){
            srand(time(NULL));
            int nuevoflip = (unsigned)Utilities::random(0,24);
            int cambio = 0;
            if(muta < InversionRate){
                if(nuevoflip< 6){
                    for (int o=0;o<6;o++){
                        nuevoGen[o].flip();
                        cambio++;
                    }
                }else if(nuevoflip>=6 && nuevoflip<12){
                    for (int o=0;o<6;o++){
                        nuevoGen[o+6].flip();
                        cambio++;
                    }
                }else if(nuevoflip>=12 && nuevoflip<18){
                    for (int o=0;o<6;o++){
                        nuevoGen[o+12].flip();
                        cambio++;
                    }
                }else if(nuevoflip>=18 && nuevoflip<24){
                    for (int o=0;o<6;o++){
                        nuevoGen[o+18].flip();
                        cambio++;
                    }
                }else if(nuevoflip>=24 && nuevoflip<30){
                    for (int o=0;o<6;o++){
                        nuevoGen[o+24].flip();
                        cambio++;
                    }
                }
            }
            if(cambio == 0){
                nuevoGen[nuevoflip].flip();
            }

        }

        Espectro* nuevoIntegrante = new Espectro("Espectro" + std::to_string(Generation),nuevoGen.to_string());
        LE->add(nuevoIntegrante);
    }
    bubbleSort(LE);

    for (int p = 0; p<5;p++){
        LE->deleteL();
    }
}


