/*

You are given a doubly linked list consisting of N nodes and an integer value X.
Your task is to delete all nodes from the linked list whose value is equal to X, and then return the modified linked list.
If after deletion the linked list becomes empty, print -1.

*/

/*
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
}
*/

Node* deleteAllOccurrences(Node* head, int X) {
    if (head == nullptr) return head;
    Node dummy(0);
    dummy.next = head;
    Node* prevNode = &dummy;
    Node* cur = prevNode->next;
    Node* nextNode;
    while(cur != nullptr) {
        nextNode = cur->next;
        if (cur->data == X) {
            prevNode -> next = nextNode;
            if (nextNode != nullptr)
                nextNode ->prev = prevNode;
            delete cur;
        } else {
            prevNode = cur;
        }
        cur = nextNode;
    }
    return dummy.next;
}
