#define channelCount 17

int incomingByte[channelCount];
const int channelPin[channelCount] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4}; //The rest are the channel outputs in order from 1 - 15
const int switchPin = A5; //Input for the override switch

void setup()
{
  Serial.begin(9600);
  
  for (int i=0; i<channelCount; i++) pinMode(channelPin[i], OUTPUT);
  
  pinMode(switchPin, INPUT);
}

void loop()
{
  if (digitalRead(switchPin) == HIGH) { //If the switch is on "vixen mode" and do whatever vixen tells it to
    if (Serial.available() >= channelCount)  //If there is available serial bytes, and there are at least as many as the amount of channels we have
    {
      for (int i=0; i<channelCount+1;i++)  //Read up to the number of channels we have and set the correct pins
      {
        incomingByte[i] = Serial.read();
        analogWrite(channelPin[i], incomingByte[i]);
      }
    }
  }
  else {  //If the switch is NOT on "vixen mode" then turn everything on
      for (int i=0; i<channelCount+1;i++)  //Run for up to the number of channels we have and set the pins all high
      {
        digitalWrite(channelPin[i], HIGH);
      }
  }
}
