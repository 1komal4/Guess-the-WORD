#include<iostream>
#include<windows.h> //
#include<cstring>  //for getline fucntion
#include<cstdlib>  //for using rand()
using namespace std;
void display();
int GameFunction();
int main()
{
	string name;
	cout<<"Enter Name  :   ";  //getline will read the whole string and store into the variable
	getline(cin,name);
	cout<<endl;
	
	
	int score=0;
	char input; //to ask whether want to play agian or not
	do
	{ 
	    system("cls");  //to clear screen
	    display();  //it will explain the game and rules
	    score=score+GameFunction(); //it will add the score by 1 when player will ans correctly 
		cout<<"Would you Like to play agin  y/n :  ";
		cin>>input;
	}
	
	while(input!='n');
	cout<<name<<" Your score is "<<score;
	cout<<endl<<endl<<endl;
	
}


void display()
{
	cout<<"***********************WORD SEARCHING GAME**************************\n"<<endl;
	cout<<"A Puzzle of words alphabets is shown on screen.You Have to guess a Hidden correct"<<endl;
	cout<<"word from the puzzle.For each correct guessing you will one score"<<endl<<endl;
}


int GameFunction()
{
	//array[index][i];
	string array[10]={"Python","Java","C++","Php","Hello","HTML","CSS","Data Structure","C","Goodbye"}; //words to be guess
	char matrix[10][10];//randomly generating alphabets
	int r;
	int c;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++){
			r=rand()%26;    //r=0
			c='a'+r;  //c=a+0,c=97+0=a// ascii value
			matrix[i][j]=c;
		}
	}
	
	int index=rand()%10;  //for placing a particular word
	string output=array[index];
	
	if(array[index].length()%2==0)  //4%2==0 //python is on 0th index
	{
		//horizontally
		int row=rand()%10;
		int col=rand()%3;
		for(int i=0;array[index][i]!='\0';i++,col++)
		{
			matrix[row][col]=array[index][i];
		}
	}
	else
	{
		//vertically
		int row=rand()%3;
		int col=rand()%10;
		for(int i=0;array[index][i]!='\0';i++,row++)
		{
			matrix[row][col]=array[index][i];
		}
	}
	
	
	cout<<"            Puzzle"<<endl<<endl;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<matrix[i][j]<<" ";
			Sleep(100);  //to display puzzle in slow 
		}
		cout<<"\n";
   }
          cout<<"\n";
          
	string guess;
    int hint;
    cout<<"Press 1 for guess input    "<<endl;
    cout<<"Press 2 for see the hint   "<<endl;
    
    a://It will execute the code according to the pressed no.
    cout<<"Enter input :    ";
    cin>>hint;
    cout<<endl;
    
    if(hint==1)
    {
    	cout<<"Enter guessing word :  ";  //to guess direclty
    	cin>>guess;
    	cout<<endl;
	}
	else if (hint==2)
	{
		cout<<"The guessing word size is :    "<<output.length()<<endl;  //to get an hint
			cout<<"Enter guessing word :         ";  //to guess direclty
    	cin>>guess;
    	cout<<endl;
	}
	else
	{
		cout<<"Enter valid input    "<<endl;
		goto a;  
	}
	if(output==guess) 
	{
		cout<<"Congratualtions !! You Guessed the right word "<<endl<<endl;
		return 1;
	}
    
}


