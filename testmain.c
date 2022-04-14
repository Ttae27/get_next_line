#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*read_to_left(int fd, char *left)
{
	char	*buf;
	int	rd;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE  + 1);
	if (!buf)
		return (NULL);
	rd = 1;
	while (rd != 1)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		left = ft_strjoin(left, buf);
		printf("left = %s\n", left);
	}
	free(buf);
	return (left);
}

int	main()
{
	int	fd;
//	char	*line;
	static char	*left;

	fd = open("test1", O_RDONLY);
	printf("fd = %d\n", fd);
	if (fd == -1)
		printf("fail");
	left = read_to_left(fd, left);
	printf("main left = %s", left);
}
