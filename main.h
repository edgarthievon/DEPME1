#ifndef TEST_MAIN_CASE_H
#define TEST_MAIN_CASE_H
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define nCase 10 //nb case
#define cShift 63 // decalage entre le premier px and the left corner of the case (43+20)


typedef struct {
    int x, y, largeur, hauteur, vitesse;
    ALLEGRO_COLOR c;
} Rect;

typedef struct Elem {
    char path[255]; // a mettre allegro
    int x, y;
    int caseX, caseY;
    ALLEGRO_BITMAP *bitmap;
    struct Elem *next;
}Element;


typedef struct List {
    Element *first;
    struct Lis *next;
}Liste;


typedef struct Joueur {
    char path[255]; 
    int x, y;
    int caseX, caseY;
    ALLEGRO_BITMAP *bitmap;
}Player;



void dessinerRect(Rect r);



void displayBg(ALLEGRO_BITMAP *bitmap);
void render(ALLEGRO_BITMAP *bitmap, Rect r, Liste *liste1, Liste *liste2, Player *player1);


//LISTE 
void renderList(Liste *liste);
int sizeList(Liste *liste);
void printList(Liste *liste);
void popFront(Liste *liste);
void pushFront(Liste *liste, char path[255], int caseX, int caseY, int type);
void fullDelete(Liste *list);
Liste *init();


//Player
Player *initPlayer(char path[255], int caseX, int caseY);
void renderPlayer(Player *player);
void movePlayer(Player *player, ALLEGRO_BITMAP *bitmap, Rect rectangle, Liste *liste1, Liste *liste2, int pCaseX, int pCaseY, char matrix[10][10]);
void deletePlayer(Player *player);



//VECTEUR 
void vCalcul(float premier[], float second[]);
void CalculNouvPoint(float Vmtg[], float Vmbg[], int nouv[], int caseT, int caseB);
void CalculDroite(float *mm1, float *mm2, float *pp1, float *pp2); //, Liste *list
void findPos(int x, int y, int *caseX, int *caseY, float m1, float m2, float p1, float p);
void drawPath(int cCaseX, int cCaseY, int pCaseX, int pCaseY, Liste *liste, char matrix[10][10]);


//MATRICE
void resetMatrix();
void importMatrix(char tab[10][10]);
void printMatrix(char tab[10][10]);
void analyseMatrix(char tab[10][10], Liste *list);




#endif //TEST_VECTEUR_CASE_H
