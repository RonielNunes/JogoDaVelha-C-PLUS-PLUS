#include "./Headers/tabuleiro.hpp"
#include "./Headers/system.hpp"

int main(int argc, char const *argv[])
{
    Tabuleiro *jogo = new Tabuleiro(); //O new faz a alocação do objeto é retorna seu endereço
    jogo->inicializarTabuleiro();
    jogo->mostrarTabuleiro();
    jogo->marcar(1,'x');
    jogo->mostrarTabuleiro();
    jogo->marcar(2,'x');
    jogo->mostrarTabuleiro();
    jogo->marcar(4,'x');
    jogo->mostrarTabuleiro();
    jogo->marcar(2,'0');
    jogo->mostrarTabuleiro();

    cout << sistema;

    return 0;
}
