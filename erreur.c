#include "header.h"

void erreur(const char *message)
{
    perror(message);
    exit(1);
}

void erreur_arg(char c)
{
    printf("ls: illegal option -- %c\n", c);
    printf("usage: ls [-...] [file ...]");
    exit(1);
}
