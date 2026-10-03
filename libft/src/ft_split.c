/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:27:48 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/23 14:56:41 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_split allocates and copies an array of strings by
	splitting the given string s using the given separator c.

	RETURN VALUE :
	An array of strings resulting from the split. NULL if the memory
	allocation fails.
*/

// Counts the total number of words seperated by the delimiter 'c'
static int	ft_count_words(const char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			words++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

// Allocates memory for each individual word in the 2D array
static char	**ft_malloc_strs(char **strs, const char *s, char c)
{
	int	count;
	int	i;
	int	x;

	count = 0;
	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		if ((s[i] == c && i > 0 && s[i - 1] != c)
			|| (s[i] != c && s[i + 1] == '\0'))
		{
			strs[x] = malloc(sizeof(char) * (count + 1));
			if (!strs[x])
				return (NULL);
			count = 0;
			x++;
		}
		i++;
	}
	return (strs);
}

// Copies characters from the original string into the allocated memory blocks
static char	**ft_cpy_strs(char **strs, const char *s, char c)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c)
			strs[x][y++] = s[i];
		if (s[i] != c && s[i + 1] == '\0')
			strs[x][y] = '\0';
		if (s[i] == c && i > 0 && s[i - 1] != c)
		{
			strs[x][y] = '\0';
			x++;
			y = 0;
		}
		i++;
	}
	return (strs);
}

// Frees previously allocated memory if an error occurs
static char	**ft_merror(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	return (NULL);
}

// Main function managing counting, allocation, copying and error handling
char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		wordcount;
	int		i;

	if (!s)
		return (NULL);
	wordcount = ft_count_words(s, c);
	strs = malloc(sizeof(*strs) * (wordcount + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i <= wordcount)
	{
		strs[i] = NULL;
		i++;
	}
	if (ft_malloc_strs(strs, s, c))
		ft_cpy_strs(strs, s, c);
	else
		strs = ft_merror(strs);
	return (strs);
}

/*
int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("Hola---Malaga--libft  ", '-');
	if (!result)
		return (1);
	i = 0;
	while (result[i])
	{
		printf("result[%i]: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/
