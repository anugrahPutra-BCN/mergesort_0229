#include<iostream>
using namespace std;

// Create main and temporary array
int arr[20], B[20];
// n is array input size
int n;

void input() {
    while (true) {
        cout << "Massukkan panjang element array : ";
        cin >> n;

        if (n <= 20)
        {
             break;
        }     
        else 
        {
            cout << "nMaksimalkan panjang adalah 20" << endl;
        }
    }
    cout << "\n-------------------------" << endl;
    cout << "nInputkan Isi element array: ";
    cout << "\n-------------------------" << endl;

    for (int i = 0; i < n; i++) 
    {
        cout << "Array index ke- " << i << " : ";
        cin >> arr[i];
    }
}

// Create function to merge two sorted arrays
void mergesort(int low, int high) 
{ 

    if (low >= high) // step 1 
    {
        return; // Step 1.a
    }

    int mid = (low + high) / 2; // Step 2

    // Step 3
    // fungsi rekursi - memanggil diri sendiri
    mergesort(low, mid); // Step 3.a
    mergesort(mid + 1, high); // Step 3.b

    // Step 4
    int i = low; // Step 4.a
    int j = mid + 1; // Step 4.b
    int k = low; // Step 4.c

    while (i <= mid && j <= high) // step 4.d 
    { 
        if (arr[i] < arr[j]) // step 4.i
         { 
            B[k] = arr[i]; 
            i++; 
        } 
        else
         { 
            B[k] = arr[j]; 
            j++; 
        } 
        k++; // step 4.d.ii
    }

    while (j <= high) 
    { 
        B[k] = arr[j]; // Step 4.e
        j++;           // Step 4.e.ii
        k++;           // Step 4.e.iii   
    }

    while (i <= mid) 
    { 
        B[k] = arr[i]; // Step 4.f
        i++;           // Step 4.f.ii
        k++;           // Step 4.f.iii
    }

    // Step 5
    for (int x = low; x <= high; x++) 
    {
        arr[x] = B[x]; 
    }

    
}

void output()
{
    cout << "\nData setelah diurutkan (Merger sort):";
    for (int i = 0; i < n; i++)
    {
        cout << arr [i] << " ";
    }
    cout << endl;
}

int main() 
{
    input();  
    mergesort(0, n - 1);  
    output();
}