#include "../Headers/tabuleiro.hpp"
#include "../Headers/system.hpp"

//Construtor
Tabuleiro::Tabuleiro(void){
    this->tamanho = 5;
    vector<vector<string>> aux(5,vector<string>(5));
    this->matriz = aux;
    
}

//Destrutor
Tabuleiro::~Tabuleiro(void){

}

bool Tabuleiro::marcar(int numero, char simbolo){
    if(simbolo == 'x'){
        if(numero == 1){
            this->matriz[0][0] = " x "; 
        }else if(numero == 2){
            this->matriz[0][2] = " x "; 
        }else if(numero == 3){
            this->matriz[0][4] = " x "; 
        }else if(numero == 4){
            this->matriz[2][0] = " x "; 
        }else if(numero == 5){
            this->matriz[2][2] = " x "; 
        }else if(numero== 6){
            this->matriz[2][4] = " x "; 
        }else if(numero == 7){
            this->matriz[4][0] = " x "; 
        }else if(numero == 8){
            this->matriz[4][2] = " x "; 
        }else if(numero == 9){
            this->matriz[4][4] = " x "; 
        }
    }else{
        if(numero == 1){
            this->matriz[0][0] = " o "; 
        }else if(numero == 2){
            this->matriz[0][2] = " o "; 
        }else if(numero == 3){
            this->matriz[0][4] = " o "; 
        }else if(numero == 4){
            this->matriz[2][0] = " o "; 
        }else if(numero == 5){
            this->matriz[2][2] = " o "; 
        }else if(numero== 6){
            this->matriz[2][4] = " o "; 
        }else if(numero == 7){
            this->matriz[4][0] = " o "; 
        }else if(numero == 8){
            this->matriz[4][2] = " o "; 
        }else if(numero == 9){
            this->matriz[4][4] = " o "; 
        }
    }
    return true;
}

void Tabuleiro::inicializarTabuleiro(void){
    int flag = 1;
    for (int i = 0; i < this->tamanho; i++)
    {
        for (int j = 0; j < this->tamanho; j++)
        {
                if( j == 1)
                    this->matriz[i][j] = " | ";
                else if(j == 3)
                    this->matriz[i][j] = " | ";
                else if(i == 1)
                    this->matriz[i][j] = " - ";
                else if(i == 3)
                    this->matriz[i][j] = " - ";
                else{//this->matriz[i][j] = " x ";
                    if(flag == 1){
                        this->matriz[i][j] = " 1 "; 
                        flag++;
                    }else if(flag == 2){
                        this->matriz[i][j] = " 2 "; 
                        flag++;
                    }else if(flag == 3){
                        this->matriz[i][j] = " 3 "; 
                        flag++;
                    }else if(flag == 4){
                        this->matriz[i][j] = " 4 "; 
                        flag++;
                    }else if(flag == 5){
                        this->matriz[i][j] = " 5 "; 
                        flag++;
                    }else if(flag == 6){
                        this->matriz[i][j] = " 6 "; 
                        flag++;
                    }else if(flag == 7){
                        this->matriz[i][j] = " 7 "; 
                        flag++;
                    }else if(flag == 8){
                        this->matriz[i][j] = " 8 "; 
                        flag++;
                    }else if(flag == 9){
                        this->matriz[i][j] = " 9 "; 
                        flag++;
                    }
                }
                    
        }
    }
}

void Tabuleiro::mostrarTabuleiro(void){

    if(sistema == 0){
        for (int i = 0; i < this->tamanho; i++)
        {
            for (int j = 0; j < this->tamanho; j++)
            {
                cout << this->matriz[i][j];
            }
            cout << endl;
        }
    }else{
        cout << endl << endl;
        for (int i = 0; i < this->tamanho; i++)
        {
            cout << "                                                   ";
            for (int j = 0; j < this->tamanho; j++)
            {
                if( j == 1){
                    textcolor(0, 15); /*primeiro cor letra, segundo cor fundo */
                    cout << "   ";
                    textcolor(15, 0); /*primeiro cor letra, segundo cor fundo */
                }else if(j == 3){
                    textcolor(0, 15); /*primeiro cor letra, segundo cor fundo */
                    cout << "   ";
                    textcolor(15, 0); /*primeiro cor letra, segundo cor fundo */
                }else if(i == 1){
                    textcolor(0, 15); /*primeiro cor letra, segundo cor fundo */
                    cout << "   ";
                    textcolor(15, 0); /*primeiro cor letra, segundo cor fundo */
                }else if(i == 3){
                    textcolor(0, 15); /*primeiro cor letra, segundo cor fundo */
                    cout << "   ";
                    textcolor(15, 0); /*primeiro cor letra, segundo cor fundo */
                }else{
                    cout << this->matriz[i][j];
                }
                
            }
            cout << endl;
        }
    }
    cout << endl;
}