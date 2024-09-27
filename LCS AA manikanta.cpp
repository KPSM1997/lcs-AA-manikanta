#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Template function for finding the longest common substring
template <typename T>
std::basic_string<T> longestCommonSubstring(const std::basic_string<T>& str1, const std::basic_string<T>& str2) {
    int n = str1.length();
    int m = str2.length();

    // Create a 2D grid initialized to 0
    std::vector<std::vector<int>> lookupTable(n + 1, std::vector<int>(m + 1, 0));

    // Variables to track the length of the longest substring and its ending index
    int maxLength = 0;
    int endIndex = 0;

    // Fill the lookup table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                lookupTable[i][j] = lookupTable[i - 1][j - 1] + 1;

                // Update maxLength and endIndex if a longer substring is found
                if (lookupTable[i][j] > maxLength) {
                    maxLength = lookupTable[i][j];
                    endIndex = i;
                }
            }
        }
    }

    // Display the detailed lookup table with headings
    std::cout << "Detailed Lookup Table:\n";
    
    // Print the column headers
    std::cout << "    ";  // Adjust space for alignment
    for (int j = 0; j <= m; ++j) {
        if (j == 0)
            std::cout << "  ";  // Initial empty corner
        else
            std::cout << str2[j - 1] << " ";
    }
    std::cout << "\n";

    // Print the table with row headers
    for (int i = 0; i <= n; ++i) {
        if (i == 0)
            std::cout << "  ";  // First empty row label
        else
            std::cout << str1[i - 1] << " ";  // Row header

        for (int j = 0; j <= m; ++j) {
            std::cout << std::setw(2) << lookupTable[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Extract the longest common substring
    return str1.substr(endIndex - maxLength, maxLength);
}

int main() {
    // Declare variables to store the input strings
    std::string str1, str2;

    // Prompt the user to enter the strings
    std::cout << "Enter the first string: ";
    std::cin >> str1;

    std::cout << "Enter the second string: ";
    std::cin >> str2;

    // Check if the strings have the same length
    if (str1.length() != str2.length()) {
        std::cout << "The two strings must be of identical length.\n";
        return 1;  // Exit the program with an error code
    }

    // Find the longest common substring using the template function
    std::string result = longestCommonSubstring(str1, str2);

    // Display the result
    std::cout << "\nLongest Common Substring: " << result << "\n";
    std::cout << "Length: " << result.length() << "\n";

    return 0;
}
