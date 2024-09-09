#include<iostream>

using namespace std;

struct user{
    string name;
    string password;
};

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
    }
    count++;
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
void addItem(){}
void showItem(){}
void buyItem(){}
void updateItem(){}
void searchItem(){}

int main(){
    int cho;  
    int max = 100;
    user userlist[max];


 do{       
    cout << "************************" << endl;
    cout << " Skyray Ordering Systrm " << endl;
    cout << "************************" << endl;
    cout << " 01 . Customer Login  " << endl;
    cout << " 02 . Customer Signup " << endl;
    cout << " 03 . Admin Login     " << endl;
    cout << " Please Your Choice  :  " ;
    cin >> cho ;

    switch(cho){
        case 1:
            userLogin(userlist ,  max);
            break;
        case 2:
            userSignup(userlist , max);
            break;
        case 3:
            adminLogin();
            break;
                
    }
 }while(cho !=4);



    return 0;
}