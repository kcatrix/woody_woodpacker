#ifndef WOODY_H
#define WOODY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>

typedef struct s_woody
{
    char        *file;
    int         size;
    Elf64_Ehdr  *header;
    Elf64_Shdr  *text;
	Elf64_Phdr  *load;
    int         new;
}               woody;

void		error(char *s);
char    	*cp_file(char *file, woody w);

#endif