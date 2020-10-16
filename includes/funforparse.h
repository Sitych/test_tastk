#ifndef FUNFORPARSE_H
# define FUNFORPARSE_H

#include "parser.h"

funforparse_t	parse_g[] = 
{
	{"Wifi", wifi_parser},
	{"One_day", one_day_parser},
	{"PWM", pwm_parser},
	{NULL, NULL}
};

#endif