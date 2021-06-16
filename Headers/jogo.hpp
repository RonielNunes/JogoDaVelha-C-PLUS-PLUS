class Jogo{
    private:
        int vitoriaJogador;
        int vitoriaComputador;
        bool rodada;
        vector<bool> memoria;
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
        void setVitoriaJogador(void);
        void setVitoriaComputador(void);
        bool verificaPosicao(int);
};