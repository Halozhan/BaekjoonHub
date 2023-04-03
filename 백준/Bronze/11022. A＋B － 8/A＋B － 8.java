import java.util.Scanner;
public class Main
{
    public static void main(String[] args) throws java.io.IOException {
        Scanner scan = new Scanner(System.in);
        int count = scan.nextInt();
        for(int i = 0; i < count; i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            System.out.println("Case #" + (i + 1) + ": " + a + " + " + b + " = " + (a + b));
        }
        scan.close();
    }
}