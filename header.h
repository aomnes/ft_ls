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

#include <ctype.h>

typedef struct s_argument
{
    int arg_l;
    int arg_R;
    int arg_a;
    int arg_r;
    int arg_t;
} s_argument;

void erreur(const char *message);
void erreur_fichier(void);
void erreur_arg(char c);

void ft_affiche_date(char *nom);
void ft_affiche_size(int nombre, int max);
void ft_affiche_nlink(int nombre, int max);
void ft_affiche_groupe(char *groupe, int max);
void ft_affiche_user(char *user, int max);
void acl(char *filename);
void ft_l(char *nom, int max, int max_nlink);
s_argument agv(const char *arg, s_argument result);

int ft_max_size(void);
int ft_max_nlink(void);
int ft_max_groupe(void);
int ft_max_user(void);
int compt_dir(void);
void ft_sum_block(void);
int	ft_strcmp(const char *s1, const char *s2);

#endif //HEADER_H
