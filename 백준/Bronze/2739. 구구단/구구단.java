import java.util.Scanner;
public class Main
{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        scan.close();
        
        for(int i = 1; i <= 9; i++) {
            System.out.println(a + " * " + i + " = " + a * i);
        }
    }
}