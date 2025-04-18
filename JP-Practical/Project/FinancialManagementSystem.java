package Project;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class FinancialManagementSystem extends JFrame {
    private double balance = 0.0;

    private JLabel balanceLabel;
    private JTextField amountField;
    private JTextArea transactionArea;

    public FinancialManagementSystem() {
        setTitle("Financial Management System");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Panel for top balance section
        JPanel topPanel = new JPanel();
        balanceLabel = new JLabel("Current Balance: ₹0.00");
        balanceLabel.setFont(new Font("Arial", Font.BOLD, 16));
        topPanel.add(balanceLabel);

        // Panel for input and buttons
        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(2, 2, 10, 10));
        inputPanel.add(new JLabel("Amount (₹):"));
        amountField = new JTextField();
        inputPanel.add(amountField);

        JButton incomeButton = new JButton("Add Income");
        JButton expenseButton = new JButton("Add Expense");
        inputPanel.add(incomeButton);
        inputPanel.add(expenseButton);

        // Panel for transaction history
        transactionArea = new JTextArea();
        transactionArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(transactionArea);

        // Add listeners
        incomeButton.addActionListener(e -> addTransaction(true));
        expenseButton.addActionListener(e -> addTransaction(false));

        // Layout setup
        setLayout(new BorderLayout(10, 10));
        add(topPanel, BorderLayout.NORTH);
        add(inputPanel, BorderLayout.CENTER);
        add(scrollPane, BorderLayout.SOUTH);
    }

    private void addTransaction(boolean isIncome) {
        try {
            double amount = Double.parseDouble(amountField.getText());
            if (amount <= 0) throw new NumberFormatException();

            if (isIncome) {
                balance += amount;
                transactionArea.append("Income Added: ₹" + amount + "\n");
            } else {
                if (amount > balance) {
                    JOptionPane.showMessageDialog(this, "Insufficient balance!", "Error", JOptionPane.ERROR_MESSAGE);
                    return;
                }
                balance -= amount;
                transactionArea.append("Expense Recorded: ₹" + amount + "\n");
            }

            balanceLabel.setText("Current Balance: ₹" + String.format("%.2f", balance));
            amountField.setText("");
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Please enter a valid positive number.", "Input Error", JOptionPane.WARNING_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new FinancialManagementSystem().setVisible(true));
    }
}
