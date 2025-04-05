#include <iostream>

#include<string>

#include<limits>

#include<algorithm>

using namespace std;

class stack{
    public:
string friends[100];
int top;

public:
stack(){
top=-1;
}

void push_friend(string name1){//adds a friend to the array
if (top==99){
    cout<<"your friend list seems to be full already"<<endl;
}else{
top=top+1;
friends[top]=name1;
}
}
void delete_friend(string targetfriend){//removes a friend of your choice
if(top==-1){
    cout<<"your friend list is currently empty!! "<<endl;
}else{
int foundindex=-1;//index of friend you want to delete

for(int i=0;i<=top;i++){//iterarates through friend string looking for friend you want to delete
    if(friends[i]==targetfriend){
        foundindex=i;
        break;//stops loop once friend is found
    }
}
if(foundindex==-1){
    cout<<"this friend isnt on your list!!"<<endl;
}
if(foundindex<top){//if the element you are looking for is not the top:this is done because in a stack you can only delete the top element
    friends[foundindex]=friends[top];
}
top--;//removes the element you chose
cout<<"friend:"<<targetfriend<<"has been deleted!!"<<endl;//prints deleted friend
}
}
void check_last_friend(){//displays the last friend added
if(top==-1){
    cout<<"your friend list is currently empty!! "<<endl;
}else{
    cout<<"Your last friend added was:\n"<<friends[top]<<endl;
}
}
void print_friends(){//prints all the friends currently in the array
    if(top==-1){
     cout<<"your friend list is currently empty!! "<<endl;
    }else{
for(int i=0;i<=top;i++){//loop to iterate the friends added
    cout<<"Your friends are:\n"<<i+1<<friends[i]<<endl;
}
}
}

};
int main()
{
    stack s;
    string wierdnames[]={"cow","goat","lion","elephant","zebra","shirt","pen","pencil","table","plate"};//weird possibilities a user may enter that will be rejected after user input is compared with it
    int arraySize=sizeof(wierdnames)/sizeof(wierdnames[0]);//size of array of weird posibilities that is used in comparison
    int result;
    cout<<"welcome to your personal friend library!!"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    do{
cout<<"choose 1.Add a new friend\n 2.remove last friend on the list\n 3.display current friends\n 4.check last friend added\n 5.exit friend library "<<endl;
cin>>result;
if(cin.fail()){
   cout<<"please enter an integer!!"<<endl;
    cin.ignore();
}else{
switch(result){
case 1:{
  string newfriend;//used as a parameter in place of name 1
  bool validAddInput=false;
  while(!validAddInput){//while loop to allow user to reenter incase of wrong type of data or wierd string name
    cout<<"enter the names of the friends you want to add"<<endl;
    cin>>newfriend;
if(cin.good()){//if data type is right
        if(find(wierdnames,wierdnames+arraySize,newfriend)!=wierdnames+arraySize){//checks to see if string is an animal name using find to compare to weird array
                cout<<"wierd things are not your friends bro!!"<<endl;
                cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }else{
                s.push_friend(newfriend);//new friend works as a parameter in place of name 1
                validAddInput=true;//breaks loop when input is right
            }
}else{//if data type is wrong
   cout<<"please enter a proper name!!"<<endl;
    cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
}


cout<<"----------------------------------------------------------------------"<<endl;
  }
    break;
}
case 2:{
    string oldfriend;//replaces target friend as the new parameter when function is called
    bool validInput=false;
    while(!validInput){//while loop to allow user to re-enter incase of wrong type of data or weird string name
    cout<<"enter the names of the friends you want to remove"<<endl;
    cin>>oldfriend;
    if(cin.good()){//if its the right data type
            if(find(wierdnames,wierdnames+arraySize,oldfriend)!=wierdnames+arraySize){
                cout<<"wierd things are not your friends bro!!"<<endl;
                cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
}else{
           s.delete_friend(oldfriend);
           validInput=true;//breaks the loop when input is right
            }

    }else{//if its the wrong data type
    cout<<"please enter a proper name!!"<<endl;
       cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout<<"----------------------------------------------------------------------"<<endl;
    }
    break;}
case 3:{
    s.print_friends();
    cout<<"----------------------------------------------------------------------"<<endl;
    break;}
case 4:{
    s.check_last_friend();
    cout<<"----------------------------------------------------------------------"<<endl;
    break;}
    case 5:{
    //code gives user to quit incase they chose other options that are not 5 and want to quit immediately
int num;
bool valid=false;
while(!valid){
        cout<<"----------------------------------------------------------------------"<<endl;
cout<<"finally want to leave the library?\n 1.yes\n 2.no\n"<<endl;
cin>>num;
if(cin.good()){//if input is right
   if(num==1){//if input is one terminate the code
        valid=true;
    break;
}else if(num==2){//if input is 2 ,continue and repeat execution of do while
    valid=true;
continue;
}else{//if input is an integer but not 1 or 2
cout<<"please enter 1 or 2!!"<<endl;
}
}else{//if input is wrong data type
cout<<"enter an integer only!!"<<endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
cout<<"thanks for using the friend library!!"<<endl;
}
break;
    }
default:{
    cout<<"invalid input!"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    break;
}
}
}

}while(result!=5);//stops when user chooses 5

return 0;
}
