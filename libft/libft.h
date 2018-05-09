/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:34:43 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/07 17:52:43 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/*
** C Data Types
*/

# define LI long int
# define LLI long long int
# define I_SIZE (sizeof(int))
# define C_SIZE (sizeof(char))
# define LI_SIZE (sizeof(LI))
# define LLI_SIZE (sizeof(LLI))
# define LI_MAX 2147483647
# define LI_MIN -2147483648

/*
** defines
*/

# define IS_SEPARATOR(c, str) (c == str)

/*
** memory functions
*/

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst
									, const void *src
									, int c
									, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					*ft_fast_memcpy(void *dst, const void *src, size_t n);
int						ft_fast_memcmp(const void *s1
									, const void *s2
									, size_t n);

/*
** String functions
*/

char					*ft_skip_delim(char const *str, char delim);
size_t					ft_count_by_delim(char const *s, char c);
char					*ft_next_delim(char const *string, char delim);
size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack
									, const char *needle
									, size_t len);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s
								, char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s
								, unsigned int start
								, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *string, char delim);

/*
** String functions
** Function ideas: should implement as necessary
** {multi} mean it should take a list of f(x)'s and variable num of args
** char *ft_strmap(char *str, );
** char *ft_strjoin(char *str, );
** char *ft_striter(char *str, );
** char *ft_strfilter(char *str, );
** char *ft_strfoldl(char *str, );
** char *ft_strfoldl(char *str, );
** char *ft_strfoldl_new(char *str, );
** char *ft_strzip(char *str, );
** char *ft_strzip_with(char *str, );
** char *ft_strreverse(char *str, );
** char *ft_strreduce(char *str, );
**
** char *ft_strmultimap();
** char *ft_strmultijoin();
** char *ft_strmultiiter();
** char *ft_strmultifilter();
** char *ft_strmultifoldl();
** char *ft_strmultifold();
** char *ft_strmultifold_new();
** char *ft_strmultizip();
** char *ft_strmultizip_with();
** char *ft_strmultireverse();
** char *ft_strmultireduce(char *str, );
*/

/*
** List functions
*/

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lststart(t_list **alst, t_list *new);
t_list					*ft_lstat(t_list *begin_list, unsigned int nbr);
t_list					*ft_lstfind(t_list *begin_list
									, void *data_ref
									, int (*cmp)());
t_list					*ft_lstlast(t_list *begin_list);
void					ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
void					ft_lstpushback(t_list **begin_list
										, void *data
										, size_t size);
void					ft_lstpushfront(t_list **begin_list
										, void *data
										, size_t size);
t_list					*ft_lstpushparams(int ac, char **av);
t_list					*ft_lstcndremove(t_list **begin_list
										, void *data_ref
										, int (*cmp)());
void					ft_lstreverse(t_list **begin_list);
int						ft_lstsize(t_list *begin_list);

/*
** List functions
** Function ideas: should implement as necessary
** {multi} mean it should take a list of f(x)'s and variable num of args
** t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstjoin(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstiter(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfilter(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfold(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfold(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfold_new(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstzip(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstzip_with(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstreverse(t_list *lst, t_list *(*f)(t_list *elem));
**
** t_list *ft_lstmultimap(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstmultijoin(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstmultiiter(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstmultifilter(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstmultifoldld(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstmultifoldld(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstmultifoldld_new(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstmultizip(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstmultizip_with(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstmultireverse(t_list *lst, t_list *(*f)(t_list *elem));
*/

/*
** Array functions
*/

void					*ft_arriter(void (*f)(void *elem, size_t i)
										, size_t len
										, size_t step
										, void *arr);
void					*ft_arrfoldl(void *(*f)(void *acc, size_t i)
										, void *arr
										, size_t len
										, size_t step);

/*
** implement once able to use stdarg.h
** void *ft_arrmultiiter(t_lambda f[], size_t len, size_t step, void *arr);
** void *ft_arrfoldr(void *arr, size_t len, size_t step);
** void *ft_arrfoldr_new(void *arr, size_t len, size_t step);
** void *ft_arrmultifoldl(void *arr, size_t len, size_t step);
** void *ft_arrmultifoldr(void *arr, size_t len, size_t step);
** void *ft_arrmultifoldr_new(void *arr, size_t len, size_t step);
*/

/*
** Function ideas: should implement as necessary
** {multi} mean it should take a list of f(x)'s and variable num of args
** void *ft_arrmap(void *arr, size_t len, size_t step);
** void *ft_arrjoin(void *arr, size_t len, size_t step);
** void *ft_arrfilter(void *arr, size_t len, size_t step);
** void *ft_arrzip(void *arr, size_t len, size_t step);
** void *ft_arrzip_with(void *arr, size_t len, size_t step);
** void *ft_arrreverse(void *arr, size_t len, size_t step);
**
** void *ft_arrmultimap(void *arr, size_t len, size_t step);
** void *ft_arrmultijoin(void *arr, size_t len, size_t step);
** void *ft_arrmultifilter(void *arr, size_t len, size_t step);
** void *ft_arrmultizip(void *arr, size_t len, size_t step);
** void *ft_arrmultizip_with(void *arr, size_t len, size_t step);
** void *ft_arrmultireverse(void *arr, size_t len, size_t step);
*/

/*
** io functions
*/

int						ft_atoi(char *str);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);

/*
** int functions
*/

int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_count_digits(int number);

/*
** Function ideas: should implement as necessary
** {multi} mean it should take a list of f(x)'s and variable num of args
** https://github.com/OpenGenus/cosmos has common data structures and algos
**
** Misc functions
** char *ft_swap_all();
** char *ft_swap();
** void free_all(....);
*/
#endif
