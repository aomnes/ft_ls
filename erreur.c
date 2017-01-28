#include "header.h"

void erreur(const char *message)
{
    perror(message);
    exit(0);
}
