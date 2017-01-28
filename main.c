#include "header.h"

void erreur(const char *message)
{
    perror(message);
    exit(0);
}

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

char **affiche_dir(char **nom_f_d)
{
    struct dirent *lecture;
    DIR *rep;
    int index;
    int len;

    index = -2;
    rep = opendir("." );
    if (rep == NULL)
        erreur("opendir");
    while ((lecture = readdir(rep)))
    {
        len = strlen(lecture->d_name);
        if (index >= 0)
        {
            nom_f_d[index] = (char*)malloc(sizeof(char) * len);
            nom_f_d[index][len] = '\0';
            strcpy(nom_f_d[index], lecture->d_name);
        }
        index++;
    }
    if (closedir(rep) == -1)
        erreur("closedir");
    return (nom_f_d);
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

void ft_l(char *nom)
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

    printf("\t%d",fileStat.st_nlink);
    user = getpwuid(fileStat.st_uid);
    printf("\t%s", user->pw_name);
    groupe = getgrgid(fileStat.st_gid);
    printf("\t%s", groupe->gr_name);
    printf("\t%lld", fileStat.st_size);
    ft_affiche_date(nom);
    printf("\t%s\n", nom);

//    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}

int main()
{
    char **nom_f_d;
    int nb_val;

    nb_val = compt_dir();
//    printf("nb: %d\n", nb_val);
    nom_f_d = (char**)malloc(sizeof(char) * nb_val);
    nom_f_d = affiche_dir(nom_f_d);

    ft_sum_block();
    ft_l(".");
    ft_l("..");
    ft_l(nom_f_d[0]);
    ft_l(nom_f_d[1]);
    ft_l(nom_f_d[2]);
    ft_l(nom_f_d[3]);
    free(nom_f_d);
    return (0);
}
