#include "input.h"

/*
**	Returns a freshly allocated st_txt with an allocated copy of the txt
**	parameter. If no parameter is passed, duplicates an empty string
*/

t_st_txt	*init_st_txt(const char *txt)
{
	t_st_txt	*st_txt;

	if (!(st_txt = (t_st_txt*)malloc(sizeof(*st_txt))))
		clean_exit(1, MALLOC_ERR);
	if (!txt)
	{
		if (!(st_txt->txt = ft_strdup("")))
			clean_exit(1, MALLOC_ERR);
	}
	else if (!(st_txt->txt = ft_strdup(txt)))
		clean_exit(1, MALLOC_ERR);
	st_txt->data_size = ft_strlen(st_txt->txt);
	st_txt->malloc_size = st_txt->data_size + 1;
	st_txt->tracker = 0;
	return (st_txt);
}

/*
**	Memdels st_txt and frees up the allocated memory
*/

void		free_st_txt(t_st_txt **st_txt)
{
	if (!st_txt || !(*st_txt))
		return ;
	ft_strdel(&(*st_txt)->txt);
	ft_memdel((void*)st_txt);
}
