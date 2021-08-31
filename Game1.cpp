#include <iostream>
using namespace std;

char game[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;
bool draw=false;

void board()
{
    system("cls");
    cout<<"\t\t\t\tTIC TAC TOE \n";
    cout<<"\t\tPlayer1 [X]\n";
    cout<<"\t\tPlayer2 [O]\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<game[0][0]<<"  |  "<<game[0][1]<<"  |  "<<game[0][2]<<"  \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<game[1][0]<<"  |  "<<game[1][1]<<"  |  "<<game[1][2]<<"  \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<game[2][0]<<"  |  "<<game[2][1]<<"  |  "<<game[2][2]<<"  \n";
    cout<<"\t\t\t\t     |     |     \n";
}
void player_turn()
{
   int choice;
   if(turn=='X')
    cout<<"Player1 [X] turn: ";

   if(turn=='O')
    cout<<"Player1 [O] turn: ";

   cin>>choice;

   switch(choice)
    {
        case 1: row=0;column=0; break;
        case 2: row=0;column=1; break;
        case 3: row=0;column=2; break;
        case 4: row=1;column=0; break;
        case 5: row=1;column=1; break;
        case 6: row=1;column=2; break;
        case 7: row=2;column=0; break;
        case 8: row=2;column=1; break;
        case 9: row=2;column=2; break;
        default:
            cout<<"\nInvalid Input! Please try again.\n";
    }
    if(turn=='X' && game[row][column]!='X' && game[row][column]!='O')
    {
        game[row][column]='X';
        turn='O';
    }
    else if(turn=='O' && game[row][column]!='X' && game[row][column]!='O')
    {
       game[row][column]='O';
       turn='X';
    }
    else
    {
       cout<<"\nPlace filled! Please try again.\n\n";
       player_turn();
    }
    board();
}
bool gameover()
{
// check win
for(int i=0;i<3;i++)
        if((game[i][0] == game[i][1] && game[i][1] == game[i][2]) || (game[0][i] == game[1][i] && game[0][i] == game[2][i]))
        return false;

if((game[0][0] == game[1][1] && game[0][0] == game[2][2]) || (game[0][2] == game[1][1] && game[0][2] == game[2][0]))
    return false;


// to continue
for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    if(game[i][j]!='X' && game[i][j]!='O')
    return true;


// draw
draw=true;
return false;
}

int main()
{
    while(gameover())
    {
        board();
        player_turn();
        gameover();
    }
if(turn=='X' && draw==false)
    cout<<"\nPlayer2 [O] wins!! Congratulations!\n";

else if(turn=='O' && draw==false)
    cout<<"\nPlayer1 [X] wins!! Congratulations!\n";

else
    cout<<"\n\t\t\t\tAWWWW KHICHDI PAK GAI!!\n";
}

// End of program
