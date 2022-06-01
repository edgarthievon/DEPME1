#include <stdio.h>
#include "main.h"



Player *initPlayer(char path[255], int caseX, int caseY) {

    Player *player = malloc(sizeof(Player)); 

    if (player == NULL) //check if allocation ok
        exit(EXIT_FAILURE);


    float Vmtg[2] =  {};
    float Vmbg[2] =  {};
    vCalcul(Vmtg, Vmbg);
    int nouvPoint[2] = {};
    CalculNouvPoint(Vmtg,Vmbg,nouvPoint, caseX*2, caseY*2);



    strcpy(player->path, path);    
    player->x = nouvPoint[0] - 130; 
    player->y = nouvPoint[1] - 120;
    player->caseX = caseX;
    player->caseY = caseY;
    player->bitmap = al_load_bitmap(path);

    return player;
}


void renderPlayer(Player *player){
    al_draw_bitmap(player->bitmap, player->x, player->y, 0);
}


void movePlayer(Player *player, ALLEGRO_BITMAP *bitmap, Rect rectangle, Liste *liste1, Liste *liste2, int pCaseX, int pCaseY, char matrix[10][10]){

    int nouvPoint[2] = {};

    float Vmtg[2] =  {};
    float Vmbg[2] =  {};
    vCalcul(Vmtg, Vmbg);

    short int old_caseX = player->caseX;
    short int old_caseY = player->caseY;

    short int caseXmov = pCaseX - player->caseX; //case à déplacer = case souris - case actuelle 
    short int caseYmov = pCaseY - player->caseY;

    short int caseXsave = player->caseX -1; //-1//décallage case
    short int caseYsave = player->caseY -1; //-1

    int new_x;
    int new_y;

    short int speed = 4;



    if(pCaseX == -1 || pCaseY == -1) //verif si sur map
        return;

    if(matrix[pCaseX-1][pCaseY-1] != 48){ //si case bloquée
        return;
    }

    if(abs(caseXmov)>2|| abs(caseYmov)>2  ||  abs(caseXmov)+abs(caseYmov) > 2||abs(caseXmov)+abs(caseYmov) < -2) //depend de point de mouvement
        return;


    //CaseX

    if (caseXmov >= 0) //déplacement vers avant en x
    { 

        for(short int i = 0; i < caseXmov+1; i++) //décalle d'une case
        {    
            caseXsave = old_caseX+i; //déplacement case par case
            player->caseX = caseXsave;

            CalculNouvPoint(Vmtg,Vmbg,nouvPoint, caseXsave*2, old_caseY*2);
            new_x = nouvPoint[0] - 130; //décallage x de l'image
            new_y = nouvPoint[1] - 120; //décallage y de l'image

            while (1) {
                if(player->x < new_x) //décalage vers droite
                { 
                    player->x +=speed;
                    render(bitmap, rectangle, liste1, liste2, player);
                }
                if(player->y > new_y) //décalage vers haut
                { 
                    player->y -= speed/2;
                    render(bitmap, rectangle, liste1, liste2, player);
                }
                if(player->x >= new_x && player->y <= new_y)
                    break;

            }
        }


    }else{

        for(short int i = 0; i < abs(caseXmov-1); i++) //décalle d'une case
        {    
            caseXsave = old_caseX-i; //déplacement case par case
            player->caseX = caseXsave;

            CalculNouvPoint(Vmtg,Vmbg,nouvPoint, caseXsave*2, old_caseY*2);
            new_x = nouvPoint[0] - 130; //décallage x de l'image
            new_y = nouvPoint[1] - 120; //décallage y de l'image

            while (1) {

                if(player->x > new_x) //décalage vers droite
                { 
                    player->x -=speed;
                    render(bitmap, rectangle, liste1, liste2, player);
                }
                if(player->y < new_y) //décalage vers haut
                { 
                    player->y +=speed/2;
                    render(bitmap, rectangle, liste1, liste2, player);
                }
                if(player->x <= new_x && player->y >= new_y)
                    break;
            }

        }

        //printf("(%d,%d)\n",caseXsave, old_caseY);

    }

    //CaseY
    
    if (caseYmov >= 0) //déplacement vers avant en y
    {

        for(short int i = 0; i < caseYmov+1; i++) //décalle d'une case
        {
            caseYsave =  old_caseY+i;
            player->caseY = caseYsave;

            CalculNouvPoint(Vmtg,Vmbg,nouvPoint, caseXsave*2, caseYsave*2);
            new_x = nouvPoint[0] - 130; //décallage x de l'image
            new_y = nouvPoint[1] - 120; //décallage y de l'image

            while (1) {

                if(player->x < new_x) //décalage vers droite
                { 
                    player->x +=speed;
                    render(bitmap, rectangle, liste1, liste2, player);
                }
                if(player->y < new_y) //décalage vers haut
                { 
                    player->y +=speed;
                    render(bitmap, rectangle, liste1, liste2, player);
                }
                if(player->x >= new_x && player->y >= new_y)
                    break;

            }
        }


    }else{
        
        for(short int i = 0; i < abs(caseYmov-1); i++) //décalle d'une case
        {
            caseYsave =  old_caseY-i;
            player->caseY = caseYsave;

            CalculNouvPoint(Vmtg,Vmbg,nouvPoint, caseXsave*2, caseYsave*2);
            new_x = nouvPoint[0] - 130; //décallage x de l'image
            new_y = nouvPoint[1] - 120; //décallage y de l'image

            while (1)
            {

                if(player->x > new_x) //décalage vers droite
                { 
                    player->x -=speed;
                    render(bitmap, rectangle, liste1, liste2, player);
                }
                if(player->y > new_y) //décalage vers haut
                { 
                    player->y -=speed;
                    render(bitmap, rectangle, liste1, liste2, player);
                }
                if(player->x <= new_x && player->y <= new_y)
                    break;

            }
        }

    }


}





void deletePlayer(Player *player){
    free(player);
}

void displayBg(ALLEGRO_BITMAP *bitmap){
    al_draw_bitmap(bitmap, 0,-20,0); //rendu arrière plan
}











