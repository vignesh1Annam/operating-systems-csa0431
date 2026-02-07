#include <stdio.h>

int main() {
    int n, i, time=0, completed=0;
    int bt[20], at[20], pr[20], rt[20];
    int wt[20], tat[20], ct[20];
    float avgwt=0, avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        printf("Enter AT BT Priority for P%d: ", i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    while(completed < n) {
        int idx = -1;
        int high = 9999;

        for(i=0;i<n;i++) {
            if(at[i] <= time && rt[i] > 0 && pr[i] < high) {
                high = pr[i];
                idx = i;
            }
        }

        if(idx != -1) {
            rt[idx]--;
            time++;

            if(rt[idx]==0) {
                completed++;
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                avgwt += wt[idx];
                avgtat += tat[idx];
            }
        }
        else {
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tPR\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], pr[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat/n);

    return 0;
}
