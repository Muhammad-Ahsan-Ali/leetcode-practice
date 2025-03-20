
void reHeapDown(vector<int> &array, int n, int i)
{
    int j;
    while (((i * 2) + 1) < n) // While left child exists
    {
        j = (i * 2) + 1; // Left child index

        if (j + 1 < n && array[j] < array[j + 1]) // If right child is larger
        {
            j = j + 1; // Move to the right child
        }

        if (array[i] >= array[j]) // If heap property is maintained, break
        {
            break;
        }

        swap(array[i], array[j]); // Swap and continue
        i = j;                    // Move index to the child
    }
}

void heapSort(vector<int> &array)
{
    int n = array.size();

    // Step 1: Build Max Heap
    for (int i = (n / 2) - 1; i >= 0; i--) // Start from last non-leaf node
    {
        reHeapDown(array, n, i);
    }

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) // Swap max element with last element
    {
        swap(array[0], array[i]); // Move largest to the end
        reHeapDown(array, i, 0);  // Reheapify with reduced size
    }
}
