class Jogo{
    private:
        int vitoriaJogador;
        int vitoriaComputador;
        bool jogador;
        bool computador;
        bool rodada;
        vector<string> memoria;
        vector<vector<char>> memoriaTabuleiro;
    public:
        Jogo(void); //Construtor
        ~Jogo(void); //Destrutor
        void cabecalho(void);
        void menuJogo(void);
        void menuPlacar(void);
        int getVitoriaJogador(void);
        int getVitoriaComputador(void);
        bool getRodada(void);
        void setRodada(void);
        bool getJogador(void);
        void setJogador(void);
        bool getComputador(void);
        void setComputador(void);
        void setVitoriaJogador(void);
        void setVitoriaComputador(void);
        bool verificaPosicao(int,char);
        bool verificaFimDeJogo(char);
        void mensagemFim(void);
};