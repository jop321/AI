#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include<stdlib.h>
#include <time.h>

void printnumber(int number){
    if (number == 99)
    {
        printf("  O ");
    }
    else if (number == 100)
    {
        printf("  T ");
    }
    else if (number < 10)
    {
        printf(" 0%d ",number);
    }
    else if (number>=10)
    {
        printf(" %d ",number);
    } 
}

void winner(int platerwinner){
  if (platerwinner == 0)
    {
        printf(" O WINNER");
        Sleep(100000);
    }
    else if (platerwinner == 1)
    {
        printf(" T WINNER");
        Sleep(100000);
    } 
    else if (platerwinner == 2)
    {
        printf(" DRAW ");
        Sleep(100000);
    }   

}

void table (int n,int *all){
    // printf(" %d ",*((all+1*n)+0));
    // printf(" %d ",*((all+2*n)+0));
    // printf(" %d ",*((all+3*n)+0));
    // printf(" %d \n",*((all+4*n)+0));
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {     
                printnumber(*((all+i*n)+j));
                if (j<n-1)
                {
                    printf("|");
                }else
                {
                    printf("\n");
                }   
            }
            if(i<n-1)
            for (int j = 0; j < (5*n)-1; j++)
            {
                printf("-");
            } 
            printf("\n");         
        }
}

void addarr(int n,int *all){
    int nub = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *((all+i*n)+j) = nub++;
        }    
    }
}

int inputbyplayer (int n,int player ,int *all){
    int input;
    if (player ==  0)
    {
        printf("player O = " );
        scanf("%d", &input);        
    }
    else if (player == 1)
    {        
        printf("player T = " );
        scanf("%d", &input);  
    }
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(input == *((all+i*n)+j)){
                    
                    if(player == 0){
                        *((all+i*n)+j) = 99;
                        player = 1;
                        return 0;   
                        }
                    else if(player == 1) {
                        *((all+i*n)+j) =100;
                        player = 0;
                        return 1;        
                        }
                }
            }
              
        }
    return 99;
}

int checkwinner(int n,int *all,int count){
    int check[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            check[i][j] = *((all+i*n)+j);
        }    
    }
    if (count < ((n*n)))
    {
        for (int i = 0; i < n; i++)
        {
        for (int j = 0; j < n; j++)
        {
            if (check[i][j] == 99 && check[i][j+1] == 100 && check[i][j+2] == 100 && check[i][j+3] == 99 && j < n-3)
            {
                return 0;
            }
            else if (check[i][j] == 100 && check[i][j+1] == 99 && check[i][j+2] == 99 && check[i][j+3] == 100 && j < n-3)
            {
                return 1;
            }
            else if (check[i][j] == 99 && check[i+1][j] == 100 && check[i+2][j] == 100 && check[i+3][j] == 99 && i < n-3)
            {
                return 0;
            }
            else if (check[i][j] == 100 && check[i+1][j] == 99 && check[i+2][j] == 99 && check[i+3][j] == 100 && i < n-3)
            {
                return 1;
            }
            else if (check[i][j] == 99 && check[i+1][j+1] == 100 && check[i+2][j+2] == 100 && check[i+3][j+3] == 99 && j < n-3 && i < n-3)
            {
                return 0;
            }
            else if (check[i][j] == 100 && check[i+1][j+1] == 99 && check[i+2][j+2] == 99 && check[i+3][j+3] == 100 && j < n-3 && i < n-3)
            {
                return 1;
            }          
        }   
        }
    }
    if (count == (n*n))
    {
        if(n == 5){
            if (check[0][0] == 99 && check[1][1] == 99 && check[2][2] == 99 && check[3][3] == 99 && check[4][4] == 99) return 0;
            else if (check[0][0] == 100 && check[1][1] == 100 && check[2][2] == 100 && check[3][3] == 100 && check[4][4] == 100) return 1;
            else if (check[4][0] == 99 && check[3][1] == 99 && check[2][2] == 99 && check[1][3] == 99 && check[0][4] == 99) return 0;
            else if (check[4][0] == 100 && check[3][1] == 100 && check[2][2] == 100 && check[1][3] == 100 && check[0][4] == 100) return 1;
            else if (check[0][0] == 99 && check[1][1] == 99 && check[1][2] == 99 && check[1][3] == 99 && check[0][4] == 99) return 0;
            else if (check[0][0] == 100 && check[1][1] == 100 && check[1][2] == 100 && check[1][3] == 100 && check[0][4] == 100) return 1;
            else if (check[0][0] == 99 && check[1][1] == 99 && check[0][2] == 99 && check[1][3] == 99 && check[0][4] == 99) return 0;
            else if (check[0][0] == 100 && check[1][1] == 100 && check[0][2] == 100 && check[1][3] == 100 && check[0][4] == 100) return 1;
            else if (check[2][0] == 99 && check[1][1] == 99 && check[0][2] == 99 && check[1][3] == 99 && check[2][4] == 99) return 0;
            else if (check[2][0] == 100 && check[1][1] == 100 && check[0][2] == 100 && check[1][3] == 100 && check[2][4] == 100) return 1;
        }
        else if(n == 6){
            if (check[0][0] == 99 && check[1][1] == 99 && check[2][2] == 99 && check[3][3] == 99 && check[4][4] == 99 && check[5][5] == 99) return 0;
            else if (check[0][0] == 100 && check[1][1] == 100 && check[2][2] == 100 && check[3][3] == 100 && check[4][4] == 100 && check[5][5] == 100) return 1;
            else if (check[5][0] == 99 && check[4][1] == 99 && check[3][2] == 99 && check[2][3] == 99 && check[1][4] == 99 && check[0][5] == 99) return 0;
            else if (check[5][0] == 100 && check[4][1] == 100 && check[3][2] == 100 && check[2][3] == 100 && check[1][4] == 100 && check[0][5] == 100) return 1;
            else if (check[0][0] == 99 && check[1][1] == 99 && check[1][2] == 99 && check[1][3] == 99 && check[1][4] == 99 && check[0][5] == 99) return 0;
            else if (check[0][0] == 100 && check[1][1] == 100 && check[1][2] == 100 && check[1][3] == 100 && check[1][4] == 100 && check[0][5] == 100) return 1;
            else if (check[0][0] == 99 && check[1][1] == 99 && check[0][2] == 99 && check[1][3] == 99 && check[0][4] == 99 && check[1][5] == 99) return 0;
            else if (check[0][0] == 100 && check[1][1] == 100 && check[0][2] == 100 && check[1][3] == 100 && check[0][4] == 100 && check[1][5] == 100) return 1;
            else if (check[2][0] == 99 && check[1][1] == 99 && check[0][2] == 99 && check[0][3] == 99 && check[1][4] == 99 && check[2][5] == 99) return 0;
            else if (check[2][0] == 100 && check[1][1] == 100 && check[0][2] == 100 && check[0][3] == 100 && check[1][4] == 100 && check[2][5] == 100) return 1;
        }
        return 2;
    }
}


int alltable (int n){
    bool play = true;
    int player = 0; 
    int all[n][n];
    int count = 0;
    bool checkerror = false; 
    addarr(n,(int *)all);
    while (play == true){
        system("cls");
        // printf("%d\n",count);
        if (checkerror == true) {
            printf("change number\n");
            }
        else if(checkerror == false){
            (" \n");
            }
        table(n,(int *)all);   
        printf("\n");
        
        switch (inputbyplayer(n,player,(int *)all))
        {
        case 0: player = 1; checkerror = false; count++; break;
        case 1: player = 0; checkerror = false; count++; break;
        case 99: checkerror = true; break;
        default: break;
        }
            switch (checkwinner(n,(int *)all,count))
        {
        case 0:
            system("cls");
            table(n,(int *)all);
            printf("\n");  
            return 0; 
        case 1:
            system("cls");
            table(n,(int *)all);
            printf("\n");
            return 1;
        case 2:
            system("cls");
            table(n,(int *)all);
            printf("\n\n");
            return 2;  
        default:
            break;
        }
    }        
}



void main(){
    bool check = true;
    srand(time(NULL));
        
    do
    {   if (rand()%2 == 0) winner(alltable(5));
        else winner(alltable(6));
        Sleep(100000);
    } while (check == true);
    
}
