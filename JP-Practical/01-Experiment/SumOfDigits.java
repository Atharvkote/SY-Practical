import java.util.Scanner;

public class SumOfDigits {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a Mininmum Three Number : ");
        int number = sc.nextInt();
        int sum = 0;
        while(number > 0){
            sum =  sum + number % 10 ;
            number /= 10;
        }
        System.out.println(sum);
        sc.close();
    }
}
