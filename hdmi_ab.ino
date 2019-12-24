/**************************************** ir receive ****************************************/

//------------------------------------------------------------------------------
// Include the IRremote library header
//
#include <IRremote.h>

//------------------------------------------------------------------------------
// Tell IRremote which Arduino pin is connected to the IR Receiver (TSOP4838)
//
int recvPin = 3;
IRrecv irrecv(recvPin);

/********************************************************************************************/

/****************************************** ir send ******************************************/

const int ir_send_pin = 2;

const uint32_t send_agc_pulse = 5000;
const uint32_t send_long_send_pause = 9000;
const uint32_t send_pause = 500;
const uint32_t send_zero = 500;
const uint32_t send_one = 1700;
const uint32_t send_stop = 600;
const uint8_t data_size = 32;
const uint8_t packet_size = 16;


const bool addr[packet_size] =      {0, 0 ,0 ,0 ,0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
const bool channel[][packet_size]= {{0 ,1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
                                    {0 ,0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1},
                                    {1 ,1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1}};

int currentChannel = 0;
                              
/********************************************************************************************/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  irrecv.enableIRIn();  // Start the receiver
  pinMode(ir_send_pin, OUTPUT);
  digitalWrite(ir_send_pin, LOW);
}



void loop() {
  decode_results  results;
  
  if (irrecv.decode(&results)) 
  {
    if(results.value == 216401163)
    {
      sendChannel(currentChannel);
    
      if(++currentChannel > 2)
        currentChannel = 0;
    }
      
    irrecv.resume();
  }
}


void sendChannel(int channelNr)
{
  startSignal();
  sendBytes(channel[channelNr]);
  stopSignal();
}

bool comparePulse(int pulseLength, int expectedVal)
{
  int marge = 50;
  if(pulseLength < (expectedVal + marge) && pulseLength > (expectedVal - marge))
    return 1;
  else
    return 0;
}

void sendBytes(bool * channel)
{

  bool sendBit;
  for(int curBit = 0; curBit <= data_size; curBit++)
  {
    if(curBit < packet_size)
      sendBit= addr[curBit];
    else
      sendBit = channel[curBit-packet_size];
      
    if(sendBit)
    {
      pulseOut(ir_send_pin, send_one, send_pause);
    }
    else
    {
      pulseOut(ir_send_pin, send_zero, send_pause);
    }
  } 

}

void stopSignal()
{
  pulseOut(ir_send_pin, send_stop, 0);
}

void startSignal()
{
  pulseOut(ir_send_pin, send_agc_pulse, send_long_send_pause);
}

void pulseOut(int pin, uint32_t usLength, uint32_t ussend_pause)
{
   digitalWrite(pin, LOW);
   delayMicroseconds(ussend_pause);
   digitalWrite(pin, HIGH);
   delayMicroseconds(usLength);
}
