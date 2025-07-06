#include <iostream>
#include<bits/stdc++.h>
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
    int getDuration(){
        return duration;
    }
    
    void showDetails(){
        cout<<"Movie Details : "<<endl;
        cout<<"MovieId : "<<id<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Duration : "<<duration<<":hrs"<<endl;
    }
};

class Theater{
    string id;
    string address;
    string name;
    map<pair<int, int>, int> seats;
    int capacity;
    
    public:
    
    Theater(string id,string address,string name ,int capacity){
        this->id = id;
        this->address=address;
        this->name = name;
        this->capacity = capacity;
    }
    
    void bookSeat(int row,int col){
        seats[{row,col}]=1;
    }
    void cancelSeat(int row,int col){
        seats[{row,col}]=0;
    }
    
    void showDetails(){
        cout<<"Theater Details : "<<endl;
        cout<<"TheaterId : "<<id<<endl;
        cout<<"Theater Name : "<<name<<endl;
        cout<<"Address : "<<address<<endl;
    }
};

class Show{
    string id;
    string name;
    string time;
    int price;
    Theater * theater;
    Movie * movie;
    public:
    
    Show(string id,string name,string time,int price,Theater * theater,Movie * movie){
        this->id = id;
        this->name = name;
        this->time = time;
        this->price = price;
        this->movie = movie;
        this->theater=theater;
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
    
    void bookShow(int x,int y){
        theater->bookSeat(x,y);
    }
    
    void cancelShow(int x,int y){
        theater->cancelSeat(x,y);
    }
    
    void showDetails(){
        cout<<"Show Details : "<<endl;
        movie->showDetails();
        theater->showDetails();
        cout<<"Timing : "<<time<<endl;
    }
};

class User{
    string name;
    string id;
    
    public:
    
    User(string name ,string id){
        this->name = name;
        this->id = id;
    }
    
    string getName(){
        return name;
    }
    
    string getId(){
        return id;
    }
    
    void showDetails(){
        cout<<"User Details : "<<endl;
        cout<<"Name : "<<name<<endl;;
        cout<<"User Id : "<<id<<endl;
    }
};

class Booking{
    string id;
    User * user;
    Show * show;
    vector<pair<int,int>>seats;
public:    
    Booking(string id,User * user,Show * show){
        this->id = id;
        this->user = user;
        this->show = show;
    }
    
    void bookTicket(int x,int y){
        show->bookShow(x,y);
        seats.push_back({x,y});
    }
    
    void cancelTicket(int x,int y){
        show->cancelShow(x,y);
    }
    
    void showDetails(){
        show->showDetails();
        user->showDetails();
        cout<<"Seats Booked : ";
        for(int i=0;i<seats.size();i++){
            cout<<"Seats "<<"("<<seats[i].first<<","<<seats[i].second<<")"<<",";
        }
        
    }
};

class App{
    vector<User*>users;
    vector<Booking*>bookings;
    vector<Theater*>theaters;
    vector<Movie*>movies;
    vector<Show*>shows;
    public:
    
    
    Booking *createBooking(string bookingId,User * user, Show * show){
        Booking *booking = new Booking(bookingId,user,show);
        return booking;
    }
    
    void addTickets(Booking * booking,int x, int y){
        booking->bookTicket(x,y);
    }
    void removeTickets(Booking * booking,int x,int y){
        booking->cancelTicket(x,y);
    }
    
    void showBookingInfo(Booking * booking){
        booking->showDetails();
    }
};

int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    
    User * user = new User("U001","Himanshu");
    Theater * theater = new Theater("T001","ABC PARK","Theater 1",100); // Theater(string id,string address,string name ,int capacity)
    
    //Movie(string id,string name,int duration)
    Movie * movie =  new Movie("M001","Movie 1",2);
    
    //Show(string id,string name,string time,int price,Theater * theater,Movie * movie)
    Show * show = new Show("S001","First Show","9:25 AM",250,theater,movie);
    
    App * app = new App;
    Booking *booking  = app->createBooking("B001",user,show);
    app->addTickets(booking,0,0);
    app->showBookingInfo(booking);
    

    return 0;
}
rate my lld design for fresher role
