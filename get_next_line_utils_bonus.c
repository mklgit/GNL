/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirueta- <mirueta-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:27:05 by mirueta-          #+#    #+#             */
/*   Updated: 2021/09/28 12:55:59 by mirueta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == ((char )c))
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == '\0' && str[i] == c)
		return ((char *)&str[i]);
	return (0);
}

char	*ft_strjoin(char *leftxt, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!leftxt)
	{
		leftxt = (char *)malloc(1 * sizeof(char));
		leftxt[0] = '\0';
	}
	if (!leftxt || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(leftxt) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (leftxt)
		while (leftxt[i] != '\0')
		{
			str[i] = leftxt[i];
			i++;
		}
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(leftxt) + ft_strlen(buff)] = '\0';
	free(leftxt);
	return (str);
}
