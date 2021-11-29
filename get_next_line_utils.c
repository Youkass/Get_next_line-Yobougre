#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*retour;
	int		i;

	retour = (char *)s;
	i = ft_strlen(s);
	if (c == 0)
		return (retour + i);
	while (i >= 0)
	{
		if (retour[i] == c)
			return (retour + i);
		i--;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	char	*retour;
	int		i;

	retour = (char *)s;
	i = 0;
	while (retour[i])
	{
		if (c == retour[i])
			return (retour + i);
		i++;
	}
	if (retour[i] == c)
		return (retour + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	output = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
			output[j++] = s1[i++];
	}
	i = 0;
	if (s2)
	{
		while (s2[i])
			output[j++] = s2[i++];
	}
	output[j] = '\0';
	return (output);
}


