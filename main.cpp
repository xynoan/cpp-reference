#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

std::string accounts_file = "accounts.txt";

struct Account {
  std::string first_name = "";
  std::string last_name = "";
  std::string password = "";
  std::string email = "";
  bool equals(Account to_compare) { return email == to_compare.email; }
};

std::vector<Account> read_accounts_from_file() {
  std::vector<Account> accounts;
  Account account;
  std::ifstream input_file(accounts_file);
  if (input_file) {
    while (input_file >> account.first_name >> account.last_name >>
           account.password >> account.email) {
      accounts.push_back(account);
    }
    input_file.close();
  }
  return accounts;
}

void display_accounts(std::vector<Account> accounts) {
  int col_width = 10;
  std::cout << std::left << std::setw(col_width * 3) << "Name"
            << std::setw(col_width * 4) << "Email" << '\n';
  for (Account account : accounts) {
    std::cout << std::setw(col_width * 3)
              << account.first_name + ' ' + account.last_name
              << std::setw(col_width * 4) << account.email << '\n';
  }
}

void write_accounts_to_file(std::vector<Account> accounts) {
  std::ofstream output_file(accounts_file);
  if (output_file) {
    for (Account account : accounts) {
      output_file << account.first_name << '\t' << account.last_name << '\t'
                  << account.password << '\t' << account.email << '\n';
    }
    output_file.close();
  }
}

Account get_account() {
  Account account;
  std::cout << "First name: ";
  getline(std::cin, account.first_name);
  std::cout << "Last name: ";
  getline(std::cin, account.last_name);
  std::cout << "Password: ";
  getline(std::cin, account.password);
  std::cout << "Email: ";
  getline(std::cin, account.email);

  return account;
}

int main() {
  std::vector<Account> accounts = read_accounts_from_file();
  std::cout << "Create Account List\n\n";

  display_accounts(accounts);

  char another = 'y';
  while (tolower(another) == 'y') {
    Account account = get_account();
    bool alreadyExist = false;
    for (Account existingAccs : accounts) {
      if (existingAccs.equals(account)) {
        std::cout << "\nThat account already exist!\n";
        alreadyExist = true;
        break;
      }
    }

    if (alreadyExist) {
      continue;
    }

    accounts.push_back(account);
    write_accounts_to_file(accounts);
    std::cout << '\n'
              << account.email << " was added for "
              << account.first_name + ' ' + account.last_name << '\n'
              << '\n';

    std::cout << "Enter another account? (y/n): ";
    std::cin >> another;
    std::cin.ignore();
    std::cout << '\n';
  }

  display_accounts(accounts);
}
