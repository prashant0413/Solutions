import java.util.*;

public class problem151A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, k, l, c, d, p, nl, np;
		n = sc.nextInt();
		k = sc.nextInt();
		l = sc.nextInt();
		c = sc.nextInt();
		d = sc.nextInt();
		p = sc.nextInt();
		nl = sc.nextInt();
		np = sc.nextInt();
		int t1 = (k * l) / nl;
		int t2 = (c * d);
		int t3 = p / np;
		int toast = Integer.min(t1, Integer.min(t2, t3));
		toast = toast / n;
		System.out.println(toast);
		sc.close();
	}
}
