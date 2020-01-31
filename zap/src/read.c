/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 02:48:37 by yberries          #+#    #+#             */
/*   Updated: 2020/01/31 02:35:41 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		counter(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			++i;
		if (str[i])
			++count;
		while (str[i] && str[i] != c)
			++i;
	}
	return (count);
}

int		get_y(char *file)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line))
	{
		++y;
		free(line);
	}
	close(fd);
	return (y);
}

int		get_x(char *file)
{
	int		x;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	x = counter(line, ' ');
	free(line);
	close(fd);
	return(x);
}

void	fill_matrix(int	*z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		++i;
	}
	free(nums);

}

void	read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->x = get_x(file);
	data->y = get_y(file);
	data->matrix = (int **)malloc(sizeof(int*) * (data->y + 1));
	i = 0;
	while (i <= data->y)
		data->matrix[i++] = (int *)malloc(sizeof(int) * (data->x + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->matrix[i], line);
		free(line);
		++i;
	}
	close(fd);
	data->matrix[i] = NULL;
	i  = 0;
	int j = 0;
	printf("%d \n", data->y);
	printf("%d \n", data->x);
	while (i < data->y)
	{
		j = 0;
		while (j < data->x)
		{
			printf("%3d", data->matrix[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}
