#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to validate three-digit key
bool isValidKey(const string& key) {
    if (key.length() != 3) {
        return false;
    }
    for (char c : key) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

// Function to perform Caesar cipher encryption
char caesarEncrypt(char c, int shift) {
    return c + shift;
}

// Function to perform Caesar cipher decryption
char caesarDecrypt(char c, int shift) {
    return c - shift;
}

// Function to encrypt a file with three-digit key
bool encryptFile(const string& inputFile, const string& key) {
    ifstream fin;
    fin.open(inputFile, ios::in);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open input file '" << inputFile << "'" << endl;
        return false;
    }
    
    // Generate output filename
    string outputFile = "encrypted_" + inputFile;
    
    ofstream fout;
    fout.open(outputFile, ios::out);
    if (!fout.is_open()) {
        cerr << "Error: Cannot create output file '" << outputFile << "'" << endl;
        fin.close();
        return false;
    }
    
    // Extract the three digits from the key
    int caesarShift = key[0] - '0';
    int insertInterval = key[1] - '0';
    int spacingInterval = key[2] - '0';
    
    // Predefined set of letters for insertion
    string predefinedLetters = "xyzabc";
    int letterIndex = 0;
    
    char c;
    int charCount = 0;
    
    while (fin.get(c)) {
        // Step 1: Apply Caesar cipher (first digit)
        c = caesarEncrypt(c, caesarShift);
        
        // Step 2: Insert predefined letters after specific intervals (second digit)
        if (insertInterval > 0 && charCount % insertInterval == 0 && charCount > 0) {
            char insertChar = predefinedLetters[letterIndex % predefinedLetters.length()];
            fout.put(insertChar);
            letterIndex++;
        }
        
        // Step 3: Add spacing after specific intervals (third digit)
        if (spacingInterval > 0 && charCount % spacingInterval == 0 && charCount > 0) {
            fout.put(' ');
        }
        
        fout.put(c);
        charCount++;
    }
    
    fin.close();
    fout.close();
    return true;
}

// Function to decrypt a file with three-digit key
bool decryptFile(const string& inputFile, const string& key) {
    ifstream fin;
    fin.open(inputFile, ios::in);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open input file '" << inputFile << "'" << endl;
        return false;
    }
    
    // Generate output filename
    string outputFile = "decrypted_" + inputFile;
    
    ofstream fout;
    fout.open(outputFile, ios::out);
    if (!fout.is_open()) {
        cerr << "Error: Cannot create output file '" << outputFile << "'" << endl;
        fin.close();
        return false;
    }
    
    // Extract the three digits from the key
    int caesarShift = key[0] - '0';
    int insertInterval = key[1] - '0';
    int spacingInterval = key[2] - '0';
    
    // Predefined set of letters for insertion (same as encryption)
    string predefinedLetters = "xyzabc";
    int letterIndex = 0;
    
    char c;
    int originalCharCount = 0;
    
    while (fin.get(c)) {
        // Check if this character should be skipped
        bool shouldSkip = false;
        
        // Check for predefined letter insertions
        if (insertInterval > 0 && originalCharCount > 0 && originalCharCount % insertInterval == 0) {
            char expectedLetter = predefinedLetters[letterIndex % predefinedLetters.length()];
            if (c == expectedLetter) {
                shouldSkip = true;
                letterIndex++;
            }
        }
        
        // Check for space insertions
        if (spacingInterval > 0 && originalCharCount > 0 && originalCharCount % spacingInterval == 0) {
            if (c == ' ') {
                shouldSkip = true;
            }
        }
        
        if (!shouldSkip) {
            // Apply Caesar cipher decryption
            c = caesarDecrypt(c, caesarShift);
            fout.put(c);
            originalCharCount++;
        }
    }
    
    fin.close();
    fout.close();
    return true;
}

// Function to display menu
void menu() {
    cout << "\n=== File Encrypter and Decrypter ===" << endl;
    cout << "1. Encrypt a file" << endl;
    cout << "2. Decrypt a file" << endl;
    cout << "3. Exit" << endl;
    cout << "=====================================" << endl;
}

// Function to explain the three-digit key system
void explainSystem() {
    cout << "\n=== Three-Digit Key System ===" << endl;
    cout << "Your key should be exactly 3 digits (0-9):" << endl;
    cout << "1st digit: Caesar cipher shift (0-9) - shifts ALL characters" << endl;
    cout << "2nd digit: Predefined letter insertion interval (0-9)" << endl;
    cout << "3rd digit: Space insertion interval (0-9)" << endl;
    cout << "================================" << endl;
}

int main() {
    cout << "Welcome to File Encrypter and Decrypter!" << endl;
    cout << "This program uses a three-digit key encryption system." << endl;
    explainSystem();
    
    while (true) {
        menu();
        
        string choice;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cin.ignore(); // Clear the newline from buffer
        
        if (choice == "1") {
            // Encryption mode
            cout << "\n--- File Encryption ---\n" << endl;
            
            string inputFile, key;
            
            cout << "Enter input file path: ";
            getline(cin, inputFile);
            
            cout << "Enter three-digit key (000-999): ";
            getline(cin, key);
            
            // Validate inputs
            if (inputFile.empty() || key.empty()) {
                cout << "Error: All fields are required!" << endl;
                continue;
            }
            
            // Validate key format
            if (!isValidKey(key)) {
                cout << "Error: Key must be exactly 3 digits (0-9)!" << endl;
                cout << "Example: 123, 456, 789, etc." << endl;
                continue;
            }
            
            cout << "\nEncrypting file '" << inputFile << "'..." << endl;
            cout << "Output will be saved as: encrypted_" << inputFile << endl;
            cout << "Using key: " << key << endl;
            cout << "- Caesar shift: " << key[0] << " (shifts ALL characters)" << endl;
            cout << "- Insert interval: " << key[1] << endl;
            cout << "- Space interval: " << key[2] << endl;
            
            bool success = encryptFile(inputFile, key);
            
            if (success) {
                cout << "File encrypted successfully!" << endl;
                cout << "Encrypted file: encrypted_" << inputFile << endl;
            } else {
                cout << "Encryption failed!" << endl;
            }
            
        } else if (choice == "2") {
            // Decryption mode
            cout << "\n--- File Decryption ---\n" << endl;
            
            string inputFile, key;
            
            cout << "Enter input file path: ";
            getline(cin, inputFile);
            
            cout << "Enter three-digit key (000-999): ";
            getline(cin, key);
            
            // Validate inputs
            if (inputFile.empty() || key.empty()) {
                cout << "Error: All fields are required!" << endl;
                continue;
            }
            
            // Validate key format
            if (!isValidKey(key)) {
                cout << "Error: Key must be exactly 3 digits (0-9)!" << endl;
                cout << "Example: 123, 456, 789, etc." << endl;
                continue;
            }
            
            cout << "\nDecrypting file '" << inputFile << "'..." << endl;
            cout << "Output will be saved as: decrypted_" << inputFile << endl;
            cout << "Using key: " << key << endl;
            cout << "- Caesar shift: " << key[0] << " (shifts ALL characters)" << endl;
            cout << "- Insert interval: " << key[1] << endl;
            cout << "- Space interval: " << key[2] << endl;
            
            bool success = decryptFile(inputFile, key);
            
            if (success) {
                cout << "File decrypted successfully!" << endl;
                cout << "Decrypted file: decrypted_" << inputFile << endl;
            } else {
                cout << "Decryption failed!" << endl;
            }
            
        } else if (choice == "3") {
            // Exit
            cout << "\nThank you for using File Encrypter and Decrypter!" << endl;
            cout << "Goodbye!" << endl;
            break;
            
        } else {
            cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
        }
        
        // Ask if user wants to continue
        string continueChoice;
        cout << "\nPress Enter to continue or 'q' to quit: ";
        getline(cin, continueChoice);
        if (continueChoice == "q" || continueChoice == "Q") {
            cout << "\nThank you for using File Encrypter and Decrypter!" << endl;
            cout << "Goodbye!" << endl;
            break;
        }
    }
    
    return 0;
} 