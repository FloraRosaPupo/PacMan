# PacMan — Vanellope

## Descrição

Jogo acadêmico em C++ inspirado em PacMan, com renderização em Allegro 5, movimentação no tabuleiro, inimigos, colisões e coleta de pontos. A execução gráfica depende das bibliotecas e dos recursos do jogo.

## Stack e bibliotecas

C++17, Allegro 5 e projeto Visual Studio.

## Funcionalidades

- Movimento do jogador.
- Inimigos e colisões.
- Pontuação por coleta.

## Licença

Não há uma licença de distribuição definida para este repositório. Nenhuma licença MIT, Apache ou equivalente é concedida por este README. As atribuições e os direitos dos materiais de terceiros permanecem preservados.

## Validação e limites

Regras de movimento, limites e retorno em beco sem saída. Compilação e gameplay completos exigem Visual Studio/Allegro e assets.

## Executar
Abra `ProjetoFlosa.vcxproj` no Visual Studio com ferramentas de C++ e restaure as dependências indicadas em `packages.config`. A configuração original utiliza Allegro e seus addons de imagem, fontes, áudio e diálogos.

Execute com a raiz do repositório como diretório de trabalho: as imagens e `vanellope.ttf` são carregadas por caminhos relativos. Use as setas para movimentar e Escape para sair.

## Organização e validação
As classes `Vanellope`, `Viloes`, `Tijolo` e `Pirula` representam os objetos do jogo. `Main.cpp` e `Origem.cpp` são versões históricas do ponto de entrada; siga os arquivos habilitados no projeto Visual Studio, sem compilar ambos os pontos de entrada juntos.

Foi corrigido um acesso ao quarto elemento de um array com três inimigos. A compilação e a execução gráfica dependem de Visual Studio/Allegro; não há suíte automatizada de gameplay nesta versão.

## Organização e manutenção

Classes de entidades e renderização foram preservadas. A escolha de direção dos inimigos saiu para `domain/movement.h`, independente de Allegro e com aleatoriedade recebida como entrada. Evita loop infinito em beco sem saída e acesso fora dos limites.

Veja [a revisão de desenvolvimento](docs/REVISAO.md) para decisões, testes e limites, e [o guia de contribuição](CONTRIBUTING.md) para o fluxo de manutenção.
