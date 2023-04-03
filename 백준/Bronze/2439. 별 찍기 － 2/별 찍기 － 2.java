import java.util.Scanner;
public class Main
{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int lines = scan.nextInt();
        scan.close();
        for(int i = 0; i < lines; i++) {
            for(int j = 0; j < lines - i - 1; j++) {
                System.out.print(" ");
            }
            for(int j = 0; j < i + 1; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}