import java.util.*;
import java.util.Scanner;

public class Main {
    static class Edge {
        int to, cost;
        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }
    
    static class Node implements Comparable<Node> {
        int vertex, distance;
        Node(int vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }
        
        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.distance, other.distance);
        }
    }
    
    // 다익스트라 알고리즘
    static void dijkstra(int start, int n, List<List<Edge>> graph, int end) {
        int[] dist = new int[n + 1];
        boolean[] visited = new boolean[n + 1];
        
        // 거리 배열 초기화
        for (int i = 1; i <= n; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[start] = 0;
        
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        
        while (!pq.isEmpty()) {
            Node current = pq.poll();
            int u = current.vertex;
            
            if (visited[u]) continue;
            visited[u] = true;
            
            // 인접한 모든 노드 확인
            for (Edge edge : graph.get(u)) {
                int v = edge.to;
                int cost = edge.cost;
                
                // 더 짧은 경로 발견
                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    pq.offer(new Node(v, dist[v]));
                }
            }
        }
        System.out.println(dist[end]);
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 노드 수
        int m = scanner.nextInt(); // 간선 수
        List<List<Edge>> graph = new ArrayList<>();
        
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int cost = scanner.nextInt();
            graph.get(u).add(new Edge(v, cost));
        }
        int start = scanner.nextInt(); // 시작 노드
        int end = scanner.nextInt();   // 도착 노드
        dijkstra(start, n, graph, end);
    }
}
