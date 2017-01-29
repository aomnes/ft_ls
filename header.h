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

#include <sys/types.h>
#include <sys/acl.h> //ACL

#include <unistd.h>

void erreur(const char *message);
void ft_affiche_date(char *nom);
void ft_affiche_size(int nombre, int max);
void ft_affiche_nlink(int nombre, int max);
void acl(char *filename);
void ft_l(char *nom, int max, int max_nlink);

int ft_max_size(void);
int ft_max_nlink(void);
int compt_dir(void);
void ft_sum_block(void);

#endif //HEADER_H
