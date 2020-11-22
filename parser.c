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
			while(1)
			{
				while (cmd[i] != 34 && i < len && cmd[i] != 36)
				{
					str = strj(str, cmd[i++]);
				}
				if (i == len)
					return (-1);
				printf("\t\t\t|%s|\n", str);
				free(str);
				if (cmd[i] == 34)
					if (cmd[i + 1] == 32)
						printf("\t\t\t| |\n");
				str = malloc(sizeof(char) * 1);
				*str = '\0';
				cnt++;
				if (cmd[i] == 34)
					break ;
				i++;
				while (cmd[i] != 39 && cmd[i] != 34 && cmd[i] != 32 && cmd[i] != 36 && i < len)
					str = strj(str, cmd[i++]);
				printf("\t\t\t|%s|\n", str);
				free(str);
				str = malloc(sizeof(char) * 1);
				*str = '\0';
				cnt++;
			}
		}
		
		if (cmd[i] == 36)
		{
			i++;
			while (cmd[i] != 39 && cmd[i] != 34 && cmd[i] != 32 && cmd[i] != 36 && i < len)
					str = strj(str, cmd[i++]);
			printf("\t\t\t|%s|\n", str);
			free(str);
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			if (cmd[i] == 32)
				printf("\t\t\t| |\n");
			cnt++;
			i--;
			continue ;
		}

		if (cmd[i] != 34 && cmd[i] != 39 && cmd[i] != 32 && cmd[i] != 36)
		{
			while (cmd[i] != 32 && cmd[i] && cmd[i] != 34 && cmd[i] != 39 && cmd[i] != 36)
				str = strj(str, cmd[i++]);
			printf("\t\t\t|%s|\n", str);
			free(str);
			if (cmd[i] == 32)
				printf("\t\t\t| |\n");
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			cnt++;
			if (cmd[i] != 36)
			{
				i--;
				continue ;
			}
			while (cmd[i] != 39 && cmd[i] != 34 && cmd[i] != 32 && cmd[i] != 36 && i < len)
					str = strj(str, cmd[i++]);
			printf("\t\t\t|%s|\n", str);
			free(str);
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			if (cmd[i] == 32)
				printf("\t\t\t| |\n");
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