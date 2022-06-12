#include "stdio.h"
#include <stdlib.h>

struct tableau_int
{
    int n; // taille du tab
    int* value; //valeur de la case
    
    //struct tableau_int*;
};

void add_item(struct tableau_int t, int a)
{
    t.value = &a;
}

int main()
{
    char* a; // a : pointeur vers un char
    char b = 'b'; // 
    a = &b; //a pointe vers l'adresse de b
    
    char tab[10]; //tab basique de 10 char à initialiser manu
    char* tabm = (char*) malloc(10 * sizeof(char)); // 
    char* tabc = (char*) calloc(10,sizeof(char));
    char un = '1';
    tabm = &un;
    printf("%c\n",*tabm);
    return 0;
}