#include <stdio.h>

struct Process {
    int pid, at, bt, prio, ct, tat, wt, rt, remaining_bt, completed;
};

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
        printf("Priority for P%d (lower is higher priority): ", i + 1);
        scanf("%d", &p[i].prio);
        p[i].remaining_bt = p[i].bt;
        p[i].completed = 0;
    }

    int time = 0, completed = 0;
    float totalWT = 0, totalTAT = 0;

    while (completed < n) {
        int idx = -1;
        int highest = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && !p[i].completed && p[i].prio < highest && p[i].remaining_bt > 0) {
                highest = p[i].prio;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].remaining_bt--;
            if (p[idx].remaining_bt == 0) {
                p[idx].ct = time + 1;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                totalWT += p[idx].wt;
                totalTAT += p[idx].tat;
                p[idx].completed = 1;
                completed++;
            }
        }

        time++;
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].prio, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Average Waiting Time: %.2f\n", totalWT/n);
    printf("Average Turn Around Time: %.2f\n", totalTAT/n);

    return 0;
}

