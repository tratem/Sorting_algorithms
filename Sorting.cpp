/*
Sorting alghorithms:
- Bubble sort
*/

#include <iostream>
#include <time.h>
#include <chrono>

#define ARR_SIZE 100

using namespace std;
using namespace chrono;

void bubble_sort(int arr[], char c)
{
    int temp;
    //get the current time
    auto start = high_resolution_clock::now();

        for(int i = 0; i< ARR_SIZE - 1 ; i++)
        {
            for(int j = 0; j < ARR_SIZE - 1 - i; j++)
            {
                if (c == 'A') //sorting in ascending order
                {  
                    if(arr[j] > arr[j+1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                } 
                else if (c == 'D') //sorting in descending order
                {
                    if(arr[j] < arr[j+1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }

            }
        }
    // Get the current time after finishing the function
    auto end = high_resolution_clock::now();

    // Calculate the elapsed time
    duration<double> duration = end - start;
    
    // Convert duration to microseconds
    microseconds micro = duration_cast<microseconds>(duration);    

    cout << "The bubble sort was done in: " << micro.count() << " microseconds" << endl;

}

int main()
{
    srand(time(0));
    int arr[ARR_SIZE];
    char c;

    for (int i=0; i<ARR_SIZE; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Insert the sorting order [A]scending or [D]escending" << endl;
    cin >> c;

    while((toupper(c) != 'A') && (toupper(c) != 'D'))
    {
        cout <<"Incorect operation! [A]scending or [D]escending" << endl;
        cin >> c;
    }

    bubble_sort (arr, toupper(c));


    //printing the sorted arr
    for (int i=0; i<ARR_SIZE; i++)
    {
        cout << arr[i] <<  ", ";
        if (i%10 == 0)
        cout << endl;
    }

    return 0;
}