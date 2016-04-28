#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

///robustness what if they fuck up the input .
//assumes that the program opens up a speciifc file.
//how do we build the program in the terminal

//1.Assume that they enter into text.txt

char* loadgrid(){
    FILE *infile;
    infile = fopen("Text.txt", "r");
    char buffer[256];
    FILE *outfile;
    outfile = fopen("rest.txt", "w");
    char *indices=NULL;
    char board[6][6];
    char letters[5];
    char bufferrest[256];
    int indexofoutput=0;
    char newbufferrest[256];
    char *ptr;
    int i=0;
    int ret[256];
    int x,y,j,k=0; //x is the column, y is the row
    int f=0;
    char grid[4][4];
    char* onegrid;
    char newline='\n';
    
    for(int i=0;i<=6; i++){
        for (int j=0;j<=6;j++){
            board[i][j]=NULL;
        }
    }
    
    if(infile==NULL) perror ("Error opening file");
    else{
        
        int index1=0;
        while (fgets(buffer, 256, infile)){
            //  printf("This is the buffer %s\n", buffer);
            indices=strtok(buffer,",");
            while(indices!=NULL){
                //    printf("The indices are %s ,", indices);
                //letters[i]='a';
                if(*indices=='A'){
                    letters[f]='A';
                    f++;
                } else if(*indices=='B'){
                    letters[f]='B';
                    f++;
                } else if(*indices=='C'){
                    letters[f]='C';
                    f++;
                }
                
                *(ret+i)=strtol(indices, &ptr, 10);
                //  printf("The ret integers are %d\n , ", ret[i]);
                indices=strtok(NULL,",");
                i++;
                indexofoutput++;
                
            }
            
            while(fscanf(infile, "%s[^\n] ",&bufferrest)!=EOF){
                
                fprintf(outfile, "%s \n",bufferrest);
            }
            
            
            fclose(infile);
            fclose(outfile);
            
        }
        
    }
    
    infile = fopen("Text.txt", "w");
    outfile = fopen("rest.txt", "r");
    while(fscanf(outfile, "%s [^\n] ",&newbufferrest)!=EOF){
        
        fprintf(infile, "%s \n",newbufferrest);
    }
    fclose(infile);
    fclose(outfile);
    
    for(i=0; i<=3; i++){
        if(ret[i]>=6){
            x=ret[i]%6;
            y=ret[i]/6;
            if(x==0){
                y-=1;
                x=5;
            }else{
                x-=1;
            }
            board[x][y]='X';
        }else{
            x=ret[i]-1;
            board[x][0]='X';
        }
    }
    for(k=0;k<ret[4];k++){
        x=(ret[6+(2*k)]%6);
        y=(ret[6+(2*k)]/6);
        if(x==0){
            y-=1;
            x=5;
        }else{
            x-=1;
        }
        board[x][y]=letters[k];
        for(int i=0;i<=6; i++){
            for (int j=0;j<=6;j++){
                grid[i][j]=NULL;
            }
        }
        //accidentally prints out extra C
        for(int i =0;i<=5;i++)//row
        {
            for(int j=0;j<=5;j++){
                if(board[i][j]=='X'){
                    grid[i-1][j-1]=board[i][j];
                }
            }
            
        }
        
        for(int i=0;i<5;i++){
            //move letters in outer, top layer into the 4x4 grid
            if(board[i+1][0]!=NULL && grid[i][0]=='X'){
                grid[i][1]=board[i+1][0];
            } else if(board[i+1][0]!=NULL && grid[i][0]==NULL){
                grid[i][0]=board[i+1][0];
            }
            //move letters in outer,left layer into the 4x4 grid
            if(board[0][i+1]!=NULL && grid[0][i]=='X'){
                grid[1][i]=board[0][i+1];
            } else if(board[i][1]!=NULL && grid[i][0]==NULL){
                grid[0][i]=board[0][i+1];
            }
            //move letters in outer, bottom layer into the 4x4 grid
            if(board[i+1][5]!=NULL && grid[i][3]=='X'){
                grid[i][2]=board[i+1][5];
            } else if(board[i+1][5]!=NULL && grid[i][3]==NULL){
                grid[i][3]=board[i+1][5];
            }
            //move letters in outer,right layer into the 4x4 grid
            if(board[5][i+1]!=NULL && grid[3][i]=='X'){
                grid[2][i]=board[5][i+1];
            } else if(board[5][i+1]!=NULL && grid[3][i]==NULL){
                grid[3][i]=board[5][i+1];
            }
            
            
        }
        
        
        
        onegrid=(char*) malloc(sizeof(char)*36);
        //assert(onegrid != NULL);
        
        for(y=0; y<4;y++){
            for(x=0;x<4;x++){
                //*(onegrid + 4y+x)=grid[x][y];
                onegrid[4*y+x]=grid[x][y];
            }
        }
        int returnLetterNumber =ret[indexofoutput-1]+97;
        if(returnLetterNumber>122)
        {
            if(returnLetterNumber==123)
            {
                returnLetterNumber = 88;  //26
            }
            else if (returnLetterNumber==123)//27
            {
                returnLetterNumber = 89;
            }
            else if (returnLetterNumber==124)//28
            {
                returnLetterNumber = 90;
            }
            else if(returnLetterNumber==125)
            {
                returnLetterNumber = 87;    //29
            }
            else{
                printf("%s","the requested output is not in the 4X4 grid");
            }
        }
        onegrid[16]=ret[indexofoutput-1]+97;
       
    }
    
    //assert( 0 );
    
    return onegrid;
}
