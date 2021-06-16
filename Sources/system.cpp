#include "../Headers/system.hpp"

// ================ texto colorido ================

// Algoritmo para texto colorido retirado do site: https://www.clubedohardware.com.br/topic/1307510-programa-em-c-ou-c-com-texto-colorido-como-criar-estou-usando-dev-c/

/*             0     1    2     3   4      5      6      7         8  */
typedef enum
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY, /* nome das cores */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLORS;
/*  9         10         11        12        13         14    15 */

static int __BACKGROUND = 15 /*BLACK*/; /*pode ser o numero ou o nome da cor*/
static int __FOREGROUND = LIGHTGRAY;

void textcolor(int letras, int fundo)
{ /*para mudar a cor de fundo mude o background*/
    __FOREGROUND = letras;
    __BACKGROUND = fundo;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            letras + (__BACKGROUND << 4));
}

// fim do algoritmo referenciado