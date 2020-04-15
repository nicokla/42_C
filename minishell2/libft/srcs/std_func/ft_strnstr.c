#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t tmp;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && len)
	{
		tmp = len;
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && tmp > 0)
		{
			j++;
			tmp--;
		}
		if (needle[j] == 0)
			return ((char *)&haystack[i]);
		i++;
		len--;
	}
	return (NULL);
}
