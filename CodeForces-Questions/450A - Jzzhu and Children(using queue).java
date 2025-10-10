import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class problem450A {

	public static void main(String[] args) {
		// input section
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] arr = new int[n];
		Queue<pair> q = new LinkedList<>();
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
			q.add(new pair(i + 1, arr[i]));
		}

		// output section
		int last = n;
		while (!q.isEmpty()) {
			int pos = q.peek().first;
			int ele = q.peek().second;
			q.remove();
			ele -= m;
			if (ele > 0) {
				q.add(new pair(pos, ele));
				last = pos;
			}

		}
		System.out.println(last);
		sc.close();
	}
}

class pair {
	public int first;
	public int second;

	public pair(int f, int s) {
		this.first = f;
		this.second = s;
	}
}
