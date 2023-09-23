import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number = 9;
        int[] array = new int[number];
        for (int i = 0; i < array.length; i++)
        {
            array[i] = input.nextInt();
        }
        input.close();
        int max = array[0];
        int max_times = 1;
        for (int i = 0; i < array.length; i++)
        {
            if (max < array[i]) {
                max = array[i];
                max_times = i + 1;
            }
        }
        System.out.println(max);
        System.out.println(max_times);
    }
}