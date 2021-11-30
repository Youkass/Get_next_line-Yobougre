#include "get_next_line.h"

char	*ft_first_line(char *buf, int fd, char *line)
{
	char	*save;
	int		read_file;

	if (BUFFER_SIZE > 0)
	{
		read_file = 1;
		while (read_file && (!(ft_strchr(buf, '\n'))))
		{
			buf[BUFFER_SIZE] = 0;
			read_file = read(fd, buf, BUFFER_SIZE);
			printf("read_file : %d\n", read_file);
			if (read_file <= 0)
				return (NULL);
			save = line;
			line = ft_strjoin(save, buf);
		}
		return (line);
	}
	else
		return (NULL);
}

char	*ft_next_line(char *buf, int fd, char *line)
{
	char	*save;
	int		read_file;

	if (BUFFER_SIZE > 0)
	{
		read_file = 1;
		line = ft_strchr(line, '\n');
		line += 1;
		if (ft_strchr(line, '\n'))
			return (line);
		while (read_file && (!(ft_strchr(buf, '\n'))))
		{
			buf[BUFFER_SIZE] = 0;
			printf("read_file : %d\n", read_file);
			read_file = read(fd, buf, BUFFER_SIZE);
			printf("read_file : %d\n", read_file);
			if (read_file <= 0)
				return (NULL);
			save = line;
			line = ft_strjoin(save, buf);
		}
		return (line);
	}
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	char		*output;
	char		buf[BUFFER_SIZE + 1];
	static char *line = NULL;

	output = NULL;
	if (!line)
	{
		line = ft_first_line(buf, fd, line);
		output = ft_super_join(output, line);
		return (output);
	}
	else if (line)
	{
		line = ft_next_line(buf, fd, line);
		if (!line)
			return (NULL);
		output = ft_super_join(output, line);
		if (!output)
			return (NULL);
		return (output);
	}
	return (NULL);
}


int main()
{
	int		file;
	char	*temp = NULL;
	int		i;

	i = 1;
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
	//while (i)
	//temp = get_next_line(file);
	//printf("%s", temp);
	close(file);
}
