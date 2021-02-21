#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;
#define S_FAIL 0
#define S_NORMAL 1
#define S_QUIT 2

class Game2048
{ 
    private:
     int status; //Game status
	 int data[4][4]; //Array
public:
	Game2048()
        {
            status= S_NORMAL;   //constructor called when object made
            data[4][4]={0};
        }
	
	


void moveup()
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=0,ri=j;
		for(i=1;i<4;i++)
		{
			if(data[i][j]!=0)
			{
				if(data[i-1][j]==0 || data[i-1][j]==data[i][j])    //function to move up
				{
					if(data[li][ri]==data[i][j])
					{
						data[li][ri]*=2;
						data[i][j]=0;
					}
					else
					{
						if(data[li][ri]==0)
						{
							data[li][ri]=data[i][j];
							data[i][j]=0;
						}
						else
						{
							data[++li][ri]=data[i][j];
							data[i][j]=0;
						}
					}
				}
				else li++;
			}
		}
	}
}

void movedown()
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=3,ri=j;
		for(i=2;i>=0;i--)
		{
			if(data[i][j]!=0)
			{
				if(data[i+1][j]==0 ||data[i+1][j]==data[i][j])         //function to move down
				{
					if(data[li][ri]==data[i][j])
					{
						data[li][ri]*=2;
						data[i][j]=0;
					}
					else
					{
						if(data[li][ri]==0)
						{
							data[li][ri]=data[i][j];
							data[i][j]=0;
						}
						else
						{
							data[--li][ri]=data[i][j];
							data[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
}

void moveleft()
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=0;
		for(j=1;j<4;j++)
		{
			if(data[i][j]!=0)
			{
				if(data[i][j-1]==0 || data[i][j-1]==data[i][j])        //function to move left
				{
					if(data[li][ri]==data[i][j])
					{
						data[li][ri]*=2;
						data[i][j]=0;
					}
					else
					{
						if(data[li][ri]==0)
						{
							data[li][ri]=data[i][j];
							data[i][j]=0;
						}
						else
						{
							data[li][++ri]=data[i][j];
							data[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}

void moveright()
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=3;
		for(j=2;j>=0;j--)
		{
			if(data[i][j]!=0)
			{
				if(data[i][j+1]==0 || data[i][j+1]==data[i][j])      //function to move right
				{
					if(data[li][ri]==data[i][j])
					{
						data[li][ri]*=2;
						data[i][j]=0;
					}
					else
					{
						if(data[li][ri]==0)
						{
							data[li][ri]=data[i][j];
							data[i][j]=0;
						}
						else
						{
						data[li][--ri]=data[i][j];
							data[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}








bool isOver() 
    {
        for (int i = 0; i < 4; ++i) 
        {
            for (int j = 0; j < 4; ++j) 
            {  
                     if ((j + 1 < 4) && (data[i][j] * data[i][j+1] == 0 || data[i][j] == data[i][j+1])) return false;
                if ((i + 1 < 4) && (data[i][j] * data[i+1][j] == 0 || data[i][j] == data[i+1][j])) return false;
            
            
                                 // If there are vacancies or the neighbors have the same, you can continue
                
            }
        }
        return true;
    }
    
  void restart() 
    {
        for (int i = 0; i < 4; ++i) 
        {
            for (int j = 0; j < 4; ++j)  //initialize all element to zero
            {
                data[i][j] = 0;
            }
        }
        randNew();
        randNew();
        status = S_NORMAL;
    }



 void randNew()
{ 
 int l1,r1;

while(1)
{
l1=rand()%4;
r1=rand()%4;
if(data[l1][r1]==0) //create random position of array
{
data[l1][r1]=2;
break;
}
}
}


     

	void processInput()
	{  
				char ch = getch();
		
	
		if(ch == 'Q')
		{
			status = S_QUIT;
		}
		else if (ch == 'R')
		{
			restart();
		}
		else if (ch == 'A')
		 {//Left
		moveleft();
		}
		else if (ch == 'W')
		 {//Up
			
			moveup();
			
		}
		else if (ch == 'D')
		 		{//To the right 
			
		moveright();
		}
		else if (ch == 'S')
		 {//Down
			
		 movedown();
			
		}
 
		
			 randNew(); 
			if (isOver())
			{
				char ch;
				status = S_FAIL;
				cout<<"You have fail the game";
				cout<<endl;
                           cout<<"do you want to continue press R else press Q";
                           ch=getch();
                        if(ch=='R')
                        {
                          restart();
                        }
                        else
                        status=S_QUIT;
			}

 }
int getStatus()
	{
		return status;
	}
	void display()
 {
           cout<<"\n\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(data[i][j]==0) cout<<"|  0";
			else
				cout<<"| "<<data[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t-----------------\n";	

 }
};


    



int main()
{
	
	             
	        
	
	    cout<<"\n Enter Q to Quit";
	    cout<<"\nEnter R to restart";
	    cout<<"\n Enter W to move up ";
	    cout<<"\n Enter A to move left";
	    cout<<"\n Enter S to move down";
	    cout<<"\n Enter D to move right";
	            Game2048 game;
                 game.restart();
                 game.display();

     do
	{
		
		game.processInput();
		game.display();                  
            
	}while(S_QUIT!=game.getStatus());
 
	

}


 






