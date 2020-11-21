#include "minishell.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

t_arg	*new_arg(char *name, int is_env)
{
	t_arg *arg;

	arg = malloc(sizeof(t_arg));
	arg->name = name;
	arg->is_env = is_env;
	return (arg);
}

t_cmd	*new_cmd(char *name, char *flags, t_list *args, int std_in, int std_out, int is_separated, int is_bin)
{
	t_cmd *cmd;
	t_arg *arg;

	arg = new_arg("hello", 0);
	cmd = malloc(sizeof(t_cmd));
	cmd->name = name;
	cmd->flags = flags;
	cmd->args = ft_lstnew(arg);
	cmd->std_in = std_in;
	cmd->std_out = std_out;
	cmd->is_separated = is_separated;
	cmd->is_bin = is_bin;
	return (cmd);
}

void print_cmds(t_list *cmd_list)
{
	t_cmd *cmd;
	t_arg *arg;
	while(cmd_list)
	{
		cmd = cmd_list->content;
		arg = cmd->args->content;
		// printf("printf = %d\n\n", printf("name = %s\nflags = %s\narg_name = %s\narg_is_env = %d\n", 
				// cmd->name, cmd->flags, arg->name, arg->is_env));
		cmd_list = cmd_list->next;
	}
}

void	example(t_info *info)
{
	t_cmd	*cmd;

	cmd = new_cmd(ft_strdup("echo"), ft_strdup("-n"), NULL, -1, 1, 0, 0);
	info->cmd = ft_lstnew(cmd);
	cmd = new_cmd(ft_strdup("sdfsf"), ft_strdup("sadf"), NULL, -1, 1, 0, 0);
	ft_lstadd_back(&(info->cmd), ft_lstnew(cmd));
	cmd = new_cmd(ft_strdup("echo"), ft_strdup(""), NULL, -1, 1, 0, 0);
	ft_lstadd_back(&(info->cmd), ft_lstnew(cmd));
	print_cmds(info->cmd);
}



int main(int argc, char **argv, char *envp[])
{
	t_info info;
	example(&info);


	parser("'fdgfdg'\"hello   world!!!\"'ghd''echo'this is the      first example");
	 
	
	return (0);
}
