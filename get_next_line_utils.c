#include "get_next_line.h"

// strlen
size_t ft_strlen(char const *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
//strdup
char *ft_strdup(const char *s)
{
	int i;
	int j;
	int s_len;
	char *dup;

	i = 0;
	j = 0;
	s_len = ft_strlen(s);
	dup = (char *)malloc(s_len + 1);
	if (dup == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[j] = s[i];
		j++;
		i++;
	}
	dup[j] = '\0';
	return (dup);
}

///strjoin 
static char *add(char const *s1, char const *s2)
{
	size_t s1_len;
	size_t s2_len;
	size_t i;
	size_t j;
	char *s3;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (i < s1_len)
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	  s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char *ft_strjoin(char const *s1, char const *s2)
{ 
	char *s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	   return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s3 = add(s1, s2);
	return (s3);
}

static char *ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}


char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t s_len;
	char *substr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return ft_strdup("");
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc((len + 1) *sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strncpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr); 

}


char *ft_strchr(const char *s, int c)
{
	int i;
	char m;
	
	i = 0;
	m = c;
	if (m == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == m)
			return ((char *)&s[i]);
		i++;
	} 
	return (NULL);
}