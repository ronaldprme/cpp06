Implemente uma classe Base que tenha apenas um destrutor virtual público. Crie três classes vazias A, B e C, que herdam publicamente de Base.
Essas quatro classes não precisam ser projetadas na Forma Canônica Ortodoxa.
Implemente as seguintes funções:
Base * generate(void);
Ela instancia aleatoriamente A, B ou C e retorna a instância como um ponteiro Base. Sinta-se à vontade para usar o que quiser para a implementação de escolha aleatória.
void identify(Base* p);
Ela imprime o tipo real do objeto apontado por p: "A", "B" ou "C".
void identify(Base& p);
Ela imprime o tipo real do objeto apontado por p: "A", "B" ou "C". Usar um ponteiro dentro desta função é proibido.
Incluir o cabeçalho typeinfo é proibido.
Escreva um programa para testar se tudo funciona conforme o esperado.