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
