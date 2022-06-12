#include <iostream>

struct tableau_int
{
    int n;
    int* pt;
};

tableau_int initialize(int n)
{
    tableau_int t;
    t.n = n;
    t.pt = (int*) malloc(n * sizeof(int));
    return t;
}

void changer_tab(tableau_int &t, int taille)
{
    int* tmp = t.pt;
    t.pt = (int*) malloc((taille) * sizeof(int));
    for(int i = 0 ; i < t.n ; i++)
    {
        t.pt[i] = tmp[i];
    }
    t.n = taille;
    free(tmp);
}

void set(tableau_int &t , int ind)
{
    changer_tab(t,ind+1);
}

void add_item(tableau_int &t, int a, int ind)
{   
    if(ind < t.n)
    {
        t.pt[ind] = a;
    }
    else
    {
        set(t,ind);
        t.pt[ind] = a;
    }
}

void display(tableau_int const& t)
{
    for(int i = 0 ; i < t.n ; i++)
    {
        std::cout << t.pt[i] << "\n";
    }
}

void blabla()
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
}

bool vide(tableau_int const& t)
{
    return (t.n == 0);
}

int main()
{
    tableau_int t = initialize(5);
    add_item(t,1,0);
    add_item(t,2,1);
    add_item(t,10,9);
    display(t);
    //tableau_int t_vide = initialize(1);
    //std::cout << vide(t_vide) << "\n";
    return 0;
}