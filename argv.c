#include "header.h"

s_argument agv(const char *arg)
{
    int index;
    char c;
    s_argument result;

    index = 1;
    c = '\0';
    if (arg[0] != '-')
        erreur_fichier();
    while (arg[index])
    {
        c = arg[index];
        if (c != 'l' && c != 'R' && c!= 'a' && c != 'r' && c != 't')
            erreur_arg(c);
        if (c == 'l')
            result.arg_l = TRUE;
        else if (c == 'l')
            result.arg_R = TRUE;
        else if (c == 'R')
            result.arg_R = TRUE;
        else if (c == 'a')
            result.arg_a = TRUE;
        else if (c == 'r')
            result.arg_r = TRUE;
        else if (c == 't')
            result.arg_t = TRUE;
        index++;
    }
    return(result);
}
