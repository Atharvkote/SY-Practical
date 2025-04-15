public class Main {

    public class Shape {
        // ...existing code...
    }

    public static class CustomException extends Exception {
        public CustomException(String message) {
            super(message);
        }
    }

    public static void main(String[] args) {
        try {
            System.out.println("Hello World!");

            boolean simulateError = true;
            if (simulateError) {
                throw new CustomException("This is a custom exception.");
            }
            if (simulateError) {
                throw new ArithmeticException("This is a custom exception.");
            }

            int result = divide(10, 0); // This will throw an ArithmeticException
            System.out.println("Result: " + result);

        } catch (CustomException e) {
            System.out.println("Caught CustomException: " + e.getMessage());
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException occurred: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        } finally {
            System.out.println("Execution completed.");
        }
    }

    // Method to demonstrate exception handling
    public static int divide(int a, int b) throws ArithmeticException {
        return a / b;
    }
}