# Ft_printf
This project is pretty straight forward. a recoded version of printf (42 Login MOUGNOU).

# 
ft_printf must achieve the following mandatory requirements:  
  
* Manage the following conversions: `s`,`p`,`d`,`i`,`u`,`x`, `X`, `c`
* Manage `%%`
* Manage the flags `0`, `-`
* Manage the minimum field-width
* Manage the precision
  
The function must conform to 42's norm.  
The function cannot leak. All errors must be handled carefully. In no way can the function quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  
Allowed functions are `write`, `malloc`, `free`, `exit` and the three functions of `stdarg`. Everything else is forbidden.
***
### Using the project
To compile, run `make`. This will compile **libftprintf.a**. To use, include `ft_printf.h` (located inside includes directory) and use just like `printf`:
```c
#include "ft_printf.h"

int				main(void)
{
	ft_printf("%s, %s!\n", "Hello", "world");
	return (0);
}
```
Then compile with a program:
```console
gcc -Wall -Werror -Wextra main.c libftprintf.a
```
