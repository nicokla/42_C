/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:15:20 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/18 14:25:22 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

#define		STRING_1	"the cake is a lie !\0I'm hidden lol\r\n"
#define		STRING_2	"there is no stars in the sky"

int main(){

// ------------------
// PART 1
// ------------------
// memset 
// void * memset ( void * ptr, int value, size_t num );
//   char str[] = "almost every programmer should know memset!";
//   ft_memset (str,'-',6);
//   puts (str);

// bzero
// ok

// memcpy 

// memccpy 
// char	src[] = "test basic du memccpy !";
// char	buff1[22];
// memset(buff1, 0, sizeof(buff1));
// char	*r1 = memccpy(buff1, src, 'm', 22);
// char	*r2 = ft_memccpy(buff1, src, 'm', 22);
// r1 = memccpy("", src, 'm', 0);
// r2 = ft_memccpy("", src, 'm', 0);

// memmove 
//   char str[] = "memmove can be very useful......";
//   memmove (str+20,str+15,11);
//   puts (str);

// memchr 

// memcmp • 

// strlen • 
// ok

// isalpha • 
// ok

// isdigit • 
// ok

// isalnum • 
// ok 

// isascii • 
// for(unsigned char i=0; i<=254; i++){
// 	printf("%i\t%i\n",i,ft_isascii(i));
// }
// printf("%i\t%i\n",(unsigned char)255,ft_isascii((unsigned char)255));

// isprint
// ok

// • toupper
// ok

// tolower
	// int i = 0;
	// char str[] = "TUTORIALS POINT";
	// while( str[i] ) {
	// 	putchar(ft_tolower(str[i]));
	// 	i++;
	// }

//  strchr • 

//  strrchr • 
//   char str[] = "This is a sample string";
//   char * pch;
//   pch=strrchr(str,'s');
//   printf ("Last occurence of 's' found at %ld \n",pch-str+1);

//  strncmp • 
// char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
//   int n;
//   puts ("Looking for R2 astromech droids...");
//   for (n=0 ; n<3 ; n++){
//     if (ft_strncmp (str[n],"R2xx",2) == 0)
//     {
//       printf ("found %s\n",str[n]);
//     }
//   }
 
//  strlcpy • 
//   char str1[]= "To be or not to be";
//   char str2[40];
//   char str3[40];
//   /* copy to sized buffer (overflow safe): */
//   ft_strlcpy ( str2, str1, sizeof(str2) );
//   /* partial copy (only 5 chars, including the last \0, that is max 4 char from str2): */
//   ft_strlcpy ( str3, str2, 5 );
//   puts (str1);
//   puts (str2);
//   puts (str3);

//  strlcat • 
//   char str1[15];
//   char str2[100];
//   ft_strcpy (str1,"To be ");
//   ft_strcpy (str2,"or not to be allo coucou 12345 youhou pifpafpouf");
//   ft_strlcat (str1, str2, sizeof(str1));
//   puts (str1);

// strlcat, test 3
// char	*str = STRING_1;
// char	buff1[0xF00] = STRING_2;
// char	buff2[0xF00] = STRING_2;
// size_t	max = strlen(STRING_1) + 4;
// size_t	r1 = strlcat(buff1, str, max); //42
// size_t	r2 = ft_strlcat(buff2, str, max); // 47

// strstr
// char *s1 = "MZIRIBMZIRIBMZP";
// char *s2 = "MZIRIBMZP";
// char *i1 = strstr(s1, s2);
// char *i2 = ft_strstr(s1, s2);

//  strnstr

//  atoi
//   int i;
//   char buffer[256];
//   printf ("Enter a number: ");
//   fgets (buffer, 256, stdin);
//   i = ft_atoi (buffer);
//   printf ("The value entered is %d. Its double is %d.\n",i,i*2);

// calloc

// strdup
// ok

// ------------------
// PART 2
// ------------------

// char *ft_substr(char const *s, unsigned int start, size_t len);
// printf("%s\n", ft_substr("Salut comment ca va ?", 6, 15));
// printf("%s\n", ft_substr("Salut comment ca va ?", 6, 100));

// char *ft_strjoin(char const *s1, char const *s2);
// char * s = ft_strjoin("tata", " yoyo");
// printf("%s\n",s);

// char *ft_strtrim(char const *s1, char const *set);
// char *s = ft_strtrim("..  coucou . ", ". ");
// printf("%s\n",s);

// char **ft_split(char const *s, char c);
	// char **s = ft_split("coucou,  ca , va mec?", ',');
	// char **s2 = ft_split2("coucou,  ca , va mec?", " ,");
	// int i = 0;
	// while(s[i] != NULL)
	// {
	// 	printf("%s\n", s[i]);
	// 	i++;
	// }
	// printf("--------\n");
	// i = 0;
	// while(s2[i] != NULL)
	// {
	// 	printf("%s\n", s2[i]);
	// 	i++;
	// }


// char *ft_itoa(int n);
// char * s = ft_itoa (-2147483648); //2147483647
// printf("%s", s);
// char *i3 = ft_itoa(-0);

// char *ft_strmapi(char *s, void (*f)(unsigned int, char));

// void ft_putchar_fd(char c, int fd);

// void ft_putstr_fd(char *s, int fd);

// void ft_putendl_fd(char *s, int fd);

// void ft_putnbr_fd(int n, int fd);


// ------------------
// Bonus 1 : listes chainees
// ------------------
// t_list ft_lstnew(void const *content);

// void ft_lstadd_front(t_list **alst, t_list *new);

// int ft_lstsize(t_list *lst);

// t_list *ft_lstlast(t_list *lst);

// void ft_lstadd_back(t_list **alst, t_list *new);

// void ft_lstdelone(t_list *lst, void (*del)(void *);

// void ft_lstclear(t_list **lst, void (*del)(void *);

// void ft_lstiter(t_list *lst, void (*f)(t_list *);

// t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list*);


// ------------------
// Bonus 2 : libre choix
// ------------------
// ft_atoi_base
	// int a = ft_atoi_base("101", "01");
	// printf("\na = %i\n",a);

// -----------------------------

// ft_strlcpy
	// char	*dest;
	// if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
	// 	return (0);
	// char	*dest2;
	// if (!(dest2 = (char *)malloc(sizeof(*dest) * 15)))
	// 	return (0);
	// memset(dest, 0, 15);
	// memset(dest, 'r', 6);
	// memset(dest2, 0, 15);
	// memset(dest2, 'r', 6);
	// size_t a = ft_strlcpy(dest, "", 15); // ft_strlcpy(dest, "", 15);
	// size_t b = strlcpy(dest2, "", 15);
	// printf("%s\n", dest);
	// printf("%s\n", dest2);

// ft_substr             ok             success     clean            ✓✓✓✓✗               KO
	// char	str[] = "lorem ipsum dolor sit amet";
	// char	*strsub;
	// int		arg;
	// char *bullshit;
	// if (!(strsub = ft_substr(str, 400, 20)))
	// 	printf("NULL\n");
	// else
	// {
	// 	bullshit = (char *)&strsub[30];
	// 	bullshit = "FULL BULLSHIT";
	// 	if (strsub)
	// 		printf("%s\n",strsub);
	// 	else
	// 		printf("rip\n");
	// }
	// if (str == strsub)
	// 	printf("\nA new string was not returned");

// ft_memchr             ok             success     clean            ✓✓✓✓✓✓A             KO
	// const char *str, *str2;
	// char *pouet = "z";
	// char *lolzer = (char *)&pouet[2];
	// lolzer = "aaaaaaaaaa";
	// str = ft_memchr(pouet, 'a', 50);
	// str2 = memchr(pouet, 'a', 50);
	// if (!str)
	// 	printf("NULL\n");
	// else
	// {
	// 	printf("%s\n",str);
	// }

// atoi
	// printf("%d\n", atoi("9999999999"));
	// printf("%d\n", ft_atoi("9999999999"));


// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_isalnum.o test_ft_isalnum.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_isalpha.o test_ft_isalpha.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_isascii.o test_ft_isascii.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_isdigit.o test_ft_isdigit.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_isprint.o test_ft_isprint.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_tolower.o test_ft_tolower.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_toupper.o test_ft_toupper.c


// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_memset.o test_ft_memset.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_bzero.o test_ft_bzero.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_memchr.o test_ft_memchr.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_strchr.o test_ft_strchr.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_strlen.o test_ft_strlen.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_calloc.o test_ft_calloc.c


// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_atoi.o test_ft_atoi.c			?
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_memccpy.o test_ft_memccpy.c	+
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_memcmp.o test_ft_memcmp.c		?
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_memcpy.o test_ft_memcpy.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_memmove.o test_ft_memmove.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_strdup.o test_ft_strdup.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_strlcat.o test_ft_strlcat.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_strncmp.o test_ft_strncmp.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_strlcpy.o test_ft_strlcpy.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_strnstr.o test_ft_strnstr.c
// gcc -Wall -Wextra -Werror -g3   -c -o test_ft_strrchr.o test_ft_strrchr.c
	// printf("%d\n", memcmp("", "", 2));
	// char *s = ft_strtrim("coucou", "");
	// char *s2 = strtrim("coucou", "");
	// char n[40] = "1800000000000000000";
	// int i1 = atoi(n);
	// int i2 = ft_atoi(n);
	// printf("%i\n%i\n", i1, i2);
	char *a = strchr(NULL, ' ');
	char *b = ft_strchr(NULL, ' ');

	return 0;
}
