import java.util.Scanner;
public class Main
{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int hours = scan.nextInt();
        int minutes = scan.nextInt();
        scan.close();
        
        int mClock = hours * 60 + minutes;
        if(mClock < 24 * 0 + 45) { // 0시 45분 보다 작으면 전날로 계산
            mClock = mClock + 24 * 60 - 45;
        }
        else {
            mClock -= 45;
        }
        hours = mClock / 60;
        minutes = mClock % 60;
        System.out.println(hours + " " + minutes);
    }
}