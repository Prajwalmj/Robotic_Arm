#include <Servo.h>
Servo myservo1,myservo2,myservo3,myservo4; // create servo object to control a servo
// a maximum of eight servo objects can be created
int pos1 = 0; // variable to store the servo position
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
myservo1.attach(8); // attaches the servo on pin 9 to the servo object
myservo2.attach(9);
myservo3.attach(10);
myservo4.attach(11);
myservo1.write(0);
myservo2.write(0);
myservo3.write(0);
myservo4.write(0);
}


void pick(){

for(pos1 = 0; pos1 <= 90; pos1 += 1) //bottom disc
{
myservo1.write(pos1);
delay(15);
}

myservo4.write(0);
delay(50);

for(pos2= 0 ; pos2 <= 60; pos2 +=1) //joint 1(near bottom disc)
{
myservo2.write(pos2);
delay(15);
}

myservo4.write(0);
delay(50);

for(pos3= 0 ; pos3 <= 50; pos3 +=1) //joint 2
{
myservo3.write(pos3);
delay(15);
}

myservo4.write(0);
delay(50);

myservo4.write(0);

for(pos4= 0 ; pos4 <= 10; pos4 += 1) // claw
{
myservo4.write(pos4);
delay(15);
}

delay(500);
}

void move_to_destination(){
myservo4.write(pos4);

for(pos3= 50 ; pos3 >= 0; pos3 -=1)
{
myservo3.write(pos3);
delay(15);
}

myservo4.write(pos4);
delay(50);

for(pos2=60 ; pos2 >= 0; pos2 -=1)
{
myservo2.write(pos2);
delay(15);
}

myservo4.write(pos4);
delay(50);

for(pos1 = 90; pos1>=0; pos1 -=1)
{
myservo1.write(pos1);
delay(15);
}

myservo4.write(pos4);
delay(50);
delay(40);
}

void place(){
for(pos2= 0 ; pos2 <= 60; pos2 +=1) //joint 1(near bottom disc)
{
myservo2.write(pos2);
delay(15);
}

delay(50);

for(pos3= 0 ; pos3 <= 50; pos3 +=1) //joint 2
{
myservo3.write(pos3);
delay(15);
}

delay(50);

for(pos4= 10 ; pos4 >= 0; pos4 -= 1)
{
myservo4.write(pos4);
delay(15);
}

delay(50);
}

void return_to_original_position(){
for(pos3= 50 ; pos3 >= 0; pos3 -=1)
{
myservo3.write(pos3);
delay(15);
}

//myservo4.write(pos4);
delay(50);

for(pos2=60 ; pos2 >= 0; pos2 -=1)
{
myservo2.write(pos2);
delay(15);
}

//myservo4.write(pos4);
delay(50);
}

void loop()
{
pick();
move_to_destination();
place();
return_to_original_position();
}