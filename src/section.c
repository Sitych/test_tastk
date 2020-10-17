#include "parser.h"

static char	*get_name(char *line)
{
	size_t	len;
	char	*name;

	len = ft_strlen(line);
	name = ft_strnew(len - 2);
	if (name == NULL)
	{
		ft_putstr("Error: malloc error\n");
		exit(EXIT_FAILURE);
	}
	ft_strncpy(name, ft_strchr(line, '[') + 1, len - 2);
	return (name);
}

section_t	*section_create(char ***lines)
{
	section_t	*tmp;

	tmp = (section_t*)ft_malloc(sizeof(section_t));
	tmp->name = get_name(**lines);
	if (tmp->name == NULL)
	{
		ft_putstr("Error: malloc error\n");
		exit(EXIT_FAILURE);
	}
	tmp->data = NULL;
	*lines = section_data(*lines, &tmp);
	tmp->next = NULL;
	return (tmp);
}

char	**section_data(char **lines, section_t **ptr)
{
	char		**data;
	char		**next_section;
	char		**section;
	int 		j;
	
	j = 0;
	next_section = (char**)lines + 1;
	while (*next_section)
	{
		if (ft_strchr(*next_section, '[')) 
			break ;
		if ((*next_section)[0] != '#')
			j++;
		next_section++;
	}
	data = (char**)ft_malloc(sizeof(char*) * (j + 1));
	j = 0;
	section = (char**)lines + 1;
	while (*section != *next_section)
	{
		if ((*section)[0] != '#')
		{
			data[j] = ft_strdup(*section);
			if (data[j] == NULL)
			{
				ft_putstr("Error: malloc error\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		section++;
	}
	data[j] = NULL;
	(*ptr)->data = data;
	return (next_section);
}

section_t	*sections_parse(char **lines)
{
	section_t	*head;
	section_t	*ptr;

	while (ft_strchr(*lines, '[') == 0 || (*lines)[0] == '#')
		lines++;
	ptr = section_create(&lines);
	head = ptr;
	int i = 0;
	while (*lines)
	{
		ptr->next = section_create(&lines);
		ptr = ptr->next;
		i++;
	}
	return (head);
}

void		ft_section_del(section_t **ptr)
{
	int	len;
	section_t *tmp;

	while (*ptr)
	{
		tmp = (*ptr)->next;
		ft_strdel(&((*ptr)->name));
		len = 0;
		while ((*ptr)->data[len])
			len++;
		(*ptr)->data = (char**)ft_free((void**)(*ptr)->data, len);
		free(*ptr);
		*ptr = NULL;
		*ptr = tmp;
	}
	*ptr = NULL;
}