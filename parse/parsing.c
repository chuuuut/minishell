/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:32:41 by chdoe             #+#    #+#             */
/*   Updated: 2025/07/28 12:06:20 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*expand_cmd(char **argv, char **env)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strncmp(argv[i][0], '$', ft_strlen(argv[i])) == 0)
		{
			
		}
	}
	// checker si la commande existe dans env
	// si elle existe, recuperer le chemin
	// sinon, checker ce que ca fait dans le bash --posix et renvoyer la meme chose
}
