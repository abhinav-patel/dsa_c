#include <stdio.h>
int main()
{
    
    int P[100][4];
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;
    printf("Enter number of process: ");
    scanf("%d", &n);
    printf("Enter Burst Time:\n");
   
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &P[i][1]);
        P[i][0] = i + 1;
    }
   
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++)
            if (P[j][1] < P[index][1])
                index = j;
        temp = P[i][1];
        P[i][1] = P[index][1];
        P[index][1] = temp;
 
        temp = P[i][0];
        P[i][0] = P[index][0];
        P[index][0] = temp;
    }
    P[0][2] = 0;
    
    for (i = 1; i < n; i++) {
        P[i][2] = 0;
        for (j = 0; j < i; j++)
            P[i][2] += P[j][1];
        total += P[i][2];
    }
    avg_wt = (float)total / n;
    total = 0;
    printf("P     BT     WT     TAT\n");
    .
    for (i = 0; i < n; i++) {
        P[i][3] = P[i][1] + P[i][2];
        total += P[i][3];
        printf("P%d     %d     %d      %d\n", P[i][0],
               P[i][1], P[i][2], P[i][3]);
    }
    avg_tat = (float)total / n;
    printf("Average Waiting Time= %f", avg_wt);
    printf("\nAverage Turnaround Time= %f", avg_tat);
}