// Read: https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/

// An efficient approach that requires O(n) time is, using a single scan similar to bubble sort 
// and then maintain a flag for representing which order () currently we are. 
// If the current two elements are not in that order then swap those elements otherwise not.

void zigZagList(Node* head)
{
    // If flag is true, then next
    // node should be greater
    // in the desired output.
    bool flag = true;
 
    // Traverse linked list starting from head.
    Node* current = head;
    while (current->next != NULL) {
        if (flag) /* "<" relation expected */
        {
            /* If we have a situation like A > B > C
               where A, B and C are consecutive Nodes
               in list we get A > B < C by swapping B
               and C */
            if (current->data > current->next->data)
                swap(current->data, current->next->data);
        }
        else /* ">" relation expected */
        {
            /* If we have a situation like A < B < C where
               A, B and C  are consecutive Nodes in list we
               get A < C > B by swapping B and C */
            if (current->data < current->next->data)
                swap(current->data, current->next->data);
        }
 
        current = current->next;
        flag = !flag; /* flip flag for reverse checking */
    }
}