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
};

vector<Account> read_accounts_from_file() {
  string first_name;
  string last_name;
  string password;
  string email;
  vector<Account> accounts;
  ifstream input_file("accounts.txt");
  if (input_file) {
    while (input_file >> first_name >> last_name >> password >> email) {
      Account account = {first_name, last_name, password, email};
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
  cout << '\n';
}

void write_accounts_to_file(vector<Account> accounts) {
  ofstream output_file(accounts_file, ios::app);
  if (output_file) {
    for (Account account : accounts) {
      output_file << account.first_name << '\t' << account.last_name << '\t'
                  << account.password << '\t' << account.email << '\n';
    }
    output_file.close();
  }
}

void get_account() { Account account; }

void write_account_to_file(const string first, const string last,
                           const string password, const string email) {
  ofstream output_file(accounts_file, ios::app);
  if (output_file) {
    output_file << first << '\t' << last << '\t' << password << '\t' << email
                << '\n';
    output_file.close();
  }
}

int main() {
  cout << "Create Account List\n\n";

  string first_name;
  string last_name;
  string password;
  string email;

  display_accounts(read_accounts_from_file());

  char another = 'y';
  while (tolower(another) == 'y') {
    cout << "First name: ";
    getline(cin, first_name);
    cout << "Last name: ";
    getline(cin, last_name);
    cout << "Password: ";
    getline(cin, password);
    cout << "Email: ";
    getline(cin, email);

    write_account_to_file(first_name, last_name, password, email);
    cout << endl
         << email << " was added for " << first_name + ' ' + last_name << endl
         << endl;

    cout << "Enter another account? (y/n): ";
    cin >> another;
    cin.ignore();
    cout << endl;
  }

  display_accounts(read_accounts_from_file());
}
