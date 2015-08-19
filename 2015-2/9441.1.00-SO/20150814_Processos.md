Arquiteturas de SO (Continuação)
===

Prof. João Caram - [Slides](http://webdav.sistemas.pucminas.br:8080/webdav/sistemas/sga/20152/954543_SO_Aula3_Processos_Conceitos.pdf)

- Processo
	- É o programa em execução
		- Está sendo gerenciado pelo SO
		- Programa pode não estar em execução
	- Estrutura
		- Código
		- Dados
		- Pilha
		
![Estrutura de um processo na memória](http://www.read.cs.ucla.edu/111/_media/2006spring/notes/scribe-note2.jpg)

- Multiprogramação
	- Controle simultâneo de tarefas (jobs)
		- Por bloqueio
			- Gravar em disco (não precisa do processador)
		- Por Prioridade
			- Tempo de execução
		- Retomada
		
- Estados de um processo
	- Novo, Pronto, Executando, Bloqueio/Espera
		- Diagrama nos slides (página _)