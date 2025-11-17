#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char grid[26][26][20];

void boardset()
{
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
        strcpy(grid[i][j]," ");
        }
    }

    strcpy(grid[0][2],"  ⚪");
    for(int i=2;i<25;i++)
    {
        strcpy(grid[0][i]," ⚪");
    }
    strcpy(grid[0][2],"   ");


    strcpy(grid[1][2],"\033[31m       --\033[0m");    
    for(int i=3;i<24;i++)
    {
        strcpy(grid[1][i],"\033[31m---\033[0m");    
    }

    for(int i=2;i<24;i++)
    {
        for(int j=0;j<24;j++)
        {
            strcpy(grid[i][j]," ⚪");
        }
        strcpy(grid[i][1],"\033[90m |\033[0m");
        strcpy(grid[i][24],"\033[90m |\033[0m");
        strcpy(grid[i][25]," ⚪");
    }

    strcpy(grid[24][2],"\033[31m       --\033[0m");    
    for(int i=3;i<24;i++)
    {
        strcpy(grid[24][i],"\033[31m---\033[0m");    
    }

    strcpy(grid[25][2],"  ⚪");
    for(int i=2;i<25;i++)
    {
        strcpy(grid[25][i]," ⚪");
    }
    strcpy(grid[25][2],"   ");
}

void board()
{
    printf("    0    ");
    for(int i=1;i<10;i++)
    {
        printf("%d  ",i);
    }
    for(int i=10;i<23;i++)
    {
        printf("%d ",i);
    }
    printf("  23\n");

    for(int i=0;i<26;i++)
    {
        if(i==0)
        {
            printf(" 0 ");
        }
        else
        {
            if(i>1 && i<11)
            {
                printf(" %d ",i-1);
            }
            else
            {
                if(i>9 && i<24)
                {
                    printf("%d ",i-1);
                }
                else
                {
                    if(i==25)
                    {
                        printf("23 ");
                    }
                }
            }
        }
        for(int j=0;j<26;j++)
        {
            printf("%s",grid[i][j]);
        }
        printf("\n");
    }
}

int game()
{
    int x,y;
    int game_end=0;
    while(game_end==0)
    {
        int redvalid = 0;
        while(redvalid==0)
        {
            printf("\n");
            printf("\033[31mRed's\033[0m turn: ");
            scanf ("%d%d",&x,&y);
            printf("\n");
            if(x==-1 && y==-1)
            {
                printf("Red has resigned.\n");
                printf("\033[90mBlack wins!\033[0m\n");
                return 0;
            }
            else
            {
                if(x==0 && y==0)
                {
                    printf("New game started.\n\n");
                    boardset();
                    board();
                    redvalid=1;
                }
                else
                {
                    if(strcmp(grid[0][y+2]," ⚫")!=0 && x==0 && y>0 && y<23 && strcmp(grid[0][y+2]," 🔴")!=0)
                    {
                        strcpy(grid[0][y+2]," 🔴");
                        redvalid=1;
                    }
                    else
                    {
                        if(strcmp(grid[x+1][y+1]," ⚫")!=0 && x>0 && y>0 && x<23 && y<23 && strcmp(grid[x+1][y+1]," 🔴")!=0)
                        {
                            strcpy(grid[x+1][y+1]," 🔴");   
                            redvalid=1;
                        }
                        else
                        {
                            if(strcmp(grid[25][y+2]," ⚫")!=0 && x==23 && y>0 && y<23 && strcmp(grid[25][y+2]," 🔴")!=0)
                            {
                                strcpy(grid[25][y+2]," 🔴");
                                redvalid=1;
                            }
                            else
                            {
                                printf("Please enter valid input.\n");
                            }
                        }
                    }
                }
            }
        }
        if(x==0 && y==0)
        {
            continue;
        }
        board();

        int blackvalid = 0;
        while(blackvalid==0)
        {
            printf("\n");
            printf("\033[90mBlack's\033[0m turn: ");
            scanf ("%d%d",&x,&y);
            printf("\n");
            if(x==-1 && y==-1)
            {
                printf("Black has resigned.\n");
                printf("\033[31mRed wins!\033[0m\n");
                return 0;
            }
            else
            {
                if(x==0 && y==0)
                {
                    printf("New game started.\n\n");
                    boardset();
                    board();
                    blackvalid=1;
                }
                else
                {
                    if(strcmp(grid[x+1][0]," 🔴")!=0 && y==0 && x>0 && x<23 && strcmp(grid[x+1][0]," ⚫")!=0)
                    {
                        strcpy(grid[x+1][0]," ⚫");
                        blackvalid = 1;
                    }
                    else
                    {
                        if(strcmp(grid[x+1][y+1]," 🔴")!=0 && x>0 && y>0 && x<23 && y<23 && strcmp(grid[x+1][y+1]," ⚫")!=0)
                        {
                            strcpy(grid[x+1][y+1]," ⚫");   
                            blackvalid=1;
                        }
                        else
                        {
                            if(strcmp(grid[x+1][25]," 🔴")!=0 && y==23 && x>0 && x<23 && strcmp(grid[x+1][25]," ⚫")!=0)
                            {
                                strcpy(grid[x+1][25]," ⚫");
                                blackvalid = 1;
                            }
                            else
                            {
                                printf("Please enter valid input.\n");
                            }
                        }
                    }
                }
            }
        }
        if(x==0 && y==0)
        {
            continue;
        }
        board();
    }

    return 0;
}

int main()
{
    printf("Let's play Twixt :)\n");
    printf("To resign, enter -1 -1\n");
    printf("To start new game, enter 0 0\n\n");

    boardset();
    board();

    game();

    return 0;
}