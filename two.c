#include <stdio.h>
#include <stdlib.h>
int main() {
int disk_size, n, head, i, count = 0, total = 0;
printf("Enter total number of disk blocks: ");
if(scanf("%d", &disk_size) != 1) return 0;
printf("Enter number of requests: ");
if(scanf("%d", &n) != 1) return 0;
int req[100], visited[100] = {0};
printf("Enter requests: ");
for(i = 0; i < n; i++) scanf("%d", &req[i]);
printf("Enter current head position: ");
scanf("%d", &head);
printf("\nSSTF Order of Service:\n%d", head);
while(count < n) {
int min_dist = 1e9, idx = -1;
for(i = 0; i < n; i++) {
if(!visited[i]) {
int dist = abs(head - req[i]);
if(dist < min_dist) {
min_dist = dist;
idx = i;
}
}
}
visited[idx] = 1;
total += min_dist;
head = req[idx];
printf(" -> %d", head);
count++;
}
printf("\nTotal number of head movements: %d\n", total);
return 0;
}
