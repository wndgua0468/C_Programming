#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void score_gene();
void arr_prt();
void ranking();
void mean_score();

int Std_score[4][5];

int main()
{
score_gene();
arr_prt();
ranking();
mean_score();
}

void score_gene() {
srand((unsigned)time(NULL));
for (int i = 0;i < 5;i++) {
Std_score[0][i] = i+1;
Std_score[1][i] = rand() % 100;
Std_score[2][i] = rand() % 100;
Std_score[3][i] = rand() % 100;
}
}
void arr_prt() {
printf("\n학번\t");
for (int i = 0;i < 5;i++) printf("%d\t", Std_score[0][i]);
printf("\n수학\t");
for (int i = 0;i < 5;i++) printf("%d\t", Std_score[1][i]);
printf("\n국어\t");
for (int i = 0;i < 5;i++) printf("%d\t", Std_score[2][i]);
printf("\n영어\t");
for (int i = 0;i < 5;i++) printf("%d\t", Std_score[3][i]);
printf("\n\n");
}
void ranking() {
int score_rank[3][2];
int score_rank_who[3][2];
for (int i = 0;i < 3;i++) {
for (int j = 0;j < 5;j++) {
if (score_rank[i][0] <= Std_score[i+1][j]) {
score_rank[i][1] = score_rank[i][0];
score_rank[i][0] = Std_score[i+1][j];
score_rank_who[i][1] = score_rank_who[i][0];
score_rank_who[i][0] = j+1;
}
else if (score_rank[i][1] <= Std_score[i + 1][j]) {
score_rank[i][1] = Std_score[i + 1][j];
score_rank_who[i][1] = j+1;
}
}
}

for (int i = 0;i < 3;i++) {
if (i == 0) printf("수학 등수\n");
if (i == 1) printf("국어 등수\n");
if (i == 2) printf("영어 등수\n");
printf("1등 : %d번, %d점\n",score_rank_who[i][0],score_rank[i][0]);
printf("2등 : %d번, %d점\n", score_rank_who[i][1], score_rank[i][1]);
printf("\n\n");
}

}
void mean_score() {

for (int i = 0;i < 3;i++) {
int mean = 0;
if (i == 0) printf("수학 평균 = ");
if (i == 1) printf("국어 평균 = ");
if (i == 2) printf("영어 평균 = ");
for (int j = 0;j < 5;j++) mean += Std_score[i + 1][j];
mean /= 5;
printf("[%d]\n", mean);
}
}
