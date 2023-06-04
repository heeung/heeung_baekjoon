import java.io.*;
import java.util.*;

public class Main {
	static class Ball implements Comparable<Ball>{
		int id;
		int color;
		int weight;
		public Ball(int id, int color, int weight) {
			this.id = id;
			this.color = color;
			this.weight = weight;
		}
		@Override
		public int compareTo(Ball o) {
			if (this.weight == o.weight) {
				return this.color - o.color;
			}
			return this.weight - o.weight;
		}
		
	}
	static int N;
	static ArrayList<Ball> balls;
	static int[] sum, ret;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		balls = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			
			int color = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			balls.add(new Ball(i, color, weight));
		}
		sum = new int[200001];
		ret = new int[N];
		Collections.sort(balls);
		
		int all = 0;
		int preWeight = 0;
		int cntEqual = 1;
		HashMap<Integer, Integer> check = new HashMap<>();
		for (int i = 0; i < N; i++) {
			Ball now = balls.get(i);
			
			sum[now.color] += now.weight;
			all += now.weight;
			
			if (preWeight == now.weight) {
				cntEqual++;
				if (check.containsKey(now.color)) {
					ret[now.id] = all - sum[now.color] - ((cntEqual - (check.get(now.color) + 1)) * now.weight);
				} else {
					ret[now.id] = all - sum[now.color] - ((cntEqual - 1) * now.weight);
				}
			} else {
				check.clear();
				cntEqual = 1;
				ret[now.id] = all - sum[now.color];
			}
			preWeight = now.weight;
			
			if (check.containsKey(now.color)) {
				check.put(now.color, check.get(now.color) + 1);
			} else {
				check.put(now.color, 1);
			}
		}
		
		for (int i = 0; i < N; i++) {
			System.out.println(ret[i]);
		}
	}

}