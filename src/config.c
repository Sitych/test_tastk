#include "parser.h"
#include "funforparse.h"
#include "write.h"

void	print_config(config_t *config)
{
	ft_printf("Wifi:\n%s\n%s\n",config->wifi.ssid, config->wifi.pass);
	ft_printf("One_day:\n%d\n%d\n",config->day.sunrise, config->day.sunset);
	ft_printf("PWM:\n%d\n%d\n%d\n%d\n%d\n",config->pwm.ch1, config->pwm.ch2, config->pwm.ch3, config->pwm.ch4, config->pwm.ch5);
}

config_t	*config_create(void)
{
	config_t	*tmp;

	tmp = (config_t*)ft_malloc(sizeof(config_t));
	tmp->day.sunrise = LONG_MAX;
	tmp->day.sunset = LONG_MAX;
	tmp->wifi.ssid = NULL;
	tmp->wifi.pass = NULL;
	tmp->pwm.ch1 = INT32_MAX;
	tmp->pwm.ch2 = INT32_MAX;
	tmp->pwm.ch3 = INT32_MAX;
	tmp->pwm.ch4 = INT32_MAX;
	tmp->pwm.ch5 = INT32_MAX;
	return (tmp);
}

config_t	*config_parser(char **lines, config_t *config)
{
	section_t		*ptr;
	section_t		*tmp;
	funforparse_t	*ptr1;

	ptr = sections_parse(lines);
	tmp = ptr;
	while (tmp)
	{
		ptr1 = parse_g;
		while (ptr1->str)
		{
			if (!ft_strcmp(tmp->name, ptr1->str))
				break ;
			ptr1++;
		}
		if (!ptr1->str)
		{
			ft_printf("Unknown name section %s\n", ptr->name);
			return (0);
		}
		config = ptr1->fun(tmp, config);
		tmp = tmp->next;
	}
	ft_section_del(&ptr);
	return (config);
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
	__out_config = config_parser(lines, __out_config);
	int i = 0;
	while (lines[i])
		i++;
	ft_free((void**)lines, i);
	ft_strdel(&str);
	lines = NULL;
	config_write(__out_config);
	// print_config(__out_config);
	close(fd);
	return (1);
}

char*	config_write(const config_t* __config)
{
	int		fd;

	fd = open(FILENAME, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		fd = open(FILENAME, O_CREAT | O_WRONLY | O_APPEND | O_EXCL, __S_IWRITE | __S_IREAD);
		if ((write_wifi(fd, __config->wifi) != 1) || (write_one_day(fd, __config->day) != 1) || (write_pwm(fd, __config->pwm) != 1))
		{
			ft_putstr("Can not write at file ");
			ft_putstr(FILENAME);
			ft_putstr("\n");
			perror("");
		}
		close(fd);
	}
	else
	{
		ft_printf("File %s has already existed\n", FILENAME);
		close(fd);
	}
	return (FILENAME);
}
