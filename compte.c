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
    char nom[100];

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
    char val[15];

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
    char val[15];

    max = 0;
    rep = opendir(".");
    if (rep == NULL)
        erreur("opendir");
    while ((lecture = readdir(rep)))
    {
        if(stat(lecture->d_name, &fileStat) < 0)
            erreur(lecture->d_name);
        sprintf(val, "%hu", fileStat.st_nlink);//remplacer par atoa()
//        printf("vallllll: %s\n", val);
        if (max < (int)strlen(val))
            max = strlen(val);
    }
    if (closedir(rep) == -1)
        erreur("closedir");
//    printf("maaaaaaaxxxxxxxx: %d\n", max);
    return (max);
}
