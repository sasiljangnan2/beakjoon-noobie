import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int maxdp[][] = new int[n][3];
        int smindp[][] = new int[n][3];
        for(int i=0; i<n; i++){
            String[] input = br.readLine().split(" ");
            for(int j=0; j<3; j++){
                int num = Integer.parseInt(input[j]);
                if(i==0){
                    maxdp[i][j] = num;
                    smindp[i][j] = num;
                }else{
                    if(j==0){
                        maxdp[i][j] = Math.max(maxdp[i-1][j], maxdp[i-1][j+1]) + num;
                        smindp[i][j] = Math.min(smindp[i-1][j], smindp[i-1][j+1]) + num;
                    }else if(j==1){
                        maxdp[i][j] = Math.max(maxdp[i-1][j-1], Math.max(maxdp[i-1][j], maxdp[i-1][j+1])) + num;
                        smindp[i][j] = Math.min(smindp[i-1][j-1], Math.min(smindp[i-1][j], smindp[i-1][j+1])) + num;
                    }else{
                        maxdp[i][j] = Math.max(maxdp[i-1][j], maxdp[i-1][j-1]) + num;
                        smindp[i][j] = Math.min(smindp[i-1][j], smindp[i-1][j-1]) + num;
                    }
                }
            }
        }        
       System.out.println(Math.max(maxdp[n-1][0], Math.max(maxdp[n-1][1], maxdp[n-1][2])) + " " + Math.min(smindp[n-1][0], Math.min(smindp[n-1][1], smindp[n-1][2])));
       
}}

