#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "get_next_line.h"
# include "libftprintf.h"
# include <sys/uio.h>

# define BUF_READ 64

typedef struct wifi_t {
	char* ssid;
	char* pass;
} wifi_t;

typedef struct pwm_t {
	uint32_t ch1;
	uint32_t ch2;
	uint32_t ch3;
	uint32_t ch4;
	uint32_t ch5;
} pwm_t;

typedef struct one_day_t {
	time_t sunrise;
	time_t sunset;
} one_day_t;

typedef struct config_t {
	one_day_t day;
	pwm_t pwm;
	wifi_t wifi;
} config_t;

// typedef struct	sections_s
// {
// 	char		*name;
// 	char		**data;
// }				section_t;

int		config_read(const char* __ini_data, config_t* __out_config);
char*	config_write(const config_t* __config);

config_t	*config_create(void);
char		*read_file(int fd);
#endif