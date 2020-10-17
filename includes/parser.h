#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "get_next_line.h"
# include "libftprintf.h"
# include <sys/uio.h>
# include "time.h"

# define BUF_READ	64
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

typedef struct	section_s
{
	char				*name;
	char				**data;
	struct section_s	*next;
}				section_t;

typedef struct	funforparse_s
{
	char				*str;
	config_t			*(*fun)(section_t *section, config_t *);
}				funforparse_t;

int		config_read(const char* __ini_data, config_t* __out_config);
char*	config_write(const config_t* __config);

config_t	*config_create(void);
char		*read_file(int fd);
section_t	*section_create(char ***lines);
char		**section_data(char **lines, section_t **ptr);
section_t	*sections_parse(char **lines);
config_t	*wifi_parser(section_t *ptr, config_t *);
config_t	*one_day_parser(section_t *ptr, config_t *);
config_t	*pwm_parser(section_t *ptr, config_t *);
void		ft_section_del(section_t **ptr);

#endif