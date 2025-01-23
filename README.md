# Payment Processing System

## Description

This project is a payment processing system that handles credit card transactions. The system includes several components:

1. **Card**: This component handles the input and validation of the card holder's name, primary account number, and expiration date.
2. **Terminal**: This component handles the transaction-related tasks, such as getting the transaction date, checking if the card is expired, getting the transaction amount, and setting the maximum transaction amount.
3. **Server**: This component is responsible for processing the transaction data, including validating the account, checking the account balance, and saving the transaction details.
4. **App**: This is the main application that orchestrates the interaction between the other components and handles the overall flow of the payment processing system.

The system is designed to handle various scenarios, such as declined transactions due to insufficient funds, stolen cards, or expired cards. It also includes a feature to list all saved transactions.

## Features

- Capture and validate card holder information
- Check card expiration date
- Get transaction amount and validate it against the maximum allowed amount
- Process the transaction and handle various scenarios (e.g., insufficient funds, stolen card, fraud)
- Save transaction details
- List all saved transactions

## Usage

To use the payment processing system, follow these steps:

1. Compile and run the `app.c` file.
2. Enter the card holder's name, primary account number, and expiration date when prompted.
3. Enter the transaction amount when prompted.
4. The system will process the transaction and display the result (approved or declined, with the reason).
5. The system will save the transaction details and list all saved transactions.
