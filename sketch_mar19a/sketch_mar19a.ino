//Assign the pin to their pin numbers on the board
const int  trigPin = 10;
const int echoPin = 12;
const int ledPin = 13;
const int buzzer = 8;

void setup() 
{
  //Initialize serial communication at 9600 bps
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);//Set the trigPin as output
  pinMode(echoPin, INPUT);//Set the echoPin as input
  pinMode(ledPin, OUTPUT);//Set the ledPIN as output
  pinMode(buzzer, OUTPUT);//Set the buzzer as output

}

void loop()
 {
  //Send the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delay(500);
  digitalWrite(trigPin, HIGH);
  delay(500);
  digitalWrite(trigPin, LOW);
  
  //Measure the duration of the pulse 
  long duration = pulseIn(echoPin, HIGH);

  //Calculate the distance in centimeters
  long distance = duration * 0.034 / 2;

  //Print the distance to the serial monitor 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  //Activate buzzer if the distance is below the threshold
  if (distance < 20)//If the distance is below 20cm 
  {
    //Turn on the buzzer 
    digitalWrite(buzzer, HIGH);
    delay(500);//Delay for 0.5 second
  }

  //Deactivate buzzer if the distance is above the threshold
  else
  {
    //Turn off the buzzer
    digitalWrite(buzzer, LOW);
    delay(1000);// Delay for a second
  
  }

  //Blink LED
  digitalWrite(ledPin, HIGH);// Turn on the LED
  delay(5000);//Delay for five second
  digitalWrite(ledPin, LOW);//Turn off the LED
  delay(500);//Delay for 0.5 second
  
}
