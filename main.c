#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	char	*str;
	int		fd;

//	fd = open("test", O_RDONLY);
	while(get_next_line(0, &str))
	{
		printf("%s\n", str);
		free(str);
	}
	printf("%s\n", str);
	free(str);
}
