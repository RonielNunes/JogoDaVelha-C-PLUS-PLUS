#include "../Headers/tabuleiro.hpp"
#include "../Headers/jogo.hpp"

Jogo::Jogo(void){
    char simbolo;
    char simboloPC;
    int posicao;
    string msg;
    Tabuleiro * tabuleiro = new Tabuleiro();

    this->vitoriaJogador = 0;
    this->vitoriaComputador = 0;
    this->rodada = true;
    this->jogador = false;
    this->computador = false;
    vector<vector<char>> aux(3,vector<char>(3));
    this->memoriaTabuleiro = aux;
    
    vector<string> vetorauxiliar(9);
    this->memoria = vetorauxiliar;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            memoriaTabuleiro[i][j] = '*';
        }
        
    }
    

    for (int i = 0; i < this->memoria.size() ; i++)
        memoria.at(i) = "valido";

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
        do
        {
            cout << endl <<"          Digite digite a posicao que voce deseja marcar: ";
            cin >> posicao;
            
        } while (!this->verificaPosicao(posicao,simbolo));

        tabuleiro->marcar(posicao,simbolo);
        tabuleiro->mostrarTabuleiro();
        //verifica se o jogo acabou
        this->setRodada(); //Rodada mudou para o pc
        //pC escolha e tudo se repete

        
        this->menuPlacar();
    } while (!this->verificaFimDeJogo(simbolo));

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

bool Jogo::getJogador(void){
    return this->jogador;

}

void Jogo::setJogador(void){
    this->jogador = !this->jogador;
}

bool Jogo::getComputador(void){
    return this->computador;
}

void Jogo::setComputador(void){
    this->computador = !this->computador;
}

void Jogo::setVitoriaJogador(void){
    this->vitoriaJogador++;
}

void Jogo::setVitoriaComputador(void){
    this->vitoriaComputador++;
}

bool Jogo::verificaPosicao(int posicao, char simbolo){
    if(posicao > 0 and posicao < 10){
        if(posicao == 1){
            this->memoriaTabuleiro[0][0] = simbolo; 
        }else if(posicao == 2){
            this->memoriaTabuleiro[0][1] = simbolo; 
        }else if(posicao == 3){
            this->memoriaTabuleiro[0][2] = simbolo; 
        }else if(posicao == 4){
            this->memoriaTabuleiro[1][0] = simbolo; 
        }else if(posicao == 5){
            this->memoriaTabuleiro[1][1] = simbolo; 
        }else if(posicao == 6){
            this->memoriaTabuleiro[1][2] = simbolo; 
        }else if(posicao == 7){
            this->memoriaTabuleiro[2][0] = simbolo; 
        }else if(posicao == 8){
            this->memoriaTabuleiro[2][1] = simbolo; 
        }else if(posicao == 9){
            this->memoriaTabuleiro[2][2] = simbolo; 
        } 
        if(this->memoria[posicao-1] == "valido"){
            this->memoria.at(posicao-1) = "invalido";
            return true;
        }
    }
    return false;
}

bool Jogo::verificaFimDeJogo(char simbolo){
    int linhaX = 0,linhaO = 0;
    int colunaX = 0, colunaO = 0;
    int diagonalPrincipalX = 0, diagonalPrincipalO = 0;
    int diagonalReversaX = 0, diagonalReversaO = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //Verificação das linhas 
            if(i == 0){
                if(this->memoriaTabuleiro[i][j] == 'x'){
                    linhaX++;
                }else if(this->memoriaTabuleiro[i][j] == 'o'){
                    linhaO++;
                }
            }
            if(i == 1){
                if(this->memoriaTabuleiro[i][j] == 'x'){
                    linhaX++;
                }else if(this->memoriaTabuleiro[i][j] == 'o'){
                    linhaO++;
                }
            }
            if(i == 2){
                if(this->memoriaTabuleiro[i][j] == 'x'){
                    linhaX++;
                }else if(this->memoriaTabuleiro[i][j] == 'o'){
                    linhaO++;
                }
            }
            //verificação das colunas
            if(j == 0){
                if(this->memoriaTabuleiro[j][i] == 'x'){
                    colunaX++;
                }else if(this->memoriaTabuleiro[j][i] == 'o'){
                    colunaO++;
                }
            }
            if(j == 1){
                if(this->memoriaTabuleiro[j][i] == 'x'){
                    colunaX++;
                }else if(this->memoriaTabuleiro[j][i] == 'o'){
                    colunaO++;
                }
            }
            if(j == 2){
                if(this->memoriaTabuleiro[j][i] == 'x'){
                    colunaX++;
                }else if(this->memoriaTabuleiro[j][i] == 'o'){
                    colunaO++;
                }
            }


            //Verificação da diagonal principal
            if(i == j){
                if(this->memoriaTabuleiro[i][j] == 'x'){
                    diagonalPrincipalX++;
                }else if(this->memoriaTabuleiro[i][j] == 'o'){
                    diagonalPrincipalO++;
                }
            }
            //verificando diagonal reversa
            if(i + j == 2){
                
                if(this->memoriaTabuleiro[i][j] == 'x'){
                    diagonalReversaX++;
                }else if(this->memoriaTabuleiro[i][j] == 'o'){
                    diagonalReversaO++;
                }
            }
        }

        //Verificando flags linhas
        if(linhaX == 3){
            if(simbolo == 'x'){
                this->setVitoriaJogador();
                this->setJogador();
            
            }else{
                this->setVitoriaComputador();
                this->setComputador();
            }
            return true;

        }else if(linhaO== 3){

            if(simbolo == 'x'){
                this->setVitoriaJogador();
                this->setJogador();
            }
            else{
                this->setVitoriaComputador();
                this->setComputador();
            }
            return true;
        }

        linhaX = 0;
        linhaO = 0;

        //Verificando flags colunas
        if(colunaX == 3){
            if(simbolo == 'x'){
                this->setVitoriaJogador();
                this->setJogador();
            
            }else{
                this->setVitoriaComputador();
                this->setComputador();
            }
            return true;

        }else if(colunaO== 3){

            if(simbolo == 'x'){
                this->setVitoriaJogador();
                this->setJogador();
            }
            else{
                this->setVitoriaComputador();
                this->setComputador();
            }
            return true;
        }

        colunaX = 0;
        colunaO = 0;

        //verificando flags diagonal
        if(diagonalPrincipalX == 3){

            if(simbolo == 'x'){
                this->setVitoriaJogador();
                this->setJogador();
            }
            else{
                this->setVitoriaComputador();
                this->setComputador();
            }
            return true;
        }else if(diagonalPrincipalO == 3){
            if(simbolo == 'x'){
                this->setVitoriaJogador();
                this->setJogador();
            }
            else{
                this->setVitoriaComputador();
                this->setComputador();
            }
            return true;
        }

        //Verificando flags diagonal reversa
        if(diagonalReversaX == 3){
            if(simbolo == 'x'){
                this->setVitoriaJogador();
                this->setJogador();
            }
            else{
                this->setVitoriaComputador();
                this->setComputador();
            }
            return true;
        }else if(diagonalReversaO == 3){
            if(simbolo == 'x'){
                this->setVitoriaJogador();
                this->setJogador();
            }
            else{
                this->setVitoriaComputador();
                this->setComputador();
            }
            return true;
        }
    }
    return false;
}

void Jogo::mensagemFim(void){
    if(this->getJogador()){
        cout << endl << endl;
        cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
        cout << "                                     x               PARABENS                x          " << endl;
        cout << "                                     x         VOCE VENCEU O JOGO!!!         x          " << endl;
        cout << "                                     x                                       x          " << endl;
        cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
        cout << endl << endl;
        this->setJogador();
    }else{
        cout << endl << endl;
        cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
        cout << "                                     x               VOCE PERDEU             x          " << endl;
        cout << "                                     x           SE TENTE NOVAMENTE!!!       x          " << endl;
        cout << "                                     x                                       x          " << endl;
        cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
        cout << endl << endl;
        this->setComputador(); //Retornando para falso
    }
}

