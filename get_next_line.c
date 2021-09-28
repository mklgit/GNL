/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirueta- <mirueta-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:25:55 by mirueta-          #+#    #+#             */
/*   Updated: 2021/09/28 15:19:58 by mirueta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_leftxt(int fd, char *leftxt)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(leftxt, '\n') && rd_bytes > 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		leftxt = ft_strjoin(leftxt, buff);
	}
	free(buff);
	return (leftxt);
}

char	*ft_getline(char *leftxt)
{
	int		i;
	char	*str;

	i = 0;
	if (!leftxt[i])
		return (NULL);
	while (leftxt[i] && leftxt[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (leftxt[i] && leftxt[i] != '\n')
	{
		str[i] = leftxt[i];
		i++;
	}
	if (leftxt[i] == '\n')
	{
		str[i] = leftxt[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_leftxt(char *leftxt)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (leftxt[i] && leftxt[i] != '\n')
		i++;
	if (!leftxt[i])
	{
		free(leftxt);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(leftxt) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (leftxt[i])
		str[j++] = leftxt[i++];
	str[j] = '\0';
	free(leftxt);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*leftxt;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftxt = ft_read_to_leftxt(fd, leftxt);
	if (!leftxt)
		return (NULL);
	line = ft_getline(leftxt);
	leftxt = ft_new_leftxt(leftxt);
	return (line);
}
