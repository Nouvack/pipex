/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:00:40 by nsantand          #+#    #+#             */
/*   Updated: 2025/02/04 12:09:37 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*new_join(const char *s1, const char *s2);
int		ft_srhchr(char *s, int c);
char	*gnl_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
