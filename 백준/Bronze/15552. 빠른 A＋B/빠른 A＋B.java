import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws java.io.IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int testCase = Integer.parseInt(reader.readLine());
        
        for (int i = 0; i < testCase; i++) {
            String input = reader.readLine();
            StringTokenizer st = new StringTokenizer(input);
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            writer.write(a + b + "\n");
        }
        reader.close();
        writer.flush();
        writer.close();
    }
}