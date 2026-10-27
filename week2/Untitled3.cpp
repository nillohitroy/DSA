#include <stdio.h>
#include <stdlib.h>
struct Soldier {
    int id;
    struct Soldier* next;
};
struct Soldier* createSoldier(int id) {
    struct Soldier* newSoldier = (struct Soldier*)malloc(sizeof(struct Soldier));
    newSoldier->id = id;
    newSoldier->next = NULL;
    return newSoldier;
}
int findChosenSoldier(int n, int k) {
    if (n == 1) return 1;
    struct Soldier* head = createSoldier(1);
    struct Soldier* prev = head;
    
    for (int i = 2; i <= n; i++) {
        prev->next = createSoldier(i);
        prev = prev->next;
    }
    prev->next = head; 
    struct Soldier* curr = head;
    prev = head;
    
    
    while (prev->next != head) {
        prev = prev->next;
    }

    
    while (curr->next != curr) {
        
        for (int count = 1; count < k; count++) {
            prev = curr;
            curr = curr->next;
        }
        
        
        prev->next = curr->next;
        printf("Soldier %d is eliminated.\n", curr->id);
        
        struct Soldier* temp = curr;
        curr = curr->next;
        free(temp); 
    }

    int remainingSoldierId = curr->id;
    free(curr); 
    return remainingSoldierId;
}

int main() {
    int n, k;

    
    printf("Enter total number of soldiers (n): ");
    scanf("%d", &n);
    printf("Enter the elimination count step (k): ");
    scanf("%d", &k);

    if (n <= 0 || k <= 0) {
        printf("Please enter positive integers greater than 0.\n");
        return 1;
    }

    int chosenOne = findChosenSoldier(n, k);
    printf("\n--> Soldier %d is chosen to get reinforcements!\n", chosenOne);

    return 0;
}


