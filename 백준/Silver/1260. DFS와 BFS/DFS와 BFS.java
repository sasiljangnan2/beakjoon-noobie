
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static LinkedList<Integer>[] adj;
    static boolean[] visited;
    static StringBuilder dfsarr = new StringBuilder();
    static StringBuilder bfsarr = new StringBuilder();

    public static void dfs(int v) {
        visited[v] = true;
        dfsarr.append(v).append(' ');
        for (int nx : adj[v]) {
            if (!visited[nx])
                dfs(nx);
        }
    }

    public static void bfs(int start) {
        boolean[] vis = new boolean[adj.length];
        LinkedList<Integer> q = new LinkedList<>();
        q.add(start);
        vis[start] = true;
        while (!q.isEmpty()) {
            int cur = q.removeFirst();
            bfsarr.append(cur).append(' ');
            for (int nx : adj[cur]) {
                if (!vis[nx]) {
                    vis[nx] = true;
                    q.add(nx);
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int V = Integer.parseInt(st.nextToken());

        adj = new LinkedList[N + 1];
        for (int i = 1; i <= N; i++)
            adj[i] = new LinkedList<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
            adj[b].add(a);
        }
        for (int i = 1; i <= N; i++) Collections.sort(adj[i]);
        visited = new boolean[N + 1];
        dfs(V);
        bfs(V);
        System.out.println(dfsarr.toString());
        System.out.println(bfsarr.toString());
    }
}
