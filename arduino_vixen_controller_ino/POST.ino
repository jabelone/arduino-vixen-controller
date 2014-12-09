void POST() //Power on self test
{

  /////////////////// Turn all inputs on then off ///////////////////
  for (int i=0; i<=channelCount+1;i++)  //Run for up to the number of channels we have
  {
    digitalWrite(channelPin[i], HIGH); //Set the pins all high with a small delay in between
    delay(200);  //Delay for 200ms
  }
  for (int i=0; i<=channelCount+1;i++)  //Run for up to the number of channels we have
  {
    digitalWrite(channelPin[i], LOW);  //Set the pins all low with a small delay in between
    delay(200);  //Delay for 200ms
  }

  /////////////////// Fade all Inputs in then out ///////////////////

  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue +=2) {  // sets the value (range from 0 to 255):
    for (int i=0; i<=channelCount; i++)  //Read up to the number of channels we have and set the correct pins
    {
      analogWrite(channelPin[i], fadeValue);  //Set the output pin to the fade value
    }
    delay(30);  //Delay for 30ms
  } 

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -=2) {  // sets the value (range from 0 to 255):
    for (int i=0; i<=channelCount; i++)  //Read up to the number of channels we have and set the correct pins
    {
      analogWrite(channelPin[i], fadeValue);  //Set the output pin to the fade value
    }
    delay(30);  //Delay for 30ms
  }

}



