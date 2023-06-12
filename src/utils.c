#include "woody.h"

void error(char *s)
{
    write(2, s, strlen(s));
    exit(1);
}

char    *cp_file(char *file, woody w)
{
    int fd = open(file, O_RDWR);
    if (fd == -1)
        error(strerror(errno));
    w.size = lseek(fd, 0, SEEK_END);
    if (w.size == -1)
        close(fd), error(strerror(errno));
    lseek(fd, 0, SEEK_SET);
    char *map = (char *) mmap(NULL, w.size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    close(fd);
    if (map == MAP_FAILED)
        error(strerror(errno));
    return map;
}

int verif_elf(char *file)
{
	if (file[0] == (char)127 && file[1] == 'E' && file[2] == 'L' && file[3] == 'F' && file[4] == 2)
        return (0);
    return (1);
}