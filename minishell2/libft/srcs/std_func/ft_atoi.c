#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		modif;
	int		finalnb;

	i = 0;
	modif = 1;
	finalnb = 0;
	if (!(str))
		return (0);
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\b'
			|| str[i] == '\f' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		modif = -1;
	}
	if (str[i] == '+' && modif != -1)
		i++;
	while (ft_isdigit(str[i]))
	{
		finalnb = finalnb * 10 + str[i] - '0';
		i++;
	}
	return (finalnb * modif);
}
