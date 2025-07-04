// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class User{
    string userId;
    string name;
    string phone;
    string address;
    
    public:
    
    User(string userId,string name,string phone,string address){
        this->name = name;
        this->userId = userId;
        this->phone = phone;
        this->address= address;
    }
    
    string getName(){
        return name;
    }
    string getUserID(){
        return userId;
    }
    string getPhone(){
        return phone;
    }
    string getAddress(){
        return address;
    }
    
    // void showDetails(){
    //     cout<<
    // }
};

class MenuItem{
    
    string itemId;
    string name;
    int price;
    string description;
    bool available;
    
    public:
    
    MenuItem(string itemId,string name,string description,int price){
        this->itemId = itemId;
        this->name = name;
        this->price = price;
        this->description=description;
        this->available = 1;
    }
    
    string getItemId(){
        return itemId;
    }
    string getName(){
        return name;
    }
    int getPrice(){
        return price;
    }
    
    string getDescription(){
        return description;
    }
    bool isAvailable(){
        return available;
    }
    
    void showDetails(){
        cout<<"ItemId : "<<itemId<<endl;
        cout<<"ItemName : "<<name<<endl;
    }
};

class Restraunt{
    string restrauntId;
    string name;
    string cusine;
    string address;
    bool open;
    vector<MenuItem*>menu;
    public:
    
    Restraunt(string restrauntId,string name,string cusine,string address){
        this->restrauntId= restrauntId;
        this->name = name;
        this->cusine =cusine;
        this->address=address;
        open =  1;
    }
    
    string getRestruantId(){
        return restrauntId;
    }
    vector<MenuItem*>getMenu(){
        return menu;
    }
    string getName(){
        return name;
    }
    void addMenuItems(MenuItem * item){
        menu.push_back(item);
    }
    
    string getRestrauntId(){
        return restrauntId;
    }
    string getCusine(){
        return cusine;
    }
    bool isOpen(){
        return open;
    }
    

};

class Order{
    string orderId;
    User * user;
    Restraunt * restraunt;
    unordered_map<MenuItem*,int>qty;
    double totalAmount;
    string status;
    
    
    public:
    Order(User * user,Restraunt * restraunt, string orderId){
        this->orderId = orderId;
        this->user = user;
        this->restraunt = restraunt;
        this->status = "Placed";
        totalAmount = 0;
    }
    
    void addItems(MenuItem * item,int qty){
        if(item && qty >0){
            this->qty[item]+=qty;
        }
        
    }
    
    void updateStatus(string status){
        this->status=status;
    }
    
    void calculateTotal(){
        for(auto it : qty){
            totalAmount+=it.first->getPrice()*it.second;
        }
    }
    
    void showDetails(){
        cout<<"User name : "<<user->getName()<<endl;
        cout<<"Restraunt Name : "<<restraunt->getName()<<endl;
        
        for(auto it : qty){
            it.first->showDetails();
            cout<<"Item qty : "<<it.second<<endl;
        }
        calculateTotal();
        cout<<"Total amount : "<<totalAmount<<endl;
    }
    
    
};

class App{
    vector<User*>users;
    vector<Order*>orders;
    vector<Restraunt*>restraunts;
    int orderCounter=0;
    public:
    
    string getOrderId(){
        orderCounter++;
        return "000"+(orderCounter+'0');
    }
    
    void addUser(User * user){
        users.push_back(user);
    }
    void addRestraunt(Restraunt * restraunt){
        restraunts.push_back(restraunt);
    }
    
    Order* createOrder(User * user,Restraunt * restraunt){
        if(!user || ! restraunt || !restraunt->isOpen())return NULL;
        
        Order *order = new Order(user,restraunt,getOrderId());
        
        return order;
    }
    
    void addItemsToOrder(Order *order,MenuItem * item,int qty){
        order->addItems(item,qty);
    }
    
    void generateBill(Order * order ){
        order->showDetails();
    }
    
    void restrauntMenu(string restrauntId){
        Restraunt * r = findRestraunt(restrauntId);
        
        for(auto it : r->getMenu()){
            it->showDetails();
        }
    }
    
    Restraunt* findRestraunt(string restrauntId){
        for(auto it : restraunts){
            if(it->getRestrauntId()==restrauntId)
            {
                return it;
            }
            
        }
    }
};



int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    
    User *u1 = new User("U001","Himanshu1","12344563","kk district 1 alpha");
    User *u2 = new User("U001","Himanshu1","12344563","kk district 1 alpha");
    
     MenuItem* item1 = new MenuItem("I001", "Margherita Pizza", 
                                 "Classic tomato and mozzarella", 12.99);
    MenuItem* item2 = new MenuItem("I002", "Pepperoni Pizza", 
                                 "Spicy pepperoni with cheese", 14.99);
    
    Restraunt* restraunt1 = new Restraunt("R001", "Pizza Palace", 
                                           "Italian", "456 Oak Ave");
    restraunt1->addMenuItems(item1);
    restraunt1->addMenuItems(item2);
    
    App  app; 
    Order * order = app.createOrder(u1,restraunt1);
    
    app.addItemsToOrder(order,item1,1);
    app.addItemsToOrder(order,item2,2);
    app.generateBill(order);
    
    
    // Restraunt r1 = new 

    return 0;
}
