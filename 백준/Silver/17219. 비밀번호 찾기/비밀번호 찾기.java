import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            while (line != null && line.isEmpty()) line = br.readLine();
            if (line == null) break;
            String[] parts = line.split(" ");
            if (parts.length >= 2) {
                map.put(parts[0], parts[1]);
            }
        }

        for (int i = 0; i < M; i++) {
            String temp = br.readLine();
            if (temp == null) temp = "";
            String res = map.get(temp);
            if (res != null) System.out.println(res);
        }
    }
}