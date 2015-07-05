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
4. Inicie o ttymidi a partir da porta em que está o arduino. Ex: 
```sudo ttymidi -s /dev/ttyACM0 -v```
5. Conecte o ttymidi ao FluidSynth. Para esta etapa recomendamos o [QJackCtl](http://qjackctl.sourceforge.net/)

