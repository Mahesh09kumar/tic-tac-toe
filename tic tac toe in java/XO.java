import java.util.*;

public class XO {
  char[][] a = new char[3][3];
  char winner =' ';
  int count = 9;
  
  public static void main(String[] args){
    XO game = new XO();
    game.initializeBoard();
    game.displayBoard();
  
    do {
      game.playerIn('X');
      game.updateBoard();
      game.checkWinner('X');
      if (game.winner != ' ' || game.count == 0) break;
      
      game.playerIn('O');
      game.updateBoard();
      game.checkWinner('O');
    } while(game.count != 0 && game.winner == ' ');

    if (game.winner != ' ') {
      System.out.println("Player " + game.winner + " wins!");
    } else {
      System.out.println("It's a draw!");
    }
  }

  public void initializeBoard() {
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        a[i][j] = ' ';
      }
    }
  }

  public void displayBoard() {
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        System.out.print(a[i][j]);
        if(j<2) {
          System.out.print("|");
        }
      }
      if(i<2) {  
        System.out.println("\n------");
      }
    }
    System.out.println();
  }

  public void updateBoard() {
    displayBoard();
  }

  public void playerIn(char pSign) {
    Scanner scn = new Scanner(System.in);
    int row, col;
    
    while(true) {
      System.out.println("\nPLAYER " + pSign + " TURN:");
      System.out.print("Enter row and col (1-3): ");
      row = scn.nextInt() - 1;
      col = scn.nextInt() - 1;

      if(row >= 0 && row < 3 && col >= 0 && col < 3 && a[row][col] == ' ') {
        a[row][col] = pSign;
        count--;
        break;
      } else {
        System.out.println("Invalid move. Try again.");
      }
    }
  }

  public void checkWinner(char pSign) {
    for(int i = 0; i < 3; i++) {
      if(a[i][0] == pSign && a[i][1] == pSign && a[i][2] == pSign) {
        winner = pSign;
      }
      if(a[0][i] == pSign && a[1][i] == pSign && a[2][i] == pSign) {
        winner = pSign;
      }
    }
    if(a[0][0] == pSign && a[1][1] == pSign && a[2][2] == pSign) {
      winner = pSign;
    }
    if(a[0][2] == pSign && a[1][1] == pSign && a[2][0] == pSign) {
      winner = pSign;
    }
  }
}
