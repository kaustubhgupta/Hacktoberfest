/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/


//beats 100% java solutions 
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null) return head; //this condition imp when head is null like [] ...
        int count=0;    //basically count here is used to count total length of head
        ListNode a=head;
        ListNode temp;
        while(a!=null){
            count++;
            a=a.next;
        }
        a=head;
        k=k%count;   //if k is greater than len of head then ...
        if(k==0){
            return head;
        }
        else{
            int val=count-k-1;
            while(val!=0){
                a=a.next;
                val--;
            }
            temp=a.next;
            a.next=null;   //this also effects head too (now head becomes [1,2,3] instead of [1,2,3,4,5])
            
            a=temp;      //again fresh use of a by allocating temp
            while(a.next!=null){
                a=a.next;
            }
            a.next=head;
        }
  //    System.out.println(count+" "+k);
        return temp;
        
    }
}
