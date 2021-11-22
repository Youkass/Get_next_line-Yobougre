#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*output;
	int		read_file;
	char	buf[BUFFER_SIZE];
	int		i;

	i = 0;
	while ((read_file = read(fd, buf, BUFFER_SIZE)) && buf[i] != '\n')
		i++;
	output = malloc(sizeof(char) * i + BUFFER_SIZE);
	if (!output)
		return (NULL);
	i = 0;
	while ((read_file = read(fd, buf, BUFFER_SIZE)) && output[i] != '\n')
	{
		output[i] = *buf;
		i++;
	}
	output[i] = '\0';
	return (output);
}

int main()
{
	int		file;
	char	*output;

	file = open("texte.txt", O_RDONLY);
	if (!file)
		exit(1);
	//while ((output = get_next_line(file) != NULL))
		printf("%s\n",get_next_line(file));
	free(output);
	close(file);
	return (0);
}
