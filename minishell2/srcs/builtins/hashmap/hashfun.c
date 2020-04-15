#include "hashmap.h"

/*
** hashfun
** is a typical hashing function
** (damn, what a comment !)
*/

unsigned int	hashfun(const char *input)
{
	unsigned int	hash_address;
	unsigned int	i;

	hash_address = 0;
	i = 0;
	while (input[i])
	{
		hash_address = input[i] + (hash_address << 6) + (hash_address << 16)
			- hash_address;
		i++;
	}
	return (hash_address);
}
