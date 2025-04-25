import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

public class Calculator {
    private JTextField num1Field, num2Field, resultField;
    private JButton addButton, subtractButton, multiplyButton, divideButton, clearButton;

    public Calculator() {
        // Set up the frame
        JFrame frame = new JFrame("Simple Calculator");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        // Heading at the top
        JLabel headingLabel = new JLabel("edSlash Coding Hub Calculator", JLabel.CENTER);
        headingLabel.setFont(new Font("Arial", Font.BOLD, 22));
        headingLabel.setBorder(BorderFactory.createEmptyBorder(10, 0, 10, 0));
        frame.add(headingLabel, BorderLayout.NORTH);

        // Create the form panel
        JPanel formPanel = new JPanel(new GridLayout(5, 2, 10, 10));
        formPanel.setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        // Number 1 Input
        JLabel num1Label = new JLabel("Number 1:");
        num1Field = new JTextField();
        formPanel.add(num1Label);
        formPanel.add(num1Field);

        // Number 2 Input
        JLabel num2Label = new JLabel("Number 2:");
        num2Field = new JTextField();
        formPanel.add(num2Label);
        formPanel.add(num2Field);

        // Result Display
        JLabel resultLabel = new JLabel("Result:");
        resultField = new JTextField();
        resultField.setEditable(false); // Result field is read-only
        formPanel.add(resultLabel);
        formPanel.add(resultField);

        // Operation Buttons
        addButton = new JButton("Add");
        subtractButton = new JButton("Subtract");
        multiplyButton = new JButton("Multiply");
        divideButton = new JButton("Divide");
        clearButton = new JButton("Clear");

        JPanel buttonPanel = new JPanel(new GridLayout(1, 5, 5, 5));
        buttonPanel.add(addButton);
        buttonPanel.add(subtractButton);
        buttonPanel.add(multiplyButton);
        buttonPanel.add(divideButton);
        buttonPanel.add(clearButton);

        // Add components to the frame
        frame.add(formPanel, BorderLayout.CENTER);
        frame.add(buttonPanel, BorderLayout.SOUTH);

        // Add Action Listeners using Lambdas
        ActionListener listener = e -> handleOperation(e.getActionCommand());
        addButton.addActionListener(listener);
        subtractButton.addActionListener(listener);
        multiplyButton.addActionListener(listener);
        divideButton.addActionListener(listener);
        clearButton.addActionListener(e -> clearFields());

        // Make the frame visible
        frame.setVisible(true);
    }

    private void handleOperation(String operation) {
        try {
            double num1 = Double.parseDouble(num1Field.getText().trim());
            double num2 = Double.parseDouble(num2Field.getText().trim());
            double result = 0;

            switch (operation) {
                case "Add" : result = num1 + num2; break;
                case "Subtract" : result = num1 - num2; break;
                case "Multiply" : result = num1 * num2; break;
                case "Divide" : {
                    if (num2 == 0) {
                        showError("Cannot divide by zero.");
                        return;
                    }
                    result = num1 / num2;
                }
            }

            resultField.setText(String.valueOf(result));
        } catch (NumberFormatException ex) {
            showError("Please enter valid numbers.");
        }
    }

    private void showError(String message) {
        JOptionPane.showMessageDialog(null, message, "Input Error", JOptionPane.ERROR_MESSAGE);
    }

    private void clearFields() {
        num1Field.setText("");
        num2Field.setText("");
        resultField.setText("");
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Calculator::new);
    }
}
