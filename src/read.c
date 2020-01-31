/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 02:48:37 by yberries          #+#    #+#             */
/*   Updated: 2020/01/31 05:36:17 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix(int fd, t_fdf *data)
{
	char	*line;
	int		i;
	char	**nums;
	int		j;

	i = 0;
	data->matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	while (get_next_line(fd, &line))
	{
		data->matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		nums = ft_strsplit(line, ' ');
		j = 0;
		while (nums[j])
		{
			data->matrix[i][j] = ft_atoi(nums[j]);
			free(nums[j]);
			++j;
		}
		free(nums);
		free(line);
		++i;
	}
	close(fd);
	data->matrix[i] = NULL;
}

void	read_file(char *file, t_fdf *data)
{
	char	*line;
	int		width;
	int		fd;

	if (!((fd = open(file, O_RDONLY)) >= 0))
		ft_error(1);
	data->height = 0;
	data->width = 0;
	while (get_next_line(fd, &line))
	{
		width = ft_countwords(line, ' ');
		if (data->width != 0 && data->width != width)
			ft_error(2);
		data->width = width;
		data->height++;
	}
	free(line);
	close(fd);
	fd = open(file, O_RDONLY);
	matrix(fd, data);
}
