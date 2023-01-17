#include <Servo.h>
Servo   Steeringservo;
Servo servo; 

#define MOTOR_R_IN1 2

#define MOTOR_R_IN2 3

#define MOTOR_R_ENA 5

#define MOTOR_L_IN1 4

#define MOTOR_L_IN2 7

#define MOTOR_L_ENB 6

#define RC_SERVO_PIN 8 // 차량에 맞도록

#define NEURAL_ANGLE 70

#define LEFT_STEER_ANGLE  -40  // 실험으로 구할것

#define RIGHT_STEER_ANGLE  50  // 실험으로 구할
int Steering_Angle = NEURAL_ANGLE;
int value = 0;    // 각도를 조절할 변수 value
    //Servo 클래스로 servo객체 생성

    int pos = 0;
void Forward();
void steering_control()

{

  if(Steering_Angle<= LEFT_STEER_ANGLE + NEURAL_ANGLE)  Steering_Angle  = LEFT_STEER_ANGLE + NEURAL_ANGLE;

  if(Steering_Angle>= RIGHT_STEER_ANGLE + NEURAL_ANGLE)  Steering_Angle = RIGHT_STEER_ANGLE + NEURAL_ANGLE;

  Steeringservo.write(Steering_Angle);  

}

void motor_control(int speed_l,int dir_l, int speed_r, int dir_r)

{

   if(dir_l ==1) // 전진

   {

     digitalWrite(MOTOR_L_IN1, HIGH);

     digitalWrite(MOTOR_L_IN2, LOW);

     analogWrite(MOTOR_L_ENB, speed_l);  

   }

   else if( dir_l == -1)//후진

   {  

     digitalWrite(MOTOR_L_IN1, LOW);

     digitalWrite(MOTOR_L_IN2, HIGH);

     analogWrite(MOTOR_L_ENB, speed_l); 

   }

   else

   {

     digitalWrite(MOTOR_L_IN1, LOW);

     digitalWrite(MOTOR_L_IN2, LOW);

     analogWrite(MOTOR_L_ENB, 0);

   }  
    if(dir_r ==1) // 전진

   {

     digitalWrite(MOTOR_R_IN1, HIGH);

     digitalWrite(MOTOR_R_IN2, LOW);

     analogWrite(MOTOR_R_ENA, speed_r);  

   }

   else if( dir_r == -1)//후진

   {  

     digitalWrite(MOTOR_R_IN1, LOW);

     digitalWrite(MOTOR_R_IN2, HIGH);

     analogWrite(MOTOR_R_ENA, speed_r); 

   }

   else

   {

     digitalWrite(MOTOR_R_IN1, LOW);

     digitalWrite(MOTOR_R_IN2, LOW);

     analogWrite(MOTOR_R_ENA, 0);

   }  

}

void setup() {

  // put your setup code here, to run once:
  servo.attach(8);     //servo 서보모터 7번 핀에 연결
                       // 이때 ~ 표시가 있는 PWM을 지원하는 디지털 핀에 연결

  Serial.begin(9600); //9600 속도로 통신을 시작 한다.

  pinMode(MOTOR_R_IN1, OUTPUT);

  pinMode(MOTOR_R_IN2,OUTPUT);

  pinMode(MOTOR_R_ENA, OUTPUT);

  pinMode(MOTOR_L_IN1, OUTPUT);

  pinMode(MOTOR_L_IN2, OUTPUT);

  pinMode(MOTOR_L_ENB, OUTPUT);  

} // 설정 함수

void loop() {
     
 for (pos = 0; pos <= 120; pos += 1) {
    // in steps of 1 degree
    servo.write(pos);             
    delay(15);                     
  }
  for (pos = 120; pos >= 0; pos -= 1) { 
    servo.write(pos);             
    delay(15);                      
  }

{
  digitalWrite(MOTOR_L_IN1, LOW);
  digitalWrite(MOTOR_L_IN2, HIGH);
  digitalWrite(MOTOR_R_IN1, HIGH);
  digitalWrite(MOTOR_R_IN2, LOW);
}
   
    
}
