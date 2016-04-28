//description of what file does
//descriptoin of method paramteers, what should do , and what it should reutrn.
//doccument line by line




/*
 
 Description of file: This file is responsible for recursively solving the 36X36 grid that has
 been passed to setGrid(char *onegrid).The file first cosntructs the 4X4 grid based on the specifications
 wihtin the 36X36 board. Using this constructed 4X4 grid, the file recursivley solves the 4X4 grid. 
 The file then has a method responsible for returning the found letter. The main method is
 responsible for calling the following methods, and therefore ultimatley responsible for 
 solving the board. This file just provides the methods neccessary for solving the board.
 
 
 Description of Algorithim:  1. Check to see if the specified location's letter has been filled in,if so
                                set char final to the letter found at the specified location, which will 
                                be later returned. Only if the letter has not been filled in at the specified
                                location continue to step 2.
                             2.  Check Rows if there exists only one possible solution to
                                replace an 'M'(case that there are 2 letters). Upon the first 
                                case of this proving true replace 'M' with appropriate letter, and 
                                jump back to step 1. If there exists no such case continue to
                                step 3.
                            3.  Check Cols if there exists only one possible solution to
                                replace an 'M'(case that there are 2 letters). Upon the first
                                case of this proving true replace 'M' with appropriate letter, and
                                jump back up to step 1. If there exists no such case continue to
                                step 4.
                            4.  Find any place there exists an 'M', parse the 'M''s col and 
                                rows. Replace 'M' with the letter that was not found during 
                                the parsing of 'M''s rows and cols. Jump to Step 1.
 
 
 
 
 void setGrid(char *onegrid)
 {
     Paramter:ptr to a 36x36 game board constructed in and passed by loadgrid() in load.c
     Responsibilites:   1) Construct a 4x4 game board based on specifcations in 36x36 board.
                        2)Convert number,which is disguised as a letter, present at end of
                        onegrid to be used as the specified locaiton to return letter.
    Returns:Returns nothing, fulfills  responsibilites above.
 }
 
 
 bool checkOneRow()
 {
    Paramter: Nothing.
    Responsibilites: Responsible for checking Rows in 4x4 grid to find a row where the exists only 
                     one possible solution ('M' = blank space) Ex: BXMC -> only possible solution is
                     'A' so row becomes BXAC. The method creates a temp array letters so as to keep
                     track of letters found wihtin row, and keeps track of the number of letters found 
                     in the row. If it finds that there exists only one solution for the row, it will replace
                     the 'M' with the proper letter, and return a boolean true. This is used for the method
                     that is orchestrating the algorihtim that solves the board
    Return: Return true if only one possible solution in a row is found, return false if no rows contain 
            only one possible solution.
 
 }
 
 
 bool checkOneCol()
 {
 Paramter: Nothing.
 Responsibilites: Responsible for checking Cols in 4x4 grid to find a row where the exists only
 one possible solution ('M' = blank space) ex: B        B
                                               X   ->   X
                                               M        A
                                               C        C
 The method creates a temp array letters so as to keep track of letters found wihtin col,
 and keeps track of the number of letters found in the col. If it finds that there exists
 only one solution for the col, it will replace  the 'M' with the proper letter, and return
 a boolean true. This is used for the method  that is orchestrating the algorihtim that solves 
 the board.
 Return: Return true if only one possible solution in a col is found, return false if no cols contain
 only one possible solution.
 
 }
 
 bool checkElse()
 
 {
    Paramter: Nothing
    Responsibilites: Responsible for parsing the 4X4 gird to find any 'M's that have not 
    otherwise been filled in by  checkOneCol()  and checkOneRow(). Upon finding an 'M'
    the method parses through the row in which the 'M' is found in and the col in which 
    the 'M' is found in to keep track of the letters found in a temp array of letters. 
    Upon finding a letter,a for instance the method will set aFound to true, and continue 
    parsing for letters upon finding another letter, c for instance,  it will also set 
    cFound to true. After the method has parsed the 'M''s row and col, the method will 
    reflect upon what letters it has found, and replace the letter that hasn't been found
    with the 'M'. In our current example it would replace 'M' with 'B'. Upon replacing a letter
    the method will return true.This is used for the method  that is orchestrating the algorihtim that solves
    the board.
 
    Return true if replaced a letter, false if it did not.
 
 }
 
 
 
 
 void findSol()
 {
    paramters: none
    responsibilites: orchestrate the component parts of the algorithim:checkOneRow(),
                     checkOneCol(),and checkElse() to correctly solve the board
                    and return the letter at the specified location.Continually check
                    if the letter at the specified locaiton has been filled in. If so 
                    set char final to that letter, which will be later returned and outputed.
    return: nothing.
 
 }
 
 
 
 char returnFinal()
 {
    parameters:none
    responsibilites: examine global varibale: char final, and return this char.
    return: returns global variable char final.
 
 }


*/










#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char grid[4][4];                    //4x4 grid used to find letter at specified location
int number;                         //specified location
int row=0;
int col=0;
char final;                        // letter at specified location which will be returned

void setGrid(char *onegrid)
{
    char *ptr;
    
    char *p;
    p = (onegrid);
    
    for(int y=0;y<4;y++){
        for(int x=0;x<4;x++){
            if(*(onegrid+4*x+y)==NULL){
                grid[x][y]='M';
            } else {
            grid[x][y]=(*(onegrid+4*x+y));
            }
        }
    }
    
    
    printf("%c",'\n');
    for(int i =0; i<=3;i++) //row
    {
        for(int j=0;j<=3;j++)// col
        {
            printf("%c",grid[i][j]);
            
        }
        printf("%c",'\n');
        
    }
    
    

    
    
    switch(*(onegrid+16))             //specified locaiton was embeded in one grid array .
    {
        case 'a': number = 0;
                  break;
        case 'b': number = 1;
            break;
        case 'c': number = 2;
            break;
        case 'd': number =3;
            break;
        case 'e': number =4;
                break;
        case 'f':number = 5;
            break;
        case 'g':number = 6;
            break;
        case 'h':number = 7;
            break;
        case 'i':number =8;
            break;
        case 'j':number =9;
            break;
        case 'k':number =10;
            break;
        case 'l':number =11;
            break;
        case 'm':number = 12;
            break;
        case 'n':number = 13;
            break;
        case 'o':number = 14;
            break;
        case 'p':number = 15;
            break;
        case 'q' :number = 16;
            break;
        case 'r':number = 17;
            break;
        case 's':number = 18;
            break;
        case 't':number = 19;
            break;
        case 'u' :number = 20;
            break;
        case 'v':number = 21;
            break;
        case 'w':number = 22;
            break;
        case 'x':number = 23;
            break;
        case 'y' :number = 24;
            break;
        case 'z' :number = 25;
            break;
            
        case 'X':number = 26;
            break;
        case 'Y':number = 27;
            break;
        case 'Z':number = 28;
            break;
        case 'W':number = 29;
            break;
    }
    

}



bool checkOneRow()
{
    char letters[10];
    bool aFound;
    bool bFound;
    bool cFound;
    bool oneInRow= false;
    int lettersFound =-1;
    
    
    
    for(int i =0; i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            if(grid[i][j]=='A')
            {
                letters[++lettersFound]='A';
                aFound=true;
            }
            else  if(grid[i][j]=='B')
            {
                letters[++lettersFound]='B';
                bFound=true;
            }
            else if(grid[i][j]=='C')
            {
                letters[++lettersFound]='C';
                cFound=true;
            }
        }
        if(lettersFound==1)
        {
            int k =0;
            while(k<=3)
            {
                if(grid[i][k]=='M')
                {
                    if(aFound && bFound)
                    {
                        grid[i][k]='C';
                        
                        
                        printf("%c",'\n');
                        for(int i =0; i<=3;i++)
                        {
                            for(int j=0;j<=3;j++)
                            {
                                printf("%c",grid[i][j]);
                                
                            }
                            printf("%c",'\n');
                            
                        }
                        
                        
                        
                        oneInRow=true;
                        return oneInRow;


                    }
                    else if(aFound&cFound)
                    {
                        grid[i][k] ='B';
                        
                        
                        printf("%c",'\n');
                        for(int i =0; i<=3;i++)
                        {
                            for(int j=0;j<=3;j++)
                            {
                                printf("%c",grid[i][j]);
                                
                            }
                            printf("%c",'\n');
                            
                        }
                        
                        
                        
                        
                        
                        oneInRow = true;
                        return oneInRow;

                    }
                    else{
                        grid[i][k]='A';
                        
                        
                        printf("%c",'\n');
                        for(int i =0; i<=3;i++)
                        {
                            for(int j=0;j<=3;j++)
                            {
                                printf("%c",grid[i][j]);
                                
                            }
                            printf("%c",'\n');
                            
                        }
                        
                        
                        
                        
                        
                        
                        oneInRow = true;
                        return oneInRow;
                    }
                }
                k++;
            }
            k=0;
        }
        letters[0]=NULL;
        letters[1]=NULL;
        letters[2]= NULL;
        
        aFound= false;
        bFound =false;
        cFound = false;
        oneInRow = false;

        lettersFound =-1;
        
    }

    
    return oneInRow;
    
}



bool checkOneCol()
{
    
    char letters[10];
    bool aFound;
    bool bFound;
    bool cFound;
    bool oneInCol= false;
    int lettersFound =-1;
    
    for(int j =0; j<=3;j++)
    {
        for(int i=0;i<=3;i++)
        {
            if(grid[i][j]=='A')
            {
                letters[++lettersFound]='A';
                aFound=true;
            }
            else  if(grid[i][j]=='B')
            {
                letters[++lettersFound]='B';
                bFound=true;
            }
            else if(grid[i][j]=='C')
            {
                letters[++lettersFound]='C';
                cFound=true;
            }
        }
        if(lettersFound==1)
        {
            int k =0;
            while(k<=3)
            {
                if(grid[k][j]=='M')
                {
                    if(aFound && bFound)
                    {
                        grid[k][j]='C';
                        
                        
                        printf("%c",'\n');
                        for(int i =0; i<=3;i++)
                        {
                            for(int j=0;j<=3;j++)
                            {
                                printf("%c",grid[i][j]);
                                
                            }
                            printf("%c",'\n');
                            
                        }
                        
                        
                        
                        
                        oneInCol=true;
                        return oneInCol;
                    }
                    else if(aFound&cFound)
                    {
                        grid[k][j] ='B';
                        
                        
                        
                        printf("%c",'\n');
                        for(int i =0; i<=3;i++)
                        {
                            for(int j=0;j<=3;j++)
                            {
                                printf("%c",grid[i][j]);
                                
                            }
                            printf("%c",'\n');
                            
                        }
                        
                        
                        
                        
                        
                        
                        oneInCol=true;
                        return oneInCol;
                    }
                    else{
                        grid[k][j]='A';
                        
                        printf("%c",'\n');
                        for(int i =0; i<=3;i++)
                        {
                            for(int j=0;j<=3;j++)
                            {
                                printf("%c",grid[i][j]);
                                
                            }
                            printf("%c",'\n');
                            
                        }
                        
                        
                        
                        
                        
                        oneInCol=true;
                        return oneInCol;
                    }
                }
                k++;
            }
            k=0;
        }
        letters[0]=NULL;
        letters[1]=NULL;
        letters[2]= NULL;
        
        aFound= false;
        bFound =false;
        cFound = false;
        oneInCol=false;
        lettersFound =-1;
        
    }

    return oneInCol;
}


bool checkElse()
{
    
    char letters[10];
    bool aFound;
    bool bFound;
    bool cFound;
    bool checkFill = false;
    int lettersFound =-1;

    for(int i =0;i<=3;i++)
    {
        for(int j =0;j<=3;j++)
        {
            if(grid[i][j]=='M')
            {
                
                //parss row
                
                int k =0;
                
                while(k<=3)
                {
                    if(grid[i][k]=='A')
                    {
                        letters[++lettersFound]='A';
                        aFound=true;
                    }
                    else if(grid[i][k]=='B')
                    {
                        letters[++lettersFound]='B';
                        bFound=true;
                    }
                    else if(grid[i][k]=='C')
                    {
                        letters[++lettersFound]='C';
                        cFound=true;
                    }
                    k++;
                    
                }
                
                k=0;
                while(k<=3)
                {
                    if(grid[k][j]=='A')
                    {
                        letters[++lettersFound]='A';
                        aFound=true;
                    }
                    else if(grid[k][j]=='B')
                    {
                        letters[++lettersFound]='B';
                        bFound=true;
                    }
                    else if(grid[k][j]=='C')
                    {
                        letters[++lettersFound]='C';
                        cFound=true;
                    }
                    k++;
                }
                
                
                if(aFound&&bFound)
                {
                    grid[i][j]='C';
                    
                    
                    
                    printf("%c",'\n');
                    for(int i =0; i<=3;i++)
                    {
                        for(int j=0;j<=3;j++)
                        {
                            printf("%c",grid[i][j]);
                            
                        }
                        printf("%c",'\n');
                        
                    }
                    
                    
                    
                    checkFill = true;
                    return checkFill;
                }
                else if(aFound&&cFound)
                {
                    grid[i][j]='B';
                    
                    
                    
                    
                    printf("%c",'\n');
                    for(int i =0; i<=3;i++)
                    {
                        for(int j=0;j<=3;j++)
                        {
                            printf("%c",grid[i][j]);
                            
                        }
                        printf("%c",'\n');
                        
                    }
                    
                    
                    
                    checkFill = true;
                    return checkFill;

                    
                }
                else if(bFound&&cFound)
                {
                    grid[i][j]='A';
                    
                    
                    
                    
                    printf("%c",'\n');
                    for(int i =0; i<=3;i++)
                    {
                        for(int j=0;j<=3;j++)
                        {
                            printf("%c",grid[i][j]);
                            
                        }
                        printf("%c",'\n');
                        
                    }
                    
                    
                    
                    
                    checkFill = true;
                    return checkFill;

                    
                    
                }
                
                
                
                
                
                
                
                
                
            }
        }
        
        letters[0]=NULL;
        letters[1]=NULL;
        letters[2]= NULL;
        
        aFound= false;
        bFound =false;
        cFound = false;
        checkFill =false;
        lettersFound =-1;
        
        
    }
    return checkFill;
}







void findSol()                                              
{
    printf("%c",'\n');
    for(int i =0; i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            printf("%c",grid[i][j]);
            
        }
        printf("%c",'\n');
        
    }

    if(grid[(number/6)-1][(number%6)-2]!='M'&&(grid[(number/6)-1][(number%6)-2]!='X')) //if at any time the location asked for is filled
    {
        final = grid[(number/6)-1][(number%6)-2];                                      //set char to letter at the location asked for.
    }
    else{
              if(checkOneRow())                                                        //if there exist
        {
            findSol();
        }
        else{
        
        if(checkOneCol())
        {
            findSol();
        }
        else{
            if(checkElse())
            {
                findSol();
            }
            else{
            }
        }
        }
        
    }
}








char returnFinal()
{
    return final;
}