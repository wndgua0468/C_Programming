#include <NewPing.h>
#define SONAR_NUM 3
#define MAX_DISTANCE 200

#define MOTOR_R_IN1 3 //오른쪽 모터핀1
#define MOTOR_R_IN2 2 //오른쪽 모터핀2
#define MOTOR_R_ENA 5

#define MOTOR_L_IN3 4 //왼쪽 모터핀 3
#define MOTOR_L_IN4 7 //왼쪽 모터핀 4
#define MOTOR_L_ENB 6  

int WALL = 49;
int angle = 91;

int Speed = 50;//모터속도


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
  line_sensor[i] = digitalRead(A0+i);
  sum += line_sensor[i];
  Serial.print(line_sensor[i]);
  Serial.print("  ");
}
  Serial.println(""); 
 //line_sensor[0] line_sensor[1] line_sensor[2] line_sensor[3] line_sensor[4]
 //     -4            -3             -2          -1   0  1  2    3  4 

 if(sum==5) line_index = -10;
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

return line_index;
} //라인 센서 구동함수



void setup(){
  pinMode(MOTOR_R_IN1,OUTPUT);
  pinMode(MOTOR_R_IN2,OUTPUT);
  analogWrite(MOTOR_R_ENA,HIGH);
  pinMode(MOTOR_L_IN3,OUTPUT);
  pinMode(MOTOR_L_IN4,OUTPUT);
  analogWrite(MOTOR_L_ENB,HIGH);
  
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
    case -10 :   //정지
            digitalWrite(MOTOR_R_IN1, HIGH);
            digitalWrite(MOTOR_R_IN2, LOW);
            digitalWrite(MOTOR_L_IN3, HIGH);
            digitalWrite(MOTOR_L_IN4, LOW);
            analogWrite(MOTOR_R_ENA, 0);
            analogWrite(MOTOR_L_ENB, 0);
            Serial.println("[-10]");
            break;
    case 0 :     //전진
             digitalWrite(MOTOR_R_IN1, HIGH);
             digitalWrite(MOTOR_R_IN2, LOW);
             digitalWrite(MOTOR_L_IN3, LOW);
             digitalWrite(MOTOR_L_IN4, HIGH);
             analogWrite(MOTOR_R_ENA, 150);
             analogWrite(MOTOR_L_ENB, 150);
             Serial.println("[0]");
             break;
    case 2 :     //우회전
            digitalWrite(MOTOR_R_IN1, HIGH);
            digitalWrite(MOTOR_R_IN2, LOW);
            digitalWrite(MOTOR_L_IN3, HIGH);
            digitalWrite(MOTOR_L_IN4, LOW);
            analogWrite(MOTOR_R_ENA, 0);
            analogWrite(MOTOR_L_ENB, 200);
            Serial.println("[2]");
            break;
    case 4 :     //우회전
            digitalWrite(MOTOR_R_IN1, HIGH);
            digitalWrite(MOTOR_R_IN2, LOW);
            digitalWrite(MOTOR_L_IN3, HIGH);
            digitalWrite(MOTOR_L_IN4, LOW);
            analogWrite(MOTOR_R_ENA, 0);
            analogWrite(MOTOR_L_ENB, 200);
            Serial.println("[4]");
            break;                  
    case -2 :     //좌회전
           digitalWrite(MOTOR_R_IN1, LOW);
           digitalWrite(MOTOR_R_IN2, HIGH);
           digitalWrite(MOTOR_L_IN3, LOW);
           digitalWrite(MOTOR_L_IN4, HIGH);
           analogWrite(MOTOR_R_ENA, 200);
           analogWrite(MOTOR_L_ENB, 0);
           Serial.println("[-2]");
           break;
    case -4  :    //좌회전
           digitalWrite(MOTOR_R_IN1, LOW);
           digitalWrite(MOTOR_R_IN2, HIGH);
           digitalWrite(MOTOR_L_IN3, LOW);
           digitalWrite(MOTOR_L_IN4, HIGH);
           analogWrite(MOTOR_R_ENA, 200);
           analogWrite(MOTOR_L_ENB, 0);
           Serial.println("[-4]");
           break;
    case -3 :     //좌회전
           digitalWrite(MOTOR_R_IN1, LOW);
           digitalWrite(MOTOR_R_IN2, HIGH);
           digitalWrite(MOTOR_L_IN3, LOW);
           digitalWrite(MOTOR_L_IN4, HIGH);
           analogWrite(MOTOR_R_ENA, 200);
           analogWrite(MOTOR_L_ENB, 0);
           Serial.println("[-3]");
           break;
    case -1 :     //좌회전
           digitalWrite(MOTOR_R_IN1, LOW);
           digitalWrite(MOTOR_R_IN2, HIGH);
           digitalWrite(MOTOR_L_IN3, LOW);
           digitalWrite(MOTOR_L_IN4, HIGH);
           analogWrite(MOTOR_R_ENA, 200);
           analogWrite(MOTOR_L_ENB, 0);
           Serial.println("[-1]");
           break;
    case 1 :     //우회전
           digitalWrite(MOTOR_R_IN1, HIGH);
            digitalWrite(MOTOR_R_IN2, LOW);
            digitalWrite(MOTOR_L_IN3, HIGH);
            digitalWrite(MOTOR_L_IN4, LOW);
            analogWrite(MOTOR_R_ENA, 0);
            analogWrite(MOTOR_L_ENB, 200);
            Serial.println("[1]");
            break;
    case 3 :     //회전
           digitalWrite(MOTOR_R_IN1, HIGH);
            digitalWrite(MOTOR_R_IN2, LOW);
            digitalWrite(MOTOR_L_IN3, HIGH);
            digitalWrite(MOTOR_L_IN4, LOW);
            analogWrite(MOTOR_R_ENA, 200);
            analogWrite(MOTOR_L_ENB, 100);
            Serial.println("[3]");
            break;
  }                                                     
            
  
    //if(mission==0)
     //line-fowllowing()
    if((digitalRead(MOTOR_L_ENB)==HIGH) && (digitalRead(MOTOR_R_ENA)==HIGH))
{
  analogWrite(MOTOR_L_IN3,0);
  analogWrite(MOTOR_L_IN4,Speed);

  analogWrite(MOTOR_R_IN1,Speed);
  analogWrite(MOTOR_R_IN2,0);
}
else if((digitalRead(MOTOR_L_ENB)==LOW) && (digitalRead(MOTOR_R_ENA)==HIGH))
{
  analogWrite(MOTOR_L_IN3,0);
  analogWrite(MOTOR_L_IN4,Speed);

  analogWrite(MOTOR_R_IN1,0);
  analogWrite(MOTOR_R_IN2,Speed);
}
else if((digitalRead(MOTOR_L_ENB)==HIGH) && (digitalRead(MOTOR_R_ENA)==LOW))
{
  analogWrite(MOTOR_L_IN3,Speed);
  analogWrite(MOTOR_L_IN4,0);

  analogWrite(MOTOR_R_IN1,Speed);
  analogWrite(MOTOR_R_IN2,0);
}
    //obstacle-detection(); //초음파센서 장애물이 있으면 멈춤 없으면 이동
    //int distance = ();

    //장애물감지
   // if(distance<15){
     /* MOTOR_R_IN1(STOP);
      MOTOR_R_IN2(STOP);
      MOTOR_L_IN3(STOP);
      MOTOR_L_IN4(STOP);
    }*/
    //wall-detection(); - mission=1;
  }

//left_wall_tracking();
int line_follwing(){;

if(WALL<50){
  if(angle>90){
  motor_control(1,100,1,50);
  }
    
}

//cwrotation()
//center_tracking()
}
