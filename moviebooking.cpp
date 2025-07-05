// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Movie{
    string id;
    string name;
    int duration;
    
    public:
    Movie(string id,string name,int duration){
        this->id = id;
        this->name=name;
        this->duration=duration;
    }
    
    string getId(){
        return id;
    }
    string getName(){
        return name;
    }
    int duration(){
        return duration;
    }
    
    void showDetails(){
        cout<<" ShowId : "<<id<<endl;
        cout<<" Name : "<<name<<endl;
        cout<<" Duration : "<<duration<<endl;
    }
};

class theater{
    string id;
    string address;
    string name;
    unordered_map<pair<int,int>,int>seats;
    int capacity;
    
    public:
    
    Theater(string id,string address,string name ,int capacity){
        this->id = id;
        this->address=address;
        this->name = name;
        this->capacity = capacity;
    }
    
    void bookSeat(int row,col){
        seats[{row,col}]=1;
    }
    void cancelSeat(int row,int col){
        seats[{row,col}]=0;
    }
    
    void showDetails(){
        cout<<" TheaterId : "<<id<<endl;
        cout<<" Theater Name : "<<name<<endl;
        cout<<" Address : "<<address<<endl;
    }
};

class Show{
    string id;
    string name;
    string time;
    int price;
    
    Show(string id,string name,string time,int price,Theater * theater,Movie * movie){
        this->id = id;
        this->name = name;
        this->time = time;
        this->price = price;
    }
    
    public:
    
    string getId(){
        return id;
    }
    string getName(){
        return name;
    }
    string getTime(){
        return time;
    }
    
    void bookShow(int x,int y,int qty){
        for(int i=0;i<qty;i++)
        theater.bookSeat(x,y);
    }
    
    void showDetails(){
        movie.showDetails();
        theater.showDetails();
        cout<<"Timing : "<<time<<endl;
    }
};

class 
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}
