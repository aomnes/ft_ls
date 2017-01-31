#include "header.h"

static void ft_jours(char *nom)
{
    struct stat fileStat;
    char temps[100];
    char jour[3];

    if(stat(nom, &fileStat) < 0)
        erreur("jour");
    strcpy(temps, ctime(&fileStat.st_mtimespec.tv_sec));
    strncpy(jour, &temps[8], 2);
    jour[2] = '\0';
    printf(" %s", jour);
}

static void ft_mois(char *nom)
{
    struct stat fileStat;
    char temps[100];
    char mois[4];

    if(stat(nom, &fileStat) < 0)
        erreur("mois");
    strcpy(temps, ctime(&fileStat.st_mtimespec.tv_sec));
    strncpy(mois, &temps[4], 3);
    mois[0] = temps[4] + 32;
    mois[3] = '\0';
    printf(" %s", mois);
}

static void ft_heure(char *nom)
{
    struct stat fileStat;
    char temps[100];
    char heure[6];

    if(stat(nom, &fileStat) < 0)
        erreur("heure");
    strcpy(temps, ctime(&fileStat.st_mtimespec.tv_sec));
    strncpy(heure, &temps[11], 5);
    heure[5] = '\0';
    printf(" %s", heure);
}

static void ft_annee(char *nom)
{
    struct stat fileStat;
    char temps[100];
    char annee[5];

    if(stat(nom, &fileStat) < 0)
        erreur("annee");
    strcpy(temps, ctime(&fileStat.st_mtimespec.tv_sec));
    strncpy(annee, &temps[20], 4);
    annee[4] = '\0';
    printf(" %s", annee);
    printf(" ");//car un caractere de moins par rapport a date
}

static void ft_annee_or_date(char *nom)
{
    struct stat fileStat;
    long long diff;
    long long six_mois_sec;

    six_mois_sec = 15778800;
    if(stat(nom, &fileStat) < 0)
        erreur("anne/date");

    diff = time(NULL) - fileStat.st_mtimespec.tv_sec;
    if (diff >= six_mois_sec)
        ft_annee(nom);
    else
        ft_heure(nom);
}

void ft_affiche_date(char *nom)
{
    ft_jours(nom);
    ft_mois(nom);
    ft_annee_or_date(nom);
}
