#include <iostream>
using namespace std;

int main() {
    int n, target;
    cout << "Enter the Number of Elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cout <<"Enter element At ["<<i<<"] :";
        cin >> arr[i];
    }

    cout<<"Given Array : [ ";
    for (int i = 0; i < n; ++i) {
       cout <<arr[i]<<" ,";
    }
    cout<<"]\n";
    cout<<"Array Index : [ ";
         for (int i = 0; i < n; ++i) {
             cout <<i<<" ,";
     }
    cout<<"]\n";
    cout << "Enter the target element to search for: ";
    cin >> target;
    int count=0;
	for (int i = 0; i < n; ++i) {
            if(arr[i]==target){
            	count++;
            }
    }
    int ocurr[count];
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            ocurr[j]=i;
            j++; 
        }
    } 

    if (count>0) {
    	 cout << "Number of Occurance : ["<<count << "]\n";
         cout << "Element First Ocuurance [" << ocurr[0] << "].\n";
         int x = sizeof(ocurr)/sizeof(int);
         cout << "Element Last Ocuurance [" << ocurr[x-1] << "].\n";
         cout<<"All Index Of Ocuurance : [ ";
         for (int i = 0; i < count; ++i) {
             cout <<ocurr[i]<<" ,";
         }
         cout<<"]\n";
    } else {
        cout << "Element not found.\n";
    }

    return 0;
}
