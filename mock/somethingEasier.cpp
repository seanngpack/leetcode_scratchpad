#include <iostream>

int main() {
    return 0;
}

node.val = 7
node.next = 0

result.next = function

7 -> 0 -> 8 -> 7

length 4 -> 3
length 3 -> 4
result 7

right 2 -> 4
right 1 -> 6
10
0

right 1 -> 2
right 0 -> 5
7 + 1
8

right 0 -> 7

7


// (7 -> 2 -> 4 -> 3) +
//      (5 -> 6 -> 4)
//  7 -> 8 -> 0 -> 7

// (0) (2->4)
// (2->4)

// (null) (2->4)
// (2->4)

// (0) null
// 0

// return a linked list with the added numbers
// addition is happening from right->left
// problem: uneven lists, how to handle the longer list? Don't forget, say you have 6+4, carry the 1 over
// problem: addition is happening from right->left
  // Approach: could reverse the lists and then, cheating
  // Approach:
// how do I traverse through the linked list? let's do this recursively

int carry = 0;


int add(Node* node1, Node* node2 ) {

    if (length of node1 > node2) add_helper(node1, node2, diff)
    if (length of node2 > node1) add_helper(node2, node1, diff)

}

//
Node* add_helper(Node* node1, Node* node2, int diff) {
    // base case
    if (node1.next == nullptr && node2.next == nullptr) {
        int sum = node1.val + node2.val;
        carry = sum / 10;
        Node* temp = new Node(sum % 10);
        return temp;
    }

    Node* node;
    if (diff > 0) {
        return node.next = add_helper(hode1.next, node2);
    }
    return node.next = add_helper(hode1.next, node2.next);

}

// linked list recursion isnt intuitive