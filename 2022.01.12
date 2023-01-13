#include <NewPing.h>
#define SONAR_NUM 3
#define MAX_DISTANCE 200

#define F_sonsr 8
#define R_sonsr 10
#define L_sonsr 11

#define MOTOR_R_IN1 7 //오른쪽 모터핀7
#define MOTOR_R_IN2 4 //오른쪽 모터핀4
#define MOTOR_R_ENA 6

#define MOTOR_L_IN3 3 //왼쪽 모터핀 3
#define MOTOR_L_IN4 2 //왼쪽 모터핀 2
#define MOTOR_L_ENB 5 

 float R_sonar_Distance = 0.0;
float R_sonar_Distance_old = 0.0;
float R_sonar_Error = 0.0;

float L_sonar_Distance = 0.0;
float L_sonar_Distance_old = 0.0;
float L_sonar_Error = 0.0;

float F_sonar_Distance = 0.0;
float F_sonar_Distance_old = 0.0;
float F_sonar_Error = 0.0;

int speedmax = 90;

int WALL = 49;
int angle = 90;

int Speed = 50;//모터속도


 NewPing sonar[SONAR_NUM] = {
NewPing(8, 8, MAX_DISTANCE),
NewPing(10, 10, MAX_DISTANCE),
NewPing(11, 11, MAX_DISTANCE)
};

void read_sonar_sensor(void) //초음파 센서 값을 읽는 함수
{
   R_sonar_Distance = sonar[1].ping_cm()*10.; //각자에 맞도록 센서 번호 설정
   L_sonar_Distance = sonar[2].ping_cm()*10.;
   F_sonar_Distance = sonar[0].ping_cm()*10.;
   if( R_sonar_Distance == 0) R_sonar_Distance = MAX_DISTANCE * 10.0;
   if( L_sonar_Distance == 0) L_sonar_Distance = MAX_DISTANCE * 10.0;
   if( F_sonar_Distance == 0) F_sonar_Distance = MAX_DISTANCE * 10.0;
}

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
    digitalWrite(MOTOR_L_IN3, HIGH);
    digitalWrite(MOTOR_L_IN4, HIGH);
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
    digitalWrite(MOTOR_R_IN1, LOW);
    digitalWrite(MOTOR_R_IN2, HIGH);
    analogWrite(MOTOR_R_ENA, speed_r);        
   }
   else
   {
    digitalWrite(MOTOR_R_IN1, HIGH);
    digitalWrite(MOTOR_R_IN2, HIGH);
    analogWrite(MOTOR_R_ENA, 0);
   }
      
  }
  
  
void loop(){
  int index;
  index = read_line_sensor();


  int value = digitalRead(F_sonar_Distance);
  if(value == 0){
    digitalWrite(MOTOR_R_IN1,0);
    digitalWrite(MOTOR_R_IN2,0);
    digitalWrite(MOTOR_L_IN3,0);
    digitalWrite(MOTOR_L_IN4,0);
  }
  
  switch(index)
  {
    case -10 :   //정지
            motor_control(0,0,0,0);
            Serial.println("[-10]");
            break;
    case 0 :     //전진
             motor_control(1,speedmax,1,speedmax);
             Serial.println("[0]");
             break;
    case 1 :     //우회전
            motor_control(1,speedmax,1,speedmax*0.7);
            Serial.println("[1]");
            break;
    case 2 :     //우회전
            motor_control(1,speedmax,1,speedmax*0.6);
            Serial.println("[2]");
            break;
    case 3 :     //우회전
           motor_control(1,speedmax,1,speedmax*0.5);
            Serial.println("[3]");
            break;
    case 4 :     //우회전
            motor_control(1,speedmax,-1,speedmax*0.3);
            Serial.println("[4]");
            break;   
    case -1 :     //좌회전
           motor_control(1,speedmax*0.7,1,speedmax);
           Serial.println("[-1]");
           break;               
    case -2 :     //좌회전
           motor_control(1,speedmax*0.6,1,speedmax);
           Serial.println("[-2]");
           break;
    case -3 :     //좌회전
           motor_control(1,speedmax*0.5,1,speedmax);
           Serial.println("[-3]");
           break;
    case -4  :    //좌회전
           motor_control(-1,speedmax*0.3,1,speedmax);
           Serial.println("[-4]");
           break;
    }                                                     
            
  
    //if(mission==0)
     //line-fowllowing()
    
    //obstacle-detection(); //초음파센서 장애물이 있으면 멈춤 없으면 이동
    //int distance = ();

   
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
