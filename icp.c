#include <stdio.h>
#define MAX 1000
#define MIN(x,y) (((x)<(y))?(x):(y))

int n, m;
int a[MAX],b[MAX],c[MAX];
int d[MAX][MAX];

int main(){
int i,j;
int count;
while(1){
scanf("%d%d", &n, &m);
if(n==0 && m==0) break;
for(i=0; i<n; i++) scanf("%d", &a[i]);
for(i=0; i<n; i++) scanf("%d", &b[i]);
for(i=0; i<n; i++){
c[i] = (b[i] - a[i]) % m;
if(c[i]<0) c[i] += m;
}
for(j=0; j<n; j++)
d[0][j] = c[0] + m*j;
for(i=1; i<n; i++){
for(j=0; j<n; j++){
if(c[i-1]>=c[i]){
if(j == 0) d[i][0] = d[i-1][0];
else {
d[i][j] =
MIN(d[i-1][j-1]+c[i]+m-c[i-1], d[i-1][j]);
}
}
else {
if(j==n-1)
d[i][j] = d[i-1][j] + c[i]-c[i-1];
else {
d[i][j] =
MIN(d[i-1][j] + c[i]-c[i-1], d[i-1][j+1]);
}
}
}
}
count = d[n-1][0];
for(i=1; i<n; i++){
if(d[n-1][i] < count) count = d[n-1][i];
}
printf("Output %d¥n", count);
}
return 0;
}