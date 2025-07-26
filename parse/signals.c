//      fonction qui attrape les signaux
#include "../includes/minishell.h"

void    sh_ctrlc_behave(int signal)
{
    printf("\n");
    rl_on_new_line();           //met le curseur au home
    rl_replace_line("", 0);     //vide le buffer
    rl_redisplay();             //reaffiche le prompt

}

void    get_signal(void)
{
    signal(SIGINT, sh_ctrlc_behave);
    signal(SIGQUIT, SIG_IGN);
}
