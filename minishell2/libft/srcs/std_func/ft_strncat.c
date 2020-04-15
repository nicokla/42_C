#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	while (*s2 && n)
	{
		s1[i] = *s2;
		i++;
		s2++;
		n--;
	}
	s1[i] = 0;
	return (s1);
}
