#include <stdio.h>
#include <stdlib.h>

struct Node {
    int pid, start, length;
    struct Node* next;
};
typedef struct Node Node;

void alloc(Node* head, int pid, int length) {
    Node* proc = (Node*)malloc(sizeof(Node));
    Node* hole = head->next;
    proc->pid = pid;
    proc->start = hole->start;
    proc->length = length;
    hole->start += length;
    hole->length -= length;
    if (hole->length <= 0) {
        proc->next = hole->next;
        free(hole);
    } else {
        proc->next = hole;
    }
    head->next = proc;
}

int dealloc(Node* head, int pid) {
    Node* pre = head;
    Node* temp = head->next;
    while (temp != NULL) {
        if (temp->pid != pid) {
            pre = temp;
            temp = temp->next;
            continue;
        }
        temp->pid = -1;
        if (temp->next->pid == -1) {
            Node* nt = temp->next;
            temp->length += nt->length;
            temp->next = nt->next;
            free(nt);
        }
        if (pre->pid == -1) {
            pre->length += temp->length;
            pre->next = temp->next;
            free(temp);
        }
        return 1;
    }
    return 0;
}

Node* firstFit(Node* head, int val) {
    Node* temp = head;
    Node* temp1 = temp;
    temp = temp->next;
    while (temp != NULL) {
        if (temp->pid < 0) { // hole finding
            if ((temp->length) - val >= 0) {
                return temp1;
            }
        }
        temp1 = temp;
        temp = temp->next;
    }
    return NULL;
}

Node* bestFit(Node* head, int val) {
    Node* temp = head;
    Node* temp1 = temp;
    Node* temp2 = NULL;
    temp = temp->next;
    int var = -1; // variable to store length of hole
    while (temp != NULL) {
        if (temp->pid < 0) { // hole finding
            if ((temp->length) - val == 0) {
                return temp1;
            } else if ((temp->length) - val > 0) {
                if ((var - (temp->length) > 0 && var != -1) || var == -1) {
                    var = temp->length;
                    temp2 = temp1;
                }
            }
        }
        temp1 = temp;
        temp = temp->next;
    }
    return temp2;
}

Node* worstFit(Node* head, int val) {
    Node* temp = head;
    Node* temp1 = temp;
    Node* temp2 = NULL;
    temp = temp->next;
    int var = -1; // variable to store length of hole
    while (temp != NULL) {
        if (temp->pid < 0) { // hole finding
            if ((temp->length) - val > 0) {
                if ((var - (temp->length) < 0 && var != -1) || var == -1) {
                    var = temp->length;
                    temp2 = temp1;
                }
            }
        }
        temp1 = temp;
        temp = temp->next;
    }
    return temp2;
}

void printL(Node* head) {
    Node* temp = head->next;
    while (temp != NULL) {
        printf("PID: %d\tStart: %d\tLength: %d\n", temp->pid, temp->start, temp->length);
        temp = temp->next;
    }
}

void printN(Node* node) {
    if (node != NULL) {
        printf("PID: %d\tStart: %d\tLength: %d\n", node->pid, node->start, node->length);
    }
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->pid = head->start = head->length = -2;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->pid = -1;
    head->next->start = 0;
    head->next->length = 100;

    int choice, pid, length, dl;	
Node *temp;
    printf("Memory Allocation Strategies:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("First Fit\n");
            printf("Enter Process ID: ");
            scanf("%d", &pid);
            printf("Enter Process Length: ");
            scanf("%d", &length);
            alloc(head, pid, length);
			// Print memory layout
			printf("Memory Layout after Allocation:\n");
			printL(head);

			printf("Enter Process ID to Deallocate: ");
			scanf("%d", &pid);

			dl = dealloc(head, pid);

			// Print memory layout after deallocation
			printf("Memory Layout after Deallocation:\n");
			printL(head);
			printf("Deallocated: %d\n", dl);
			temp = firstFit(head, length);
			printf("Hole using the selected strategy:\n");
			printN(temp);
            break;
        case 2:
            printf("Best Fit\n");
            printf("Enter Process ID: ");
            scanf("%d", &pid);
            printf("Enter Process Length: ");
            scanf("%d", &length);
            alloc(bestFit(head, length), pid, length);
			// Print memory layout
			printf("Memory Layout after Allocation:\n");
			printL(head);

			printf("Enter Process ID to Deallocate: ");
			scanf("%d", &pid);

			dl = dealloc(head, pid);

			// Print memory layout after deallocation
			printf("Memory Layout after Deallocation:\n");
			printL(head);
			printf("Deallocated: %d\n", dl);
			temp = bestFit(head, length);
			printf("Hole using the selected strategy:\n");
			printN(temp);
            break;
        case 3:
            printf("Worst Fit\n");
            printf("Enter Process ID: ");
            scanf("%d", &pid);
            printf("Enter Process Length: ");
            scanf("%d", &length);
            alloc(worstFit(head, length), pid, length);
			// Print memory layout
			printf("Memory Layout after Allocation:\n");
			printL(head);

			printf("Enter Process ID to Deallocate: ");
			scanf("%d", &pid);

			dl = dealloc(head, pid);

			// Print memory layout after deallocation
			printf("Memory Layout after Deallocation:\n");
			printL(head);
			printf("Deallocated: %d\n", dl);
			temp = worstFit(head, length);
			printf("Hole using the selected strategy:\n");
			printN(temp);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    

    return 0;
}
