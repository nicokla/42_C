#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!((int *)s1 > (int *)s2 && (int *)s2 + n > (int *)s1))
		ft_memcpy(s1, s2, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*((char *)s1 + i) = *((char *)s2 + i);
		}
	}
	return (s1);
}
