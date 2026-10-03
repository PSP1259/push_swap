/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pspuhler <pspuhler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 12:25:50 by pspuhler          #+#    #+#             */
/*   Updated: 2026/09/25 12:26:02 by pspuhler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

/* ---------------	CHARS		--------------- */
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/* ---------------	STRINGS		--------------- */
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);

/* ---------------	STRINGS: Additional_libft_functions		--------------- */
// char	*ft_strcpy(char *dst, const char *src);
// char	*ft_strncpy(char *dst, char const *src, size_t size);
// char	*ft_strcat(char *dst, const char *src);
// char	*ft_strncat(char *dst, const char *src, size_t size);
// char	*ft_strstr(const char *h, const char *n);
// int	ft_strcmp(const char *s1, const char *s2);
// char	*ft_strnew(size_t size);
// void ft_strdel(char **as);
// void ft_strclr(char *s);
// void	ft_striter(char *s, void (*f)(char*));
// char	*ft_strmap(char const *s, char (*f)(char));
// int	ft_strequ(char const *s1, char const *s2);
// int 	ft_strnequ(char const *s1, char const *s2, size_t n);
// char	*ft_strsub(char const *s, unsigned int start, size_t len);
// char	**ft_strsplit(char const *s, char c);

/* ---------------   FILE DESCRIPTORS   --------------- */
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/* -----------	FILE DESCRIPTORS: Additional_libft_functions ----------- */
// void	ft_putchar(char c);
// void	ft_putstr(char const *s);
// void	ft_putendl(char const *s);
// void	ft_putnbr(int n);

/* ---------------	MEMORY		--------------- */
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/* ---------------	MEMORY: Additional_libft_functions		--------------- */
// void *ft_memccpy(void *dest, const void *src, int c, size_t n);
// void	*ft_memalloc(size_t size);
// void	ft_memdel(void **ap);

/* ---------------	NUMBERS		--------------- */
int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);

/* ---------------	LISTS	--------------- */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
unsigned int	ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/* ----------	LISTS: Additional_libft_functions	----------- */
// void    ft_lstdel(t_list **alst, void (*del)(void *, size_t));
// void		ft_lstadd(t_list **alst, t_list *new);

#endif
