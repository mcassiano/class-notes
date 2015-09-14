Escalonamento
===

Prof. João Caram - [Slides](http://webdav.sistemas.pucminas.br:8080/webdav/sistemas/sga/20152/954550_SO_Aula4_EscalonamentoProcessos.pdf)

- Escalonador
	- Só escolhe um processo para executar os que estiverem marcados como pronto
	- Algoritmo (regra) para para escolher a ordem dos processos
	- Escalonamento preemptivo
		- Tempo máximo fixado
		- Se estiver rodando ao final do tempo, é suspenso
		- Escalonador escolhe outro processo (se houver disponível)
		- Precisa de interrupções do relógio
    	- *Processo em bloqueio e passa para pronto*
    	- *Processo em execução e volta para pronto*
    	
	- Escalonamento não preemptivo
		- Deixa executar até que ele seja bloqueado
			- Requer I/O
		- Ou até que voluntariamente libere CPU (é encerrado)

- Ambientes
	- Lote
		- Não existem usuários esperando
		- Tarefas em lote
	- Interativo
		- Algoritmos preemptivos são essenciais
		- Uma falha em um programa pode impedir que outros sejam executados
		- Caso de servidores
	- Tempo real
		- Algoritmos preemptivos geralmente desnecessários
		- Processos sabem que não podem executar por longos períodos
		- Executam programas que visam o progresso da aplicação

- Objetivos
	- Todos os sistemas
   		- **Justiça**
       		- Dar fração justa da CPU a cada processo
   		- **Política**
       		- Sistema deve cumprir regras estabelecidas
   		- **Equilíbrio**
       		- Todas as partes do sistema devem ser ocupadas
    - Sistemas em lote
    
    	- **Vazão**
       		- Maximizar número de tarefas
       		- Exemplo: Pagar muitos boletos no caixa eletrônico enquanto pessoas aguardam para sacar dinheiro ou consultar saldo
    	
    	- **Tempo de retorno**
    		- Minimizar tempo entre submissão e término
    		
    	- **Utilização de CPU**
    		- Manter CPU sempre ocupada
    		
    - Sistemas interativos
    	- **Proporcionalidade**
        	- Tempo de atendimento x expectativa do usuário
        - **Tempo de resposta**
        	- Responder rapidamente às requisições
    
    - Sitemas de tempo real
	    - **Cumprimento de prazos**
    	- **Previsibilidade**
    	
    	
- Escalonamento em Sistemas em Lote
	- *First Come, First Served*
		- Mais simples
		- Ordem de chegada
		- Fila única de processos prontos
		- Algoritmo Justo
	- *Shortest job first*
		- Tarefa com tempo de execução menor, primeiro
		- Bom em situações em que as tarefas estejam disponíveis simultaneamente
	- *Shortest remaining time next*
		- Sempre escolhe o processo com menor tempo de execução restante
		- Tempo de execução deve ser previamente conhecido
		- Novas tarefas (mais curtas) tenham bom desempenho

- Escalonamento em Sistemas Interativos
	- *Round-robin*
		- Chaveamento circular
		- Cada processo tem um intervalo de tempo (*quantum*) que é permitido executar
		- Quando um processo consome todo o seu *quantum*, ele é colocado no final da lista
		- Quantum muito alto: resposta pobre a requisições mais curtas
		- Quantum muito baixo: muitos chaveamentos de CPU, reduzindo eficiência
	
	- *Escalonamento por prioridades*
		- Decisão de escalonamento depende de fatores externos
		- A cada processo é atribuída uma prioridade
			- É permitido executar o processo com prioridade mais alta
		- Maneiras de evitar que um processo com alta prioridade execute indefinidamente
			- Reduzir a prioridade a cada ciclo de clock
			- Atribuir quantum máximo
		- Comando *nice* permite ajustar prioridade
	- *Escalonamento garantido*
		- Taxa de proporcionalidade
			- Se existem *n* processos, cada um deve ter *1/n* ciclos de CPU
	- *Loteria*
		- *n* bilhetes
		- Processos mais importantes: mais bilhetes
		- Responsividade
		- É possível troca de bilhetes por cooperação
			- *Client* pode dar seus bilhetes ao *Server*
	- *Fração justa*
		- CPU é alocada por usuário
		- Justo

	