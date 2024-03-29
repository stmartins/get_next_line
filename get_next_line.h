/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlinc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:55:54 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/23 19:04:58 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 3

typedef struct				s_line
{
	int				oct;
	char			*tmp;
	char			*chr;
	char			*buff;
}					t_line;

int				get_next_line(int fd, char **line);

#endif
