# File Encrypter and Decrypter

A simple interactive command-line tool written in C++ for encrypting and decrypting files using a sophisticated three-digit key encryption system.

## Docker Usage

You can use this tool without compiling it locally by running the Docker image:

### Pull the image

Run-"docker pull <your-docker-username>/cpp-encrypter:latest"

### Run the container

Run-"docker run -it --rm -v /path/to/your/files:/data <your-docker-username>/cpp-encrypter"
Example-"docker run -it --rm -v /home/user/files:/data sambhav1501/cpp-encrypter"

## Features

- **Interactive Interface**: User-friendly menu-driven interface
- **Three-Digit Key System**: Advanced encryption using three different techniques
- **File Encryption**: Encrypt any file using a custom three-digit key
- **File Decryption**: Decrypt previously encrypted files using the same key
- **Cross-platform**: Works on Windows, Linux, and macOS
- **Binary Safe**: Handles all file types including images, documents, etc.
- **Runtime Input**: No command line arguments needed - everything is entered at runtime

## How It Works

The program uses a sophisticated three-digit key encryption system where each digit controls a different encryption technique:

### Three-Digit Key System
Your key must be exactly 3 digits (0-9), where each digit performs a different function:

1. **First Digit (Caesar Cipher)**: Controls the shift value for Caesar cipher encryption
   - Range: 0-9
   - Example: If first digit is 3, letters are shifted by 3 positions

2. **Second Digit (Random Letter Insertion)**: Controls how often random letters are inserted
   - Range: 0-9 (0 means no insertion)
   - Example: If second digit is 5, a random letter is inserted every 5 characters

3. **Third Digit (Space Insertion)**: Controls how often spaces are inserted
   - Range: 0-9 (0 means no spacing)
   - Example: If third digit is 4, a space is inserted every 4 characters

### Encryption Process
1. **Caesar Cipher**: Each alphabetic character is shifted by the first digit value
2. **Random Letter Insertion**: Random lowercase letters are inserted at intervals specified by the second digit
3. **Space Insertion**: Spaces are inserted at intervals specified by the third digit

### Example
- **Key**: 123
- **Original text**: "Hello World"
- **After Caesar cipher (shift 1)**: "Ifmmp Xpsme"
- **After random letter insertion (every 2 chars)**: "Ifmmp Xpsme" + random letters
- **After space insertion (every 3 chars)**: "Ifm mp Xps me" + random letters

## Compilation

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- Make (optional, for using the Makefile)

### Using Makefile (Recommended)
```bash
# Compile the program
make

# Or explicitly
make all
```

### Manual Compilation
```bash
# Using GCC
g++ -std=c++11 -Wall -Wextra -O2 file_encrypter.cpp -o file_encrypter

# Using Clang
clang++ -std=c++11 -Wall -Wextra -O2 file_encrypter.cpp -o file_encrypter
```

## Usage

### Running the Program
Simply run the executable:
```bash
./file_encrypter
```

### Interactive Menu
The program will display a menu with the following options:
```
=== File Encrypter and Decrypter ===
1. Encrypt a file
2. Decrypt a file
3. Exit
=====================================
```

### Three-Digit Key System Explanation
The program will also display:
```
=== Three-Digit Key System ===
Your key should be exactly 3 digits (0-9):
1st digit: Caesar cipher shift (0-9)
2nd digit: Random letter insertion interval (0-9)
3rd digit: Space insertion interval (0-9)
================================
```

### Step-by-Step Usage

#### Encrypting a File
1. Run the program: `./file_encrypter`
2. Choose option `1` (Encrypt a file)
3. Enter the input file path when prompted
4. Enter the output file path when prompted
5. Enter your three-digit key (e.g., 123, 456, 789) when prompted
6. The program will show the encryption parameters and process the file

#### Decrypting a File
1. Run the program: `./file_encrypter`
2. Choose option `2` (Decrypt a file)
3. Enter the encrypted file path when prompted
4. Enter the output file path when prompted
5. Enter the same three-digit key used for encryption when prompted
6. The program will show the decryption parameters and process the file

### Example Session
```
Welcome to File Encrypter and Decrypter!
This program uses a three-digit key encryption system.

=== Three-Digit Key System ===
Your key should be exactly 3 digits (0-9):
1st digit: Caesar cipher shift (0-9)
2nd digit: Random letter insertion interval (0-9)
3rd digit: Space insertion interval (0-9)
================================

=== File Encrypter and Decrypter ===
1. Encrypt a file
2. Decrypt a file
3. Exit
=====================================
Enter your choice (1-3): 1

--- File Encryption ---
Enter input file path: secret.txt
Enter output file path: secret.enc
Enter three-digit key (000-999): 123

Encrypting file 'secret.txt' to 'secret.enc'...
Using key: 123
- Caesar shift: 1
- Insert interval: 2
- Space interval: 3
✓ File encrypted successfully!
```

### Key Examples
- **Key 000**: No encryption (Caesar shift 0, no insertions, no spacing)
- **Key 123**: Caesar shift 1, random letter every 2 chars, space every 3 chars
- **Key 555**: Caesar shift 5, random letter every 5 chars, space every 5 chars
- **Key 999**: Caesar shift 9, random letter every 9 chars, space every 9 chars

## Security Notes

⚠️ **Important Security Considerations:**

1. **Three-Digit Key System**: This implementation uses a combination of Caesar cipher, random letter insertion, and spacing for file obfuscation.

2. **Key Management**: 
   - Keep your three-digit keys secure
   - Don't share keys in plain text
   - Use different keys for different files
   - Remember that 0 in any position disables that encryption feature

3. **File Safety**: 
   - Always backup important files before encryption
   - Test decryption on a copy first
   - Keep the original key safe - losing it means losing access to the file

4. **Not for Critical Data**: For highly sensitive data, consider using more robust encryption methods like AES.

## Troubleshooting

### Common Issues

1. **"Cannot open input file"**
   - Check if the file path is correct
   - Ensure the file exists
   - Verify you have read permissions

2. **"Cannot create output file"**
   - Check if you have write permissions in the target directory
   - Ensure the output directory exists
   - Make sure you have sufficient disk space

3. **"All fields are required"**
   - Make sure you enter values for all prompts
   - Don't leave any field empty

4. **"Key must be exactly 3 digits"**
   - Enter exactly 3 digits (0-9)
   - Examples: 123, 456, 789, 000, 999
   - Don't include letters or special characters

5. **Compilation errors**
   - Ensure you have a C++11 compatible compiler
   - Check that all required headers are available

### Getting Help

If you encounter issues:
1. Check the error messages for specific details
2. Verify all file paths are correct
3. Test with a simple text file first
4. Ensure you're using the correct three-digit key for decryption
5. Try different key combinations to understand the encryption behavior

## License

This project is open source and available under the MIT License.

## Contributing

Feel free to submit issues, feature requests, or pull requests to improve this tool. 
