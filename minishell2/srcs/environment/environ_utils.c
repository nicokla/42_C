#include "ftsh.h"
#include "env.h"

/*
** ft_strcmp_before_c
** return "c offset" if search==str before the c char in str
** return 0 otherwise
*/

static	int		ft_strcmp_before_c(char *search, char *str, char c)
{
	int		i;

	if (!search || !str || !c)
		return (0);
	i = -1;
	while (str[++i] && str[i] != c && search[i])
	{
		if (str[i] != search[i])
			return (0);
	}
	if (!search[i] && str[i] == c)
		return (i);
	else
		return (0);
}

char			*get_name_from_varline(char *varline)
{
	char	*varname;
	int		i;

	if (!varline)
		return (NULL);
	i = 0;
	while (varline[i] && varline[i] != '=')
		i++;
	if (varline[i] == '=')
	{
		if (!(varname = ft_strndup(varline, i)))
			clean_exit(1, MALLOC_ERR);
		return (varname);
	}
	else
		return (NULL);
}

/*
** get_envline_index
** return the index of the searched variable
** return -1 if not found
*/

int				get_envline_index(char *search, char **env)
{
	int	i;

	i = -1;
	if (!env)
		return (-1);
	while (env && env[++i])
	{
		if (ft_strcmp_before_c(search, env[i], '='))
			return (i);
	}
	return (-1);
}

/*
** get_envline_value
** return a pointer to the envline after '='
** return NULL otherwise
*/

char			*get_envline_value(char *search, char **env)
{
	int		i;
	int		offset;

	if (!search)
		return (NULL);
	i = -1;
	while (env && env[++i])
	{
		if ((offset = ft_strcmp_before_c(search, env[i], '=')))
			return (&(env[i][offset + 1]));
	}
	return (NULL);
}

/*
** get_envline
** return a pointer to the searched envline
** return NULL otherwise
*/

char			*get_envline(char *search, char **env)
{
	int		i;

	i = -1;
	if (!search || !env)
		return (NULL);
	while (env[++i])
	{
		if (ft_strcmp_before_c(search, env[i], '='))
			return (env[i]);
	}
	return (NULL);
}
