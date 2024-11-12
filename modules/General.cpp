#include "General.h"

char getAnswer(char answer1, char answer2, std::string prompt) {
  char answer;
  while (true) {
    std::cout << prompt;

    // Read the single character input
    std::cin >> answer;

    // Clear out any remaining characters in the buffer, including newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Convert to lowercase and check if it matches answer1 or answer2
    answer = std::tolower(answer);
    if (answer == answer1 || answer == answer2) {
      return answer;
    }

    // Notify user of invalid input
    std::cout << "Invalid input. Please enter " << answer1 << " or '" << answer2
              << "'.\n";
  }
}

int getNumber(int min, int max, std::string prompt) {
  // Ask for input
  std::cout << prompt;
  int number;
  std::cin >> number;
  // Check if input is an integer in the given range
  while (std::cin.fail() || number > max || number < min) {
    std::cout << "Invalid input. Please enter a number between " << min
              << " and " << max << ".\n";
    // Clear stdin
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Ask for new input
    std::cout << prompt;
    std::cin >> number;
  }
  return number;
}