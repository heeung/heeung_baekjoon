import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] destAlpha, srcAlpha;
    static String dest, src;
    static int N, M, cnt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        destAlpha = new int[52];
        srcAlpha = new int[52];

        src = br.readLine();
        dest = br.readLine();

        for (int i = 0; i < N; i++) {
            int now = src.charAt(i);
            if (now > 95) { // 소문자
                srcAlpha[now - 97]++;
            } else { // 대문자
                srcAlpha[now - 65 + 26]++;
            }
        }

        for (int i = 0; i < N; i++) { // 처음 비교
            int now = dest.charAt(i);
            if (now > 95) { // 소문자
                destAlpha[now - 97]++;
            } else { // 대문자
                destAlpha[now - 65 + 26]++;
            }
//            destAlpha[now]++;
        }

        if (compare(srcAlpha, destAlpha)) {
            cnt++;
        }

        for (int left = 0, right = N; right < M; left++, right++) {
            int leftAlpha = dest.charAt(left); // 얘는 빼고
            int rightAlpha = dest.charAt(right); // 얘는 더하고

            if (leftAlpha > 95) { // 소문자
                destAlpha[leftAlpha - 97]--;
            } else { // 대문자
                destAlpha[leftAlpha - 65 + 26]--;
            }

            if (rightAlpha > 95) { // 소문자
                destAlpha[rightAlpha - 97]++;
            } else { // 대문자
                destAlpha[rightAlpha - 65 + 26]++;
            }

            if (compare(srcAlpha, destAlpha)) {
                cnt++;
            }
        }

        System.out.println(cnt);
    }

    static boolean compare(int[] src, int[] dest) {
        for (int i = 0; i < 52; i++) {
            if (src[i] != dest[i]) {
                return false;
            }
        }
        return true;
    }
}