#include "get_next_line.h"




int here_your_line(char *str)
{
	int i = 0;

	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return i;
}


char *uptade_buffer();



char *get_next_line(int fd)
{
	static char *BUFFER;
	char *old;
	char *tmp;
	char *line;
	
	int count = 1;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return NULL;
	
	while ((count = read(fd, tmp, BUFFER_SIZE)) >= 0)
	{
		if (count == 0)
			return (free(tmp), NULL);
		tmp[count] = '\0';
		old = BUFFER;
		BUFFER = ft_strjoin(BUFFER, tmp);
		free(old);
		if (ft_strchr(BUFFER, '\n') != NULL)
			break;
	}

	old = BUFFER;

	line = ft_substr(BUFFER, 0, here_your_line(BUFFER) + 1);
	BUFFER = ft_substr(BUFFER, here_your_line(BUFFER) + 1, (ft_strlen(BUFFER) - here_your_line(BUFFER)));
	
	if (count < 0 || !BUFFER)
	{
		free(tmp);
		free(old);
		free(line);
		return NULL;
	}
	if (count == 0 && (!line || !*line))
	{
		free(line);
		free(tmp);
		free(old);
		return NULL;
	}
	free(old);
	free(tmp);
	return (line);
}

int main()
{
	int fd= open("anas.txt", O_RDONLY, 0777);
	char *s;
	for (int i = 0; i < 3; i++)
	{
		s = get_next_line(fd);
		printf("%s", s);
		 free(s);
	}
	system("leaks a.out");
	
}