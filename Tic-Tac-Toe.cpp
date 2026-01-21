#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std ;

void drawboard(char *spaces);
void playermove(char *spaces,char player);
void computermove(char *spaces,char computer);
bool checkwinner(char *spaces,char player,char computer);
bool checktie(char *spaces);


int main()
{
    
    char spaces[9] ={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X' ;
    char computer = 'O' ;
    bool running = true ;
    srand(time(0));
    drawboard(spaces);

    while (running)
    {
        playermove(spaces,player);
        drawboard(spaces);
        if (checkwinner(spaces,player,computer))
        {
            running = false;
            break;
        }
        else if (checktie(spaces))
        {
            running = false;
            break;
        }

        computermove(spaces,computer);
        drawboard(spaces);
        if (checkwinner(spaces,player,computer))
        {
            running = false;
            break;
        }
        else if (checktie(spaces))
        {
            running = false;
            break;
        }
    }
    
    system("pause");

    return 0 ;
}
void drawboard(char *spaces)
{
   cout<<endl;
   cout<<"     |     |     "<<endl;
   cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"   "<<endl;
   cout<<"_____|_____|_____"<<endl;
   cout<<"     |     |     "<<endl;
   cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"   "<<endl;
   cout<<"_____|_____|_____"<<endl;
   cout<<"     |     |     "<<endl;
   cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"   "<<endl;
   cout<<"     |     |     "<<endl;
   cout<<endl;


}
void playermove(char *spaces,char player)
{ 
    int number;
    do
    {
        cout<<"Enter number between (1-9) :- ";
        cin>>number;
        number--;
        if (number < 0 || number > 8)
        {
            cout<<"Invalid input! Please enter a number between 1-9."<<endl;
        }
        else if (spaces[number] != ' ')
        {
            cout<<"That space is already taken! Please choose another."<<endl;
        }
        else
        {
            spaces[number] = player;
            break;
        }
    } while (true);
}
void computermove(char *spaces,char computer)
{
    int number;
    cout<<"Computer turn :"<<endl;
    do
    {
        number = rand() % 9;
    } while (spaces[number] != ' ');

    spaces[number] = computer;
}


bool checkwinner(char *spaces,char player,char computer)
{
    int winning[8][3] = {
        {0,1,2},{3,4,5},{6,7,8}, // rows
        {0,3,6},{1,4,7},{2,5,8}, // cols
        {0,4,8},{2,4,6}          // diagonals
    };

    for (int i = 0; i < 8; i++)
    {
        char first = spaces[winning[i][0]];
        if (first != ' ' && first == spaces[winning[i][1]] && first == spaces[winning[i][2]])
        {
            if (first == player)
            {
                cout<<"YOU WIN!"<<endl;
            }
            else
            {
                cout<<"YOU LOSE!"<<endl;
            }
            return true;
        }
    }
    return false;
}
bool checktie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    cout<<"IT'S A TIE!"<<endl;
    return true;
}