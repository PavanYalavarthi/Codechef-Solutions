/*
You are given the head of a singly linked list A of length N. The values in the list are A1, Az,..., An respectively. You are also given two integers L and R. You need to reverse the nodes of the list from position L to position R.
*/

/*struct Node {
	int val;
	struct Node* next;
	Node(int x){
		val = x;
		next = NULL;
	}
};*/

Node* reverseSegment(Node* head, int L, int R) {
    if (head == nullptr || L == R) return head;
    Node dummy(0);
    dummy.next = head;
    Node* prev = &dummy;
    for(int i=1; i < L; i++)
        prev = prev -> next;
    
    Node* curr = prev ->next;
    Node* nextNode;
    for(int i = 0; i < R - L; i++) {
        nextNode = curr -> next;
        curr -> next = nextNode -> next;
        nextNode ->next = prev -> next;
        prev->next = nextNode;
    }
    return dummy.next;
}
