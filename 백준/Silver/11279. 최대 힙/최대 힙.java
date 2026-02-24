
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static void swap(int[] heap, int i, int j) {
        int tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }

    static void insert(int[] heap, int size, int x) {
        heap[++size] = x;
        int idx = size;
        while (idx > 1) {
            int parent = idx / 2;
            if (heap[parent] < heap[idx]) {
                swap(heap, parent, idx);
                idx = parent;
            } else
                break;
        }
    }

    static void delete(int[] heap, int size) {
        heap[1] = heap[size--];
        int idx = 1;
        while (idx * 2 <= size) {
            int left = idx * 2;
            int right = idx * 2 + 1;
            int max = left;
            if (right <= size && heap[right] > heap[left]) {
                max = right;
            }
            if (heap[idx] < heap[max]) {
                swap(heap, idx, max);
                idx = max;
            } else
                break;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int size = 0;
        int[] heap = new int[N + 1];

        for (int i = 0; i < N; i++) {
            int x = Integer.parseInt(br.readLine());
            if (x == 0) {
                if (size == 0) {
                    sb.append(0).append("\n");
                } else {
                    sb.append(heap[1]).append("\n");
                    delete(heap, size);
                    size--;
                }
            } else {
                insert(heap, size, x);
                size++;
            }
        }
        System.out.print(sb.toString());
    }
}
