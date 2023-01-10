#include<stdio.h>
#include<stdlib.h>// rand()원형 정의
#include<time.h>//time()의 원형 정의

 int score[4][5];

int main(void){

srand((unsigned int)time(NULL));
for (int i = 0;i < 5;i++) {
score[0][i] = i+1;
score[1][i] = rand() % 100; //난수범위 지정
score[2][i] = rand() % 100;
score[3][i] = rand() % 100;
}
    
    double averages[5] = { 0, };
  //  int i, j;
 
    for (int i=0; i<4; i++) {
        for (int j=0; j < 5; j++) {
            score[i][5] += score[i][j];
            averages[j] += score[i][j];
        }
        averages[5] += score[i][5];
    }
    for (int j = 0; j < 5; j++)
        averages[j] /= 5;
 
    printf("       학번   수학  국어  영어  \n");
 
    for (int i = 0; i < 5; i++) {
        printf(" 학 생  %d번: ", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("%d ", score[i][j]);
        }
        printf("\n");
    }
    printf("과목 별 평균:   ");
    for (int j = 0; j < 5; j++){
        printf("%5.1f ", averages[j]);
	}
}
