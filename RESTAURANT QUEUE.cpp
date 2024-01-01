#include<iostream>
#include<iomanip>
#include<queue>
#include<windows.h>
using namespace std;

int main(){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int inputchoice;
int inputtable;
int temp;
string name;
queue<int>chosenqueue;
int y=0;
queue<int> table;
queue<int> showtable;
queue<int> notchosen;
queue<int>tempqueue;
queue<int>holdqueue;
queue<int>alreadyqueue;
bool tableAssigned = false;
int x = 0;
for(x=1;x<=10;x++){
    table.push(x);
}


SetConsoleTextAttribute(h,10);
  cout<<"    ___________________________________     _______________     ______________________ _______\n";
  cout<<"    7  77  7  77  _  77     77 77     7     7      77     7     7     77  _  77      7 7     7 \n";
  cout<<" ___|  ||  |  ||  _  ||  _  |!/ |  ___!     !__  __!|  7  |     |  ___!|  _  |!__  __! !__!  |\n";
  cout<<" 7  !  ||  |  ||  7  ||  7  |   !__   7       7  7  |  |  |     |  __|_|  7  |  7  7      !__!\n";
  cout<<" |     ||  !  ||  |  ||  |  |   7     |       |  |  |  !  |     |     7|  |  |  |  |      ____ \n";
  cout<<" !_____!!_____!!__!__!!__!__!   !_____!       !__!  !_____!     !_____!!__!__!  !__!      7__7 \n";

system("pause");
system("cls");

do{
SetConsoleTextAttribute(h,10);
cout<<"\n\n\n";
cout<<"\t\t\t\t\t\t\tOptions: \n\t\t\t\t\t\t\t1.Enter the restaurant \n\t\t\t\t\t\t\t2.Release Table\n\t\t\t\t\t\t\t3.Show available table \n\t\t\t\t\t\t\t4.Quit \n\t\t\t\t\t\t\tEnter Your Choice: ";
cin>>inputchoice;

while(inputchoice<0||inputchoice>4){
        SetConsoleTextAttribute(h,12);
 cout<<"\n\t\t\t\t\t\t\t============================================================================";
    cout<<"\n\n\t\t\t\t\t\t\t InvalidChoice. Select another: ";
    cin>>inputchoice;
    system("pause");
    system("cls");
}

switch(inputchoice){
case 1:
    SetConsoleTextAttribute(h,6);
     cout<<"\t\t\t\t\t\t\t============================================================================";
     cout<<"\n\n\t\t\t\t\t\t\tWelcome! Please enter your name: ";
    cin>>name;
    cout<<"\t\t\t\t\t\t\tHello,  "<< name <<" Please choose a table number(1-10): "    ;
    cin>>inputtable;

    while(inputtable<0||inputtable>10)
{
SetConsoleTextAttribute(h,12);
cout<<"\t\t\t\t\t\t\t============================================================================";
cout<<"\n\n\t\t\t\t\t\t\tTable is not available as of the moment. Please select another table: ";
cin>>inputtable;

}

    while(!table.empty()){
         if(inputtable==table.front()){

              chosenqueue.push(table.front());
                table.pop();
                SetConsoleTextAttribute(h,9);
                  cout<<"\t\t\t\t\t\t\t============================================================================";
                   cout<<"\n\n\t\t\t\t\t\t\tWelcome, " << name  <<"! Please proceed to table "<<inputtable<<endl<<endl;
                   break;
         }
         else{
            notchosen.push(table.front());
            table.pop();

         }


    }

 if(table.empty()&&inputtable!=table.back()){
 cout<<"\t\t\t\t\t\t\t============================================================================";
cout<< "\n\n\t\t\t\t\t\t\tSorry, table "<<inputtable<< " is already occupied. Please Choose another table\n\n";
         }
              system("Pause");
      system("cls");
table.swap(notchosen);

    while(!notchosen.empty()){
        table.push(notchosen.front());
        notchosen.pop();
    }
    break;


case 2:
cout<<"\t\t\t\t\t\t\t============================================================================";
SetConsoleTextAttribute(h,11);
cout<<"\n\n\t\t\t\t\t\t\tTable to be released?: ";
cin>>inputtable;

while(inputtable<0||inputtable>10)
{
SetConsoleTextAttribute(h,12);
cout<<"\t\t\t\t\t\t\t============================================================================";
cout<<"\n\n\t\t\t\t\t\t\tWe do not have table "<<inputtable<<". Please select another table: ";
cin>>inputtable;

}

    while(!chosenqueue.empty()){

        if(inputtable==chosenqueue.front()){
            temp = chosenqueue.front();
            chosenqueue.pop();



            while(temp>table.front()&&!table.empty()){
                    tempqueue.push(table.front());
                table.pop();
                if(temp<table.front())
                break;
            }

            table.swap(tempqueue);
            table.push(temp);

            while(!tempqueue.empty()){
                table.push(tempqueue.front());
                tempqueue.pop();
            }

        }else{
            holdqueue.push(chosenqueue.front());
            chosenqueue.pop();
        }
    }



if(temp!=inputtable){
    cout<<"\t\t\t\t\t\t\t============================================================================";
    cout << "\n\n\t\t\t\t\t\t\tTable " << inputtable << " is already released." << endl;
    cout << "\n\n\t\t\t\t\t\t\tSelect another table. ";
}else {
    cout<<"\t\t\t\t\t\t\t============================================================================";
    cout << "\n\n\t\t\t\t\t\t\tTable " << inputtable << " released." << endl;
    cout << "\n\n\t\t\t\t\t\t\tServing next customer. Table " << inputtable << " is ready." << endl << endl;
}
  system("Pause");
    system("cls");
chosenqueue.swap(holdqueue);
/*SetConsoleTextAttribute(h,3);
    cout<<"\t\t\t\t\t\t\t============================================================================";
    cout << "\n\n\t\t\t\t\t\t\tTable " << inputtable << " released." << endl;
    cout << "\n\n\t\t\t\t\t\t\tServing next customer. Table " << inputtable << " is ready." << endl << endl;
  system("Pause");
    system("cls");*/
temp=0;
    break;
case 3:
    SetConsoleTextAttribute(h,9);
cout<<"\t\t\t\t\t\t\t============================================================================";
cout<<"\n\n\t\t\t\t\t\t\tAvailable Tables: ";
    while(!table.empty()){
        showtable.push(table.front());
        cout<<table.front()<<" ";
        table.pop();
    }
    table.swap(showtable);
    cout<<endl;

    system("pause");
    system("cls");

    break;
case 4:
     SetConsoleTextAttribute(h,12);
    cout<<"\n\n\t\t\t\t\t\t\tExiting...";
   exit(0);
    break;


}

}while(inputchoice!=4);



return 0;
}
