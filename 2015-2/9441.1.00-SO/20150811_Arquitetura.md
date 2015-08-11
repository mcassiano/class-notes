Arquiteturas de SO
===

Prof. João Caram - [Slides](http://webdav.sistemas.pucminas.br:8080/webdav/sistemas/sga/20152/948102_SO_Aula2_ArquiteturaDeSO20152.pdf)

- Estrutura Interna
	- Núcleo (Kernel)
		- Funções básicas
	- Chamadas de sistema
		- Usadas para executar funções do Kernel
	- Usuários
		- Usuário
		- Supervisor


- Sistemas Monolíticos 
	- *Software* que roda praticamente todo em modo supervisor
	- Todos os métodos públicos e em apenas uma camada
	- Arquitetura simples
	- Desvantagens
		- Manutenção
		- Difícil entendimento

- Sistema em Camadas
	- Hierárquico
	- Abstração em níveis mais altos
	- Chamadas de sistemas são encapsuladas em diferentes camadas do sistema
		- Exemplo: chamadas de sistema de *I/O* só são recebidas da camada de *I/O Management*.
	- Problemas
		- Latência
		- Trechos que podem estar entre fronteiras de camadas