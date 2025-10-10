import java.util.Scanner;

public class program221A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		
		System.out.print(n + " ");
		for (int i = 1; i < n; i++)
			System.out.print(i + " ");
	}
}
