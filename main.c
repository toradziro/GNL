#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int 	fd;
	char	*str;
	fd = open("test", O_RDONLY);
	while (get_next_line(fd, &str))
		printf("%s", str);
}
