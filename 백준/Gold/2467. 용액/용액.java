
import java.util.*;
import java.io.*;


public class Main {

	static int N;
	static int[] potions;
	static int min = Integer.MAX_VALUE;
	static int[] answer;
	
	public static void main(String[] args) throws Exception{
		init();
		
		solution();
		
		System.out.println(answer[0]+" "+answer[1]);
		
//		System.out.println(Arrays.toString(answer)+"///"+min);
	}
	
	static void solution() {
		int start = 0;
		int end = N-1;
		while(end>start) {
			int result = potions[start]+potions[end];
			if(Math.abs(result)<=min) {
				min = Math.abs(result);
				answer[0] = potions[start];
				answer[1] = potions[end];
			}
			if(result<0) {
				start++;
			}else if(result>0) {
				end--;
			}else {
				break;
			}
		}
	}
	
	
	static void init() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		String[] input = br.readLine().split(" ");
		potions = new int[N];
		for(int i=0;i<N;i++) {
			potions[i] = Integer.parseInt(input[i]);
		}
		answer = new int[2];
	}
}
