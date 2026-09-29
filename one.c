#include <stdio.h>
#include <stdlib.h>
int main() {
int n = 5, m = 4;
int alloc[5][4] = {
{0, 0, 1, 2},
{1, 0, 0, 0},
{1, 3, 5, 4},
{0, 6, 3, 2},
{0, 0, 1, 4}
};
int max_m[5][4] = {
{0, 0, 1, 2},
{1, 7, 5, 0},
{2, 3, 5, 6},
{0, 6, 5, 2},
{0, 6, 5, 6}
};
int avail[4] = {1, 5, 2, 0};
int need[5][4];
int i, j, k;
for(i = 0; i < n; i++) {
for(j = 0; j < m; j++) {
need[i][j] = max_m[i][j] - alloc[i][j];
}
}
printf("Need Matrix:\nProcess\tA B C D\n");
for(i = 0; i < n; i++) {
printf("P%d\t", i);
for(j = 0; j < m; j++) {
printf("%d ", need[i][j]);
}
printf("\n");
}
int work[4];
for(j = 0; j < m; j++) work[j] = avail[j];
int finish[5] = {0};
int safe_seq[5];
int count = 0;
for(k = 0; k < n; k++) {
for(i = 0; i < n; i++) {
if(!finish[i]) {
int possible = 1;
for(j = 0; j < m; j++) {
if(need[i][j] > work[j]) {
possible = 0;
break;
}
}
if(possible) {
for(j = 0; j < m; j++) work[j] += alloc[i][j];
safe_seq[count++] = i;
finish[i] = 1;
}
}
}
}
if(count == n) {
printf("\nSystem is in SAFE STATE.\nSafe sequence: ");
for(i = 0; i < n; i++) {
printf("P%d", safe_seq[i]);
if(i < n - 1) printf(" -> ");
}
printf("\n");
} else {
printf("\nSystem is NOT in a safe state!\n");
}
return 0;
}
