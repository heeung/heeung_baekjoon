import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;
import java.util.List;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		List<Integer> arr = new ArrayList<>();
		
		while (N != 0) {
			arr.add(N % 10);
			N /= 10;
		}
		
		Collections.sort(arr, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return (o2 - o1);
			}
		});
		
		for (int i : arr)
			System.out.print(i);
		
		sc.close();
	}
}
