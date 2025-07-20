#include <stdio.h>

struct Process {
    int pid, at, bt, ct, tat, wt;
};

void sortByArrival(struct Process p[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (p[i].at > p[j].at) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Arrival Time for P%d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    sortByArrival(p, n);

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].at)
            time = p[i].at;
        p[i].ct = time + p[i].bt;
        time = p[i].ct;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    printf("Average Waiting Time: %.2f\n", totalWT/n);
    printf("Average Turn Around Time: %.2f\n", totalTAT/n);

    return 0;
}

