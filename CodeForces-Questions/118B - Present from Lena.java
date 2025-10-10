import java.util.Scanner;

public class Program118B {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		for (int i = 0; i <= n; i++) {
			
			// printing spaces
			for (int k = 1; k <= n - i; k++)
				System.out.print("  ");
			
			// printing front numbers
			for (int j = 0; j <= i; j++) {
				System.out.print(j);
				if (j != i)
					System.out.print(" ");
			}
			
			// printing back numbers
			for (int j = i - 1; j >= 0; j--) {
				System.out.print(" " + j);
			}
			
			// for new line
			System.out.println();
		}
		
		for (int i = n - 1; i >= 0; i--) {
			
			// printing spaces
			for (int k = 1; k <= n - i; k++)
				System.out.print("  ");
			
			// printing front numbers
			for (int j = 0; j <= i; j++) {
				System.out.print(j);
				if (j != i)
					System.out.print(" ");
			}
			
			// printing back numbers
			for (int j = i - 1; j >= 0; j--) {
				System.out.print(" " + j);
			}
			
			// for new line
			System.out.println();
		}
	}
}
