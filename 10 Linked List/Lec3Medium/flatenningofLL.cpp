#include <bits/stdc++.h>
#include <iostream>
// So i am not going to draw the full LL in here i will just paste the code so
// that you can see it

// Naive Approach : Although these are all sorted but i don't think of any
// single pass sorting algorithm for this, i am thinking to first convert it a
// single LL and then apply mrege sort on it

// Traversing it like a 2D array and then sorting it
// So that approach will take extra space and time but we didn't take the
// advnatage of the fact that the LL were already sorted, so think of it as that
// can we merge two LL,s, like merging two LL but for child pointer and keep on
// calling the recursion till we get the final answer

using namespace std;
//  /* Merge the two linked lists in a particular
//      order based on the data value */
//     ListNode* merge(ListNode* list1, ListNode* list2){
//         /* Create a dummy node as a
//         placeholder for the result */
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* res = dummyNode;

//         // Merge the lists based on data values
//         while(list1 != NULL && list2 != NULL){
//             if(list1->val < list2->val){
//                 res->child = list1;
//                 res = list1;
//                 list1 = list1->child;
//             }
//             else{
//                 res->child = list2;
//                 res = list2;
//                 list2 = list2->child;
//             }
//             res->next = NULL;
//         }

//         // Connect the remaining elements if any
//         if(list1){
//             res->child = list1;
//         } else {
//             res->child = list2;
//         }

//         // Break the last node's link to prevent cycles
//         if(dummyNode->child){
//             dummyNode->child->next = NULL;
//         }

//         return dummyNode->child;
//     }

// public:
//     // Function to flatten a linked list with child pointers
//     ListNode* flattenLinkedList(ListNode* head) {
//         // If head is null or there is no next node
//         if(head == NULL || head->next == NULL){
//             return head; // Return head
//         }

//         // Recursively flatten the rest of the linked list
//         ListNode* mergedHead = flattenLinkedList(head->next);

//         // Merge the lists
//         head = merge(head, mergedHead);
//         return head;
//     }
// };
int main(

) {
  return 0;
}