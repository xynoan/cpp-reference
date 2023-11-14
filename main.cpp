#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string accounts_file = "accounts.txt";

struct Account {
  string first_name = "";
  string last_name = "";
  string password = "";
  string email = "";
  bool equals(Account to_compare) { return email == to_compare.email; }
};

vector<Account> read_accounts_from_file() {
  vector<Account> accounts;
  Account account;
  ifstream input_file(accounts_file);
  if (input_file) {
    while (input_file >> account.first_name >> account.last_name >>
           account.password >> account.email) {
      accounts.push_back(account);
    }
    input_file.close();
  }
  return accounts;
}

void display_accounts(vector<Account> accounts) {
  int col_width = 10;
  cout << left << setw(col_width * 3) << "Name" << setw(col_width * 4)
       << "Email" << endl;
  for (Account account : accounts) {
    cout << setw(col_width * 3) << account.first_name + ' ' + account.last_name
         << setw(col_width * 4) << account.email << endl;
  }
}

void write_accounts_to_file(vector<Account> accounts) {
  ofstream output_file(accounts_file);
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
  cout << "First name: ";
  getline(cin, account.first_name);
  cout << "Last name: ";
  getline(cin, account.last_name);
  cout << "Password: ";
  getline(cin, account.password);
  cout << "Email: ";
  getline(cin, account.email);

  return account;
}

int main() {
  vector<Account> accounts = read_accounts_from_file();
  cout << "Create Account List\n\n";

  display_accounts(accounts);

  char another = 'y';
  while (tolower(another) == 'y') {
    Account account = get_account();
    bool alreadyExist = false;
    for (Account existingAccs : accounts) {
      if (existingAccs.equals(account)) {
        cout << "\nThat account already exist!\n";
        alreadyExist = true;
        break;
      }
    }

    if (alreadyExist) {
      continue;
    }

    accounts.push_back(account);
    write_accounts_to_file(accounts);
    cout << endl
         << account.email << " was added for "
         << account.first_name + ' ' + account.last_name << endl
         << endl;

    cout << "Enter another account? (y/n): ";
    cin >> another;
    cin.ignore();
    cout << endl;
  }

  display_accounts(accounts);
}
