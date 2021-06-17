#include "../Headers/tabuleiro.hpp"
#include "../Headers/jogo.hpp"

Jogo::Jogo(void){
    char simbolo;
    char simboloPC;
    char jogar;

    int posicao;
    string msg;
    Tabuleiro * tabuleiro = new Tabuleiro();

    /* ---- Novos nomes ---- */

    //Contadores
    this->numeroDeVitoriaJogador = 0;
    this->numeroDevitoriaComputador = 0;
    this->numeroDeEmpate = 0;

    //Controladores de ganhandor
    this->ganhadorJogador = false;
    this->ganhadorComputador = false;
    this->ganhadorEmpate = false;

    //Controle de quem ta jogando
    this->quemTajogandoJogador =false;
    this->quemTaJogandoComputador = false;


    vector<vector<char>> aux(3,vector<char>(3));
    this->memoriaTabuleiro = aux;

    
    vector<string> vetorauxiliar(9);
    this->memoria = vetorauxiliar;


        

    /*           -------      */

    do
    {
        //inicialização de memórias
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++) {
                memoriaTabuleiro[i][j] = '*';
            }
        }

        for (int i = 0; i < this->memoria.size() ; i++)
            memoria.at(i) = "valido";
        //menus
        this->cabecalho();
        this->menuJogo();
        //Escolha de simbolo
        do{
            cout << "                                     Digite x ou o: ";
            cin >> simbolo;
            msg = (simbolo == 'x' or simbolo == 'o')? "APROVADO" : "NAO_APROVADO";
        } while (msg != "APROVADO");
        simboloPC = (simbolo == 'x')? 'o' :'x';
        //Inicilização de tabuleiro e mostra de placar com o tabuleiro
        tabuleiro->inicializarTabuleiro();
        this->menuPlacar();
        tabuleiro->mostrarTabuleiro();
        //Jogo
        do
        {   
            this->setQuemTajogandoJogador(true); //verdadeiro
            this->setQuemTaJogandoComputador(false);

            do{
                cout << endl <<"          Digite digite a posicao que voce deseja marcar: ";
                cin >> posicao;
            } while (!this->verificaPosicao(posicao,simbolo));
            
            tabuleiro->marcar(posicao,simbolo);
            tabuleiro->mostrarTabuleiro();

            

            if(!this->verificaFimDeJogo()){
                if(this->temJogadasMemoria()){
                    this->setQuemTajogandoJogador(false);
                    this->setQuemTaJogandoComputador(true);
                    this->computadorAcoes(simboloPC,tabuleiro);
                    tabuleiro->mostrarTabuleiro();
                }else{
                    this->setGanhadorEmpate(true);
                    break;
                }
            }
        } while (!this->verificaFimDeJogo());//Verificar fim de jogo
        //cout << "96:quem ganhou:" << this->getGanhadorComputador() << " " << this->getGanhadorJogador() << " " << this->getGanhadorEmpate() << endl;

        this->mensagemFim();
        this->menuPlacar();

         do
        {
            cout << endl <<"                            Digite a opcao desejada(y/n): ";
            cin >> jogar;
           
        } while (jogar != 'y' and jogar != 'Y' and jogar != 'n' and jogar != 'N');


    } while (jogar == 'y' or jogar == 'Y');
    

}


bool Jogo::verificaFimDeJogo(void){
    int linhaX = 0,linhaO = 0;
    int colunaX = 0, colunaO = 0;
    int diagonalPrincipalX = 0, diagonalPrincipalO = 0;
    int diagonalReversaX = 0, diagonalReversaO = 0;
    int count = 0 ;

    for(int i; i < 9; i++){
        if(this->memoria.at(i) == "invalido"){
            count++;
        }
    }
    if(count == 9){
        this->setGanhadorEmpate(true);//Empate recebe que ganhou
        return true; //Acabou
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
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
            if(this->getQuemTajogandoJogador()){
                this->setGanhadorJogador(true);
            }else if(this->getQuemTaJogandoComputador()){
                this->setGanhadorComputador(true);
            }
            return true;
        }else if(linhaO == 3){
            if(this->getQuemTajogandoJogador()){
                this->setGanhadorJogador(true);
            }else if(this->getQuemTaJogandoComputador()){
                this->setGanhadorComputador(true);
            }
            return true;
        }
        linhaX = 0;
        linhaO = 0;

        //Verificando flags colunas
        if(colunaX == 3){
            if(this->getQuemTajogandoJogador()){
                this->setGanhadorJogador(true);
            }else if(this->getQuemTaJogandoComputador()){
                this->setGanhadorComputador(true);
            }
            return true;
        }else if(colunaO== 3){
            return true;
        }
        colunaX = 0;
        colunaO = 0;

        //verificando flags diagonal
        if(diagonalPrincipalX == 3){
            if(this->getQuemTajogandoJogador()){
                this->setGanhadorJogador(true);
            }else if(this->getQuemTaJogandoComputador()){
                this->setGanhadorComputador(true);
            }
            return true;
        }else if(diagonalPrincipalO == 3){
            if(this->getQuemTajogandoJogador()){
                this->setGanhadorJogador(true);
            }else if(this->getQuemTaJogandoComputador()){
                this->setGanhadorComputador(true);
            }
            return true;
        }

        //Verificando flags diagonal reversa
        if(diagonalReversaX == 3){
            if(this->getQuemTajogandoJogador()){
                this->setGanhadorJogador(true);
            }else if(this->getQuemTaJogandoComputador()){
                this->setGanhadorComputador(true);
            }
            return true;
        }else if(diagonalReversaO == 3){
            if(this->getQuemTajogandoJogador()){
                this->setGanhadorJogador(true);
            }else if(this->getQuemTaJogandoComputador()){
                this->setGanhadorComputador(true);
            }
            return true;
        }
    }
    return false;
}

Jogo::~Jogo(void){

}

void Jogo::computadorAcoes(char simboloPC, Tabuleiro *tabuleiro){
    unsigned seed = time(0); //A cada segundo o retorno do time é diferente deixando aleatorio  o sorteio
    srand(seed);;//Definindo a semente para iniciar
    int posicao;
    do
    {
        posicao = rand() % 9;
    } while (!this->verificaPosicao(posicao,simboloPC));
    tabuleiro->marcar(posicao,simboloPC);
}

bool Jogo::temJogadasMemoria(void){
    int count  = 9;
    for (int i = 0; i < 9; i++)
    {
        if(this->memoria.at(i) == "valido")
            count--;
    }
    if(count == 0)
        return false;
    else
        true;
}

bool Jogo::verificaPosicao(int posicao, char simbolo){
    if(posicao > 0 and posicao < 10){
        if(this->memoria[posicao-1] == "valido"){
            this->memoria.at(posicao-1) = "invalido";

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

            return true;
        }
    }
    return false;
}

//DECIDE QUEM GANHOU E MODIFICA OS VALORES 
void Jogo::mensagemFim(void){
    if(this->getGanhadorJogador()){
        this->setNumeroDevitoriaComputador();
        this->setGanhadorJogador(false);
        cout << endl << endl;
        cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
        cout << "                                     x               PARABENS                x          " << endl;
        cout << "                                     x         VOCE VENCEU O JOGO!!!         x          " << endl;
        cout << "                                     x                                       x          " << endl;
        cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
        cout << endl << endl;

    }else if(this->getGanhadorComputador()){
        this->setNumeroDevitoriaComputador();
        this->setGanhadorComputador(false);
        cout << endl << endl;
        cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
        cout << "                                     x             VOCE PERDEU               x          " << endl;
        cout << "                                     x         SE TENTE NOVAMENTE!!!         x          " << endl;
        cout << "                                     x                                       x          " << endl;
        cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
        cout << endl << endl;
        
    }else if(this->getGanhadorEmpate()){
        this->setNumeroDeEmpate();
        this->setGanhadorEmpate(false);
        cout << endl << endl;
        cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
        cout << "                                     x               EMPATE                  x          " << endl;
        cout << "                                     x         SE TENTE NOVAMENTE!!!         x          " << endl;
        cout << "                                     x                                       x          " << endl;
        cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
        cout << endl << endl;

    }

    cout << endl << endl;
    cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
    cout << "                                     x       DESEJA JOGAR NOVAMENTE?         x          " << endl;
    cout << "                                     x         Y(SIM)   OR   N(NAO)          x          " << endl;
    cout << "                                     x                  ?                    x          " << endl;
    cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
    cout << endl << endl;
}

//MENUS
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
    cout << "                                     x Pontuacao Jogador   :    "<< this->getNumeroDeVitoriaJogador() <<"            x          " << endl;
    cout << "                                     x Pontuacao Computador:    "<< this->getNumeroDevitoriaComputador() <<"            x          " << endl;
    cout << "                                     x EMAPTE(S)           :    "<< this->getNumeroDeEmpate()<<"            x          " << endl;
    cout << "                                     x Total de partidas   :    "<< this->getNumeroDeVitoriaJogador() + this->getNumeroDevitoriaComputador() + this->getNumeroDeEmpate()<<"            x          " << endl;
    cout << "                                     x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x 0 x          " << endl;
    cout << endl << endl;
}

/*gets e sets*/
void Jogo::setNumeroDeVitoriaJogador(void){
    this->numeroDeVitoriaJogador++;
}
int Jogo::getNumeroDeVitoriaJogador(void){
    return  this->numeroDeVitoriaJogador;
}

void Jogo::setNumeroDevitoriaComputador(void){
     this->numeroDevitoriaComputador++;
}
int Jogo::getNumeroDevitoriaComputador(void){
    return this->numeroDevitoriaComputador;
}

void Jogo::setNumeroDeEmpate(void){
    this->numeroDeEmpate++;
}
int Jogo::getNumeroDeEmpate(void){
    return this->numeroDeEmpate;
}


//Controladores de ganhandor
void Jogo::setGanhadorJogador(bool boleano){
    this->ganhadorJogador = boleano;
}
bool Jogo::getGanhadorJogador(void){
    return this->ganhadorJogador;
}

void Jogo::setGanhadorComputador(bool boleano){
    this->ganhadorComputador = boleano;
}
bool Jogo::getGanhadorComputador(void){
    return this->ganhadorComputador;
}


void Jogo::setGanhadorEmpate(bool boleano){
    this->ganhadorEmpate = boleano;
}
bool Jogo::getGanhadorEmpate(void){
    return this->ganhadorEmpate;
}

//Controle de quem ta jogando
void Jogo::setQuemTajogandoJogador(bool boleano){
    this->quemTajogandoJogador = boleano;
}
bool Jogo::getQuemTajogandoJogador(void){
    return this->quemTajogandoJogador;
}

void Jogo::setQuemTaJogandoComputador(bool boleano){
    this->quemTaJogandoComputador = boleano;
}
bool Jogo::getQuemTaJogandoComputador(void){
    return this->quemTaJogandoComputador;
}