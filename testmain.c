#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main()
{
	int		fd;
	char	*line;
	int		i = 1;

	fd = open("test1", O_RDONLY);
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("line[%02d] = %s",i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
//	printf("%s",get_line("slakjk\nlkajs"));
}