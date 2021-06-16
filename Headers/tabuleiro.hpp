#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

class Tabuleiro{
    private:
        int tamanho;
        vector<vector<string>> matriz;
    public:
        Tabuleiro(void);  //Construtor
        ~Tabuleiro(void); //Construtor
        bool marcar(int , char );
        void inicializarTabuleiro(void);
        void mostrarTabuleiro(void);
};

#endif