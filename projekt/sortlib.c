//
// Created by dami on 21.05.16.
//

#include "sortlib.h"

void insertSort(int a[], int length)
{
    int i, j, value;

    for (i = 1; i < length; ++i) {
        value = a[i];
        for (j = i - 1; j >= 0 && a[j] > value; --j)
            a[j + 1] = a[j];
        a[j + 1] = value;
    }
}
void selectSort(int t[], int n)
{
    int i = n;
    for (i = n; i >= 2; i--)
    {
        int max = maxInd(i, t);
        if (max != i - 1)
            swap(&t[i - 1], &t[max]);
    }
}
void bubbleSort(int *arr, int len)
{
    int i, j;
    for( i = 0; i < len; i++ )
    {
        for( j = 0; j < len - 1; j++ )
        {
            if( arr[ j ] > arr[ j + 1 ] )
                swap( &arr[ j ], &arr[ j + 1 ] );

        }
    }
}

void quickSort(int *arr, int left, int right)
{
    srand(time(NULL));
    int i,j;
    int pivot;
    pivot=arr[rand()%(right-left)+left+1];
    i = left;
    j = right;
    do
    {
        while (arr[i] < pivot) ++i;
        while (arr[j] > pivot) --j;
        if (i<=j)
        {
            swap(&arr[i], &arr[j]);
            ++i;
            --j;
        }
    } while(i < j);
    if (left < j) quickSort(arr, left, j);
    if (right > i) quickSort(arr, i, right);
}

/* heap sort procedures set */
void heapSort(int *array, int size) {
    int temp, i;

    generateHeap(array, size);

    for(i = size-1; i > 0; i--) {
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        size--;
        shiftDown(array, size, 0);
    }
}

void generateHeap(int *array, int size) {
    int i;
    for(i = size/2; i >= 0; i--)
        shiftDown(array, size, i);
}

void shiftDown(int *array, int size, int i) {
    int largest, temp,
            l = i*2+1, r = l+1;

    if (l < size && array[l] > array[i])
        largest = l;
    else
        largest = i;

    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i) {
        temp = array[largest];
        array[largest] = array[i];
        array[i] = temp;
        shiftDown(array, size, largest);
    }
}

/* end of heap sort */

void shellSort(int *array, int size){
    int i,j,k;
    for(i=size/2; i>0; i=i/2) {
        for(j=i; j<size; j++)
        {
            for(k=j-i; k>=0; k=k-i)
            {
                if(array[k+i]>=array[k])
                    break;
                else
                {
                    swap(&array[k], &array[k+i]);
                }
            }
        }
    }
}


int maxInd(int n, int *t)
{
    int max = 0;
    int i = 1;
    for (i = 1; i < n; i++)
        if (t[i] > t[max])
            max = i;
    return max;
}


void shuffle(int *array, int n)
{
    srand ( time(NULL) );
    if (n > 1)
    {
        int i;
        for (i = 0; i < n - 1; i++)
        {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}
void swap(int *a, int *b){
    int c = *b;
    *b = *a;
    *a = c;
}
void print_r(int *arr, int len){
    int i = 0;
    for(i = 0; i < len; i++){
        printf("%d\n", arr[i]);
    }
}
int putArrayIntoFile(FILE *fp, int *arr, int len){
    /*
     * file pointer should be different from NULL and file should be opened in w, w+ or rw mode
     * @return 0 if no errors; 1 if pointer is NULL
     * */
    if(fp){
        int i;
        for(i = 0; i < len; i++){
            fprintf(fp, "%d\n", arr[i]);
        }
        return 0;
    }else return 1;
}
void reverseAscArray(int *array, int len){
    int i;
    for(i = 0; i < len; i++){
        if(array[i] > array[len-i-1]) break;
        swap(&array[i], &array[len-i-1]);
    }
}
/* it retunrs pointer to allocated array */
int *loadArrayFromFile(FILE *fp, int *len){
    int size = 0;
    int i = 0;
    int k;
    int *pointer = NULL;
    printf("Reading start:\n\n");
    fp = fopen("data", "r");
    while (!feof(fp)) {
        fscanf(fp, "%d", &k);
        size++;
    }
    printf("Size of array is: %d\n", size);
    if(size){
        rewind(fp);
        pointer = (int*)malloc(size * sizeof(int));
        while (!feof(fp)) {
            fscanf(fp, "%d", &k);
            printf("%d\n", k);
            pointer[i] = k;
            i++;
        }
    }
    fclose(fp);
    *len = size;
    return pointer;
}