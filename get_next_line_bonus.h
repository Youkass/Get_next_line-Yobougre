/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:39:56 by yobougre          #+#    #+#             */
/*   Updated: 2021/12/02 17:42:04 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(char *s);
int		ft_strchr_pimp(char *s, char c);
char	*ft_strdup_pimp(char *s);
char	*ft_strjoin_pimp(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_next_line(char *line);

#endif
