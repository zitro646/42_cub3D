/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:51:39 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/28 16:14:47 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# define RED 0xFF0000
# define PINK 0xFF00FF
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define CYAN 0x00FFFF
# define WHITE 0xFFFFFF
# define ORANGE 0xFF6600
# define PURPLE 0x4B0082
# define GREY 0x8C8C8C


typedef struct s_list
{
	int				x_axis;
	int				y_axis;
	int				go_to_x;
	int				go_to_y;
	char			type;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct window
{
	void	*floor_title;
	void	*player_title;
	void	*enemy_title;
	void	*exit_title;
	void	*wall_title;
	void	*coin_title;
}	t_window;

typedef struct data_map
{
	char			**showmap;
	t_window		*window;
	int				max_width;
	int				height;
	char			*_north_texture_path;
	char			*_south_texture_path;
	char			*_east_texture_path;
	char			*_west_texture_path;
	char			*_floor_colour_path;
	char			*_roof_colour_path;
}	t_data_map;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_strlen(const char *str);
void		*ft_memset(void *str, int c, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_count_list(int *list);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

//List functions
t_list		*ft_lstnew(char type, int x, int y);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);

//GNL functions
char		*get_next_line(int fd);
int			ft_write_char(int c);
int			ft_write_string(const char *c);
int			ft_strlen_gnl(const char *str);
char		*ft_strchr_gnl(const char *s, int c);
void		*ft_memcpy_gnl(void *dest, const void *src, size_t n);
void		*ft_calloc_gnl(size_t count, size_t size);
void		ft_bzero_gnl(void *s, size_t n);

#endif
