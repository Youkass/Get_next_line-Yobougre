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
	while((read_file = read(fd, buf, 1)) && buf[i] != '\n')
		i++;
	output = malloc(sizeof(char) * i + 1);
	if (!output)
		return (NULL);
	i = 0;
	while((read_file = read(fd, buf, 1)) && output[i] != '\n')
	{
		output[i] = *buf;
		i++;
	}
	output[i] = '\0';
	return (output);
}


