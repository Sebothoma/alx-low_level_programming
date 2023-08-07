#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Define error codes*/
#define ERROR_FILE_READ  1
#define ERROR_MEMORY_ALLOC 2
#define ERROR_FILE_OPEN  3

/* ... The rest of the functions and constants ...*/

int main(int argc, char *argv[])
{
/* Validate command line arguments */
if (argc < 2)
{
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return 1;
}

Elf64_Ehdr *header;
int o, r;

o = open(argv[1], O_RDONLY);
if (o == -1)
{
fprintf(stderr, "Error: Can't open file '%s'\n", argv[1]);
return ERROR_FILE_OPEN;
}

header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close(o);
fprintf(stderr, "Error: Memory allocation failed\n");
return ERROR_MEMORY_ALLOC;
}

r = read(o, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
close(o);
fprintf(stderr, "Error: Cannot read file '%s'\n", argv[1]);
return ERROR_FILE_READ;
}

check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);
print_class(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);

free(header);
close(o);
return 0;
}
