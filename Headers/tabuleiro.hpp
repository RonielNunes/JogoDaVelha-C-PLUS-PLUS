#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Tabuleiro{
    private:
        int tamanho;
        vector<vector<char>> * matriz;
    public:
        Tabuleiro(void);  //Construtor
        ~Tabuleiro(void); //Construtor
        bool marcar(int , int , char );
        void mostrarTabuleiro(void);
};

#endif