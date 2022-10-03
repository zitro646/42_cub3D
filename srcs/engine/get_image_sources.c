/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_sources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:31:14 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/03 10:11:08 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_image(t_image *image)
{
	free_matrix(image->img_chars, 0);
	free_matrix(image->img_colours, 0);
	free(image->color_values);
	free(image);
	return ;
}

int hextodc(char *hex)
{

	int y = 0;
	int dec = 0;
	int x,i;

	i = ft_strlen(hex) - 1;
	while (i >= 0)
	{
		if ( hex[i]>= '0' && hex[i]<= '9')
		{
			x = hex[i] - '0';
		}
		
		else
		{
			x = hex[i] - 'A' + 10;
		}
		dec = dec + (x * pow(16 , y));
		i--;
		y++;
	}
	return (dec);
}

int get_value(t_image *image, char **pixel_map, int y, int x)
{
	// char *aux;
	(void)image;
	(void)pixel_map;
	(void)y;
	(void)x;
	int i;
	// int pos;
	char *c;

	c = ft_calloc(sizeof(char),image->n_pixel_char + 1);
	ft_memcpy(c,&pixel_map[y][x],image->n_pixel_char);
	i = 0;
	// printf("Value recolected from '%s'\n",c);
	
	while( i < image->n_colours)
	{
		// printf("Search on %d -> '%s' is '%s' \n",i,c ,image->img_chars[i]);
		if (ft_strnstr(image->img_chars[i], c, ft_strlen(image->img_chars[i])))
		{
			// printf(" Found it\n");
			break;
		}
		i++;
	}
	// printf("Position is %d\n",i);
	i = hextodc(image->img_colours[i]);
	free(c);
	return (i);
}

void set_image_data(t_image *image,char **pixel_map)
{
	int *values;
	int aux;
	int i;
	int j;
	
	i = 0;
	j = 0;
	values = ft_calloc(sizeof(int),image->n_colums * image->n_files + 1);
	// see_matrix(image->img_chars);
	// aux = get_value(image,pixel_map,0,0);
	// printf ("For %c[%d][%d] his value is %d\n",pixel_map[i][j],i,j,aux);
	// aux = get_value(image,pixel_map,6,3);
	// printf ("For %c[%d][%d] his value is %d\n",pixel_map[i][j],i,j,aux);
	while (i < image->n_colums)
	{
		j = 0;
		while (j < image->n_files)
		{
			// printf("i = %d , j = %d\n",i,j);
			aux = get_value(image,pixel_map,i,j);
			values[(i * 15) + j] = aux;
			// printf ("For %c[%d][%d] his value is %d\n",pixel_map[i][j],i,j,aux);
			j++;
		}
		printf("\n");
		i++;
	}
	image->color_values = values;
	return;
}

char **get_colour_value_list(char **_crude_data, t_image *image)
{
	char **new_values;
	char *aux;
	char *aux2;
	int i = 4;

	new_values = ft_calloc(sizeof(char *),image->n_colours + 1);
	while (i < image->n_colours + 4)
	{
		aux = ft_calloc(sizeof(char),ft_strlen(_crude_data[i]) - (image->n_pixel_char + 4));
		ft_memcpy(aux,&_crude_data[i][image->n_pixel_char + 4], ft_strlen(_crude_data[i]) - (image->n_pixel_char + 4));
		aux2 = replace_str(aux,'#',"");
		free(aux);
		aux = replace_str(aux2,'"',"");
		free(aux2);
		aux2 = replace_str(aux,',',"");
		free(aux);
		new_values[i - 4] = aux2;
		i++;
	}
	return(new_values);
}

char **get_colour_chars_list(char **_crude_data, t_image *image)
{
	char **new_values;
	char *aux;
	int i = 4;

	new_values = ft_calloc(sizeof(char *),image->n_colours + 1);
	while (i < image->n_colours + 4)
	{
		aux = ft_calloc(sizeof(char),image->n_pixel_char + 1);
		ft_memcpy(aux,&_crude_data[i][1],image->n_pixel_char);
		new_values[i - 4] = aux;
		i++;
	}
	return(new_values);
}

char **get_img_map(char **_crude_data, t_image *image)
{
	(void)_crude_data;
	char **new_values;
	char *aux;
	int i = 4 + image->n_colours;

	new_values = ft_calloc(sizeof(char *),image->n_colours + 1);
	while (i < image->n_colours + image->n_colums + 4)
	{
		aux = ft_calloc(sizeof(char),image->n_pixel_char + 1);
		ft_memcpy(aux,&_crude_data[i + 1][1],image->n_files);
		new_values[i - image->n_colours - 4] = aux;
		i++;
	}
	return(new_values);
}

t_image *xpm_to_image(t_game *game, t_data_map *data, char *str_dir)
{
	(void)game;
	(void)data;
	t_image *image;
	char **_crudedata;
	char **_data_image;
	char **pixel_map;
	
	image = ft_calloc(sizeof(t_image), 1);
	_crudedata = read_filedata(str_dir, get_file_height(str_dir));
	_data_image = ft_split(_crudedata[3],' ');
	switch_chars_on_matrix(_data_image,'"',"");
	//Image setup
	image->n_colums = ft_atoi(_data_image[0]);
	image->n_files = ft_atoi(_data_image[1]);
	image->n_colours = ft_atoi(_data_image[2]);
	image->n_pixel_char = ft_atoi(_data_image[3]);
	image->img_colours = get_colour_value_list(_crudedata, image);
	image->img_chars = get_colour_chars_list(_crudedata, image);
	pixel_map = get_img_map(_crudedata,image);
	// see_matrix(image->img_chars);
	set_image_data(image, pixel_map);
	
	free_matrix(_crudedata, 0);
	free_matrix(_data_image, 0);
	free_matrix(pixel_map, 0);
	
	// free_image(image);
	// see_matrix(ft_split(_crudedata[3],'"'));
	return (image);
}