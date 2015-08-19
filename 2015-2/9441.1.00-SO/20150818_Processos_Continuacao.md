Processos (Continuação)
===

Prof. João Caram - [Slides](http://webdav.sistemas.pucminas.br:8080/webdav/sistemas/sga/20152/954543_SO_Aula3_Processos_Conceitos.pdf)

- Bloco de controle do processo
	- Representação lógica do processo
	- Contém informações sobre todos os registradores importantes para o processo
	    - PC
	    - Acumuladores
	    - Ponteiro da pilha
	    - Base e limite da memória

	- Essa mudança de estado e salvamento de informações é conhecida como troca de contexto
	- Grau de programação alto: uso intensivo de CPU

- Modelo de multiprogramação

	- p: porcentagem do tempo em espera
	- n: número de processos no sistema
	- p^n: probabilidade de todos os processos estarem em espera
	- uso de cpu: 1-p^n
	- grau de multiprogramação (?)