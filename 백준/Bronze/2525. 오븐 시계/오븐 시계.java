import java.util.Scanner;
public class Main
{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int hours = scan.nextInt();
        int minutes = scan.nextInt();
        int durations = scan.nextInt();
        scan.close();
        
        int mClock = hours * 60 + minutes;
        if(mClock >= 24 * 60 - durations) { // 다음 날이 넘어가는 시간
            mClock = mClock - 24 * 60 + durations;
        }
        else {
            mClock += durations;
        }
        hours = mClock / 60;
        minutes = mClock % 60;
        System.out.println(hours + " " + minutes);
    }
}