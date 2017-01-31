#include "header.h"

char *fill(char *tab, int len, char *name)
{
    tab = (char*)malloc(sizeof(name) * (len + 1));
    if (!tab)
        erreur("malloc nom_f_d[index]");
    tab[len] = '\0';
    strcpy(tab, name);
    return (tab);
}

char **affiche_dir(char **nom_f_d)
{
    struct dirent *lecture;
    DIR *rep1;
    int index;
    int len;

    index = -2;
    rep1 = opendir(".");
    if (rep1 == NULL)
        erreur("opendir");
    while ((lecture = readdir(rep1)))
    {
        len = strlen(lecture->d_name);
        if (index >= 0)
        {
            nom_f_d[index] = fill(nom_f_d[index], len, lecture->d_name);
        }
        index++;
    }
    if (closedir(rep1) == -1)
    {
        printf("%d\n", (int)rep1);
        erreur("closedir affiche_dir");
    }
    return (nom_f_d);
}

int main(int argc, char const *argv[])
{
    char **nom_f_d;
    int nb_val;
    int index;
    int max_size;
    int max_nlink;

    index = 0;
    if (argc > 2)
        erreur_fichier();
    if (argc == 2)
        agv(argv[1]);

    nb_val = compt_dir();
//    printf("nb: %d\n", nb_val);
    nom_f_d = (char**)malloc(sizeof(*nom_f_d) * nb_val);
    if (!nom_f_d)
        erreur("malloc nom_f_d");
    nom_f_d = affiche_dir(nom_f_d);
    max_size = ft_max_size();
    max_nlink = ft_max_nlink();
    ft_sum_block();
    ft_l(".", max_size, max_nlink);
    printf(" %s\n", ".");
    ft_l("..", max_size, max_nlink);
    printf(" %s\n", "..");
    index = 0;
    while (index != nb_val)
    {
        ft_l(nom_f_d[index], max_size, max_nlink);
        printf(" %s\n", nom_f_d[index]);
        index++;
    }
    while (index != nb_val)
    {
        free(nom_f_d[index]);
        index++;
    }
    free(nom_f_d);
    return (0);
}
