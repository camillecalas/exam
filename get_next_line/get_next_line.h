#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (42)
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *line_wip, char *buff);
char	*ft_line(char *line_wip);
char	*ft_new_start(char	*line_wip);
char	*ft_read_fd(int fd, char *line_wip);
char	*get_next_line(int fd);

#endif
