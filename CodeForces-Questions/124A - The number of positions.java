import java.util.Scanner;

public class program124A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		System.out.println((n - a > b + 1) ? b + 1 : n - a);	
	}
}
