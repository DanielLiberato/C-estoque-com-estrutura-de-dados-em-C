# C - estoque com estrutura de dados em C
Trabalho da faculdade criando um programa de Controle de estoque de caixas de chuchus em C; Foi usado estrutura de dados pilha (LIFO) e estrutura de dados fila (FIFO)
# Introdução
Na longa estrada da BR 174, Mitski é uma fazendeira pacata que vive da venda de seus chuchus em caixotes,
que ela cuida ativamente na sua pequena fazenda à beira da estrada. Neste contexto, Mitski segue sua
saga para vender ao máximo seus caixotes sem ter muita perda de chuchus (pela demora de venderem e
estragarem) e vendendo com o máximo de qualidade. Afinal, servir bem para servir sempre.

No entanto, Mitski anda descontente com seus ajudantes, pois seus caixotes têm apresentado chuchus
estragados em algumas unidades, o que ajuda os clientes a não sentirem mais vontade de retornar para
comprar mais chuchus. Os ajudantes informaram que isso ocorre pelo fato de que as remessas estão enormes,
não havendo mais como manter um controle de qualidade sem a ajuda de ferramentas computacionais.
A ajudante Olívia Rogéria, braço direito de Mitski, comentou que há um(a) grande especialista no
desenvolvimento de ferramentas computacionais, e que poderia resolver esta situação. Aliás, um(a) não, mas
dois/duas especialistas. E claro que ela está falando de você(s) :)! Mitski amou a ideia, e lhe enviou os
detalhes do problema a ser resolvido. Vamos lá, não decepcione nossa amável fazendeira.

# Detalhes do Problema
O objetivo neste trabalho é exercitar e praticar os conceitos relacionados à construção de algoritmos e
estruturas de dados. O problema principal segue a premissa: Mitski deseja saber e controlar os caixotes de
chuchu que compõem o seu estoque para venda. Para tal, ela necessita de um sistema computacional que as
organize em 3 estruturas, listadas a seguir:

- Preparação para a venda: antes da venda, os caixotes são posicionados de acordo com sua aptidão
para a venda. Só que tem uma peculiaridade, Mitski é superticiosa e organiza os caixotes que chegam
na ordem inversa. Ou seja, o primeiro caixote que ele informará para o sistema é o menos apto para
a venda, assim, deve ser o último, de fato, a ser vendido. Da mesma maneira, o último caixote
informado no sistema será o primeiro a ser vendido.

- Venda: Mitski necessita de um controle para os caixotes que estão na fila para a venda. Dado o
comando de venda, a caixa selecionada deve ser a mais apta para a venda que está aguardando,
baseado na posição armazenada na estrutura de preparação para a venda.

- Caixa avariada: Como em todo processo de venda em ambiente de feira, algumas caixas podem ter
alguma avaria, isto é, alguns dos chuchus em uma caixa podem estar batidas ou estragadas. Uma vez
que seja reportado que uma caixa possui uma avaria, ela deve ser removida da estrutura de preparação
para a venda, e ser incluída na estrutura de caixas avariadas. Uma vez avariada, os outros ajudantes de
Mitski irão remover os chuchus avariados da caixa e adicionar novos chuchus, mitigando o processo
de perda de chuchus. É importante frisar que, dadas duas caixas, caixa1 e caixa2, se a caixa1 foi
avariada antes da caixa2, então a caixa1 será consertada antes da caixa2. Ou seja: as caixas
avariadas primeiro, são consertadas primeiro! Uma vez que a equipe de manutenção dos caixotes avisa
que uma caixa foi corrigida, a caixa passa a aguardar a ordem de Mitski para entrar novamente na
estrutura de venda, tendo preferência sobre todas as outras que já estão aguardando venda.

# Entrada e Saída
Neste trabalho, a entrada será a padrão do sistema (stdin ou pela linha de comando). A saída também será
a padrão do sistema (stdout). A primeira linha da entrada é composta por um valor inteiro N (0 < N ≤
5000), que indica o total de caixas geradas na fazendinha da Mitski. A seguir, haverão N linhas compostas
por números inteiros, que representam o identificador de cada caixa. Após, a entrada é composta por várias
linhas, cada qual contendo um inteiro I, que indica a ação a ser realizada no sistema computacional, cujos
significados são descritos a seguir:


  - 0: indica que Mitski deseja enviar a caixa mais apta para a venda. Ao ser enviada, a mensagem ”caixa
  K enviada para a venda” deve ser impressa na saída, na qual K é o identificador da caixa;
  - X, tal que X é um identificar de caixa: indica que a caixa de identificador X, que estava a venda,
  foi avariada. Ao ser avariada, a mensagem ”caixa K avariada” deve ser impressa na saída, na qual K é
  o identificador da caixa;

  - -1: indica que a equipe de manutenção informou que uma caixa foi avariada. Lembre-se que a caixa
  corrigida é sempre com a maior prioridade, aquela que chegou primeiro avariada. Ao ser consertada, a
  mensagem ”caixa K consertada” deve ser impressa na saída. Lembre-se que a caixa corrigida deve ser
  levada novamente para a estrutura de preparação para a venda, tendo preferência sobre as que já estão
  lá;

  - -2: indica que Mitski deseja obter uma impressão de todas as caixas aguardando para serem vendidas,
  da mais apta para a menos apta. Cada caixote vendido deve ser impresso em uma linha. A impressão
  deve ocorrer da caixa mais para aquela menos apta;

  - -3: indica que Mitski deseja obter uma impressão do identificador de todas as caixas avariadas e que
  estão aguardando para serem corrigidas. Cada caixote avariado deve ser impresso em uma linha. A
  impressão deve ocorrer da caixa com mais prioridade para ser corrigida até a com menos prioridade.
  O final da entrada é indicado pelo EOF (CTRL + D no terminal em geral).

# Informações Adicionais
Para este trabalho, assuma que todo o sistema é coeso e que nenhuma entrada absurda é passada como
entrada, e os seguintes itens são verdades absolutas:
- Todas as caixas possuem identificadores distintos;
- Não haverá um identificador cuja valor seja o mesmo de uma instrução reservada do sistema (0, -1, -2,
-3);
- Não haverá um comando de caixa avariada com identificador X, tal que X não esteja apta para a
venda;
- Não haverá comandos de caixas para entrarem em venda, caso não haja caixas aguardando para serem
vendidas;
- Não haverá comandos para corrigir caixas, caso não existam caixas avariadas;
- Mitski não pedirá impressão de caixas aguardando para serem vendidas caso não haja caixas aguardando
para serem vendidas;
- Mitski não pedirá impressão de caixas avariadas caso não haja caixas avariadas;


# Projeto concluido funcionando
<img src="https://user-images.githubusercontent.com/81873713/170041372-a5ca23e1-a0d2-4b87-b12d-025b8e265a7c.gif">
