#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i, j,box,row,col,freespace=9;
char playersign='X',compsign='O';
char winner =' '; //x is the player.
void start_game();
void playerinput();
void updateboard();
void computerinput();
void checkwinner();
void freecell();

char board[3][3];

int main(){
	//storing blank char in board
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			board[i][j]=' ';
		}
	}
	start_game();
	do{
	    playerinput();
	    freecell();
	    if(winner!=' '){
	    	continue;
		}
	    computerinput();
	    freecell();
	    
    }while(winner==' ');
    
    
    winner:
    if(winner=='O'){
    	printf("\n\n You lose. %c won",winner);
	}
	else if(winner=='X'){
		printf("\n\nyou(%c) won the match ",winner);
	}
	else{
		for(i=0;i<3;i++){
		    for(j=0;j<3;j++){
			    if(board[i][j]==' '){
				    board[i][j]=playersign;
				    printf("\n\nyour move");
	                updateboard();
                    checkwinner();
                    goto winner;
                }
		    }
	    }
	    printf("\n\nThe match is DRAW");
    }
    return 0;

}
void start_game(){
	
    printf("\t    X O \n\n");
	int count=1; 
    for (i=0;i<3;i++){
    	printf("\n\t");
        for(j=0;j<3;j++){
        	printf("%d",count++);
        	if(j<2){
        		printf(" | ");
			}    	
		}
		if(i<2){
		printf("\n\t----------");
	    }    
    }
    printf("\n\n\n");
}
void checkwinner() {
    for(i=0;i<3;i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
        	winner = board[i][0];
        }
    }
    for(i=0;i<3;i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
        	winner = board[0][i];   
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    	winner = board[0][0];   
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    	winner = board[0][2];   
    }
}
void freecell(){
	freespace--;
	if(freespace==1){
		winner= 'd';
	}
	checkwinner();
}
void updateboard(){
    for(i=0;i<3;i++){
    	printf("\n\t");
    	for(j=0;j<3;j++){
    		printf("%c", board[i][j]);
    		if(j<2){
    			printf(" | ");
			}
		}
		if(i<2){
		printf("\n\t--------");
	    }
	}  	
}
void playerinput(){    

    printf("\n\n you playing  X \n enter the place (1-9) : ");
    scanf("%i",&box);
    row = (box-1)/3;
	col = (box-1)%3;
	
    if(board[row][col]!=' '){
    	printf("invalid input \n Enter again.\n");
	    playerinput();    
	}
	else{
	board[row][col] = playersign;
	updateboard();	
	}
}
void computerinput(){
	printf("\n\n computer's move :\n\n");
	comp:
	srand(time(NULL));
	row=(rand()% 3);
	col=(rand()% 3);
	
	if(board[row][col]!=' '){
	    goto comp;	
	}
	else{
	    board[row][col] = compsign;
        updateboard();
	}
}

