#include "header.h"

void ft_l(char *nom, int max, int max_nlink)
{
    struct stat fileStat;
    struct passwd *user;
    struct group *groupe;

    if(stat(nom, &fileStat) < 0)
        erreur(nom);

    printf( (S_ISFIFO(fileStat.st_mode)) ? "p" : "");
    printf( (S_ISCHR(fileStat.st_mode)) ? "c" : "");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "");
    printf( (S_ISBLK(fileStat.st_mode)) ? "b" : "");
    printf( (S_ISREG(fileStat.st_mode)) ? "-" : "");
    printf( (S_ISLNK(fileStat.st_mode)) ? "l" : "");
    printf( (S_ISSOCK(fileStat.st_mode)) ? "s" : "");
    printf( (S_ISWHT(fileStat.st_mode)) ? "w" : "");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    acl(nom);
    printf(" ");
    ft_affiche_nlink(fileStat.st_nlink, max_nlink);
    user = getpwuid(fileStat.st_uid);
    printf(" %s ", user->pw_name);
    groupe = getgrgid(fileStat.st_gid);
    printf(" %s  ", groupe->gr_name);
    ft_affiche_size(fileStat.st_size, max);
    ft_affiche_date(nom);
    printf(" %s\n", nom);

//    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}

void ft_affiche_size(int nombre, int max)
{
    char *valeur;
    int taille;
    int diff;

    valeur = (char*)malloc(sizeof(valeur) * (max + 1));
    valeur[max] = '\0';
    sprintf(valeur, "%d", nombre);//remplacer par atoa()
    taille = strlen(valeur);
    diff = max - taille;

    if (diff)
    {
        while (diff)
        {
            printf(" ");
            diff--;
        }
    }
    free(valeur);
    printf("%d", nombre);
}

void ft_affiche_nlink(int nombre, int max)
{
    char *valeur;
    int taille;
    int diff;

    valeur = (char*)malloc(sizeof(valeur) * (max + 1));
    valeur[max] = '\0';
    sprintf(valeur, "%d", nombre);//remplacer par atoa()
    taille = strlen(valeur);
    diff = max - taille;
    if (diff > 0)
    {
        while (diff > 0)
        {
            printf(" ");
            diff--;
        }
    }
    printf("%d", nombre);
    free(valeur);
}
