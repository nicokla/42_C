/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:57:21 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 14:19:21 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	ft_hash_code(const char *key)
{
	unsigned int	sum;
	int				i;

	sum = 0;
	i = 0;
	while (key[i])
	{
		sum += (unsigned char)key[i] * (i + 1);
		i++;
	}
	return (sum % MAX_HASH);
}

void			ft_free_item(t_hash_lst *item)
{
	free(item->key);
	if (item->value)
		free(item->value);
	if (item)
		free(item);
}

void			ft_delete_item(t_hash_lst *table[], const char *key)
{
	t_hash_lst	**link;
	t_hash_lst	*tmp;

	link = &table[ft_hash_code(key)];
	while (*link)
	{
		tmp = *link;
		if (strcmp(tmp->key, key) == 0)
		{
			*link = tmp->next;
			ft_free_item(tmp);
			break ;
		}
		else
			link = &(*link)->next;
	}
}

t_hash_lst		*ft_search(t_hash_lst *head, const char *key)
{
	t_hash_lst *cursor;

	cursor = head;
	while (cursor != NULL)
	{
		if (strcmp(cursor->key, key) == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

void			ft_insert_item(t_hash_lst **hash,
						const char *key, const char *val)
{
	unsigned int		code;
	t_hash_lst			*item;

	code = ft_hash_code(key);
	if (!(item = (t_hash_lst *)malloc(sizeof(*item))))
		fatal_error(strerror(errno));
	if (item != NULL)
	{
		if (ft_search(hash[code], key))
			ft_delete_item(hash, key);
		item->key = strdup(key);
		item->value = strdup(val);
		item->next = hash[code];
		hash[code] = item;
	}
}
