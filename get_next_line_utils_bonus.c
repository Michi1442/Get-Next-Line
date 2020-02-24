/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 12:17:43 by migalvar      #+#    #+#                 */
/*   Updated: 2020/01/25 12:51:59 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strchr(char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2)
	{
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}

static char	*ft_strjoin_cp(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s2 || !s1)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	j = 0;
	s3 = (char *)malloc(sizeof(char) * i);
	if (!s3)
		return (NULL);
	i = ft_strlen(s1);
	s3 = ft_strjoin_cp(s3, s1, i);
	while (j <= ft_strlen(s2))
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	free((char *)s1);
	return (s3);
}
