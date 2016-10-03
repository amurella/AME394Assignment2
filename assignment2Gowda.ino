/*  Akhila Murella
 *   AME394
 *   Assignment2
*/
int ledPin = D3; //output pin
int analog_no = 5 ;// define A5 as input signal pin
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int pin_value;
  int temperature;
  pin_value = analogRead(analog_no);

  //get the value in and write it to the output pin
  float voltage = pin_value * 5.0;
  voltage /= 1024;
  analogWrite(ledPin, voltage);
  float temperatureC = (voltage - 0.5) * 100;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  if(temperatureF > 70 && temperatureF < 150)
  {
    digitalWrite(temperatureF, HIGH);
  }
  Serial.print("Current temperature is ") ;
  Serial.print(temperatureF) ;
  Serial.println("F");
  Serial.print(temperatureC) ;
  Serial.println("C");
  delay(400);
}
