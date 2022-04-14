#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int	main()
{
	int	fd;
	int	rd;
	char	*buf;
	char	*left;

	fd = open("test1", O_RDONLY | O_CREAT);
	rd = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (rd != 0 && !strchr(left, '\n'))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = '\0';
		printf("%s\n",buf);
	}
	close(fd);
}
