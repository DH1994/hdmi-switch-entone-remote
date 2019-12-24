### IR Entone to HDMI Switch gateway ###
Used to translate the signal from an Entone (T-Mobile settopbox) remote to the IR signal of the hdmi switch.
When the stop button on the Entone remote is pressed, the switch jumps to the next hdmi input.

### Requirements ###
- IRremote library
https://github.com/z3t0/Arduino-IRremote
- Arduino
- Wiring
- 3x1 HDMI Switcher (Aliexpress)

### Scheme ###
 	
```
000000000000000
|Entone Remote|
000000000000000
     .
     .
     .
     .            pin d3          pin d2
0000000000000          00000000000          000000000000000
|IR Receiver| ---[]==> | Arduino | ---[]==> | HDMI Switch | 
0000000000000          00000000000          000000000000000
                  jack in        jack out
```
