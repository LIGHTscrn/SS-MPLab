#include <stdio.h>

int main() {
    int disk[50] = {0};
    int indexBlock, blocksNeeded, blockNums[50], i, count = 0;

    while (1) {
        printf("\nEnter index block: ");
        scanf("%d", &indexBlock);

        if (disk[indexBlock] == 1) {
            printf("Index block is already allocated.\n");
            continue;
        }

        printf("Enter number of blocks needed: ");
        scanf("%d", &blocksNeeded);

        printf("Enter the blocks: ");
        count = 0;
        for (i = 0; i < blocksNeeded; i++) {
            scanf("%d", &blockNums[i]);
            if (disk[blockNums[i]] == 0) {
                count++;
            }
        }

        if (count == blocksNeeded) {
            disk[indexBlock] = 1;
            for (i = 0; i < blocksNeeded; i++) {
                disk[blockNums[i]] = 1;
            }
            printf("File Allocated at index block %d\n", indexBlock);
            printf("Blocks allocated: ");
            for (i = 0; i < blocksNeeded; i++) {
                printf("%d ", blockNums[i]);
            }
            printf("\n");
        } else {
            printf("Some blocks are already allocated. File cannot be allocated.\n");
        }

        char choice;
        printf("Do you want to allocate another file? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
            break;
    }

    return 0;
}

