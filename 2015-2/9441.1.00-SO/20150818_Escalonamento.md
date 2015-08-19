Processos (Continuação)
===

Prof. João Caram - [Slides](http://webdav.sistemas.pucminas.br:8080/webdav/sistemas/sga/20152/954550_SO_Aula4_EscalonamentoProcessos.pdf)

- Escalonador
	- Só escolhe um processo para executar os que estiverem marcados como pronto
	- Algoritmo (regra) para para escolher a ordem dos processos
	- Decide
    	- Acabou o tempo
   		- Próximo processo
	- Objetivos
    	- Justiça
        	- Dar fração justa da CPU a cada processo
    	- Política
        	- Sistema deve cumprir regras estabelecidas
    	- Equilíbrio
        	- Todas as partes do sistema devem ser ocupadas
    	- Vazão (throughput)
        	- Usuários satisfeitos
        	- Exemplo: 1 cliente do banco com muitas ordens de pagamento mas vários que desejam apenas mudar a senha do cartão
    	- Tempo de resposta
    	- Proporcionalidade
        	- Tempo de atendimento x expectativa do usuário
	    - Cumprimento de prazos
    	- Previsibilidade

- Quando escalonar
	- Escalonamento preemptivo
    	- Processo em bloqueio e passa para pronto
    	- Processo em execução e volta para pronto
	- Escalonamento não preemptivo
    	- Processo pede para ser encerrado