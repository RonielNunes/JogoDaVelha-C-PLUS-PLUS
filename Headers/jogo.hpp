class Jogo{
    private:
        //Contadores
        int numeroDeVitoriaJogador;
        int numeroDevitoriaComputador;
        int numeroDeEmpate;
        //Controladores de ganhandor
        bool ganhadorJogador;
        bool ganhadorComputador;
        bool ganhadorEmpate;

        //Controle de quem ta jogando
        bool quemTajogandoJogador;
        bool quemTaJogandoComputador;

        vector<string> memoria;
        vector<vector<char>> memoriaTabuleiro;
    public:
        Jogo(void); //Construtor
        ~Jogo(void); //Destrutor

        /*gets e senters*/
        
        //Contadores
        void setNumeroDeVitoriaJogador(void); //Soma mais 1
        int getNumeroDeVitoriaJogador(void); //Retorna o valor

        void setNumeroDevitoriaComputador(void);
        int getNumeroDevitoriaComputador(void);

        void setNumeroDeEmpate(void);
        int getNumeroDeEmpate(void);


        //Controladores de ganhandor
        void setGanhadorJogador(bool);
        bool getGanhadorJogador(void);


        void setGanhadorComputador(bool);
        bool getGanhadorComputador(void);
        

        void setGanhadorEmpate(bool);
        bool getGanhadorEmpate(void);

        //Controle de quem ta jogando
        void setQuemTajogandoJogador(bool);
        bool getQuemTajogandoJogador(void);

        void setQuemTaJogandoComputador(bool);
        bool getQuemTaJogandoComputador(void);

        /* fim get e sets*/



        void cabecalho(void);
        void menuJogo(void);
        void menuPlacar(void);
        bool verificaPosicao(int,char);
        bool verificaFimDeJogo(void);
        void mensagemFim(void);
        void computadorAcoes(char,Tabuleiro *);
        bool temJogadasMemoria(void);
};