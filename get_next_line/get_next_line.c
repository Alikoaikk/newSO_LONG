/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:47:42 by akoaik            #+#    #+#             */
/*   Updated: 2025/06/07 16:41:15 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void	free_list(t_char_lst **head)
{
	t_char_lst	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

char	*get_next_line(int fd)
{
	char				*buffer;
	int					i;
	int					size;
	static t_char_lst	*head;

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE);
	while (!new_line_exist(head))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
		{
			if (size < 0)
				free_list(&head);
			break ;
		}
		i = 0;
		while (i < size)
			add_last(buffer[i++], &head);
	}
	free(buffer);
	if (!head)
		return (NULL);
	return (find_in_lst(&head));
}

// int	main(void)
// {
// 	int	fd ;

// 	fd = open("input.txt", O_RDONLY);
// 	// fd = 1 ;
// 	char *line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// }
