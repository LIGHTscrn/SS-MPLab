#include <stdio.h>

typedef struct {
    int pid;
    int at;
    int bt;
    int ct;
    int rt;
    int wt;
    int tat;
    int completed;
} Process;

int main() {
    int n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter time quantum: ");
    scanf("%d", &tq);

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Arrival Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].at);

        printf("Burst Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].bt);

        p[i].rt = p[i].bt;
        p[i].completed = 0;
    }

    int done = 0, time = 0;
    int queue[100], front = 0, rear = 0;
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    // Add initial processes that arrived at time 0
    for (int i = 0; i < n; i++) {
        if (p[i].at == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (done < n) {
        if (front == rear) {
            time++;
            for (int i = 0; i < n; i++) {
                if (p[i].at <= time && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];

        int exec_time = (p[idx].rt > tq) ? tq : p[idx].rt;
        time += exec_time;
        p[idx].rt -= exec_time;

        // Check for newly arrived processes during execution
        for (int i = 0; i < n; i++) {
            if (p[i].at > time - exec_time && p[i].at <= time && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (p[idx].rt == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = 1;
            done++;
        } else {
            queue[rear++] = idx;  // Requeue
        }
    }

    float total_wt = 0, total_tat = 0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turn Around Time: %.2f\n", total_tat / n);

    return 0;
}

