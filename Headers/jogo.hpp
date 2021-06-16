class Jogo{
    private:
        int vitoriaJogador;
        int vitoriaComputador;
        bool rodada;
    public:
        Jogo(void); //Construtor
        ~Jogo(void); //Destrutor
        void cabecalho(void);
        void menuJogo(void);
        void menuRodadas(void);
        int getVitoriaJogador(void);
        int getVitoriaComputador(void);
        bool getRodada(void);
        void setRodada(void);
        void setVitoriaJogador(void);
        void setVitoriaComputador(void);
        void placar(void);
};