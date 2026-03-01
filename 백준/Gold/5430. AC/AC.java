import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new java.io.OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String command = String.valueOf(br.readLine());
            int n = Integer.parseInt(br.readLine());
            String[] arr= br.readLine().replaceAll("[\\[\\]]", "").split(",");
            Deque<String> deque = new java.util.LinkedList<>();
            for (String s : arr) {
                if (!s.equals("")) {
                    deque.offer(s);
                }
            }
            boolean isReversed = false;
            boolean isError = false;
            for (char c : command.toCharArray()) {
                if (c == 'R') {
                    isReversed = !isReversed;
                } else if (c == 'D') {
                    if (deque.isEmpty()) {
                        isError = true;
                        break;
                    }
                    if (isReversed) {
                        deque.pollLast();
                    } else {
                        deque.pollFirst();
                    }
                }
            }
            if (isError) {
                bw.write("error\n");
            } else {
                StringBuilder sb = new StringBuilder();
                sb.append("[");
                while (!deque.isEmpty()) {
                    if (isReversed) {
                        sb.append(deque.pollLast());
                    } else {
                        sb.append(deque.pollFirst());
                    }
                    if (!deque.isEmpty()) {
                        sb.append(",");
                    }
                }
                sb.append("]\n");
                bw.write(sb.toString());
                bw.flush();
            }
        }
        bw.close();
        br.close();
    }
}
