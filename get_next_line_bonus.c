/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:16:39 by migalvar      #+#    #+#                 */
/*   Updated: 2020/01/25 12:53:02 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned long	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (0);
	while (i < len && s[start])
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	return (subs);
}

static int		ft_free(char **stored)
{
	free(*stored);
	*stored = NULL;
	return (0);
}

static char		*ft_strchr_gnl(char *s, char c)
{
	char	*s2;
	int		i;

	i = 0;
	while (*s && s[i] != c)
		i++;
	s[i] = '\0';
	s2 = ft_strdup(s);
	free(s);
	return (s2);
}

static int		ft_recall(char **stored, int fd, char **line)
{
	char	*temp;
	size_t	len;

	temp = ft_strdup(stored[fd]);
	stored[fd] = ft_strchr_gnl(stored[fd], '\n');
	len = ft_strlen(stored[fd]);
	*line = ft_strdup(stored[fd]);
	ft_free(&stored[fd]);
	stored[fd] = ft_substr(temp, len + 1, (ft_strlen(temp) - len));
	ft_free(&temp);
	if (!stored[fd])
		return (ft_free(&stored[fd]));
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*stored[256];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE == 0)
		return (-1);
	if (!stored[fd])
		stored[fd] = ft_strdup("");
	ret = 1;
	while (ret > 0)
	{
		if (ft_strchr(stored[fd], '\n') == 0)
		{
			ret = read(fd, buf, BUFFER_SIZE);
			if (ret == -1)
				return (-1);
			buf[ret] = '\0';
			stored[fd] = ft_strjoin(stored[fd], buf);
		}
		else
			return (ft_recall(stored, fd, line));
	}
	*line = ft_strdup(stored[fd]);
	return (ft_free(&stored[fd]));
}
