/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:48:45 by akoaik            #+#    #+#             */
/*   Updated: 2025/06/07 04:24:50 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_char_lst
{
	char				c;
	struct s_char_lst	*next ;
}		t_char_lst;

typedef struct s_char_queue
{
	t_char_lst	*head;
	t_char_lst	*tail;
}	t_char_queue;

char	*get_next_line(int fd);
int		new_line_exist(t_char_lst *head);
void	add_last(char c, t_char_lst **head);
int		length_str(t_char_lst *head);
char	*find_in_lst(t_char_lst **head);
char	*finish_line(char *str, int i, t_char_lst **head);
void	free_list(t_char_lst **head);

#endif