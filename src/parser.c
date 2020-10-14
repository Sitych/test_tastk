#include "parser.h"

char	*read_file(const int fd)
{
	char *result;
	char read_str[BUF_READ + 1];
	int len;

	len = read(fd, read_str, BUF_READ);
	read_str[len] = 0;
	result = ft_strdup(read_str);
	if (result == NULL)
	{
		ft_putstr("Error: malloc error\n");
		exit(EXIT_FAILURE);
	}
	while (BUF_READ - len == 0)
	{
		len = read(fd, read_str, BUF_READ);
		read_str[len] = 0;
		result = ft_strjoin(result, read_str);
		if (result == NULL)
		{
			ft_putstr("Error: malloc error\n");
			exit(EXIT_FAILURE);
		}
	}
	return (result);
}

int	parse_section(const char **str, char **name_section)
{

}

int	config_read(const char* __ini_data, config_t* __out_config)
{
	int 	fd;
	char	*str;
	char	**lines;

	__out_config = config_create();
	fd = open(__ini_data, O_RDONLY);
	if (fd == -1)
	{
		perror("open failed on input file");
		return (0);
	}
	str = read_file(fd);
	lines = ft_strsplit(str, '\n');
	if (lines == NULL)
	{
		ft_putstr("Error: malloc error\n");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; lines[i] ; i++)
	{
		ft_printf("%s\n", lines[i]);
	}
	close(fd);
	return (1);
}

int main(int argc, char **argv)
{
	config_t	*config = NULL;

	if (argc < 2)
	{
		ft_printf("Usage: %s <sourcefile.ini>\n", argv[0]);
		return (0);
	}
	if (config_read(argv[1], config) == -1)
	{
		ft_printf("Error: read config file");
		return (-1);
	}
	return (0);
}