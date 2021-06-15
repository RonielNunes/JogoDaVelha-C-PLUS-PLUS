#include "../Headers/tabuleiro.hpp"

//Construtor
Tabuleiro::Tabuleiro(void){
    this->tamanho = 9; //Setando o tamanho do tabuleiro
    this->matriz = new vector<vector<char>>; //Inicializando o vetor DE vetor
}

//Destrutor
Tabuleiro::~Tabuleiro(void){
    delete[] this->matriz;
}

bool Tabuleiro::marcar(int x, int y, char simbolo){
    

    return true;
}