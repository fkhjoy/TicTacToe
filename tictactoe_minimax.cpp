#include<bits/stdc++.h>

using namespace std;

const int inf = 2;

char board[10];

bool used[10];

bool pc;

int c = 0, x;

//initializing by space
void init()
{
    for(int i=1; i<10; ++i)board[i]=' ';
}

//it will print the board status
void print_board()
{
    printf("\n %c | %c | %c\n",board[1],board[2],board[3]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",board[4],board[5],board[6]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n\n",board[7],board[8],board[9]);
}

//checking board status
char check()
{
    for(int i=1;i<=7;i+=3)
    {
        char x = board[i+1];

        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&& x!=' ')
            return x;
    }
    for(int i=1; i<=3; i++)
    {
        char x = board[i];

        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&& x!=' ')
            return x;
    }
    int i=1;
    char x=board[i];
        if((board[i]==board[i+4])&&(board[i+4]==board[i+8])&& x!=' ')return board[i];
    i=3;
    x =board[i];

        if((board[i]==board[i+2])&&(board[i+2]==board[i+4])&& x!=' ')return board[i];
        if(c==9)return 'D';
    return 'N';

}

//algorithm to choose the best move
int minimax(bool maxplayer)
{

    if(check()!='N')
    {
        if(check()=='X')return 1;

        else if(check()=='O')return -1;

        else return 0;
    }

    if(maxplayer)
    {
        int v = -inf, mov = -1, val;

        for(int i=1;i<10; ++i)
        {
            if(!used[i])
            {
                used[i]=true;

                board[i]='X';

                val = minimax(false);

                if(val>v)
                {
                    v = val;
                    mov = i;
                }
                used[i]=false;
                board[i]=' ';
            }
        }
        if(mov ==-1) return 0;
        return v;
    }
    else
    {
        int v = inf, mov = -1, val;

        for(int i=1;i<10; ++i)
        {
            if(!used[i])
            {
                used[i]=true;
                board[i]='O';
                val = minimax(true);
                used[i] = false;
                board[i]=' ';
                if(val<v)
                {
                    v = val;
                    mov = i;
                }
            }
        }
        if(mov == -1)return 0;
        return v;
    }

}

//player's moves
void ply()
{
    if(pc)
    {
        int v = -inf, mov;
        for(int i=1; i<10; ++i)
        {
            if(!used[i])
            {
                used[i]=true;
                board[i]='X';
                int temp = minimax(false);
                board[i]=' ';
                used[i]=false;
                if(temp>v)
                {
                    v = temp;
                    mov = i;
                }
            }
        }
        board[mov]='X';
        c++;
        used[mov]=true;
        pc=false;
        print_board();
    }
    else
    {
        int i;
        scanf("%d", &i);
        if(!used[i])
        {
            c++;
            board[i]='O';
            used[i] = true;
            pc = true;
        }
        else
            cout<<"Invalid move. Try again"<<endl;
    }
}

int main()
{
    init();
    print_board();
    cout<<endl<<"Hey your Tic-Tac-Toe Board is ready."<<endl;
    cout<<"You'll play as 'O' and computer as 'X'. "<<"Play 1(st) or 2(nd)?: ";

    cin>>x;
    if(x==2)pc = true;

        while(true)
        {
            if(c==0)cout<<"Enter from 1 to 9"<<endl;
            ply();
            char ch = check();

            if(ch=='N')continue;

            else if(ch=='D')
            {
                cout<<endl<<"Match draw."<<endl;break;
            }

            else
            {
                if(ch=='X')cout<<"Foysal won."<<endl;
                else cout<<"Congrats !! You won though it's impossible"<<endl;
                break;
            }
        }
    return 0;
}
