import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static class Eat implements Comparable<Eat>{
		int size;
		int cnt;
		int idx;
		public Eat(int size, int cnt, int idx) {
			this.size = size;
			this.cnt = cnt;
			this.idx = idx;
		}
		@Override
		public int compareTo(Eat o) {
			return o.size - this.size;
		}
	}	
	static int N, K;;
	static boolean[] check;
	static int[][] arr;
	static PriorityQueue<Eat> eats = new PriorityQueue<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		arr = new int[2][N];
		
		st = new StringTokenizer(br.readLine());
	
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int n = Integer.parseInt(st.nextToken());
			
			sum += n;
			if (sum < K) {
				arr[0][i] = sum;
				arr[1][i] = ++cnt;
			} else {
				arr[0][i] = sum;
				arr[1][i] = ++cnt;
				cnt = 1;
				sum = n;
			}
			eats.offer(new Eat(arr[0][i], arr[1][i], i));
		}
		
//		System.out.println(Arrays.toString(arr[0]));
//		System.out.println(Arrays.toString(arr[1]));
		
		check = new boolean[N];
		cnt = 0;
		sum = 0;
		while (!eats.isEmpty()) {
			Eat cur = eats.poll();
			
			if (!check[cur.idx] && !check[cur.idx - (cur.cnt - 1)] && cur.size >= K) {
				cnt++;
				sum += cur.size;
				
				int n = cur.cnt;
				while (n-- > 0) {
					check[cur.idx--] = true;
				}
			}
		}
		
//		System.out.println(Arrays.toString(check));
//		System.out.println("sum : " + sum);
//		System.out.println("cnt : " + cnt);
		System.out.println(sum - (cnt * K));

	}

}