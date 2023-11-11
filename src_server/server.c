/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/11 16:20:51 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

#include <stdio.h>

void	ft_sig(int signal)
{
	static int	call;
	static char	buffer;

	if (signal == SIGUSR2)
		buffer |= 1 << call;
	if (signal == SIGUSR1)
		buffer |= 0 << call;
	call++;
	if (call == 8)
	{
		write(1, &buffer, 1);
		buffer = 0;
		call = 0;
	}
}

int	main(void)
{
	char	*pid;
	
	pid = ft_itoa(getpid());
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	signal(SIGUSR1, ft_sig);
	signal(SIGUSR2, ft_sig);
	while(1)
		(void) 0;
}
