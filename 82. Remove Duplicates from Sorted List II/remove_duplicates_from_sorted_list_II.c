#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_s {
    int val;
    struct list_node_s *next;
} list_node_t;

void insert_node(list_node_t **root, int val) {
    list_node_t *cur = *root;
    list_node_t *new = (list_node_t *) malloc(sizeof(list_node_t));

    if (new != NULL) {
        new->val = val;
        new->next = NULL;
    } else {
        printf("Failed to allocate the memory of node_t: %d not inserted\n", val);
    }

    if (cur == NULL) {
        *root = new;
    } else {
        if (val <= cur->val) {
            new->next = *root;
            *root = new;
        } else {
            while (cur->next != NULL && val > cur->next->val) {
                cur = cur->next;
            }
            new->next = cur->next;
            cur->next = new;
        }
    }

    return ;
}

void traverse(list_node_t *root) {
    list_node_t *scan = root;
    while (scan != NULL) {
        printf("%d->", scan->val);
        scan = scan->next;
    }
    printf("NULL\n");

    return ;
}

list_node_t *delete_duplicates(list_node_t *head) {
    list_node_t *cur = head;
    list_node_t *prev = NULL;
    list_node_t *rm = NULL;
    int mark_for_rm = 0;

    if (cur != NULL) {
        prev = head;
    }
    while (cur != NULL) {
        while (cur->next != NULL && cur->val == cur->next->val) {
            mark_for_rm = 1;
            rm = cur;
            if (prev == cur) {
                prev = cur->next;
                head = prev;
            } else {
                prev->next = cur->next;
            }
            cur = cur->next;
            free(rm);
        }
        if (mark_for_rm == 1) {
            mark_for_rm = 0;
            rm = cur;
            if (prev == cur) {
                prev = cur->next;
                head = prev;
            } else {
                prev->next = cur->next;
            }
            cur = cur->next;
            free(rm);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }

    return head;
}

#define TEST_PATTERN    (4)
int main()
{
    list_node_t *root = NULL;
#if (TEST_PATTERN == 1)
    insert_node(&root, 100);
    insert_node(&root, 1000);
    insert_node(&root, 1000);
    insert_node(&root, 1000);
    insert_node(&root, 10);
    insert_node(&root, 10);
    insert_node(&root, 9);
    insert_node(&root, 8);
    insert_node(&root, 9);
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 1);
#elif (TEST_PATTERN == 2)
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 2);
#elif (TEST_PATTERN == 3)
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 3);
#elif (TEST_PATTERN == 4)
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 2);
    insert_node(&root, 2);
    insert_node(&root, 2);
    insert_node(&root, 3);
#endif
    traverse(root);

    traverse(delete_duplicates(root));

    return 0;
}
