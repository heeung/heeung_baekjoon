import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static int N, K, cnt;
    static String str;
    static Stack<Character> stack;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        str = br.readLine();
        stack = new Stack<>();
        StringBuffer sb = new StringBuffer();

        for (int i = 0; i < N; i++) {
            Character cur = str.charAt(i);

            while (!stack.isEmpty() && cnt < K) {
                if (stack.peek() < cur) {
                    stack.pop();
                    cnt++;
                } else {
                    break;
                }
            }

            stack.push(cur);

            if (cnt == K) {
                sb.append(str.substring(i + 1));
                break;
            }
        }

        while (!stack.isEmpty()) {
            Character num = stack.pop();

            if (cnt < K) {
                cnt++;
            } else {
                sb.insert(0, num);
            }
        }

        System.out.println(sb);

        br.close();
    }
}