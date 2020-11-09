#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);

int main(void)
{
	int 	fd;
	char	*str;
	fd = open("test", O_RDWR);
	get_next_line(fd, &str);
		printf("%s", str);
}
