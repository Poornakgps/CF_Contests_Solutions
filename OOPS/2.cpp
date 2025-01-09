// #include <iostream>
// #include <string.h>

// class BankAccount
// {
//     private: 
//         // Attributes
//         std::string account_number, account_holder;
//         int balance;

//     public:
//         // constructor
//         BankAccount(const std::string& account_number, const std::string& account_holder, int balance)
//             :account_number(account_number), account_holder(account_holder), balance(balance) 
//             {
//                 std::cout << "Account Created--------------->\n";
//                 std::cout << "Number: " << account_number << "\n";
//                 std::cout << "Holder: " << account_holder << "\n"; 
//             }

//         std::string deposit(int amount)
//         {
//             this->balance = this->balance + amount;

//             return "Deposit Success\n";
//         }

//         std::string withdraw(int amount)
//         {
//             if(this->balance < amount)
//             {
//                 return "InSufficient balance\n";
//             }
            
//             this->balance -= amount;

//             return "Amount Deducted\n";
//         }

//         void getBalance() const
//         {
//             std::cout << "Current BalanceL " << this->balance << "\n";
//         }
// };

// int main()
// {
//     BankAccount customer1("123456", "Chandu", 10000);
//     std::cout << "\n";
//     BankAccount customer2("135674", "Janu", 20000);
//     std::cout << "\n";
//     std::cout << customer1.deposit(1202);
//     std::cout << customer1.withdraw(2023);
//     std::cout << customer2.withdraw(22000);
//     std::cout << customer2.deposit(2020);
//     std::cout << "\n";

//     customer1.getBalance();
//     std::cout << "\n";
//     customer2.getBalance();
//     return 0;
// }

#include <iostream>
#include <string>

class BankAccount {
private:
    std::string account_number, account_holder;
    int balance;

public:
    // Constructor with validation
    BankAccount(const std::string& account_number, const std::string& account_holder, int balance)
        : account_number(account_number), account_holder(account_holder), balance(balance) {
        if (balance < 0) {
            std::cout << "Error: Initial balance cannot be negative. Setting balance to 0.\n";
            this->balance = 0;
        }
        std::cout << "Account Created--------------->\n";
        std::cout << "Number: " << account_number << "\n";
        std::cout << "Holder: " << account_holder << "\n";
    }

    // Deposit Method
    bool deposit(int amount) {
        if (amount <= 0) {
            std::cout << "Invalid deposit amount.\n";
            return false;
        }
        this->balance += amount;
        std::cout << "Deposit Successful.\n";
        return true;
    }

    // Withdraw Method
    bool withdraw(int amount) {
        if (amount > this->balance) {
            std::cout << "Insufficient balance.\n";
            return false;
        }
        this->balance -= amount;
        std::cout << "Withdrawal Successful.\n";
        return true;
    }

    // Method to display balance
    void getBalance() const {
        std::cout << "Current Balance: " << this->balance << "\n";
    }
};

int main() {
    // Creating accounts
    BankAccount customer1("123456", "Chandu", 10000);
    std::cout << "\n";
    BankAccount customer2("135674", "Janu", 20000);
    std::cout << "\n";

    // Performing transactions
    customer1.deposit(1202);
    customer1.withdraw(2023);
    customer2.withdraw(22000);
    customer2.deposit(2020);

    // Displaying balances
    std::cout << "\n";
    customer1.getBalance();
    std::cout << "\n";
    customer2.getBalance();

    return 0;
}
