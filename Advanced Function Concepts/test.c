#include <stdio.h>
#define N 4
#define M 4
int main(){
int i,j ;
int A[N][M] , B[N][M];
for(i=0;i<N;i++){
for(j=0;j<M;j++){
printf(" Δωσε τα στοιχεια του Α(%d,%d) πινακα : ",i+1,j+1);
scanf("%d",&A[i][j]);
}
}

printf("\n Ο πινακας που δοθηκε ειναι : \n");

for(i=0; i<N; i++){
for(j=0; j<M; j++){
printf("%d ",A[i][j]);
}
printf("\n");
}

printf("\n Ο αναστροφος πινακας ειναι: \n");
for(i=0;i<N;i++){
for(j=0;j<M;j++){
printf("%d ",A[j][i]);
}
printf("\n");
}
return 0;
}