#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main()
{
	/*int		fd;
	int		rd;
	char	buf[50];

	fd = open("test1",O_RDONLY);
	if (fd < 0)
	{
		printf("Failed to open!!\n");
		return (0);
	}
	rd = read(fd, buf, 2);
	buf[rd] = '\0';
	printf("%s\n", buf);
	rd = read(fd, buf, 2);
	buf[rd] = '\0';
	printf("%s\n", buf);
	rd = read(fd, buf, 2);
	buf[rd] = '\0';
	printf("%s\n", buf);
	rd = read(fd, buf, 2);
	buf[rd] = '\0';
	printf("%s\n", buf);*/
	char	*str = "Hello";
	int		i = 0;

	while (str[i] != 'l')
	{
		i++;
	}
	printf("%ld\n",ft_strlen(&str[i]));
	printf("%ld\n",ft_strlen(str) - i);
}