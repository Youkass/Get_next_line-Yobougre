#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	buf[BUFFER_SIZE];

/*int	line_size(int fd)
{
	int		i;
	int		read_file;
	char	*tmp;

	i = 0;
	tmp = buf;
	while ((read_file = read(fd, tmp, 1)))
	{
		if (*tmp == '\n')
			return (i);
		tmp++;
		i++;
	}
	return (i);
}*/

char	*get_next_line(int fd)
{
	char	*output;
	int		i;
	char	*tmp;
	int		size;
	int		file;

	size = 0;
	tmp = buf;
	while ((file = read(fd, tmp, 1)))
	{
		if (*tmp == '\n')
			break;
		tmp++;
		size++;
	}
	output = malloc(sizeof(char) * (size + 1));
	if (!output)
		return (NULL);
	i = 0;
	while ((file = read(fd, buf, 1)) && i < size)
	{
		output[i] = *buf;
		i++;
		*buf += 1;
	}
	output[i] = '\0';
	return (output);
}

int main()
{
	int		file;
	char	*output;
	int		i;

	file = open("texte.txt",O_RDONLY);
	if (!file)
		exit(1);
	i = ft_strlen(output);
	//printf("%d\n", line_size(file));
	printf("%s\n", get_next_line(file));
	//printf("%d\n", line_size(file));
	//printf("%s\n", get_next_line(file));
	close(file);
}
