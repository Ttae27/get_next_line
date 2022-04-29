#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int		main()
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		i;
	char 	*line;

	i = 1;
	fd1 = open("test1", O_RDONLY);
	fd2 = open("alternate_line_nl_no_nl", O_RDONLY);
	fd3 = open("multiple_line_no_nl", O_RDONLY);
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d] = %s",i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d] = %s",i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d] = %s",i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
}