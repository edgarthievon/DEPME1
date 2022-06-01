//#include "Vecteur_case.h"
#include <stdio.h>
//#include "liste.h"
#include "../ing1-projet-2021-22-dofus-arena-team-d2/main.h"



void vCalcul(float premier[], float second[]){

    //coordo
    int Pg[2] = {3,500}; //gauche
    int Pb[2] = {800,1075}; //bas
    int Pt[2] = {975,40}; //top
    int Pr[2] = {1777,616}; //droite


    //calcul vecteur des cotés
    float Vtg[2] =  {Pt[0]-Pg[0], Pt[1]-Pg[1]};  //Vecteur top->gauche
    float Vbr[2] =  {Pg[0]-Pb[0], Pg[1]-Pb[1]};  //Vecteur bas->droite

    //calcul vecteur d'une demi case
    float Vmtg[2] =  {Vtg[0]/(nCase*2), Vtg[1]/(nCase*2)};  //Vecteur moitier top gauche
    float Vmbg[2] =  {Vbr[0]/(nCase*2), Vbr[1]/(nCase*2)};  //Vecteur moitier bas droite


    premier[0] = Vmtg[0];
    premier[1] = Vmtg[1];
    second[0] = Vmbg[0];
    second[1] = Vmbg[1];

}

void CalculNouvPoint(float Vmtg[], float Vmbg[], int nouv[], int caseT, int caseB){

    int pointDepart[2] = {3, 501};
    //Etape 1 pour déplacer le point vers le haut
    int etape1[2] = {pointDepart[0] + Vmtg[0]*caseT, pointDepart[1] + Vmtg[1]*caseT}; //ajout d'un vecteur au point de départ
    //Etape 2 pour déplacer le point vers le bas
    int etape2[2] = {etape1[0] - Vmbg[0]*caseB, etape1[1] - Vmbg[1]*caseB}; //ajout d'un vecteur au dernier point

    //point de retour
    nouv[0] = etape2[0];
    nouv[1] = etape2[1];
}

void CalculDroite(float *mm1, float *mm2, float *pp1, float *pp2){

    //on cherche l'équation réduite de d1 et d2 (top gauche) et (gauche bottom)
    //notée mx+p = y


    float m1;
    float p1;
    float m2;
    float p2;    

    int Pg[2] = {3,500}; //gauche
    int Pb[2] = {800,1075}; //bas
    int Pt[2] = {975,40}; //top
    int Pd[2] = {1777,616}; //droite


    //On cherche le coef directeur de d1 (m1) et d2 (m2)
    //m = (yA - yB) / (xA - xB)
    m1 = (float)(Pg[1] - Pt[1]) / (float)(Pg[0] - Pt[0]);
    m2 = (float)(Pt[1] - Pd[1]) / (float)(Pt[0] - Pd[0]);


    //on cherche maintenant p = (mx-y)*(-1)
    //on sait que nos point appartiennent aux droites 
    p1 = (m2 * (float)Pg[0] - (float)Pg[1] ) * (float)(-1);
    p2 = (m2 * (float)Pt[0] - (float)Pt[1] ) * (float)(-1);


    //returning values
    *mm1 = m1;
    *mm2 = m2;
    *pp1 = p1;
    *pp2 = p2;



}

void findPos(int x, int y, int *caseX, int *caseY, float m1, float m2, float p1, float p2){


    int ySave = -1; //si en dehors de map -1
    int xSave = -1; //si en dehors de map -1

    float res1;
    float res2;


    //On regarde si le y est plus petit ou plus grand que le y supposé
    //Ypoint - (mx+p) < 0

    int counter = 0;
    while (1) 
    {
        res1 = (float)y - (m1*(float)x + p1 + 90*counter); //90 = décallage de ordonnée à l'origine vu que parallèles (tattonage)

        if(res1 <= 0 && counter != 0) //si au dessus ou égale ok
        {
            ySave = counter;
            break;
        }

        if(counter == 10){ //en dehors
            break;
        }

        ++counter;
    }



    //On regarde si le y est plus petit ou plus grand que le y supposé
    //Ypoint - (mx+p) < 0

    counter = 0;
    while (1) 
    {
        res2 = (float)y - (m2*(float)x + p2 + 110*counter); //110 = décallage de ordonnée à l'origine vu que parallèles (tattonage)


        if(res2 <= 0 && counter != 0) //si au dessus ou égale ok
        {
            xSave = 11 - counter; //car vecteur inversé
            break;
        }

        if(counter == 10){ //en dehors
            break;
        }

        ++counter;
    }


    *caseX = xSave;
    *caseY = ySave;

}

void drawPath(int cCaseX, int cCaseY, int pCaseX, int pCaseY, Liste *liste, char matrix[10][10]){ 
    
    fullDelete(liste);

    short int caseXmov = pCaseX - cCaseX; //case à déplacer = case souris - case actuelle 
    short int caseYmov = pCaseY - cCaseY;

    short int caseXsave = cCaseX -1 ; 
    short int caseYsave = cCaseY -1 ;

    short int CaseXmovPos = abs(caseXmov); //valeur absolue
    short int CaseYmovPos = abs(caseYmov); //valeur absolue


    if(CaseXmovPos>2|| CaseYmovPos>2  ||  CaseXmovPos+CaseYmovPos > 2||CaseXmovPos+CaseYmovPos < -2) //depend de point de mouvement
        return;

    if(pCaseX == -1 || pCaseY == -1) //verif si sur map
        return;





    if(cCaseX == pCaseX && cCaseY == pCaseY){ //si survol case du joueur

        for(int i = -3; i<2; i++){
            caseXsave = cCaseX+i;
            if((caseXsave >= 0 && caseXsave <= 9 && cCaseY-1 <= 9) && matrix[caseXsave][cCaseY-1] == 48) //check si la case est sur la map et si pas bloquée dans matrice
                pushFront(liste, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", caseXsave, cCaseY-1, 0);
        }

        for(int j = -3; j<2; j++){
            caseYsave = cCaseY+j;
            if( (caseYsave >= 0 && caseYsave <= 9) && matrix[cCaseX-1][caseYsave] == 48)
                pushFront(liste, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", cCaseX-1, caseYsave, 0);
        }


        if((cCaseX-2 >= 0 && cCaseX-2 <= 9 && cCaseY-2 >= 0 && cCaseY-2 <= 9) && matrix[cCaseX-2][cCaseY-2] == 48){
            //printf("Case(%d,%d)\n", cCaseX-2, cCaseY-2);
            pushFront(liste, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", cCaseX-2, cCaseY-2, 0);
        }
        if((cCaseX >= 0 && cCaseX <= 9 && cCaseY >= 0 && cCaseY <= 9) && matrix[cCaseX][cCaseY] == 48){
            //printf("Case(%d,%d)\n", cCaseX, cCaseY);
            pushFront(liste, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", cCaseX, cCaseY, 0);
        }
        if((cCaseX-2 >= 0 && cCaseX-2 <= 9 && cCaseY >= 0 && cCaseY <= 9) && matrix[cCaseX-2][cCaseY] == 48){
            //printf("Case(%d,%d)\n", cCaseX-2, cCaseY);
            pushFront(liste, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", cCaseX-2, cCaseY, 0);
        }
        if((cCaseX >= 0 && cCaseX <= 9 && cCaseY-2 >= 0 && cCaseY-2 <= 9) && matrix[cCaseX][cCaseY-2] == 48){
            //printf("Case(%d,%d)\n", cCaseX, cCaseY-2);
            pushFront(liste, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", cCaseX, cCaseY-2, 0);
        }

        return;
    }


    if (caseXmov >= 0) //déplacement vers avant en x
    { 
        for(short int i = 0; i < caseXmov; i++)
        {
            caseXsave = cCaseX+i;
            if(matrix[caseXsave][cCaseY-1] == 48)
                pushFront(liste, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", caseXsave, cCaseY-1, 0); //-1
        }

    }else
    {
        for(short int i = -2; i > caseXmov -2; i--)//-2 *2
        { 
            caseXsave = cCaseX+i;
            if(matrix[caseXsave][cCaseY-1] == 48)
                pushFront(liste, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", caseXsave, cCaseY-1, 0);
        }
    }

    if (caseYmov >= 0)
    {
        for(short int i = 0; i < caseYmov; i++)
        {
            caseYsave = cCaseY+i;
            if(matrix[caseXsave][caseYsave] == 48)
                pushFront(liste, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", caseXsave, caseYsave, 0); //caseXsave-1
        }

    }else
    {

        for(short int i = -2; i > caseYmov-2; i--)
        { 
            caseYsave = cCaseY+i;
            if(matrix[caseXsave][caseYsave] == 48)
                pushFront(liste, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", caseXsave, caseYsave, 0);
        }
    }




}




















