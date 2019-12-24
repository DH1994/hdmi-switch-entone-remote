### IR Entone to HDMI Switch gatewat ###
This code is used to translate the signal from an Entone (T-Mobile settopbox) remote to the IR signal of the hdmi switch.
When the stopbutton on the Entone remote is pressed, the switch jumps to the next hdmi input.

### Scheme ###
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
