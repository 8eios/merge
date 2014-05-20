#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 300
#define RANGE 500

using  namespace std;

void mergearray(int a[], int first,int mid, int last)
{
    int i=first;
    int j=mid+1;
    int k=0;

    int *b=new int[last-first+1];

    while (i<=mid && j<=last)
    {
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while(i<=mid)
        b[k++] = a[i++];

    while(j<=last)
        b[k++] = a[j++];

    for(i=last;i>=first;i--)
        a[i]=b[--k];

}

void mergesort(int a[], int first, int last)
{
    if(first<last)
    {
        int mid=((first+last)/2);
        mergesort(a, first, mid);
        mergesort(a, mid+1, last);
        mergearray(a, first, mid, last);
    }
}





int main(int argc, char** argv)
{
    int a[SIZE];
    int i;
    srand(time(NULL));

    for(i=0;i<SIZE;i++)
    {
        a[i] = rand()%RANGE;
    }

    for(i=0;i<SIZE;i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl << endl;


    mergesort(a, 0, (SIZE-1));


    for(i=0;i<SIZE;i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl << endl;
}
