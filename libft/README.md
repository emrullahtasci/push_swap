*This project has been created as part of the 42 curriculum by mkotan.*

# Libft

## Description
**Libft** is the first C library developed during the 42 curriculum.
The goal of this project is to reimplement a set of standard C library functions, as well as additional utility functions, in order to deeply understand how they work internally.

By creating this library from scratch, we build a strong foundation in:
- Memory management
- String manipulation
- Low-level programming in C
- Linked list operations

This library is intended to be reused in future 42 projects.

---

## Instructions

### Compilation
To compile the library, simply run:
```bash
make
This will generate the static library:

libft.a
Makefile Rules
make or make all → Compile the library

make clean → Remove object files

make fclean → Remove object files and libft.a

make re → Recompile everything

All files are compiled with:

-Wall -Wextra -Werror
```
## Library Content
### Part 1 – Libc Functions
Reimplementation of standard libc functions, all prefixed with ft_, such as:

Character checks:
ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint

Memory functions:
ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp

String functions:
ft_strlen, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr,
ft_strlcpy, ft_strlcat, ft_strdup

Conversion functions:
ft_atoi

Allocation functions:
ft_calloc

### Part 2 – Additional Functions
Utility functions not present in libc or implemented differently:

ft_substr

ft_strjoin

ft_strtrim

ft_split

ft_itoa

ft_strmapi

ft_striteri

Output functions using file descriptors:
ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd

### Part 3 – Linked List Functions
Implementation of a simple linked list using the following structure:

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
Implemented functions:

ft_lstnew

ft_lstadd_front

ft_lstadd_back

ft_lstsize

ft_lstlast

ft_lstdelone

ft_lstclear

ft_lstiter

ft_lstmap

## Resources
- [Linux man pages](https://man7.org/linux/man-pages/)
- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/)
- [C Programming Reference (cppreference)](https://en.cppreference.com/w/c)
- [42 Intra](https://intra.42.fr)

### AI Usage
AI tools were used **only** for:
- Clarifying documentation and function behavior
- Understanding edge cases and constraints
- Reviewing explanations after personal implementation
- External help was used while writing this README to improve readability and formatting.

No code was copied or generated directly by AI.
All implementations were written and tested manually.
Notes
No global variables were used

All heap allocations are properly freed

The project follows the 42 Norm

Designed to be reused in future projects

Author
👤 mkotan
42 Kocaeli
