#include<iostream>
#include<fstream>

using namespace std;

struct user{
    string name;
    string password;
};
void loadUsers(user userlist[], int &count, int max) {
    fstream myfile;
    myfile.open("store.txt" , ios::in);
    count = 0;
    if (myfile.is_open()) {
        while (myfile >> userlist[count].name >> userlist[count].password) {
            count++;
            if (count >= max) break; // Stop if max capacity is reached
        }
        myfile.close();
    }
}
void saveUser(const user& newUser) {
    fstream myfile("store.txt", ios::app); // 'app' mode to append data
    if (myfile.is_open()) {
        myfile << newUser.name << " " << newUser.password << endl;
        myfile.close();
    } else {
        cout << "Error: Unable to open file for writing." << endl;
    }
}
void userSignup(user userlist[] , int max){
    int count = 0;
    string name2,password2;
    cout << "Enter you new username : " ;
    cin >> name2;
    cout << "Enter your new passoword : " ;
    cin >> password2;

    if(count > max){
        cout << "Storage is full" << endl;
    }
    else{
        userlist[count].name = name2  ;
        userlist[count].password = password2  ;
        saveUser(userlist[count]);
        count++;

    }
    
}
void adminLogin(){
    string name3,password3;
    do{
    cout << "Enter your admin name :" ;
    cin >> name3;
    cout << "Enter you password : ";
    cin >> password3;

    
        if(name3 == "admin" && password3 == "admin"){
            cout << "Successfully Login!!!" << endl;   
            break;    
        }
        else{
            cout << "wrong username or password!!!" << endl;
        }
    }while(true);    
    }
void userLogin(user userlist[],int max){
    string name1 , password1;
    cout << "Enter Your User name  :  " ;
    cin >> name1;
    cout << "Enter Your Passweord  :  " ;
    cin >> password1;

    for(int j = 0 ; j < max ; j++)
        {
        if(name1 == userlist[j].name && password1 == userlist[j].password){
            cout << "Welcome you " << endl;
            cout << "You successfully login!!!" << endl;
            break;
        }
        else{
            cout << "Wrong username or password!!!!!" << endl;
            break;
        }
        }
}
void adminShow();
void customerDatabase(){}
void userShow();
void addItem(){}
void stock(){}
void neworder(){}
void orderdetail(){}

int main(){
    int cho;  
    int max = 100;
    user userlist[max];
    int count = 0;
    loadUsers(userlist, count, max);
    int x;


 do{       
    cout << "************************" << endl;
    cout << " Skyray Ordering Systrm " << endl;
    cout << "************************" << endl;
    cout << " 01 . Customer Login  " << endl;
    cout << " 02 . Customer Signup " << endl;
    cout << " 03 . Admin Login     " << endl;
    cout << " 04.exit" << endl;
    cout << " Please Your Choice  :  " ;
    cin >> cho ;

    switch(cho){
        case 1:
            userLogin(userlist ,  max);
            x = 0;
            break;
        case 2:
            userSignup(userlist , max);
            break;
        case 3:
            adminLogin();
            x = 5;
            break;
        case 4:
            cout << "Exit "    ;
            break;
    }
 }while(cho != 4 && x == 5 && x == 0);

    if(x == 5){
        adminShow();    
    }
    else if(x == 0){
        userShow();


    }



    return 0;
}

void adminShow(){
    int choice;
    cout << "01.Add items" << endl;
    cout << "02.Show stocks" << endl;
    cout << "03.Customer details" <<endl;
    cout << "04.new orders" << endl;
    cout << "05.Exit main menu" << endl;
    cout << "06.exit " << endl;
    cin >> choice;
    switch(choice){
        case 1:
            addItem();
            break;
        case 2:
            stock();
            break;
        case 3:
            customerDatabase();
            break;
        case 4:
            neworder();
               


    }


}

void userShow(){
    int choice;
    do{
    cout << "01.Show items list" << endl;
    cout << "02.Order details" << endl;
    cout << "03.Exit main menu" << endl;
    cout << "04.exit " << endl;
    cin >> choice;  
       switch(choice){
        case 1:
            userShow();
            break;
        case 2:
            orderdetail();
            break;
        case 3:
            break; //delop soon
        case 4:
            exit;
               


    } 
    }while(choice != 3);
}