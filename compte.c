#include "header.h"

int compt_dir(void)
{
    struct dirent *lecture;
    DIR *rep;
    int nb;

    nb = -1;
    rep = opendir("." );
    if (rep == NULL)
        erreur("opendir");
    while ((lecture = readdir(rep)))
    {
        nb++;
        if (lecture == NULL)
            erreur("readdir");
    }
    if (closedir(rep) == -1)
        erreur("closedir");
    return (--nb);
}

void ft_sum_block(void)//attention fichier cache ne pas prendre en compte dans tous les cas
{
    struct stat fileStat;
    struct dirent *lecture;
    DIR *rep;
    long long block;
    char nom[255];//nb max caractere fichier

    block = 0;
    rep = opendir("." );
    if (rep == NULL)
        erreur("opendir");
    while ((lecture = readdir(rep)))
    {
        strcpy(nom, lecture->d_name);
        if(stat(nom, &fileStat) < 0)
            erreur(nom);
        block += fileStat.st_blocks;
    }
    if (closedir(rep) == -1)
        erreur("closedir");
    printf("total %lld\n", block);
}

int ft_max_size(void)
{
    struct stat fileStat;
    struct dirent *lecture;
    DIR *rep;
    int max;
    char val[20];//Taille maximale d’un volume et d’un fichier (Mac OS X 10.5.3 ou version ultérieure) Près de 8 Eo

    max = 0;
    rep = opendir(".");
    if (rep == NULL)
        erreur("opendir");
    while ((lecture = readdir(rep)))
    {
        if(stat(lecture->d_name, &fileStat) < 0)
            erreur(lecture->d_name);
        sprintf(val, "%lld", fileStat.st_size);//remplacer par atoa()
        if (max < (int)strlen(val))
            max = strlen(val);
    }
    if (closedir(rep) == -1)
        erreur("closedir");
//    printf("%d", max);
    return (max);
}

int ft_max_nlink(void)
{
    struct stat fileStat;
    struct dirent *lecture;
    DIR *rep;
    int max;
    char val[20];//Taille maximale d’un volume et d’un fichier (Mac OS X 10.5.3 ou version ultérieure) Près de 8 Eo

    max = 0;
    rep = opendir(".");
    if (rep == NULL)
        erreur("opendir");
    while ((lecture = readdir(rep)))
    {
        if(stat(lecture->d_name, &fileStat) < 0)
            erreur(lecture->d_name);
        sprintf(val, "%hu", fileStat.st_nlink);//remplacer par atoa()
        if (max < (int)strlen(val))
            max = strlen(val);
    }
    if (closedir(rep) == -1)
        erreur("closedir");
    return (max);
}

int ft_max_user(void)
{
    struct stat fileStat;
    struct dirent *lecture;
    DIR *rep;
    int max;

    max = 0;
    rep = opendir(".");
    if (rep == NULL)
        erreur("opendir");
    while ((lecture = readdir(rep)))
    {
        if(stat(lecture->d_name, &fileStat) < 0)
            erreur(lecture->d_name);
        if (max < (int)strlen(getpwuid(fileStat.st_uid)->pw_name))
            max = strlen(getpwuid(fileStat.st_uid)->pw_name);
    }
    if (closedir(rep) == -1)
        erreur("closedir");
//    printf("maaaaaaaxxxxxxxx: %d\n", max);
    return (max);
}

int ft_max_groupe(void)
{
    struct stat fileStat;
    struct dirent *lecture;
    DIR *rep;
    int max;

    max = 0;
    rep = opendir(".");
    if (rep == NULL)
        erreur("opendir");
    while ((lecture = readdir(rep)))
    {
        if(stat(lecture->d_name, &fileStat) < 0)
            erreur(lecture->d_name);
        if (max < (int)strlen(getgrgid(fileStat.st_gid)->gr_name))
            max = strlen(getgrgid(fileStat.st_gid)->gr_name);
    }
    if (closedir(rep) == -1)
        erreur("closedir");
//    printf("maaaaaaaxxxxxxxx: %d\n", max);
    return (max);
}
