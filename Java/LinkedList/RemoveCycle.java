// Function to identify and remove cycle in a linked list using hashing
    public static void removeCycle(Node head)
    {
        Node prev = null;        // previous pointer
        Node curr = head;        // main pointer
 
        // maintain a set to store visited nodes
        Set<Node> set = new HashSet<>();
 
        // traverse the list
        while (curr != null)
        {
            // set the previous pointer to null if the current node is seen before
            if (set.contains(curr))
            {
                prev.next = null;
                return;
            }
 
            // insert the current node into the set
            set.add(curr);
 
            // update the previous pointer to the current node and
            // move the main pointer to the next node
            prev = curr;
            curr = curr.next;
        }
    }
