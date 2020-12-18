# ifndef _GRAPHICS_H_
# define _GRAPHICS_H_

# define XRES 120		//remains constant
# define YRES 900		//may be variable

# include "universal.h"
using namespace std;

int Menu (char **arr, int rows);
int Menu (char **arr, int rows, char *header);
int Menu (char **arr, int rows, char *header, char *footer);

# endif