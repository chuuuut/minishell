/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:32:41 by chdoe             #+#    #+#             */
/*   Updated: 2025/07/29 14:30:41 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Program name
    minishell
Turn in files
    Makefile, *.h, *.c
Makefile
    NAME, all, clean, fclean, re
Arguments
External functs.
    readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay,
    add_history, printf, malloc, free, write, access, open, read, close,
    fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset,
    sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve,
    dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty,
    ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
    tgetnum, tgetstr, tgoto, tputs
Libft authorized
    Yes
Description
    Write a shell

Your shell should:
• Display a prompt when waiting for a new command.
• Have a working history.
• Search and launch the right executable (based on the PATH variable or using a
    relative or an absolute path).
• Use at most one global variable to indicate a received signal. Consider the
    implications: this approach ensures that your signal handler will not access
    your main data structures.

    Be careful. This global variable must only store the signal number
and must not provide any additional information or access to data.
Therefore, using "norm" type structures in the global scope is
forbidden.


• Not interpret unclosed quotes or special characters which are not required by
    the subject such as \ (backslash) or ; (semicolon).
• Handle ’ (single quote) which should prevent the shell from interpreting the
    meta-characters in the quoted sequence.
• Handle " (double quote) which should prevent the shell from interpreting the
    meta-characters in the quoted sequence except for $ (dollar sign).
• Implement the following redirections:
    ◦ < should redirect input.
    ◦ > should redirect output.
    ◦ << should be given a delimiter, then read the input until a line containing
    the delimiter is seen. However, it doesn’t have to update the history!
    ◦ >> should redirect output in append mode.
• Implement pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.
• Handle environment variables ($ followed by a sequence of characters) which
should expand to their values.
• Handle $? which should expand to the exit status of the most recently executed
foreground pipeline.
• Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
• In interactive mode:
    ◦ ctrl-C displays a new prompt on a new line.
    ◦ ctrl-D exits the shell.
    ◦ ctrl-\ does nothing.
• Your shell must implement the following built-in commands:
    ◦ echo with option -n
    ◦ cd with only a relative or absolute path
    ◦ pwd with no options
    ◦ export with no options
    ◦ unset with no options
    ◦ env with no options or arguments
    ◦ exit with no options


The readline() function may cause memory leaks, but you are not required to
fix them. However, this does not mean your own code, yes the code you wrote,
can have memory leaks.
You should limit yourself to the subject description. Anything that is not asked
is not required.
If you have any doubt about a requirement, take bash as a reference.
*/



/*
> = Outfile
< = Infile
$ = Variable Environnement
' = single quote
" = double quote

Expand c'est quoi ? Tu va Expand tes Variable d'Environnement genre $HOME = /homes/chdoe

' == N'interprete pas l'interieur (Fait pas les Expand)
" == interprete l'interieur (Fait les Expand)

Etapes de bash (Pas vraiment obliger de faire comme bash)
ls -la $HOME > '$PWD' < Coucou | wc -l
-> 1er Expand /// "ls -la $HOME" --> "ls -la /homes/chdoe"
ls -la /homes/chdoe > '$PWD' < Coucou | wc -l
-> 2eme Séparer les commands
ls -la /homes/chdoe > '$PWD' < Coucou
wc -l
-> 3eme Tokenisation
// Ta fonction qui rempli la struct
struct s_cmd
{
    char *cmd;
    char **args;
    char **Infiles; // On met un char ** car il y a besoin de tout les fichiers IN et OUT pour bien gerer les erreurs durant l'execution
    char **Outfiles;
    t_cmd *next;
} t_cmd;


cmd = ls
args (opt) = -la, $HOME
Infiles = Coucou
Outfiles = $PWD

- checker `echo $?`
- checker `echo $nimp$HOME$nimp2` -> fait comme `echo $HOME`
*/

#include "../includes/minishell.h"

// char	*expand_cmd(char **argv, char **env)
// {
// 	int	i;

// 	i = 1;
// 	while (argv[i])
// 	{
// 		if (ft_strncmp(argv[i][0], '$', ft_strlen(argv[i])) == 0)
// 		{
			
// 		}
// 	}
// 	// checker si la commande existe dans env
// 	// si elle existe, recuperer le chemin
// 	// sinon, checker ce que ca fait dans le bash --posix et renvoyer la meme chose
// }
