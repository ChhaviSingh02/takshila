#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//Book Class
class Book{
public:
  int id;
  string title;
  string author;
  bool isAvailable;

  Book(int id, string title,string author){
    this->id=id;
    this->title=title;
    this->author=author;
    this->isAvailable=true;//by default book is available
  }

  void display(){
    cout<<"Book ID : "<<id<<" |Title : "<<title<<" | Author"<<author;
    cout<<" | Status : "<<(isAvailable ? "Available" :"Issued") <<endl;
  }
};

class Library{
  private:
    vector<Book> books;
    unordered_map<int,int> issuedBooks;
  public:

    void addook(int id, string title,string author){
      books.push_back(Book(id,title,author));
      cout<<"Book added successfully.\n";
    }

    void removeBook(int id){
      for(auto it=books.begin(); it!=books.end(; it++){
          if(it->id==id){
              books.erase(it);
              cout<<"Book removed successfully\n";
              return;
          }
      }  
      cout<<"Books not found";
      cout<<endl;
    }
void displayBooks(){
  if(books.empty()){
      cout<<"No books available in the library"<<endl;
      return;
  }
  for(auto &book: books){
    book.display();
  }
}

void issued(int userId,int bookId){
  for(auto &book: books){
    if(book.id==bookId && book.isAvailble){
      book.isAvailable=false;
      issuedBooks[userId]=bookId;
      cout<<"Book issued successfully<<endl;
      return;
    }
  }
cout<<"Book is not availale or does not exist"<<endl;
}

void returnBook(int userId){
  if(issuedBooks.find(userId)!=issuedBooks.end()){
    int bookId=issuedBooks[userId];
    for(auto &book:books){
      if(book.id==bookId){
        book.isAvailable=true;
        issuedBooks.erase(userId);
        cout<<"Book returned successfully"<<endl;  
        return;
      }
    }
  }
cout<<"No book found for this user"<<endl;
}
};

int main(){
  Library library;
  int choice,bookId,userId;
  string title,author;

  while(true){
    cout<<"\nLibrary Management System"<<endl;
    cout<<"1.Add Book"<<endl;
    cout<<"2.Remove Book"<<endl;
    cout << "3. Display Books\n";
    cout << "4. Issue Book\n";
    cout << "5. Return Book\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

switch (choice) {
            case 1:
                cout << "Enter Book ID, Title, Author: ";
                cin >> bookId;
                cin.ignore();
                getline(cin, title);
                getline(cin, author);
                library.addBook(bookId, title, author);
                break;
            case 2:
                cout << "Enter Book ID to remove: ";
                cin >> bookId;
                library.removeBook(bookId);
                break;
            case 3:
                library.displayBooks();
                break;
            case 4:
                cout << "Enter User ID and Book ID: ";
                cin >> userId >> bookId;
                library.issueBook(userId, bookId);
                break;
            case 5:
                cout << "Enter User ID: ";
                cin >> userId;
                library.returnBook(userId);
                break;
            case 6:
                cout << "Exiting system...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}









