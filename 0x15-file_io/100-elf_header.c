#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */

int main(int argc, char *argv[])
{
/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
if (argc != 2)
{
fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
exit(EXIT_FAILURE);
}

Elf64_Ehdr *header;
int o, r;

o = open(argv[1], O_RDONLY);
if (o == -1)
{
perror("Error: Can't open file");
exit(EXIT_FAILURE);
}

header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close(o);
perror("Error: Memory allocation failed");
exit(EXIT_FAILURE);
}

r = read(o, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
close(o);
perror("Error: Failed to read the file");
exit(EXIT_FAILURE);
}

check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)

free(header);
close(o);
return EXIT_SUCCESS;
}
