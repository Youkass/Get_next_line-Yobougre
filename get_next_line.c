#include "get_next_line.h"

int	ft_strlen_spe(char const *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_super_join(char const *s1, char const *s2)
{
	char	*output;
	int		i;
	int		j;
	
	i = 0;
	//if (s1)
	//	i = ft_strlen(s1);
	output = malloc(sizeof(char) * (ft_strlen_spe(s2) + 1));
	if (!output)
		return (NULL);
	j = 0;
	while (j < ft_strlen_spe(s2))
	{
		output[i] = s2[j];
		++i;
		++j;
	}
	output[i] = '\0';
	return (output);
}

int	ft_where_end(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*output;
	char		buf[BUFFER_SIZE + 1];
	char		*save;
	static char *line = NULL;

	while (read(fd, buf, BUFFER_SIZE) )//&& !ft_where_end(output))
	{
		save = line;
		line = ft_strjoin(save, buf);
		output = ft_super_join(output, line);
	}
	if (!output)
		return (NULL);
	return (output);
}


int main()
{
	int		file;

	file = open("texte.txt", O_RDONLY);
	if (!file)
		exit(1);
	printf("resultat line 1 : %s\n", get_next_line(file));
	printf("resultat line 2 :%s\n", get_next_line(file));
	close(file);
}
