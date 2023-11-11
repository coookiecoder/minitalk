/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/11 13:25:56 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}
