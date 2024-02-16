def selection_sort(A):
    n = len(A)
    for i in range(n-1):
        minimum = i
        for j in range(i+1, n):
            if A[minimum] > A[j]:
                minimum = j
        A[i],A[minimum] = A[minimum], A[i]