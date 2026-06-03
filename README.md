AgroSpace - Sistema de Monitoramento Agrícola 

**AgroSpace** é uma solução voltada para a agricultura sustentável e de precisão. Inspirada nos sistemas de monitoramento climático por satélite, nossa plataforma usa processamento de dados para auxiliar pequenos produtores a gerenciar o uso da água e monitorar os riscos climáticos que ameaçam suas plantações.

O dispositivo atua de forma autônoma para ligar e desligar um sistema de irrigação inteligente, além de emitir alertas visuais e sonoros caso as condições ambientais atinjam níveis críticos, reduzindo o desperdício de água.

Componentes Utilizados:
A simulação foi construída na plataforma Tinkercad utilizando os seguintes componentes:
- **1x Microcontrolador Arduino Uno R3** 
- **1x Sensor de Temperatura (TMP36)** 
- **1x Potenciômetro** 
- **1x LED Azul** 
- **1x LED Vermelho** 
- **1x Buzzer Piezoelétrico** 
- **2x Resistores de 220 Ω** 
- **1x Protoboard e Jumpers** 

Explicação do Funcionamento
O sistema opera através de uma malha de controle fechada que lê os sensores a cada segundo:
1.  **Monitoramento de Umidade e Temperatura:** O sensor de temperatura e o potenciômetro (umidade) geram sinais analógicos que são convertidos em valores reais pelo Arduino.
2.  **Irrigação Inteligente:** Sempre que o solo cai abaixo do limite estabelecido em conjunto com o modelo matemático do grupo, o **LED Azul** se acende, indicando que a válvula de irrigação foi aberta.
3.  **Alerta de Risco:** Caso a temperatura esteja excessivamente alta e a umidade do solo continue a cair de forma perigosa, o sistema identifica um cenário de alto risco para o plantio, ativando imediatamente o **LED Vermelho** e o **Buzzer** para alertar o produtor.
4.  **Telemetria via Serial:** Todas as leituras e o status dos atuadores são transmitidos continuamente via porta Serial para integração.

Estrutura do Circuito
- **Sensor TMP36:** Conectado à porta analógica `A0`.
- **Potenciômetro (Umidade):** Conectado à porta analógica `A1`.
- **LED Azul (Irrigação):** Conectado à porta digital `13`.
- **LED Vermelho (Alerta):** Conectado à porta digital `12`.
- **Buzzer (Alarme Sonoro):** Conectado à porta digital `11`.

Instruções de Execução
Para testar o funcionamento do projeto:
1.  Acesse o link da simulação no Tinkercad:
2.  Clique em **Iniciar Simulação**.
3.  Abra o **Monitor Serial** no canto inferior para acompanhar os relatórios de dados gerados em tempo real.
4.  Altere o potenciômetro e o sensor de temperatura para simular variações no clima e ver os LEDs e o Buzzer reagindo aos níveis críticos.

Vídeo de Demonstração
O funcionamento deste circuito e a proposta de valor AgroSpace estão detalhados no vídeo:
- Link do Vídeo no YouTube:

Integrantes do Grupo
- **Enzo Cassiano Machado** - RM: 569630
- **José Henrique Oliveira de Lira** - RM: 569037
- **Mateus Rodrigues Tavares** - RM: 571189
- **Matheus Donas Vieira** - RM: 568626
- **Rafael Rosatti de Paula** - RM: 571280
