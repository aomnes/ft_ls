#include "header.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *new_s1;
	unsigned char *new_s2;

	new_s1 = (unsigned char*)s1;
	new_s2 = (unsigned char*)s2;
	while (*new_s1 || *new_s2)
	{
		if (*new_s1 != *new_s2)
			return (*new_s1 - *new_s2);
		new_s1++;
		new_s2++;
	}
	return (0);
}

char **tri(char **tab, int nb_val)
{
	char **tableau_trie;
	int index;

	index = 0;
	tableau_trie = (char**)malloc(sizeof(*tab) * nb_val);
	if (!tableau_trie)
		erreur("malloc tableau_trie");



}
