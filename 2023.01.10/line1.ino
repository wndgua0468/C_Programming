#include <NewPing.h>
#define SONAR_NUM 3
#define MAX_DISTANCE 200

#define MOTOR_R_IN1 3 //오른쪽 모터핀1
#define MOTOR_R_IN2 2 //오른쪽 모터핀2
#define MOTOR_R_ENA 5

#define MOTOR_L_IN3 7 //왼쪽 모터핀 3
#define MOTOR_L_IN4 4 //왼쪽 모터핀 4
#define MOTOR_L_ENB 6  

int WALL = 49;
int angle = 91;

int speed = 50;//모터속도


 NewPing sonar[SONAR_NUM] = {
NewPing(4, 5, MAX_DISTANCE),
NewPing(6, 7, MAX_DISTANCE),
NewPing(8, 9, MAX_DISTANCE)
};

int line_sensor[5]={0,0,0,0,0}; //배열을 선언

int read_line_sensor()
{
  int i; //i라는 정수변수를 선언
  int sum=0;
  int line_index=0;
  for(i=0;i<5;i++)
{
  line_sensor[i] = 1 - digitalRead(A0+i);
  sum += line_sensor[i];
  Serial.print(line_sensor[i]);
  Serial.print("  ");
}
  Serial.println(""); 
 //line_sensor[0] line_sensor[1] line_sensor[2] line_sensor[3] line_sensor[4]
 //     -4            -3             -2          -1   0  1  2    3  4 

 if(sum==0) line_index = -10;
 if(sum==1)
{
  if( line_sensor[0]==1) line_index = -4;
  if( line_sensor[1]==1) line_index = -2;
  if( line_sensor[2]==1) line_index = 0;
  if( line_sensor[3]==1) line_index = 2;
  if( line_sensor[4]==1) line_index = 4;  
}
 if(sum==2)
{
  if( (line_sensor[0]==1) && (line_sensor[1]==1) ) line_index = -3;
  if( (line_sensor[1]==1) && (line_sensor[2]==1) ) line_index = -1;
  if( (line_sensor[2]==1) && (line_sensor[3]==1) ) line_index = 1;
  if( (line_sensor[3]==1) && (line_sensor[4]==1) ) line_index = 3; 
 }
Serial.print(line_index);
Serial.println("");
} //라인 센서 구동함수



void setup(){
  pinMode(MOTOR_R_IN1,OUTPUT);
  pinMode(MOTOR_R_IN2,OUTPUT);
  pinMode(MOTOR_R_ENA,OUTPUT);
  pinMode(MOTOR_L_IN3,OUTPUT);
  pinMode(MOTOR_L_IN4,OUTPUT);
  pinMode(MOTOR_L_ENB,OUTPUT);
  
  Serial.begin(115200);
  }



void motor_control(int dir_l, int speed_l, int dir_r, int speed_r)
{
  if(dir_l==1) //전진
  {
    digitalWrite(MOTOR_L_IN3, HIGH);
    digitalWrite(MOTOR_L_IN4, LOW);
    analogWrite(MOTOR_L_ENB, speed_l);
  }
  else if(dir_l==-1) //후진
  {
    digitalWrite(MOTOR_L_IN3, LOW);
    digitalWrite(MOTOR_L_IN4, HIGH);
    analogWrite(MOTOR_L_ENB, speed_l);
  }
   else
   {
    digitalWrite(MOTOR_L_IN3, LOW);
    digitalWrite(MOTOR_L_IN4, LOW);
    analogWrite(MOTOR_L_ENB, 0);
   }
   if(dir_r==1) //전진
   {
    digitalWrite(MOTOR_R_IN1, HIGH);
    digitalWrite(MOTOR_R_IN2, LOW);
    analogWrite(MOTOR_R_ENA, speed_r);    
   }
   else if(dir_r==-1) //후진
   {
    digitalWrite(MOTOR_R_IN1, HIGH);
    digitalWrite(MOTOR_R_IN2, LOW);
    analogWrite(MOTOR_R_ENA, speed_r);        
   }
      
  }
  
  
void loop(){
  int index;
  index = read_line_sensor();

  switch(index)
  {
    case -4 : //정지
    motor_control(1,0,1,0);
    break;

    case -3 : //전진
    motor_control(1,100,1,100);
    break;

    case -2 : //좌회전
    motor_control(1,70,1,100);
    break;

    case -1 : // 좌회전
    motor_control(1,50,1,100);
    break;

    case 0 : // 좌회전
    motor_control(1,30,1,100);
    break;

    case 1 : //좌회전
    motor_control(1,30,1,120);
    break;

    case 2 : //우회전 
    motor_control(1,100,1,70);
    break;

    case 3 : //우회전 
    motor_control(1,100,1,50);
    break;

    case 4 : //우회전 
    motor_control(1,100,1,30);
    break;    
  }

//left_wall_tracking();
int line_follwing();
if((digitalRead(MOTOR_L_ENB)==HIGH) && (digitalRead(MOTOR_R_ENA)==HIGH))
{
  analogWrite(MOTOR_L_IN3,0);
  analogWrite(MOTOR_L_IN4,speed);

  analogWrite(MOTOR_R_IN1,speed);
  analogWrite(MOTOR_R_IN2,0);
}
else if((digitalRead(MOTOR_L_ENB)==LOW) && (digitalRead(MOTOR_R_ENA)==HIGH))
{
  analogWrite(MOTOR_L_IN3,0);
  analogWrite(MOTOR_L_IN4,speed);

  analogWrite(MOTOR_R_IN1,0);
  analogWrite(MOTOR_R_IN2,speed);
}
else if((digitalRead(MOTOR_L_ENB)==HIGH) && (digitalRead(MOTOR_R_ENA)==LOW))
{
  analogWrite(MOTOR_L_IN3,speed);
  analogWrite(MOTOR_L_IN4,0);

  analogWrite(MOTOR_R_IN1,speed);
  analogWrite(MOTOR_R_IN2,0);
}

if(WALL<50){
  if(angle>90){
  motor_control(1,100,1,50);
  }
    
}

//cwrotation()
//center_tracking()
}
