/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:48:30 by akoaik            #+#    #+#             */
/*   Updated: 2025/06/07 04:42:56 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_exist(t_char_lst *head)
{
	while (head)
	{
		if (head->c == '\n')
			return (1);
		head = head->next;
	}
	return (0);
}

void	add_last(char c, t_char_lst **head)
{
	t_char_lst	*new;
	t_char_lst	*temp;

	new = malloc(sizeof(t_char_lst));
	if (!new)
		return ;
	new->c = c;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

int	length_str(t_char_lst *head)
{
	int	i;

	i = 0;
	while (head && head->c != '\n')
	{
		i++;
		head = head->next;
	}
	if (head && head->c == '\n')
		i++;
	return (i);
}

char	*find_in_lst(t_char_lst **head)
{
	char		*str;
	int			i;
	int			len;
	t_char_lst	*temp;

	if (!head || !*head)
		return (NULL);
	len = length_str(*head);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*head && (*head)->c != '\n')
	{
		str[i++] = (*head)->c;
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	return (finish_line(str, i, head));
}

char	*finish_line(char *str, int i, t_char_lst **head)
{
	t_char_lst	*temp;

	if (*head && (*head)->c == '\n')
	{
		str[i++] = '\n';
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	str[i] = '\0';
	return (str);
}
