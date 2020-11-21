#include "minishell.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char		*strj(char *s1, char s2)
{
	unsigned int	i;
	char			*out_str;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	if (!(out_str = malloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (NULL);
	while (s1[++i])
		out_str[i] = s1[i];
	free(s1);
	out_str[i++] = s2;
	out_str[i] = '\0';
	return (out_str);
}

int cmd_count(char *cmd)
{
	int i;
	int j;
	int cnt;
	char *str;
	int len;

	len = ft_strlen(cmd);
	cnt = 0;
	str = malloc(sizeof(char) * 1);
	*str = '\0';
	i = -1;

	while (cmd[++i])
	{
		if (cmd[i] == 39)
		{
			i++;
			while (cmd[i] != 39 && i < len)
			{
				str = strj(str, cmd[i++]);
			}
			printf("\t\t\t|%s|\n", str);
			free(str);
			if (cmd[i + 1] == ' ')
				printf("\t\t\t| |\n");
			str = malloc(sizeof(char) * 1);
			*str = '\0'; 
			if (i == len)
				return (-1);
			cnt++;
		}

		if (cmd[i] == 34)
		{
			i++;
			while (cmd[i] != 34 && i < len)
			{
				str = strj(str, cmd[i++]);
			}
			printf("\t\t\t|%s|\n", str);
			free(str);
			if (cmd[i + 1] == ' ')
				printf("\t\t\t| |\n");
			str = malloc(sizeof(char) * 1);
			*str = '\0'; 
			if (i == len)
				return (-1);
			cnt++;
		}
		
		if (cmd[i] != 34 && cmd[i] != 39 && cmd[i] != ' ')
		{
			while (cmd[i] != ' ' && cmd[i] && cmd[i] != 34 && cmd[i] != 39)
				str = strj(str, cmd[i++]);
			printf("\t\t\t|%s|\n", str);
			free(str);
			if (cmd[i] == ' ')
				printf("\t\t\t| |\n");
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			cnt++;
			i--;
		}
	}
	return (cnt);
}

void	parser(char *command)
{
	int cmnd;

	if (!command)
		return ;
	printf("count = %d\n" , cmd_count(command));

}