import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.HashMap;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new java.io.OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            PriorityQueue<Integer> maxpq = new PriorityQueue<>(Collections.reverseOrder());
            PriorityQueue<Integer> minpq = new PriorityQueue<>();
            HashMap<Integer, Integer> Map = new HashMap<>();
            int K = Integer.parseInt(br.readLine());
            for (int j = 0; j < K; j++) {
                String[] input = br.readLine().split(" ");
                String command = input[0];
                int num = Integer.parseInt(input[1]);
                if (command.equals("I")) {
                    maxpq.offer(num);
                    minpq.offer(num);
                    Map.put(num, Map.getOrDefault(num, 0) + 1);
                } else {
                    if (maxpq.isEmpty())
                        continue;
                    if (num == 1) {
                        while (!maxpq.isEmpty()) {
                            int max = maxpq.poll();
                            if (Map.get(max) > 0) {
                                Map.put(max, Map.get(max) - 1);
                                break;
                            }
                        }
                    } else {
                        while (!minpq.isEmpty()) {
                            int min = minpq.poll();
                            if (Map.get(min) > 0) {
                                Map.put(min, Map.get(min) - 1);
                                break;
                            }
                        }
                    }
                }
            }
            if (maxpq.isEmpty() || minpq.isEmpty()) {
                bw.write("EMPTY\n");
                bw.flush();
            } else {
                boolean isEmpty = true;

                int max = 0, min = 0;
                while (!maxpq.isEmpty()) {
                    max = maxpq.poll();
                    if (Map.get(max) > 0) {
                        isEmpty = false;
                        break;
                    }

                }
                while (!minpq.isEmpty()) {
                    min = minpq.poll();
                    if (Map.get(min) > 0) {
                        isEmpty = false;
                        break;
                    }
                }
                if (isEmpty) {
                    bw.write("EMPTY\n");
                    bw.flush();
                    continue;
                }
                bw.write(max + " " + min + "\n");
                bw.flush();
            }
        }
    }
}
