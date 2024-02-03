/*
    * Reverse a given Linked List. (Return the new head)

        1. BRUTE FORCE:
            temp = head, stack st
            while (temp != NULL)
                st.push(temp --> data)
                temp = temp --> next
            temp = head
            while (temp != NULL)
                temp --> data = st.top()
                st.pop()
                temp = temp --> next

        - TC = O(2N) - SC = O(N) --> Due to creation of stack. (Needs to be optimised)

        2. OPTIMAL:
            temp = head, prev = NULL
            while(temp != NULL)
                front = temp --> next
                temp --> next = prev
                prev = temp
                temp = front
            return prev
            - TC = O(N) - SC = O(1) 

        3. RECURSIVE: (Breaks into smaller problems then backpropagates)
            reverse(head)
                    if(head == NULL || head -> next == NULL)
                        return head     // 1 or 0 Nodes.
                Node* newHead = reverse(head -> next)
                Node* front = head -> next
                front -> next = head
                head -> next = NULL
                return head
            - TC = O(N) - O(N) (recursive stack space.)
                

*/