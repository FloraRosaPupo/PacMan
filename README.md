# PacMan — Vanellope

Jogo acadêmico em C++ com Allegro 5, movimentação em labirinto, coleta de itens e inimigos.

## Executar
Abra `ProjetoFlosa.vcxproj` no Visual Studio com ferramentas de C++ e restaure as dependências indicadas em `packages.config`. A configuração original utiliza Allegro e seus addons de imagem, fontes, áudio e diálogos.

Execute com a raiz do repositório como diretório de trabalho: as imagens e `vanellope.ttf` são carregadas por caminhos relativos. Use as setas para movimentar e Escape para sair.

## Organização e validação
As classes `Vanellope`, `Viloes`, `Tijolo` e `Pirula` representam os objetos do jogo. `Main.cpp` e `Origem.cpp` são versões históricas do ponto de entrada; siga os arquivos habilitados no projeto Visual Studio, sem compilar ambos os pontos de entrada juntos.

Foi corrigido um acesso ao quarto elemento de um array com três inimigos. A compilação e a execução gráfica dependem de Visual Studio/Allegro; não há suíte automatizada de gameplay nesta versão.

## Licença
Não há licença de distribuição definida. Os recursos gráficos e sonoros também precisam ter seus direitos de uso verificados antes de redistribuição.


## Stack e bibliotecas

C++17, Allegro 5 e projeto Visual Studio.


## Funcionalidades

- Movimento do jogador.
- inimigos e colisões.
- pontuação por coleta.


## Organização e manutenção

Classes de entidades e renderização foram preservadas. A escolha de direção dos inimigos saiu para `domain/movement.h`, independente de Allegro e com aleatoriedade recebida como entrada. Evita loop infinito em beco sem saída e acesso fora dos limites.

Veja [a revisão de desenvolvimento](docs/REVISAO.md) para decisões, testes e limites, e [o guia de contribuição](CONTRIBUTING.md) para o fluxo de manutenção.
