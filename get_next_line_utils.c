/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:02:27 by pemarti2          #+#    #+#             */
/*   Updated: 2024/03/09 11:02:30 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (free(str), str = NULL, 0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *buffer, int c)
{
	int	i;

	i = 0;
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	while (buffer[i])
	{
		if (buffer[i] == (char) c)
			return ((char *) &buffer[i]);
		i++;
	}
	if (buffer[i] == (char) c)
		return ((char *) &buffer[i]);
	return (0);
}

char	*ft_strjoin(char *buffer, char *new_buffer)
{
	size_t	i;
	size_t	j;
	char	*join_result;

	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		if (!buffer)
			return (free(buffer), buffer = NULL, NULL);
		buffer[0] = '\0';
	}
	if (!new_buffer)
		return (free(new_buffer), new_buffer = NULL, NULL);
	i = ft_strlen(buffer) + ft_strlen(new_buffer);
	join_result = malloc(sizeof(char) * (i + 1));
	if (!join_result)
		return (free(buffer), buffer = NULL, NULL);
	i = -1;
	j = 0;
	while (buffer[++i])
		join_result[i] = buffer [i];
	while (new_buffer[j])
		join_result[i++] = new_buffer[j++];
	return (join_result[i] = '\0', free(buffer), join_result);
}

char	*ft_read_line(char *buffer)
{
	size_t	i;
	char	*new_buffer;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i])
	{
		if (buffer[i++] == '\n')
			break ;
	}
	new_buffer = malloc(sizeof(char) * (i + 1));
	if (!new_buffer)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		new_buffer[i] = buffer[i];
	if (buffer[i] == '\n')
		new_buffer[i++] = '\n';
	new_buffer[i] = '\0';
	return (new_buffer);
}

char	*ft_reminder(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), buffer = NULL, NULL);
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (!new_buffer)
		return (free(buffer), buffer = NULL, NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	return (free(buffer), buffer = NULL, new_buffer);
}
