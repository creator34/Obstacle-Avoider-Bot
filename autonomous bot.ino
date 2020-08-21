#include <AFMotor.h>
#include <Servo.h>
Servo servo;
#include <NewPing.h>
int Trig =A3;
int Echo  =2;
NewPing sonar(Trig,Echo);
int safe =10;
AF_DCMotor motorl(3);
AF_DCMotor motorr(4);
int ld,rd;

void setup()
{
  Serial.begin(9600);
  servo.attach(10);
  servo.write(90);
  motorl.setSpeed(255);
  motorr.setSpeed(255);
  motorr.run(RELEASE);
  motorl.run(RELEASE);
  delay(500);
  

}
void loop()
{
   
  int dist= sonar.ping_cm();
   Serial.println(dist);
   while(dist>safe)
   {
   motorr.run(BACKWARD);
   motorl.run(BACKWARD);
   }
    if(dist<safe)
   {motorr.run(RELEASE);
   motorl.run(RELEASE);
   servo.write(0);
   int rd= sonar.ping_cm();
   delay(500);
   servo.write(180);
   int ld= sonar.ping_cm();
   delay(500);
   servo.write(90);
   delay(100);
   if(rd<ld)
  { motorr.run(BACKWARD);
   motorl.run(BACKWARD);
   delay(1500);
   motorl.run(BACKWARD);
   motorr.run(FORWARD);
   delay(2000);
   }
   else if(rd>ld)
   {motorr.run(BACKWARD);
   motorl.run(BACKWARD);
   delay(1500);
     motorl.run(FORWARD);
   motorr.run(BACKWARD);
   delay(2000);//left turn
   }}
   
   
}



