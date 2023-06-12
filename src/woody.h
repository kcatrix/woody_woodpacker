#ifndef WOODY_H
#define WOODY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <elf.h>

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

#endif