#include "../includes/fdf.h"

int	count_cols(char *s)
{
	int		cols;
	char	**split;
	char	*tmp;

	tmp = ft_strdup(s);
	cols = 0;
	ft_striteri(tmp, replace_newline);
	split = ft_split(tmp, ' ');
	free(tmp);
	while (split[cols] != NULL)
		cols++;
	free_str_arr(split);
	return (cols);
}

int	lines_consistent(int cols, t_data *data)
{
	if (data->map->y_dim != 0 && data->map->x_dim != cols)
	{
		write(2, "Lines not consistent\n", 21);
		return (0);
	}
	return (1);
}


void	append_line_to_file(char **line, char **file)
{
	char	*tmp;

	tmp = *file;
	*file = ft_strjoin(tmp, *line);
	free(tmp);
	free(*line);
	*line = "";
}

char	*get_file(int fd, t_data *data)
{
	char	*line;
	char	*file;
	int		cols;

	line = "";
	file = malloc(sizeof(char));
	if (file == NULL)
		return (NULL);
	file[0] = '\0';
	data->map->y_dim = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			cols = count_cols(line);
			if (!lines_consistent(cols, data))
				return (NULL);
			data->map->x_dim = cols;
			data->map->y_dim += 1;
			append_line_to_file(&line, &file);
		}
	}
	return (file);
}

int	parse_file(t_data *data, char *filename)
{
	int		fd;
	char	*file;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Failed to open file\n", 20);
		return (-1);
	}
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		return (-1);
	file = get_file(fd, data);
	if (file == NULL)
		return (-1);
	ft_striteri(file, replace_newline);
	data->parsed_file = ft_split(file, ' ');
	if (data->parsed_file == NULL)
	{
 		   write(2, "Error: parsing file failed\n", 27);
 		   return (-1);
	}
	free(file);
	if (close(fd) == -1)
	{
		write(2, "Failed to close file\n", 21);
		return (-1);
	}
	return (0);
}
