/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/11 16:29:16 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_char(char c, pid_t pid)
{
	int	cursor;

	cursor = 0;
	while (cursor < 8)
	{
		if (c & 1 << cursor++)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(30);
	}
}

int	main(int argc, char **argv)
{
	int		cursor;
	pid_t	pid;

	cursor = 0;
	if (argc == 1 || argc > 3)
		return (1);	
	pid = ft_atoi(*(argv + 1));
	if (argc == 2)
		return (0);
	while (*(*(argv + 2) + cursor))
		send_char(*(*(argv + 2) + cursor++), pid);
	send_char(*(*(argv + 2) + cursor), pid);
}
