# tambores
Bateria (?) eletrônica feita com arduino.

## Dependências
- [ttymidi](http://www.varal.org/ttymidi/)
- [MIDILibrary](https://github.com/FortySevenEffects/arduino_midi_library)

## Esquema
![Esquema no Fritzing](/schematics/scheme.jpg)

## Utilização
1. Monte o circuito
2. Envie o programa ao Arduino
3. Inicie o FluidSynth com o soundfont desejado. Ex: 
```fluidsynth -a pulseaudio /usr/share/sounds/sf2/FluidR3_GM.sf2```
4. Inicie o ttymidi a partir da porta serial em que o arduino está conectado. Ex: 
```sudo ttymidi -s /dev/ttyACM0 -v```
5. Conecte o ttymidi ao FluidSynth. Para esta etapa recomendamos o [QJackCtl](http://qjackctl.sourceforge.net/)

## Próximos passos
- Ampliar o número de peças utilizadas
- Identificar toques simultâneos
- Sensibilidade: identificar diferentes níveis de batida
- Construir pads
- Script de instalação que verifica as dependências? Software que inicia fluidsynth, ttymidi e jack automaticamente e que permite a troca de soundfont sem a necessidade de reiniciar manualmente o ttymidi e refazer a conexão do jack.


