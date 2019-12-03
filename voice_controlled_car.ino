
//voice controlled car

#include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library

String voice;

AF_DCMotor motor1 (1, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor motor2 (2, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
//AF_DCMotor motor3 (3, MOTOR12_1KHZ);
//AF_DCMotor motor4 (4, MOTOR12_1KHZ);


void setup()
{
  Serial.begin(9600); //start serial communication
 

}

void loop() 
{
  while (Serial.available()){ //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0){
    if(voice == "*Aage Ja"){
      forward_car();
      }
    else if(voice == "*go"){
      forward_car();
      }
    else if(voice == "*Go"){
      forward_car();
      }
    else if(voice == "*again"){
      forward_car();
      }
    else if(voice == "*Again"){
      forward_car();
      }
    else if(voice == "*Go Forward"){
      forward_car();
      }
    else if(voice == "*go forward"){
      forward_car();
      }
    else if(voice == "*Piche"){
      back_car();
      }
    else if(voice == "*piche aa"){
      back_car();
      }
    else if(voice == "*pichia"){
      back_car();
      }
    else if(voice == "*pjr"){
      back_car();
      }
    else if(voice == "*back"){
      back_car();
      }
    else if(voice == "*Back"){
      back_car();
      }
    else if(voice == "*Daye") {
      right_car();
    }
    else if(voice == "*daye") {
      right_car();
    }
    else if(voice == "*die") {
      right_car();
    }
    else if(voice == "*Die") {
      right_car();
    }
    else if(voice == "*danger") {
      right_car();
    }
    else if(voice == "*Danger") {
      right_car();
    }
    else if(voice == "*right") {
      right_car();
    }
    else if(voice == "*Right") {
      right_car();
    }
    else if(voice == "*baye") {
      left_car();
    }
    else if(voice == "*baye ja") {
      left_car();
    }
    else if(voice == "*baja") {
      left_car();
    }
     else if(voice == "*bhauja") {
      left_car();
    }
    else if(voice == "*bheja") {
      left_car();
    }
    else if(voice == "*Baja") {
      left_car();
    }
     else if(voice == "*left") {
      left_car();
    }
     else if(voice == "*Left") {
      left_car();
    }
    else if(voice == "*ruk ja") {
      stop_car();
    }
    else if(voice == "*stop") {
      stop_car();
    }
    
  voice=""; //Reset the variable after initiating
  }
}

void forward_car()
{
  motor1.run(FORWARD);
  motor1.setSpeed(200);
  motor2.run(FORWARD);
  motor2.setSpeed(200);
 /* motor3.run(FORWARD);
  motor3.setSpeed(200);
  motor4.run(FORWARD);
  motor4.setSpeed(200);
  */
  delay(5000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  //motor3.run(RELEASE);
 // motor4.run(RELEASE);
}
  
void back_car()
{
  motor1.run(BACKWARD);
  motor1.setSpeed(200);
  motor2.run(BACKWARD);
  motor2.setSpeed(200);
  //motor3.run(BACKWARD);
  //motor3.setSpeed(200);
  //motor4.run(BACKWARD);
  //motor4.setSpeed(200);
  delay(5000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  //motor3.run(RELEASE);
  //motor4.run(RELEASE);
}
  
void right_car()
{
  
  motor1.run(FORWARD);
  motor1.setSpeed(190);
  motor2.run(BACKWARD);
  motor2.setSpeed(190);
  //motor3.run(FORWARD);
  //motor3.setSpeed(190);
  //motor4.run(BACKWARD);
  //motor4.setSpeed(190);
  delay(5000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  //motor3.run(RELEASE);
  //motor4.run(RELEASE);
}
  
void left_car()
{
 
  motor1.run(BACKWARD);
  motor1.setSpeed(190);
  motor2.run(FORWARD);
  motor2.setSpeed(190);
  //motor3.run(BACKWARD);
  //motor3.setSpeed(190);
  //motor4.run(FORWARD);
  //motor4.setSpeed(190);
  delay(5000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  //motor3.run(RELEASE);
  //motor4.run(RELEASE);
}

void stop_car ()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  //motor3.run(RELEASE);
  //motor4.run(RELEASE);
}
