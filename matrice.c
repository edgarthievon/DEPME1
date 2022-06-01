//#include "matrice.h"
#include <stdio.h>
//#include "liste.h"
#include "main.h"


void resetMatrix(){

    FILE *file = fopen("C:\\Users\\User\\CLionProjects\\DEPME\\matrix.txt", "w+");

    for(int i = 0; i<10; i++)
    {
        fprintf(file, "0000000000\n");
    }

}

void importMatrix(char tab[10][10]){

    FILE *file = fopen("C:\\Users\\User\\CLionProjects\\DEPME\\matrix.txt", "r+");

    char line[256];
    int i = 0; //counter


    while (fgets(line, 255, file) != NULL || i < 10) {

        for (int ii = 0; ii < 10; ii++) {
            tab[i][ii] = line[ii];
        }

        i++;
    }
    fclose(file);
}

void printMatrix(char tab[10][10]){
    for(int i = 0; i<10; i++) {
        for(int ii = 0; ii<10; ii++) {
            printf("%d", tab[i][ii]);
        }
        printf("\n");
    }
}

void analyseMatrix(char tab[10][10], Liste *list){

    int blocked;

    for(int i = 0; i<10; i++) {
        for(int ii = 0; ii<10; ii++)
        {
            if(tab[i][ii] == 49 || tab[i][ii] == 1){
                blocked = 1;
            }    
            else if(tab[i][ii] == 50 || tab[i][ii] == 2){ //si case | ( 2 = ascii(50) )
                pushFront(list, "C:\\Users\\User\\CLionProjects\\DEPME\\case.png", i, ii, 0);
            }
            else if(tab[i][ii] == 51 || tab[i][ii] == 3){ //si pierre
                    pushFront(list, "C:\\Users\\User\\CLionProjects\\DEPME\\rock.png", i, ii, 3);
            }
            else if(tab[i][ii] == 52 || tab[i][ii] == 4){ //si arbre
                    pushFront(list, "C:\\Users\\User\\CLionProjects\\DEPME\\tree.png", i, ii, 4);
            }
            else if(tab[i][ii] == 53 || tab[i][ii] == 5){ //si arbre n°2
                    pushFront(list, "C:\\Users\\User\\CLionProjects\\DEPME\\tree2.png", i, ii, 5);
            }
            else if(tab[i][ii] == 54 || tab[i][ii] == 6){ //si pierre n°2
                    pushFront(list, "C:\\Users\\User\\CLionProjects\\DEPME\\rock2.png", i, ii, 6);
            }

        }
    }
}
