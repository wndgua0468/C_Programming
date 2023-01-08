#include <NewPing.h>
#define F_Sonar  8  //정면부 초음파 센서 연결 핀
#define R_Sonar  10 //오른쪽 초음파 센서 연결 핀
#define L_Sonar  11 //왼쪽 초음파 센서 연결 핀
#define MaxDistance  150

//3번과 4번 핀은 모터 제어에 관한 핀
#define IN1  3
 #define IN2 2
 #define ENA 5
 
 #define IN3  7
 #define IN4  4
 #define ENB  6

int a;

float R_sonar_Distance = 0.0;
float R_sonar_Distance_old = 0.0;
float R_sonar_Error = 0.0;

float L_sonar_Distance = 0.0;
float L_sonar_Distance_old = 0.0;
float L_sonar_Error = 0.0;

float F_sonar_Distance = 0.0;
float F_sonar_Distance_old = 0.0;
float F_sonar_Error = 0.0;

NewPing F_sensor(F_Sonar,F_Sonar,MaxDistance);
NewPing R_sensor(R_Sonar,R_Sonar,MaxDistance);
NewPing L_sensor(L_Sonar,L_Sonar,MaxDistance);

int DW = 420;
int RW = 140;







void read_sonar_sensor(void) //초음파 센서 값을 읽는 함수
{
   R_sonar_Distance = R_sensor.ping_cm()*10.; //각자에 맞도록 센서 번호 설정
   L_sonar_Distance = L_sensor.ping_cm()*10.;
   F_sonar_Distance = F_sensor.ping_cm()*10.;
   if( R_sonar_Distance == 0) R_sonar_Distance = MaxDistance * 10.0;
   if( L_sonar_Distance == 0) L_sonar_Distance = MaxDistance * 10.0;
   if( F_sonar_Distance == 0) F_sonar_Distance = MaxDistance * 10.0;
}
void updata_sonar_old(void) //초음파센서 옛날값
{
 R_sonar_Distance_old =  R_sonar_Distance;
 L_sonar_Distance_old =  L_sonar_Distance;
 F_sonar_Distance_old =  F_sonar_Distance;
}

void updata_sonar_error(void)
{
 R_sonar_Error =  R_sonar_Distance -  L_sonar_Distance;
 L_sonar_Error =  L_sonar_Distance -  R_sonar_Distance;
 F_sonar_Error =  F_sonar_Distance -  F_sonar_Distance;
}


void motor(int L_sp, int R_sp)
{
  Go(a,100-R_sonar_Error*3, 100+R_sonar_Error*3);
  if(R_sonar_Distance<= 100);
  Go(a,100-L_sonar_Error*3, 100+L_sonar_Error*3);
  if(L_sonar_Distance<= 100);
}


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);//속도제어
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);//3,4번 제어핀들은 핀모드를 출력으로 설정
 

}


void loop() {
  // put your main code here, to run repeatedly:
 float p_gain = 1.5;
 int motor_diff = 0;
 
 read_sonar_sensor();
 updata_sonar_error();
 updata_sonar_old();
 Serial.print(R_sonar_Error); Serial.print("\t ");
 Serial.print(L_sonar_Error); Serial.print("\t ");
 Serial.println(F_sonar_Error);

 motor_diff = R_sonar_Error*p_gain;
 motor(60 - motor_diff, 60 + motor_diff);
 delay(250); 

 //회전각도
if(angle == state) = -10;
else if (angle == 40)state = 10;
angle += state; 
}


 void Go(int a, int L_sp,int R_sp)
 {
   //전진
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 analogWrite(ENA, L_sp);
 analogWrite(ENB, R_sp); 
 delay(a);
 }
 
 //후진
 void back()
 {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 analogWrite(ENA, 100);
 analogWrite(ENB, 100);
 delay(100);
 }

 void right()
 {//right
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 analogWrite(ENA, 100);
 analogWrite(ENB, 100);
 delay(100);
 }


  void lefted()
  {
    //lefted
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 analogWrite(ENA, 100);
 analogWrite(ENB, 100);
 delay(100);
 }
