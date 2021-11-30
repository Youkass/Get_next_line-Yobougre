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
	//printf("size de buf : %zu\n", ft_strlen(s2));
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

int	ft_strlen_spe(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_super_join(char *s1, char const *s2)
{
	int		i;
	int		j;
	
	i = 0;
	if (!s2 && !s1)
		return (NULL);
	s1 = malloc(sizeof(char) * (ft_strlen_spe(s2) + 2));
	j = 0;
	while (j < ft_strlen_spe(s2))
	{
		s1[i] = s2[j];
		++i;
		++j;
	}
	s1[i] = s2[j];
	s1[i + 1] = '\0';
	return (s1);
}
