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
