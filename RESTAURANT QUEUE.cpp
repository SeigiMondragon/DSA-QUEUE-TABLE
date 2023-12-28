#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;





int main(){

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
int x = 0;
for(x=1;x<=10;x++){
    table.push(x);
}

do{


cout<< "Name of your design\n";
cout<<"Options: \n1.Enter the restaurant \n2.Release Table\n3.Show available table \n4.Quit \nEnter Your Choice: ";
cin>>inputchoice;

switch(inputchoice){
case 1:
    system("cls");
     cout<<"Welcome! Please enter your name: ";
    cin>>name;

    cout<<"Hello,  "<< name <<" Please choose a table number(1-10): "    ;
    cin>>inputtable;


    while(!table.empty()){
         if(inputtable==table.front()){

              chosenqueue.push(table.front());
                table.pop();


                   cout<<"Welcome " << name  <<"! Please proceed to table "<<inputtable<<endl<<endl;
                   break;
         }
         else{
            notchosen.push(table.front());
            table.pop();

         }


    }

    if(table.empty()){
        cout<< "Sorry, table "<<inputtable<< "is already occupied. Please Choose another table\n\n";
    }

table.swap(notchosen);

    while(!notchosen.empty()){
        table.push(notchosen.front());
        notchosen.pop();
    }
    break;





case 2:
cout<<"Table to be released?: ";
cin>>inputtable;

    while(!chosenqueue.empty()){
        if(inputtable==chosenqueue.front()){
            //table.push(chosenqueue.front());
            temp = chosenqueue.front();
            chosenqueue.pop();

            while(!temp<table.front()&&!table.empty()){
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





chosenqueue.swap(holdqueue);





    break;
case 3:
cout<<"Available Tables: ";
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
   exit(0);
    break;


}

}while(inputchoice!=4);



return 0;
}
