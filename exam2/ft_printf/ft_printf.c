#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define MAX(M,N) (M >= N ? M : N)
#define MIN(M,N) (M <= N ? M : N)

typedef struct	s_params
{
	char	*str;
	va_list	va;
	int		length;
	char	precision_seen;
	int		min_width;
	int		precision;
	char	type;
}				t_params;

void	print_buffer(t_params *p, char *s, int size)
{
	write(1, s, size);
	p->length += size;
}

int		ft_strlen(char *s)
{
	int i;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_atoi(t_params *p)
{
	int a = 0;
	while (*(p->str) >= '0' && *(p->str) <= '9'){
		a *= 10;
		a += *(p->str) - '0';
		p->str++;
	}
	return (a);
}

int		get_length(int n, int bl)
{
	int i = 0;
	if (n == 0)
		return (1);
	while(n != 0){
		n /= bl;
		i++;
	}
	return i;
}

void	ft_itoa(t_params *p, long n, char *base, int bl)
{
	int 	length_n;
	char	s[50] = {0};
	length_n = get_length(n, bl);
	if (n < 0)
		n = -n;
	s[--length_n] = base[n % bl];
	n /= bl;
	while (n > 0) {
		s[--length_n] = base[n % bl];
		n /= bl;
	}
	print_buffer(p, s, ft_strlen(s));
}

void	print_int(t_params *p, long n, char *base, int bl)
{
	int len;
	int num_spaces;
	int num_zeros;
	int length_n;
	if (n == 0 && p->precision_seen && (p->precision == 0)){
		while (p->min_width--)
			print_buffer(p, " ", 1);
		return ;
	}
	length_n = get_length(n, bl);
	num_zeros = MAX(0, p->precision - length_n);
	len = num_zeros + length_n;
	if (n < 0)
		len++;
	num_spaces = MAX(0, (p->min_width - len));
	while (num_spaces--)
		print_buffer(p, " ", 1);
	if (n < 0)
		print_buffer(p, "-", 1);
	while (num_zeros--)
		print_buffer(p, "0", 1);
	ft_itoa(p, n, base, bl);
}

void	print_string_with_padding(t_params *p, char *s, int len)
{
	int a = MAX(0, (p->min_width - len));
	while (a--)
		print_buffer(p, " ", 1);
	print_buffer(p, s, len);
}

void	print_string(t_params *p)
{
	char	*s;
	int	len;
	s = va_arg(p->va, char *);
	if (p->precision_seen)
		len = MIN(ft_strlen(s), p->precision);
	else
		len = ft_strlen(s);
	if (s == NULL)
		print_string_with_padding(p, "(null)", len);
	else
		print_string_with_padding(p, s, len);
}

void	parse_and_print(t_params *p)
{
	long n;
	p->str++;
	p->precision_seen = 0;
	p->min_width = 0;
	p->precision = 0;
	p->type = 0;
	p->min_width = ft_atoi(p);
	if (*(p->str) == '.'){
		p->precision_seen = 1;
		p->str++;
		p->precision = ft_atoi(p);
	}
	if (*(p->str) == 's' || *(p->str) == 'd' || *(p->str) == 'x')
	{
		p->type = *(p->str);
		p->str++;
		if (p->type == 's')
			print_string(p);
		else if (p->type == 'd'){
			n = (long)va_arg(p->va, int);
			print_int(p, (long)n, "0123456789", 10);
		}
		else if (p->type == 'x'){
			n = (long)va_arg(p->va, unsigned int);
			print_int(p, n, "0123456789abcdef", 16);
		}
	}
}

int		ft_printf(const char *format, ...)
{
	t_params	params = {0};
	t_params	*p;
	p = &params;
	p->str = (char *)format;
	va_start(p->va, format);
	while (*(p->str) != '\0') {
		if (*(p->str) != '%') {
			write(1, p->str, 1);
			p->str++;
			p->length++;
		}
		else
			parse_and_print(p);
	}
	va_end(p->va);
	return (p->length);
}
