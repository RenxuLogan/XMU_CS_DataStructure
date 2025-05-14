#include <iostream>
using namespace std;

const int max_size = 10001;
int minHeap[max_size];

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void heapUp(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (minHeap[parent] > minHeap[index])
        {
            swap(minHeap[parent], minHeap[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}
void heapDown(int size, int index)
{
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int min = index;
        if (left < size && minHeap[left] < minHeap[min])
        {
            min = left;
        }
        if (right < size && minHeap[right] < minHeap[min])
        {
            min = right;
        }
        if (min == index)
        {
            break;
        }
        swap(minHeap[index], minHeap[min]);
        index = min;
    }
}

void insert(int *size, int val)
{
    if (*size == max_size)
    {
        return;
    }
    minHeap[*size] = val;
    heapUp(*size);
    (*size)++;
}

int pop(int *size)
{
    if (*size == 0)
    {
        return -1;
    }
    int res = minHeap[0];
    minHeap[0] = minHeap[*size - 1];
    (*size)--;
    heapDown(*size, 0);
    return res;
}
int main()
{
    int n;
    int ans = 0;
    cin >> n;
    int size = 0;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert(&size, val);
    }

    while (size > 0)
    {
        int a = pop(&size);
        if (size > 0)
        {
            int b = pop(&size);
            ans += a + b;
            insert(&size, a + b);
        }
        else
        {
            break;
        }
    }

    cout << ans;
    return 0;
}