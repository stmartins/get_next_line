/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 09:24:34 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/19 10:54:50 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void		free_mem(char **str)
{
	if (*str)
		ft_strdel(str);
}

void		find_bsn(t_line *in, char **line)
{
	in->ret = 0;
	in->chr = NULL;
	if (!in->ret && (in->chr = ft_strchr(in->buff, '\n')))
	{
		printf("str: [%s] buff: [%s] line: [%s]\n", in->str, in->buff, *line);
		if (in->str)
		{
			printf("enter\n");
			in->tmp = *line;
			*line = ft_strjoin(*line, in->str);
			free_mem(&in->tmp);
			free_mem(&in->str);
		}
		in->tmp = *line;
		*line = ft_strjoin(*line, ft_strsub(in->buff, 0,
		(size_t)(in->chr - in->buff)));
		free_mem(&in->tmp);
		if (in->chr + 1)
			in->str = ft_strdup(in->chr + 1);
	}
	in->ret = 1;
}

int			check_str(t_line in, char *line)
{
	char	*tmp;

	tmp = NULL;
	in.chr = NULL;
	if ((in.chr = ft_strchr(in.str, '\n')))
	{
		in.tmp = line;
		line = ft_strjoin(line, ft_strsub(in.str, 0,
		(size_t)(in.chr - in.str)));
		free_mem(&in.tmp);
		tmp = in.str;
		if ((in.chr + 1))
			in.str = ft_strdup(in.chr + 1);
		free_mem(&tmp);
		return (1);
	}
	return (0);
}

char		*fill_line(char **line, t_line *in)
{
	if (in->str)
	{
		in->tmp = *line;
		*line = ft_strjoin(*line, in->str);
		free_mem(&in->str);
	}
	in->tmp = *line;
	*line = ft_strjoin(*line, in->buff);
	free_mem(&in->tmp);
	return (*line);
}

int			get_next_line(int const fd, char **line)
{
	static t_line			in;

	in.ret = 0;
	if (in.str && (check_str(in, *line) == 1))
		return (1);
	free_mem(line);
	if (!(in.buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((in.oct = read(fd, in.buff, BUFF_SIZE)))
	{
		if (in.oct == -1)
			return (-1);
		in.buff[in.oct] = '\0';
		if (!(ft_strchr(in.buff, '\n')))
			*line = fill_line(line, &in);
		else
			find_bsn(&in, line);
		if (in.ret == 1)
			return (1);
	}
	free_mem(&in.buff);
	if (!(in.oct && in.str))
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	while (i++ < 20)
	{
		(get_next_line(fd, &line) == -1) ?
			ft_putstr("error\n") : printf("%s\n", line);
	}
	return (0);
}
