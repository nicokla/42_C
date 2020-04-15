#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (s && f)
	{
		i = 0;
		if (!(res = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			res[i] = f(i, s[i]);
			i++;
		}
		return (res);
	}
	return (NULL);
}
