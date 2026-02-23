
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static void binarySearch(long[] arr, long target) {
        long left = 1;
        long right = 0;
        for (long v : arr) {
            if (v > right) right = v;
        }
        long result = 0;
        while (left <= right) {
            long mid = (left + right) / 2;
            long count = 0;
            for (long v : arr) {
                count += v / mid;
            }
            if (count >= target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        System.out.println(result);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int K = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);
        long[] arr = new long[K];
        for (int i = 0; i < K; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }
        if (K == 1) {
            System.out.println(arr[0] / N);
            return;
        }
        binarySearch(arr, N);
    }
}
