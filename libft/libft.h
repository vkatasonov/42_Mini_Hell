/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:10:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/01 18:49:10 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_is_extended(int c);
int					ft_is_ext_no_quotes(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
bool				ft_isspace(char c);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_bzero(void *s, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(char *s1);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strtok(char *str, const char *delim);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
int					ft_printf_fd(int fd, const char *sign, ...);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_wdcounter(char const *str, char c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strncpy(char *dest, const char *src, size_t len);
int					ft_printf(const char *sign, ...);
int					ft_type(char type, va_list args);
int					ft_putchar(char c);
int					ft_putstr(char *str);
int					ft_putnbr(int num);
char				*ft_numbase(unsigned int num, char *set);
int					ft_putptr(void *ptr);
size_t				gnl_strlcpy(char *dst, char *src, size_t dstsize);
char				*gnl_substr(char *s, unsigned int start, size_t len);
char				*gnl_read_and_save(char *block, int fd, int *n);
char				*gnl_get_and_free(char **block, int len, int null_block);
char				*get_next_line(int fd);
size_t				gnl_strlen(char *s);
size_t				gnl_strlen_line(char *s);
size_t				gnl_strlcat(char *dst, char *src, size_t dstsize);
char				*gnl_strjoin(char *s1, char *s2);
char				*gnl_strchr(char *s, int c);
int					hex_to_int(char *hex);
void				ft_charpp_free(char **charpp);
void				*ft_realloc(void *ptr, size_t size);
int					ft_match_symbol(char c, char *str);

#endif
