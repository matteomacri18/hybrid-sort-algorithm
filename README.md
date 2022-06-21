# hybrid-sort-algorithm
Implementation HybridSort Algorithm - from Steven S. Skenia - The algorithm design manual book

Experiment where to implementation HybridSort by measuring the running time experimental for inputs of increasing length, with multiple repetitions for
the same length. </br>

Since the idea of the algorithm is to sort, recursively, arrays
smaller and smaller (the pieces of the original array), at some point, during
recursion will result in an array smaller than k. In
that moment it is no longer convenient to call MergeSort, but it is worthwhile
call InsertionSort.

![alt text](https://docs.google.com/spreadsheets/d/e/2PACX-1vQSqS7chAYFrE6QcXhZuugiudJSxP7eKAYV8ig4SJ30r_E5Eccf0BTxYF5I33WNpA/pubchart?oid=1029720362&format=image)
