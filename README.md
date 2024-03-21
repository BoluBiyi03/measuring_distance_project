# Object Avoidance Detector Using HC-SR04
## By
[Oluwabiyi Boluwatife](https://github.com/BoluBiyi03)
## Introduction 
In the realm of robotics and automation, object avoidance plays a pivotal role in ensuring safe and efficient navigation. Whether you’re designing a robotic vehicle, an industrial automation system, or a smart home device, the ability to detect and circumvent obstacles is paramount.

At the heart of our object avoidance system lies the HC-SR04 ultrasonic sensor. This compact and cost-effective sensor operates by emitting ultrasonic waves and measuring the time it takes for these waves to bounce back after encountering an obstacle. By analyzing this time delay, we can accurately calculate the distance between the sensor and the object.
## Purpose
In this project, we aim to create an intelligent system for object avoidance using the HC-SR04 ultrasonic sensor and Arduino. By integrating the HC-SR04, which emits ultrasonic waves and measures their reflection time, we can calculate distances to nearby obstacles. The Arduino processes this data, allowing the system to adapt its behavior dynamically—whether it’s stopping, changing direction, or slowing down—to avoid collisions. This project serves as a valuable learning experience, applicable in robotics, automation, and educational contexts, emphasizing safety, efficiency, and versatility. 🤖🚀
## Require Hardware
1) Arduino Uno Board
2) HC-SR04 (Ultrasonic Sensor)
3) Jumper Wires 
4) Buzzer
5) LED 
## Circuit Design
[Schematic Capture](https://drive.google.com/file/d/1-lPaWQ_OKDvLSlNSuEwufjCW1p5dBf6Y/view?usp=sharing)

[Circuit Digram](https://drive.google.com/file/d/1o0AH5swX3_jD-WcBiESZuNeC0iEYcGVn/view?usp=sharing)
## Source Code 
``` cpp
/*
This is my object avoidance detector project
By Boluwatife Oluwabiyi
C++ programming language
It detects an obstacle and gives alert to the user 
*/

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
```
## Working Principle
 The HC-SR04 ultrasonic sensor functions by emitting ultrasonic waves (sound waves with frequencies beyond human hearing) and measuring the time it takes for these waves to bounce back after hitting an obstacle. It consists of two main components, the transmitter (Trig) and the receiver (Echo).
 
 When triggered, the transmitter sends a short ultrasonic pulse. This pulse travels through the air and reflects off any nearby object. The receiver detects the reflected pulse and measures the time it took for the pulse to travel to the obstacle and back. 
 
 By knowing the speed of sound (approximately 343 metres per second at room temperature), we can calculate the distance to the obstacle using the formula: distance = (duration * 0.034) / 2. The Arduino Uno board reads the time taken from the Echo pin and performs this distance calculation.

Once the distance is calculated, the system compares it to a predefined threshold (20cm). If the calculated distance is less than this threshold, an object is detected.The system then activates two key components:

**LED**: The LED pin (Pin 13) is turned on to visually indicate the presence of an obstacle. This helps users quickly identify the danger.

**Buzzer**: The buzzer pin (Pin 8) emits an audible alarm. This sound serves as an additional warning, especially in scenarios where visual cues may be insufficient (e.g., low visibility conditions).

If the distance exceeds the threshold, the LED and buzzer are turned off, indicating a clear path.
## HEX File
[txt]([text](sketch_mar19a/sketch_mar19a.ino.hex))
## Advantages
1) Safety Enhancement: Detects obstacles in real time, preventing collisions in scenarios like robotics, autonomous vehicles, and home automation.

2) Affordability: Components (HC-SR04 sensor, Arduino Uno, LED, buzzer) are cost-effective, making it accessible for hobbyists and small-scale projects.
3) Ease of Implementation: Simple setup for beginners to learn about sensors, microcontrollers, and basic programming.
4) Customization: Adjustable detection threshold, LED brightness, and buzzer sound. Serves as a foundation for more complex projects.
5) Educational Value: Provides hands-on learning in electronics and programming, fostering curiosity and exploration. 
## Disadvantages
1) Limited Range and Accuracy: The HC-SR04 ultrasonic sensor has a maximum range of approximately 400 cm (13 feet). Beyond this range, it may not reliably detect obstacles.

2) Narrow Sensing Angle: The sensor’s 15-degree sensing angle restricts its field of view. It can only detect objects within this cone.
3) Noise and False Positives: Ultrasonic sensors are susceptible to noise interference. Echoes from nearby surfaces, acoustic reflections, or other ultrasonic sources can lead to false readings.
4) Multipath Reflections: When the ultrasonic signal reflects off multiple surfaces before returning to the sensor, it can cause multipath reflections. These reflections may confuse the sensor.
5) Complex Circuitry and Wiring: Implementing the entire system (sensor, Arduino Uno, LED, and buzzer) requires proper wiring and interfacing. Managing the connections, power supply, and signal processing can be complex, especially for beginners.
## Output
[video]()
## Summary and Conclusion 
**Summary**

Object avoidance detection is a critical aspect of autonomous robotics. It involves identifying obstacles in the environment and taking appropriate actions to avoid collisions. One cost-effective approach utilizes a single ultrasonic sensor mounted on an unmanned vehicle. The algorithm aims to minimize deviation from the original path while ensuring safe navigation. By approximating the shape of detected objects, the algorithm successfully reroutes the vehicle to avoid obstacles.

**Conclusion**

In this context, the development of an effective collision avoidance algorithm using a single ultrasonic sensor is a significant achievement. By relying on low-cost sensors, this approach demonstrates practicality and efficiency. As we continue to advance in robotics and automation, such algorithms play a crucial role in enhancing safety and reliability for unmanned vehicles.


# THANK YOU
