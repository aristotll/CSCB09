#include <stdio.h>
#include <stdlib.h>

struct item {
    int key;
    int data;
    struct item *next;
};

struct item *head = NULL;

void filllist() {
    static struct item a, b, c, d;
    head = &a;
    a.key = 5;
    a.data = 0;
    a.next = &b;
    b.key = 20;
    b.data = 2;
    b.next = &c;
    c.next = &d;
    c.key = 22;
    c.data = 6;
    d.key = 38;
    d.data = 3;
    d.next = NULL;
}


int search(int key) {
    struct item *p = head;
    while (p != NULL && p->key < key)
        p = p->next;
    if (p && p->key == key)
        return p->data;
    return -1;
}

int main () {
    filllist();
    printf("%d\n", search(20));
    printf("%d\n", search(38));
    printf("%d\n", search(138));
    printf("%d\n", search(8));
    printf("%d\n", search(5));
    /* expected output: 2, 3, -1, -1, 0 */
    return(0);
}
