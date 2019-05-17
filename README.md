# password-test

This is a small program intended to check whether a password exists in a given list of pwned passwords.

It is not functional yet.

## Motivation

This app is inspired but haveibeenpwned.com 's database of exposed passwords. It expects a password and a file of SHA-1 hashes and quickly determines if the given password's hash is in the file.

For security, it is important to be able to test the password locally and to rely on free software to do so.

## License

This project is licensed under the GPL v3.0 or newer.