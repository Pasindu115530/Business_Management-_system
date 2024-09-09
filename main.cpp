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
void addItem(){}
void showItem(){}
void buyItem(){}
void updateItem(){}
void searchItem(){}

int main(){
    int cho;  
    int max = 100;
    user userlist[max];
    int count = 0;
    loadUsers(userlist, count, max);


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