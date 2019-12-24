### IR Entone to HDMI Switch gatewat ###
This code is used to translate the signal from an Entone (T-Mobile settopbox) remote to the IR signal of the hdmi switch.
When the stopbutton on the Entone remote is pressed, the switch jumps to the next hdmi input.

### Scheme ###

---------------
|Entone Remote|
---------------
     .
     .
     .
     .               d3          d2
------------          -----------          ---------------
IR Receiver| ---[]==> | Arduino | ---[]==> | HDMI Switch | 
------------          -----------          ---------------
