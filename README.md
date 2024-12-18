# Simple Password Manager

A secure, console-based password manager application written in C++ that allows users to locally store and manage their credentials. The program creates separate database files for each user, ensuring data isolation and security.

## Features

### User Management
- Create new user accounts with email and password verification
- Secure login system with master credentials
- Individual database files for each user
- Password confirmation during registration

### Credential Management
- Store multiple credentials with custom descriptions
- Auto-incrementing ID system for easy reference
- View individual credential details
- View all stored credentials in a list format
- Update existing credentials
- Organize credentials by descriptions

### Data Storage
Each credential entry stores:
- Unique ID
- Custom description
- Username
- Email
- Password

## Installation

### Prerequisites
- C++ compiler (GCC/G++ recommended)
- Required libraries:
  - iostream
  - string.h
  - fstream

### Building from Source

1. Clone the repository

```bash
git clone https://github.com/yourusername/password-manager.git

```
2. Change directory to the project folder   
```bash
cd password-manager
```
3. Compile the program
```bash
g++ PasswordManager.cpp -o password_manager
```

4. Run the application
```bash
./password_manager or ./password_manager.exe
```



## Usage Guide

### First Time Setup
1. Launch the program
2. Choose option `1` for Registration
3. Enter your email address
4. Create a master password
5. Confirm your master password

### Regular Usage

#### Login
1. Select option `2` from main menu
2. Enter your registered email
3. Enter your master password

#### Adding New Credentials
1. After login, select option `1`
2. Enter the required information:
   - Description (e.g., "Gmail", "Facebook")
   - Username
   - Email
   - Password
3. Confirm to save the entry

#### Viewing Credentials
- To view specific credentials:
  1. Select option `2`
  2. Enter the description name
  
- To view all credentials:
  1. Select option `3`

#### Updating Credentials
1. Select option `4`
2. Enter the description of the credential
3. Input the new information
4. Confirm the changes

#### Exiting
- Select option `5` to return to main menu
- Select option `4` from main menu to exit

## Security Features
- Separate database files for each user
- Password verification during registration
- Binary file storage
- Local storage without internet requirement

## Technical Details
- Database files use `.db` extension
- File naming format: `.useremail.db`
- Compatible with both Windows and Linux systems
- Written in C++ for better performance

## Development
- Original Developer: Aung Kyaw Thu (Aungkyaw0)
- Initial Release: 2/10/2022
- Version: 1.0

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
