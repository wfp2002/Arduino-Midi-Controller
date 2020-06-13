# Arduino-Midi-Controller


Foram utilizados pra esse codigos as saidas D2 a D8, como botoes de 1 a 7 para o controlador, também sera utilizado o Analog0 com potenciometro de 10K para intensidade da Nota.

As ligacoes sao simples:

Potenciometro:

Pino1 = 5v
Pino2 Central = A0
Pino3 = GND

Para os botoes D2 a D8:

Ligar em um lado de todos os botoes o GND e do outro lado do Botao as respectivas portas D2 a D8.

Exemplo:

Botao1: Um contato do botao vai no GND e outro no D2;

Botao2: Um contato do botao vai no GND e outro no D3... e assim por diante com todos os botoes.

Para funcionar em qualquer arduino, precisamos de 2 software para converter o sinal USD-Serial do Arduino (Hairless-MidiSerial) e outro fazer um Midi Controller (LoopMidi).

Apos fazer as ligacoes do arduino e gravar o Sketch, abra o LoopMidi e na Sequencia abra o Hairless, Selecione no Hairless a porta COM correspondente do Arduino em (Serial Port) e selecione a porta do LoopMidi na (MIDI Out) do Hairless, feito isso clique na FLAG (Serial<->Midi bridge On), e pronto! Se tudo deu certo, ao pressionar os botoes ligados ao Arduino, as luzes verdes indicando roteamento MIDI no Hairless irão piscar!

Agora é só abrir sua DAW ou qualquer outro Soft Musical ou MIDI e configurar o dispositivo Midi para o LoopMidi.

