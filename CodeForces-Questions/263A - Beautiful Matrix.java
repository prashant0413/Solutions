    import java.util.*;
     
    public class Main {
        public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          int[][] mat = new int[5][5];
          
          // for taking input
          for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
              mat[i][j] = sc.nextInt();
            }
          }
          
          // now logic to solve
          int row = -1;
          int col = -1;
          
          // taking indices where 1 is present
          for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
              if(mat[i][j] == 1) {
                row = i;
                col = j;
              }
            }
          }
          
          int ans = Math.abs(row - 2) + Math.abs(col - 2);
          System.out.println(ans);
      }
    }
