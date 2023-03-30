import java.util.Scanner;
public class Main
{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int count = scan.nextInt();
        scan.close();
        
        for(int i = 0; i < count / 4; i++) {
            System.out.print("long ");
        }
        System.out.print("int");
    }
}