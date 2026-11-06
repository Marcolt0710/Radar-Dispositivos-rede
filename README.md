# Projeto 01 – Radar de Dispositivos da Rede

**Conceito de rede/segurança:** Disponibilidade
**Turma:** [preencher] · **Integrantes:** [preencher] · **Data:** 07/11/2026

## Problema

Simular uma central que acompanha quais computadores de um laboratório estão disponíveis (ativos) ou indisponíveis (inativos). O programa recebe a quantidade de dispositivos e o estado de cada um. Em seguida, mostra um painel com o total de ativos, o total de inativos e o percentual de disponibilidade, e emite um **ALERTA** quando 2 ou mais dispositivos estão fora do ar.

## Analogia com redes

Em uma rede real, a equipe de TI monitora se os equipamentos estão respondendo. Neste projeto, **cada posição do vetor `estado[10]` representa um dispositivo**. O valor digitado (1 = ativo, 0 = inativo) substitui uma checagem de conectividade, como um *ping*.

## Relação com segurança da informação

A **disponibilidade** é um dos três pilares da segurança da informação, ao lado da confidencialidade e da integridade. Quando um equipamento essencial fica fora do ar, o serviço que depende dele pode parar. O alerta ajuda a equipe a perceber o problema rapidamente.

## Conteúdos de C++ utilizados

| Conteúdo | Onde aparece |
|---|---|
| Variáveis (`int`, `double`) | contadores `ativos`, `inativos` e `percentual` |
| Decisão (`if/else`) | validação, classificação ATIVO/INATIVO e alerta |
| Repetição (`do...while`, `for`) | validação das entradas, leitura e contagem |
| Vetor fixo | `int estado[10]` |

Todo o programa fica dentro de `main()`, sem `string`, `vector`, funções próprias ou bibliotecas extras. O percentual é calculado com `100.0` (número real), o que evita a divisão inteira.

## Como compilar e executar

```bash
g++ radar_dispositivos.cpp -o radar
./radar          # no Windows: radar.exe
```

## Registro de testes

| # | Entrada | Resultado previsto | Resultado obtido |
|---|---|---|---|
| 1 | N=6; 1,1,0,1,0,1 | 4 ativos; 2 inativos; 66,7%; alerta | 4 ativos; 2 inativos; 66,7%; ALERTA ✔ |
| 2 | N=3; 1,1,1 | 100%; sem alerta | 100,0%; sem alerta ✔ |
| 3 | N=2; 0,0 | 0%; alerta | 0,0%; ALERTA ✔ |
| 4 | N=0, depois N=11, depois N=2; estado 5, depois 1,1 | rejeita N=0, N=11 e o estado 5; pede de novo | mensagens de "entrada invalida" e nova leitura ✔ |

## Limites da simulação

- Os estados são **digitados manualmente**. O programa **não** verifica IPs, **não** envia *ping* e **não** acessa a rede.
- Não mede tempo de resposta, serviços ou portas; mostra apenas um estado 0/1 por dispositivo.
- Aceita até 10 dispositivos e espera números inteiros. Letras digitadas não são tratadas.
- É uma atividade didática, não uma ferramenta real de monitoramento.

## Pergunta para a apresentação

**Por que estar "ligado" não significa necessariamente que um serviço está disponível?**

Um computador pode estar ligado e conectado à rede, mas o serviço que ele oferece pode estar travado, parado ou sobrecarregado. Isso vale para um site, um banco de dados ou um servidor de arquivos. Também pode haver problemas de configuração ou de rede no caminho até o usuário. Por isso, ter disponibilidade é o usuário conseguir **usar o serviço**, e não apenas ver o equipamento ligado.
