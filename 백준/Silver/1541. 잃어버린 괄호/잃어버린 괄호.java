
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Boolean isFirst = false;
        String[] input = br.readLine().split("-");
        for (String s : input) {
           String[] array = s.split("\\+");
            int sum = 0;
            for (String num : array) {
                sum += Integer.parseInt(num);
            }
            if (input[0].equals(s) && !isFirst) {
                input[0] = String.valueOf(sum);
                isFirst = true;
            } else {
                input[0] = String.valueOf(Integer.parseInt(input[0]) - sum);
            }
        }
        System.out.println(input[0]);
    }
}
