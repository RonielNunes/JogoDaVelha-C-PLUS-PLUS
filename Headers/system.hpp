#ifdef __unix__
#include <unistd.h>
#define sistema 0

#elif defined(_WIN32) || defined(WIN32)

#define OS_Windows

#include <windows.h>
#define sistema 1

#endif

void textcolor(int letras, int fundo);