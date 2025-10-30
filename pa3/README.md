[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.

/////////////////////////////////////////////////
Testing Report

I tested three regions for this PA, including the Data class, Hashtable, and AVL tree. For the data class, I tested the setter and getter functions to ensure they perform well and return the correct value. From this testing, the assertion returns true. For the Hashtable, I inserted the key "1234" to use find() and retrieve the data associated with that key. Another case with this involves a key "5555" that doesn't return anything since it doesn't exist. The assert function returns true in both cases. Now, for the AVL, I wasn't able to use assert because my AVL member functions aren't designed to return anything. However, I was still able to test it with a case where existing categories (Cat1 & Cat2) exist and another where a category doesn't exist (Cat0). From the result, it passes the test. 
