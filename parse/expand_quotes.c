/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:31:20 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/12 15:26:46 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//pas d'interpretation de $ dans ''

int	expand_quotes(char *line, t_quotes *quotes)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] && line[i] == '$')
		{
			i++;
			while (line[i] && is_space(line[i]))
				i++;
            if (is_bad_redirect(line[i]))
				return (-1);
		}
        else
    		i++;
	}
	return (0);
}


// # ✅ Cas valides (expansion autorisée)
// echo $USER                # ➤ Affiche la valeur de la variable USER
// echo "$HOME"              # ➤ Expansion dans double quotes (préserve les espaces)
// echo text_$PATH           # ➤ Expansion collée à du texte
// echo "${PATH}"            # ➤ Expansion avec accolades
// echo "$USER_$HOSTNAME"    # ➤ Plusieurs expansions dans une même string
// echo "Bonjour $USER !"    # ➤ Mélange texte + expansion
// echo $@                   # ➤ Expansion des paramètres positionnels
// echo "$1"                 # ➤ Expansion d’un argument spécifique
// echo "$(date)"            # ➤ Command substitution dans double quotes
// echo $INEXISTANT           # ➤ Expansion d'une variable inexistante → affiche rien
// echo "$INEXISTANT"         # ➤ Expansion inexistante dans double quotes → affiche ""
// echo texte$INEXISTANT fin   # ➤ Expansion inexistante au milieu → affiche "textefin"
// echo "${INEXISTANT}"       # ➤ Avec accolades → expansion vide
// echo "$INEXISTANT$USER"    # ➤ Mélange vide + expansion valide
// echo ${INEXISTANT:-default} # ➤ Expansion avec valeur par défaut (bash, non POSIX strict)

// # ❌ Cas à traiter correctement en parsing
// echo '$INEXISTANT'         # ➤ Pas d’expansion dans single quotes → littéral
// echo "\$INEXISTANT"        # ➤ Dollar échappé → affiche $INEXISTANT
// echo ${INEXISTANT          # ➤ Accolade ouverte non fermée → erreur de syntaxe
// echo "$INEXISTANT          # ➤ Double quote ouverte non fermée → erreur
// echo '$USER'              # ➤ Pas d’expansion dans single quotes
// echo "\$USER"             # ➤ Caractère dollar échappé → affiche $USER
// echo $                    # ➤ Dollar seul → littéral, pas d’expansion
// echo $123                 # ➤ Variable non valide (commence par un chiffre) → littéral
// echo "${UNFINISHED"       # ➤ Accolade non fermée → erreur de syntaxe
// echo $"TEXT"              # ➤ Cas spécial (localisation) → à supporter ou ignorer
// echo ${}                  # ➤ Vide entre accolades → erreur
// echo "$UNFINISHED         # ➤ Double quote ouverte → erreur (unclosed double quote)

