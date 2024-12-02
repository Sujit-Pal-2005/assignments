# Statement

Creat AVL tree for the following operations:

1. Insert(key)

2. Delete(key)

3. Search(key)

4. PrintAVL() : Do a lever order traversal and print the tree as we draw it on paper.

**Input & Output**
```
Enter 1 for insert key 
 Enter 2 for delete key
 Enter 3 for search key
 Enter 4 for display
  Enter any other for exit
Enter choice:1
 Enter no of key:12
Enter Keys:8 9 10 2 1 5 3 6 4 7 11 12
Enter choice:4
                5
        3               8
    2       4       6       10
  1                   7   9   11
                               12 

Enter choice:3
 Enter key :3
The key is present . And the depth is 1
Enter choice:2
 Enter key :3
Enter choice:4
        8
    5       10
  2   6   9   11
 1 4   7       12

Enter choice:2
 Enter key :11
Enter choice:4
        8
    5       10
  2   6   9   12
 1 4   7

Enter choice:2
 Enter key :8
Enter choice:4
        9
    5       10       
  2   6       12
 1 4   7

Enter choice:2
 Enter key :12
Enter choice:4
        6
    5       9
  2       7   10
 1 4

Enter choice:2
 Enter key :3
The key is not present.
Enter choice:3 
 Enter key :4
The key is present . And the depth is 3
Enter choice:5
```