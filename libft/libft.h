/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 21:08:08 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 14:20:35 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct					s_llist
{
	int							var;
	struct s_llist				*next;
}								t_llist;

int								ft_atoi(char *str);
void							ft_bzero(void *s, size_t n);
int								ft_isalnum(int c);
int								ft_isalpha(int c);
int								ft_isascii(int c);
int								ft_isdigit(int c);
int								ft_isprint(int c);
char							*ft_itoa(int nb);
void							ft_lstaffich(t_llist *malist);
int								ft_lstcompt(t_llist *malist);
t_llist							*ft_lstend(t_llist *malist, int val);
t_llist							*ft_lstfirst(t_llist *malist, int val);
t_llist							*ft_lstnsearch(t_llist *malist, size_t n);
t_llist							*ft_lstsearch(t_llist *malist, int val);
t_llist							*ft_lstsupdel(t_llist *malist, int n);
void							*ft_memalloc(size_t size);
void							*ft_memccpy(void *dest, const void *src,
								int c, size_t n);
void							*ft_memchr(const void *s, int c, size_t n);
int								ft_memcmp(const void *s1, const void *s2,
								size_t n);
void							*ft_memcpy(void *dest, const void *src,
								size_t n);
void							ft_memdel(void **ap);
void							*ft_memmove(void *dest, const void *src,
								size_t n);
void							*ft_memset(void *s, int c, size_t n);
void							ft_putchar_fd(char c, int fd);
void							ft_putchar(char c);
void							ft_putendl_fd(char const *s, int fd);
void							ft_putendl(char const *s);
void							ft_putnbr_fd(int nb, int fd);
void							ft_putnbr(int n);
void							ft_putstr_fd(char const *s, int fd);
void							ft_putstr(char const *str);
char							*ft_strcat(char *dest, const char *src);
char							*ft_strchr(const char *s, int c);
void							ft_strclr(char *s);
int								ft_strcmp(const char *s1, const char *s2);
char							*ft_strcpy(char *dest, char *src);
void							ft_strdel(char **as);
char							*ft_strdup(char *src);
int								ft_strequ(char const *s1, char const *s2);
void							ft_striter(char *s, void (*f)(char *));
void							ft_striteri(char *s, void
								(*f)(unsigned int, char *));
char							*ft_strjoin(char *s1, char *s2);
size_t							ft_strlcat(char *dest, const char *src,
								size_t size);
size_t							ft_strlen(const char *str);
char							*ft_strmap(char const *s, char (*f)(char));
char							*ft_strmapi(char const *s, char
								(*f)(unsigned int, char));
char							*ft_strncat(char *dest, const char *src,
								size_t n);
int								ft_strncmp(const char *s1, const char *s2,
								size_t n);
char							*ft_strncpy(char *dest, char *src, size_t n);
int								ft_strnequ(char const *s1, char const *s2,
								size_t n);
char							*ft_strnew(size_t size);
char							*ft_strnstr(const char *arbre, const char
								*feuille, size_t n);
char							*ft_strrchr(const char *s, int c);
char							**ft_strsplit(char const *s, char c);
char							*ft_strstr(const char *arbre, const char
								*feuille);
char							*ft_strsub(char const *s, unsigned int start,
								size_t len);
char							*ft_strtrim(char const *s);
int								ft_tolower(int c);
int								ft_toupper(int c);
int								ft_strsupchr(const char *s, int c);
#endif
