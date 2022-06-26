#include<stdio.h>

// QUEUES - LINKED LIST BASED IMPLEMENTATION
// To implement Queues using LL, we basically have to insert at the end/tail and delete from the head OR vice-versa 

/*
PROBLEM WITH ARRAY BASED IMPLEMENETATION
(1) We can take a large enough array and use only few block of memory. As a result, we'll be left with unused memory, which is not efficient
(2) Suppose the array gets filled completely and we have to insert another element into it, we will first have to create a new larger array and copy elements from previous array into this larger array which would take time T ∝ n, i.e., O(n)
/*
