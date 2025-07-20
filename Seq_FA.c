#include <stdio.h>

int main() {
    int disk[50] = {0};  // 0 = unallocated
    int start, len, i, j, flag;

    while (1) {
        printf("\nEnter the starting block and the length of the file: ");
        scanf("%d %d", &start, &len);

        flag = 0;
        for (i = start; i < start + len; i++) {
            if (disk[i] == 1) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            for (i = start; i < start + len; i++) {
                disk[i] = 1;
            }

            printf("File allocated successfully. Blocks allocated:\n");
            for (i = start; i < start + len; i++) {
                printf("%d ", i);
            }
            printf("\n");
        } else {
            printf("File cannot be allocated. Block %d is already allocated.\n", i);
        }

        char choice;
        printf("Do you want to allocate another file? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
            break;
    }

    return 0;
}

