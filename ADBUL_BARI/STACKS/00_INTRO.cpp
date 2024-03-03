/*
    * Works on the discipline of LIFO (Last-in First-out).
    * Real World Examples: 
        - Inserting and extracting from a can of tennis balls
        - Shunting of trains (reverses train)
        - Sometimes converting recursion to iterations we may 
          need to convert the stack and vice versa (having an 
          iterative procedure with a stack may be implemented 
          recursion through)
    * Insertion and deletion always done from top.

    ----------
    ADT Stack
    ----------
        - Data:
            ~ Space for storing elements.
            ~ Top pointer.
        - Operations:
            ~ push(x)
            ~ pop()
            ~ peek(index)
            ~ stackTop()
            ~ isEmpty()
            ~ isFull()

*/