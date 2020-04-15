
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 32

int	ft_strlen( char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(char *dest, char *src, int n)
{
	int	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		n;
	n = ft_strlen(src);
	p = malloc(sizeof(char) * (n + 1));
	ft_memcpy(p, src, n);
	p[n] = '\0';
	return (p);
}

char	*ft_strchr(char *s, char c)
{
	while (*s != c && *s != '\0')
		s++;
	if (*s == '\0' && c != '\0')
		return (NULL);
	return ((char *)s);
}

char	*ft_substr2(char *s, unsigned int start, int len)
{
	char	*answer;
	answer = malloc(len + 1);
	ft_memcpy(answer, s + start, len);
	answer[len] = '\0';
	return (answer);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		n1;
	int		n2;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	s = malloc(n1 + n2 + 1);
	ft_memcpy(s, s1, n1);
	ft_memcpy(s + n1, s2, n2);
	s[n1 + n2] = '\0';
	return (s);
}

void	ft_str_append_suffix(char **s, char *suffix)
{
	char	*answer;

	answer = ft_strjoin(*s, suffix);
	if (s != NULL)
		free(*s);
	*s = answer;
}

int		prepare(char **lines, char **line, int fd)
{
	char	*tmp;
	int		len;

	if (!ft_strchr(lines[fd], '\n'))
	{
		*line = ft_strdup(lines[fd]);
		free(lines[fd]);
		lines[fd] = NULL;
		return (0);
	}
	len = 0;
	while (lines[fd][len] != '\n')
		len++;
	*line = ft_substr2(lines[fd], 0, len);
	tmp = ft_strdup(lines[fd] + len + 1);
	free(lines[fd]);
	lines[fd] = tmp;
	return (1);
}

int		get_next_line( int fd, char **line)
{
	static char	*lines[255];
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	if (lines[fd] == NULL){
		lines[fd] = malloc(1);
		lines[fd][0] = '\0';
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_str_append_suffix(&(lines[fd]), buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	return (prepare(lines, line, fd));
}
