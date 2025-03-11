public class ConditionalStatement {
    public static void main(String[] args) {

        System.out.print("Number Divisble By 7 : [ ");
        for (int i = 1; i <= 100; i++) {
            if(i % 7 == 0 ){
                System.out.print(i + " ,");
            }
        }
        System.out.println(" ]");

        int sum = 0;
        for (int i = 100; i <= 200; i++) {
            if(i % 7 == 0 ){
                sum += i;
            }
        }
        System.out.println("Sum Of Number Divisble By 7 : [ "+ sum +" ]");
    }
} 
