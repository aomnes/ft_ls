#include "header.h"

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

int main(void)
{
    char **nom_f_d;
    int nb_val;
    int index;
    int max;

    index = 0;
    nb_val = compt_dir();
//    printf("nb: %d\n", nb_val);
    nom_f_d = (char**)malloc(sizeof(char) * nb_val);
    nom_f_d = affiche_dir(nom_f_d);

    max = ft_max_size();
    ft_sum_block();
    ft_l(".", max);
    ft_l("..", max);
    while (index != nb_val)
    {
        ft_l(nom_f_d[index], max);
        index++;
    }
    free(nom_f_d);
    return (0);
}
