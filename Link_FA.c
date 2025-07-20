#include <stdio.h>

int main() {
    int disk[50] = {0};
    int start, len, i, count;

    while (1) {
        printf("\nEnter the starting block and length of the file: ");
        scanf("%d %d", &start, &len);

        if (disk[start] == 1) {
            printf("Starting block already allocated. Cannot allocate file.\n");
        } else {
            count = 0;
            for (i = 0; i < 50 && count < len; i++) {
                if (disk[i] == 0)
                    count++;
            }

            if (count >= len) {
                count = 0;
                disk[start] = 1;
                printf("File allocated at: %d -> ", start);
                for (i = 0; i < 50 && count < len - 1; i++) {
                    if (disk[i] == 0 && i != start) {
                        disk[i] = 1;
                        printf("%d -> ", i);
                        count++;
                    }
                }
                printf("NULL\n");
            } else {
                printf("Not enough space to allocate file.\n");
            }
        }

        char choice;
        printf("Do you want to allocate another file? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
            break;
    }

    return 0;
}

