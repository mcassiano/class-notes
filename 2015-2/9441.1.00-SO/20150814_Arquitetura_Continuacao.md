Arquiteturas de SO (Continuação)
===

Prof. João Caram - [Slides](http://webdav.sistemas.pucminas.br:8080/webdav/sistemas/sga/20152/948102_SO_Aula2_ArquiteturaDeSO20152.pdf)

- Microkernel
	- Kernel básico (menor possível)
	- Divisão em pequenos módulos funcionais

- Cliente/Servidor
	- Comunicação por meio de mensagens
	- Problemas de sincronização
		- Processos que pedem os mesmos recursos ao mesmo tempo

- Máquinas Virtuais
	- Cópia em software mais próxima possível do hardware que deseja-se *emular/(simular?)*
	- Ignoradas por épocas
	- Surgimento da JVM
	- Emulação de sistemas
	- Isolar servidores e falhas