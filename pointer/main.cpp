#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

void get_monthly_weights(double *weights, std::string *months, int num_months) {
  if (weights == nullptr || months == nullptr) {
    std::cout << "Error: Null pointer detected.\n";
    return;
  }

  for (int i = 0; i < num_months; ++i) {
    std::cout << months[i] << ": ";
    std::cin >> weights[i];
  }
}

double get_total(double *weights, int num_months) {
  if (weights == nullptr) {
    std::cout << "Error: Null pointer detected.\n";
    return 0.0;
  }

  return std::accumulate(weights, weights + num_months, 0.0);
}

int main() {
  const int num_months = 12;
  double weights[num_months]{0.0};
  std::string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  std::cout << "Welcome to the Weight Tracker program!\n\n"
            << "Please enter your weight at the beginning of each month:\n";
  get_monthly_weights(weights, months, num_months);
  double average = get_total(weights, num_months) / num_months;
  auto max = std::max_element(weights, weights + num_months);
  auto min = std::min_element(weights, weights + num_months);
  std::cout << '\n';
  std::cout << "Maximum weight: " << *max << '\n'
            << "Minimum weight: " << *min << '\n'
            << "Average weight: " << average << "\n\n";
}
