#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif


char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);
size_t ft_strlen(char const *str);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *get_next_line(int fd);
char *ft_strchr(const char *s, int c);

#endif