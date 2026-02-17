
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static int min = Integer.MAX_VALUE;
    
    static void calculateDistance(int[][] distances, List<Integer> selectedChickens) {
        int sum = 0;
        for (int i = 0; i < distances.length; i++) {
            int minDist = Integer.MAX_VALUE;
            for (int chickenIdx : selectedChickens) {
                minDist = Math.min(minDist, distances[i][chickenIdx]);
            }
            sum += minDist;
        }
        min = Math.min(min, sum);
    }
        
    static void dfs(int[][] distances, List<Integer> selectedChickens, int chickenCount, int start, int M) {
        if (selectedChickens.size() == M) {
            calculateDistance(distances, selectedChickens);
            return;
        }
        
        for (int i = start; i < chickenCount; i++) {
            selectedChickens.add(i);
            dfs(distances, selectedChickens, chickenCount, i + 1, M);
            selectedChickens.remove(selectedChickens.size() - 1);
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        
        List<int[]> houses = new ArrayList<>();
        List<int[]> chickens = new ArrayList<>();
        
        for (int i = 0; i < N; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                int value = Integer.parseInt(line[j]);
                if (value == 1) {
                    houses.add(new int[]{i, j});
                } else if (value == 2) {
                    chickens.add(new int[]{i, j});
                }
            }
        }
        
        int[][] distances = new int[houses.size()][chickens.size()];
        for (int i = 0; i < houses.size(); i++) {
            for (int j = 0; j < chickens.size(); j++) {
                int[] house = houses.get(i);
                int[] chicken = chickens.get(j);
                distances[i][j] = Math.abs(house[0] - chicken[0]) + Math.abs(house[1] - chicken[1]);
            }
        }
        
        dfs(distances, new ArrayList<>(), chickens.size(), 0, M);
        System.out.println(min);
    }
}