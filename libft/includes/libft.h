/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 22:46:08 by eserebry          #+#    #+#             */
/*   Updated: 2017/12/05 15:57:08 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_dash(char *str);
int					ft_get_next_line(const int fd, char **line);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_strcat(char *s1, const char *s2);
void				ft_strdel(char **as);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putstr(const char *s);
int					ft_space(char *str);
size_t				ft_strlen(const char *s);
int					ft_strclen(char *str, char c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strcpy_int(char *dst, const char *src, int s, int t);
char				*ft_strjoin_free(char *s1, char *s2, int free);
int					ft_get_next_line(const int fd, char **line);

#endif
