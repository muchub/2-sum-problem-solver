#include <stdio.h>
#include <time.h>
#include <unistd.h>

FILE *fptr;
int testArr[300];
int num, i, j, listNum[300], tempArr[300], option, sortedArr[300], tempNum, result, target, n = 100;
void importFile(char filename[], int num);
void readFile(char filename[]);
int linearSearch(int searchNum, int dataSize);
int binarySearch(int x, int low, int high);
int interpolationSearch(int arr[], int lo, int hi, int x);
int sortList();

int main()
{
    readFile("100.txt"); // Change file here
    sortList();
    /*
    for (i=0; i<100; i++){
        printf("%d\n", listNum[i]);
    }
    */
    printf("Enter target sum: ");
    scanf("%d", &target);
    printf("1. Linear Search\n2. Binary Search\n3.Interpolation Search\nSelect option: ");
    scanf("%d", &option);

    clock_t begin = clock();

    i = 0;
    while (i < n)
    {
        tempNum = target - listNum[i];
        if (option == 1)
        {
            result = linearSearch(tempNum, n);
        }
        else if (option == 2)
        {
            result = binarySearch(tempNum, 0, n - 1);
        }
        else if (option == 3)
        {
            result = interpolationSearch(listNum, 0, n - 1, tempNum);
        }
        else
        {
            printf("error");
            break;
        }
        //printf("%d\n", tempNum);
        if (result != -1)
        {
            printf("The 2-sum combination is %d + %d = %d", tempNum, listNum[i], target);
            break;
        }
        i++;
    }
    if (result == -1)
    {
        printf("Not Found");
    }
    // sleep(1);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", time_spent);
}

void importFile(char filename[], int num)
{
    fptr = fopen(filename, "w+"); // "w" defines "writing mode"
    /* write to file */
    fprintf(fptr, "%d ", num);
    fclose(fptr);
}

void readFile(char filename[])
{
    fptr = fopen(filename, "r+");
    i = 0;
    while (!feof(fptr))
    {
        fscanf(fptr, "%d", &num);
        listNum[i] = num;
        sortedArr[i] = num;
        i++;
    }
    fclose(fptr);
}

int linearSearch(int searchNum, int dataSize)
{
    int search_status = 0;
    for (j = 0; j < dataSize; j++)
    {
        if (listNum[j] == searchNum)
        {
            search_status = 1;
            // printf("%d is found in index %d", searchNum, i);
        }
    }
    if (search_status != 1)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int binarySearch(int x, int low, int high)
{
    //sortList(array);
    // Repeat until the pointers low and high meet each other
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (listNum[mid] == x)
            return mid;

        if (listNum[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int sortList()
{
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {

            if (listNum[i] > listNum[j])
            {
                num = listNum[i];
                listNum[i] = listNum[j];
                listNum[j] = num;
            }
        }
    }
}

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));
 
        // Condition of target found
        if (arr[pos] == x)
            return pos;
 
        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);
 
        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}