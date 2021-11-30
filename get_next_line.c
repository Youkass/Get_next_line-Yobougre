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
	if (s1)
		i = ft_strlen(s1);
	output = malloc(sizeof(char) * (ft_strlen_spe(s2) + 2));
	if (!output)
		return (NULL);
	j = 0;
	while (j < ft_strlen_spe(s2))
	{
		output[i] = s2[j];
		++i;
		++j;
	}
	output[i] = '\n';
	output[i + 1] = '\0';
	return (output);
}

char	*ft_where_start(char *s, int limite)
{
	char	*output;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	output = malloc(sizeof(output) * (BUFFER_SIZE + 1));
	if (!output)
		return (NULL);
	while (s[i] != '\n')
		i++;
	while (i < limite)
	{
		output[j] = s[i];
		++j;
		++i;
	}
	output[i] = 0;
	return (output);
}
/*verif buffer_size*/
char	*get_next_line(int fd)
{
	char		*output;
	char		buf[BUFFER_SIZE + 1];
	char		*save;
	static char *line = NULL;

	if (!line)
	{
		while (read(fd, buf, BUFFER_SIZE))
		{
			buf[BUFFER_SIZE] = 0;
			save = line;
			line = ft_strjoin(save, buf);
			output = ft_super_join(output, line);
		}
		free(save);
	}
	else if (line)
	{
		line = ft_strchr(line, '\n');
		line += 1;
		output = ft_super_join(output, line);
	}
	if (!output)
		return (NULL);
	return (output);
}


int main()
{
	int		file;
	char	*temp = NULL;

	file = open("texte.txt", O_RDONLY);
	if (!file)
		exit(1);
	temp = get_next_line(file);
	while (temp)
	{
		printf("%s", temp);
		free(temp);
		temp = get_next_line(file);
	}
	close(file);
}
