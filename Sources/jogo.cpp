#include "../Headers/tabuleiro.hpp"
#include "../Headers/jogo.hpp"

Jogo::Jogo(void){
    char simbolo;
    char simboloPC;
    int posicao;
    string msg;
    Tabuleiro * tabuleiro = new Tabuleiro();

    ///////////////////////////////
    this->vitoriaJogador = 0;
    this->vitoriaComputador = 0;
    this->rodada = true;
    for (int i; i < 9; i++)
        this->memoria[i] = true; //Se true eh valido

    this->cabecalho();
    this->menuJogo();
    do
    {
        cout << "                                     Digite x ou o: ";
        cin >> simbolo;
        msg = (simbolo == 'x' or simbolo == 'o')? "Aprovado a escolha" : "Escolha nao aprovada. Tente novamente!";
    } while (msg != "Aprovado a escolha");
    simboloPC = (simbolo == 'x')? 'o' :'x';

    //Criar uma animação de load()
    tabuleiro->inicializarTabuleiro();
    tabuleiro->mostrarTabuleiro();

    do
    {
        cout << endl <<"          Digite digite a poicao que voce deseja marcar: ";
        cin >> posicao;
    } while (!this->verificaPosicao(posicao));

    tabuleiro->marcar(posicao,simbolo);
    tabuleiro->mostrarTabuleiro();
    //verifica se o jogo acabou
    this->setRodada(); //Rodada mudou para o pc
    //pC escolha e tudo se repete

    
    this->menuPlacar();


}

Jogo::~Jogo(void){

}

void Jogo::cabecalho(void){
    cout << endl << endl;
    cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
    cout << "                                     x                                       x          " << endl;
    cout << "                                     x             JOGO DA VELHA             x          " << endl;
    cout << "                                     x                                       x          " << endl;
    cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
    cout << endl << endl;
}

void Jogo::menuJogo(void){
    cout << endl << endl;
    cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
    cout << "                                     x                Esolha                 x          " << endl;
    cout << "                                     x           X       ou       O          x          " << endl;
    cout << "                                     x                    ?                  x          " << endl;
    cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
    cout << endl << endl;
}

void Jogo::menuPlacar(void){
    cout << endl << endl;
    cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
    cout << "                                     x      Placar Numero de Vitorias        x          " << endl;
    cout << "                                     x Pontuacao Jogador   :    "<< this->getVitoriaJogador() <<"            x          " << endl;
    cout << "                                     x Pontuacao Computador:    "<< this->getVitoriaComputador() <<"            x          " << endl;
    cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
    cout << endl << endl;
}

int Jogo::getVitoriaJogador(void){
    return this->vitoriaJogador;
}

int Jogo::getVitoriaComputador(void){
    return this->vitoriaComputador;
}

bool Jogo::getRodada(void){
    return this->rodada;
}
void Jogo::setRodada(void){
    this->rodada = !this->rodada; //Se true fica false, se false fica true
}
void Jogo::setVitoriaJogador(void){
    this->vitoriaJogador++;
}

void Jogo::setVitoriaComputador(void){
    this->vitoriaComputador++;
}

bool Jogo::verificaPosicao(int posicao){
    if(posicao > 0 and posicao < 10)
        return this->memoria[posicao-1] == true;
    return false;
}