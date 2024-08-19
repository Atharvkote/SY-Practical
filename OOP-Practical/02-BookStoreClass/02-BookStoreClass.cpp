
#include<iostream>
#include<string>

using namespace std;

class BookShop{
    
   public: 
               string book_name;
               string book_author;
               string book_publisher;
               int book_price;
               int book_copies;
        
   
              BookShop(){
                // un-parameterized-Constructor   
                  }

              void add_book(){

                cout << "Enter Book Name : ";
                cin >> book_name;
                cout << "Enter Book Author : ";
                cin >> book_author;
                cout << "Enter Book Publisher : ";
                cin >> book_publisher;
                cout << "Enter Book Price : ";
                cin >> book_price;
                cout << "Enter Book Copies : ";
                cin >> book_copies;

              }
   
              void display_book(){ 

                cout << "Book Name : " << book_name<<endl;
                cout << "Book Author : " << book_author<<endl;
                cout << "Book Publisher : " << book_publisher<<endl;
                cout << "Book Price : " << book_price<<endl;
                cout << "Number of Copies Available : " << book_copies<<endl;

             }

             void print_order_details(BookShop lot[] ,int indx){
                cout << "ORDER Details :";                                              
                lot[indx].display_book();
             }

             bool check_availablilty(int &required_copies){
                return required_copies < book_copies;
             }

             static int search_book(BookShop lot[] ,string &book_title,string &author_name,int &lot_size){
                
                for(int i = 0; i < lot_size ;i++){
                    if( lot[i].book_author == author_name && lot[i].book_name == book_title ){
                        return i;
                    }
                }
                return -1;

             }
            
             static void order_book(BookShop lot[],int lot_size){

                string book_title,author_name;
                int required_copies;

                cout << "Enter Book Name : ";
                cin >> book_title;
                cout << "Enter Book Author : ";
                cin >> author_name;

                int indx = BookShop :: search_book(lot,book_title,author_name,lot_size);

                if(indx != -1){ 

                     cout << "Book Copies Required : ";
                     cin >> required_copies;  

                     if(lot[indx].check_availablilty(required_copies)){

                        cout << "Order Successfully Placed !!!";
                        lot[indx].book_copies -= required_copies;

                        cout << "ORDER Details :";                                              
                        lot[indx].display_book();

                     }else{
                        cout <<"OUT OF STOCK !!!";
                     }

                }else{

                     cout << "BOOK UNAVAILABLE IN SHOP !!!";
                     return;

                } 

              } 
   
    };
   
  int main(){
      
      BookShop lot[5];
      int lot_size,choice;

       do {
       cout << "\nOperation Menu:" << endl;
        cout << "1. ADD Books" << endl;
        cout << "2. Order Book" << endl;
        cout << "3. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter Number of BOOKS: ";
                cin >> lot_size;

               for (int i = 0; i < lot_size; i++) {
                  cout<<"Enter Details of Book - "<<i+1<<" : "<<endl;
                  lot[i].add_book();
                }    
                break;
            }
            case 2: {
                BookShop :: order_book(lot,lot_size);
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
           }
        } while (choice != 3);

      return 0; 
  }
