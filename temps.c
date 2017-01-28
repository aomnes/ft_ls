#include "header.h"

static void ft_jours(char *nom)
{
    struct stat fileStat;
    char temps[100];
    char jour[2];

    if(stat(nom, &fileStat) < 0)
        erreur(nom);
    strcpy(temps, ctime(&fileStat.st_birthtimespec.tv_sec));
//  printf("jours: le temps :::%s\n", temps);

    strncpy(jour, &temps[8], 2);

    printf("%s\n", jour);
}

static void ft_mois(char *nom)
{
    struct stat fileStat;
    char temps[100];
    char mois[3];

    if(stat(nom, &fileStat) < 0)
        erreur(nom);
    strcpy(temps, ctime(&fileStat.st_birthtimespec.tv_sec));
//  printf("mois: le temps :::%s\n", temps);

    strncpy(mois, &temps[4], 3);
    mois[0] = temps[4] + 32;

    printf("%s\n", mois);
}

static void ft_heure(char *nom)
{
    struct stat fileStat;
    char temps[100];
    char heure[8];

    if(stat(nom, &fileStat) < 0)
        erreur(nom);
    strcpy(temps, ctime(&fileStat.st_birthtimespec.tv_sec));
//  printf("heure: le temps :::%s\n", temps);

    strncpy(heure, &temps[11], 5);

    printf("%s\n", heure);
}

static void ft_annee(char *nom)
{
    struct stat fileStat;
    char temps[100];
    char annee[4];

    if(stat(nom, &fileStat) < 0)
        erreur(nom);
    strcpy(temps, ctime(&fileStat.st_birthtimespec.tv_sec));
//  printf("annee: le temps :::%s\n", temps);

    strncpy(annee, &temps[20], 4);

    printf("%s\n", annee);
}

void ft_affiche_date(char *nom)
{
    ft_annee(nom);
    ft_jours(nom);
    ft_heure(nom);
    ft_mois(nom);
}
