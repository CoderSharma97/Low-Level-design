// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Book{
    string name;
    string isbn;
    string type;
    int copies;
    
    
    public:
    
    Book(string name ,string isbn,string type,int copies){
        this->name = name;
        this->isbn= isbn;
        this->type = type;
        this->copies=copies;
    }
    
    void showDetails(){
        cout<<"Book Details : "<<endl;
        cout<<"Book Name : "<<name<<endl;
        cout<<"ISBN : "<<isbn;
    }
    int getCopies();
    string getIsbn();
    string gettype();
    string getName();
    
};

class Member{
    string name;
    string address;
    string id;
    public:
    // void showDetails();
    string getName();
    string getId();
    
    Member(string name,string address,string id){
        this->name = name;
        this->address = address;
        this->id =id;
    }
    
    void showDetails(){
        cout<<"Member Details"<<endl;
        cout<<"Member Name : "<<name<<endl;
        cout<<"Member Address : "<<address<<endl;
        cout<<"Member Id"<<id<<endl;
    }
    
};

class Issue{
    Member * member;
    vector<Book*>books;
    string id;
    string issueDate;
    string returnDate;
    
    public:
    Issue(Member* member,string id,string issueDate,string returnDate){
        this->member = member;
        this->id = id;
        this->issueDate=issueDate;
        this->returnDate=returnDate;
    }
    
    void addBook(Book * book){
        books.push_back(book);
    }
    
    void showDetails(){
        cout<<"Issue Details "<<endl;
        cout<<"Issue Id : "<<id<<endl;
        cout<<"Issue Date : "<<issueDate<<endl;
        cout<<"Return Date : "<<returnDate<<endl;
        member->showDetails();
        cout<<"Books Issued"<<endl;
        for(int i=0;i<books.size();i++){
            books[i]->showDetails();
            cout<<endl;
        }
    }
};
class Library{
    string Librarian;
    string address;
    vector<Member*>members;
    vector<Issue*>issues;
    vector<Book*>books;
    
    public:
    
    Issue * createIssue(Member * member,string id,string issueDate,string returnDate){
        Issue * issue = new Issue(member,id,issueDate,returnDate);
        return issue;
    }
    
    void addBooksToIssue(Issue * issue,Book * book){
        issue->addBook(book);
    }
    
    void showIssueDetails(Issue*issue){
        issue->showDetails();
    }
    
    
};
int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    // Book(string name ,string isbn,string type,int copies)
    Book * book1 = new Book("Book1","ISBN001","Science",20);
    Book * book2 = new Book("Book2","ISBN002","History",10);
    //  Member(string name,string address,string id)
    Member * member = new Member("Himanshu","ABC Park ","M001");
    
    Library l;
    
    Issue * issue = l.createIssue(member,"I001","02-02-2025","03-03-2025");
    l.addBooksToIssue(issue,book1);
    l.addBooksToIssue(issue,book2);
    l.showIssueDetails(issue);

    return 0;
}
