#include <iostream>
#include <string>

using namespace std;

class Student{
      private :
            string name;
            int roll_number;
            string _class;
      public:
            Student(){
                strcpy(name,"No Record");
                roll_number = 0;
                strcpy(_class,"No Class Alloted");
                
            }

            Student(string _name, int _roll_number, string __class){
                 strcpy(name,_name);
                 roll_number = _roll_number;
                 strcpy(_class,__class);
            }

            static void print_shelf(Student divison[], int class_strength) {
                  for (int i = 0; i < class_strength; i++) {
                     cout << "          " << divison[i].name << "                        " << divison[i].roll_number <<"         " << divison[i]._class << endl;
                  }
            
            }

            static bool isSorted(Student divison[]){

                for (int j = 0; j < class_strength +1 ; j++) {
                      if(!(divison[j].roll_number < divison[j+1].roll_number)){
                           return false;
                     }
                }
              return true;
            }

            static void selectionSort(Student divison[], int class_strength){

                 for (int i = 0; i < class_strength - 1; i++) {
                      for (int j = i + 1; j < class_strength; j++) {
                
                           if (divison[i].roll_number < divison[j].roll_number) {
             
                                    Student temp =divison[i];
                                    divison[i] =divison[j];
                                    divison[j] = temp;
                            }
                       }
                   }
               }
            static int linearSearch(Student divison[],int class_strength ,int target){
                 
                 for(int i = 0; i < class_strength ; i++){
                    if(divison[i].roll_number == target){
                        return i;
                    }
                 }
                 return -1;
            }

            static int binarySearch(Student divison[],int class_strength ,int target){

                if(!isSorted){
                    cout << "You Entered A Unsorted Array [ Sorting Given ARRAY ]\n"
                    selectionSort(Student divison[], class_strength);
                }
                int low = 0;
                int high = class_strength -1;

                while(low < high){
                    
                    int mid = low + ( high - low ) /2;

                    if(divison[mid].roll_number == target){
                        return mid;
                    }else if(divison[i].roll_number > target){
                        low = mid;
                    }else{
                        high = mid;
                    }
                  }
                    return -1;
                }
            
            void display(){

            }


   };

   int main(){
         Student divison[10];
         int class_strength, choice;

    cout << "Enter Number of Entries: ";
    cin >> class_strength;

    for (int i = 0; i < class_strength; i++) {
        cout<<"Enter Details of Book - "<<i+1<<" : "<<endl;
        cout << "  • Enter Roll Number : ";
        cin >>  _roll_number;
        cout << "  • Enter Name : ";
        cin >> _name;
        cout << "  • Enter Class: ";
        cin >> __class;

        divison[i] = Student(_name, _roll_number,__class);
    }

    do {
       cout << "\nOperation Menu:" << endl;
        cout << "1. Sort with respect to Roll Number" << endl;
        cout << "2. Display" << endl;       
        cout << "3. Check Student Present or NOT ( Optimized ) " << endl;
        cout << "4. Check Student Present or NOT ( UnOptimized ) "<<endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student :: selectionSort(divison);
                break;
            }
            case 2: {
                 for (int i = 0; i < class_strength; i++) {

                         cout<<"Enter Details of Book - "<<i+1<<" : "<<endl;
                         cout << "  • Enter Roll Number : ";
                         cin >>  _roll_number;
                         cout << "  • Enter Name : ";
                         cin >> _name;
                         cout << "  • Enter Class: ";
                         cin >> __class;
                 }
                break;
            }
            case 3: {
                int target;
                cout<<"Enter Roll Number of Student :";
                cin >>target;
                cout << "Searching Using Binary Search ......" << endl;     
                Student :: binarySearch(divison, target,class_strength);
                break;
            }
            case 4:
                 int target;
                 cout<<"Enter Roll Number of Student :";
                 cin >>target;
                 cout << "Searching Using Linear Search ......" << endl;                 
                 Student :: linearSearch(divison, target, class_strength);
                 break;
            case 5:
            	 break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
   }
