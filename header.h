#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/xattr.h>

void erreur(const char *message);
void ft_affiche_date(char *nom);

#endif //HEADER_H
