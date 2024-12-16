# Cartório da EBAC

Este é um programa de terminal desenvolvido em C para gerenciar registros de usuários em um sistema de cartório. Ele permite registrar, consultar e deletar informações de usuários, tudo de forma segura e eficiente. O programa utiliza arquivos para armazenar os dados de forma persistente.

## Funcionalidades

1. **Registrar Usuários**:
   - Permite adicionar informações como CPF, nome, sobrenome e cargo.
   - Verifica se o CPF já está registrado antes de criar um novo registro.

2. **Consultar Usuários**:
   - Permite buscar e exibir informações de um usuário baseado no CPF.

3. **Deletar Usuários**:
   - Remove um registro de usuário utilizando o CPF.

4. **Sistema de Login de Administrador**:
   - Apenas administradores podem acessar o menu principal, sendo necessário informar a senha `admin`.

## Requisitos

- Compilador C compatível com a biblioteca padrão (`gcc`, por exemplo).
- Sistema operacional com suporte a comandos de terminal.
- Configuração de idioma ajustada para o uso de `setlocale` (Portuguese).

## Como Usar

1. **Compilar o programa**:
   - Use o seguinte comando no terminal:
     ```bash
     gcc -o cartorio cartorio.c
     ```

2. **Executar o programa**:
   - Após a compilação, execute:
     ```bash
     ./cartorio
     ```

3. **Login de Administrador**:
   - Insira a senha `admin` para acessar as funcionalidades.

4. **Navegação no Menu**:
   - Escolha uma das opções apresentadas no menu principal:
     - `[1]` Registrar nomes
     - `[2]` Consultar nomes
     - `[3]` Apagar nomes
     - `[4]` Sair do menu

## Estrutura do Código

### Bibliotecas Utilizadas

- `stdio.h`: Entrada e saída padrão.
- `stdlib.h`: Utilitário para manipulação de sistema.
- `locale.h`: Configuração de localização e idioma.
- `string.h`: Manipulação de strings.

### Principais Funções

- `registro()`: Registra um novo usuário em um arquivo nomeado pelo CPF.
- `consulta()`: Exibe as informações de um usuário com base no CPF.
- `deletar()`: Remove o arquivo correspondente ao CPF do usuário.
- `main()`: Gerencia o fluxo do programa e o menu principal.

## Observações

- **Persistência de Dados**:
  - Cada registro é armazenado em um arquivo separado, nomeado com o CPF do usuário.
  
- **Erros Comuns**:
  - CPF não encontrado: Certifique-se de que o CPF está cadastrado antes de consultar ou deletar.
  - Senha incorreta: O programa encerrará se a senha `admin` não for digitada corretamente.

- **Melhorias Futuras**:
  - Implementação de criptografia para armazenar os dados.
  - Adicionar suporte a múltiplos administradores.
  - Criar logs de auditoria para rastrear alterações nos registros.

## Autor

Desenvolvido por **Davi Rodrigues** como parte de aprendizado em programação C.

---

Sinta-se à vontade para contribuir com melhorias ou relatar problemas!
