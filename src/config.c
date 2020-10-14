#include "parser.h"

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

section_t	*section_create(char *name)
{
	section_t	*tmp;

	tmp = (section_t*)ft_malloc(sizeof(section_t));
	tmp->name = ft_strdup(name);
	if (tmp->name == NULL)
	{
		ft_putstr("Error: malloc error\n");
		exit(EXIT_FAILURE);
	}
	tmp->data = NULL;
	return (tmp);
}