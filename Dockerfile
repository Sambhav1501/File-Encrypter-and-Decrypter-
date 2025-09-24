# Use official GCC image
FROM gcc:latest

# Set working directory inside container (different from mounted folder)
WORKDIR /app

# Copy your source code into container
COPY file_encrypter.cpp .

# Compile C++ code
RUN g++ file_encrypter.cpp -o file_encrypter

# Default command
ENTRYPOINT ["./file_encrypter"]
