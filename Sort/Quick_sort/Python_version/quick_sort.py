"""
code writer	:	EOF
code date	:	2015.01.12
code file	:	quick_sort.c
e-mail		:	jasonleaster@gmail.com

Code description:
               Quick Sort is implemented in Python

"""

def quick_sort(A, p, r) :
    if p < r :
       q = partition(A, p, r)
       A = quick_sort(A, p, q-1)
       A = quick_sort(A, q+1, r)

    return A

# resorting in place 
def partition(A, p, r) :
    x = A[r]
    i = p-1
    for j in range(p, r) :
        if A[j] <= x :
           i += 1
           # swap A[i] and A[j]
           A[i], A[j] = A[j], A[i] 

    A[i+1], A[r] = A[r], A[i+1]

    return i+1

#-------------------testing code---------------------------
A = [13,19,9,5,12,8,7,4,21,2,6,11]

print "Before sorting A= " , A, "\n"

A = quick_sort(A,0,len(A)-1)

print "After  sorting A= " , A, "\n"

