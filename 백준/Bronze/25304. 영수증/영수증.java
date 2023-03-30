import java.util.Scanner;
public class Main
{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int cost = scan.nextInt();
        int forCount = scan.nextInt();
        
        int total = 0;
        for(int i = 0; i < forCount; i++) {
            int amount = scan.nextInt();
            int count = scan.nextInt();
            total += amount * count;
        }
        scan.close();
        
        if(cost == total) {
            System.out.println("Yes");
        }
        else {
            System.out.println("No");
        }
    }
}