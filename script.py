import my_string

def main():
    input_str = input("Enter the string: ")
    mystr = my_string.MyString(input_str)

    print("Is palindrome: " + str(mystr.is_palindrome()))
    print("Sliced string: " + mystr.slice(0, mystr.length, 3))

if __name__ == "__main__":
    main()
