#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main()
{
	int		fd;
	// int		fd2;
	// int		fd3;
	char	*line;
	int		i = 1;

	fd = open("test1", O_RDONLY);
	// fd2 = open("alternate_line_nl_no_nl",O_RDONLY);
	// fd3 = open("multiple_line_no_nl",O_RDONLY);
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("line[%02d] = %s",i, line);
		free(line);
		// line = get_next_line(fd2);
		// printf("line[%02d] = %s",i, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line[%02d] = %s",i, line);
		// free(line);
		i++;
	}
	close(fd);
	// close(fd2);
	// close(fd3);
	return (0);
//	printf("%s",get_line("slakjk\nlkajs"));
}