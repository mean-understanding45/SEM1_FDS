
"""Write a Python program to compute following operations on String: 
a) To display word with the longest length 
b) To determines the frequency of occurrence of particular character in the string 
c) To check whether given string is palindrome or not  
d) To display index of first appearance of the substring  
e) To count the occurrences of each word in a given strin"""


class String:
    def __init__(self):
        self.char = []

    def strcreate(self):
        str = input("Enter the string: ")

        for i in range(len(str)):
            self.char.append(str[i])
        return str

    def strlist(self, list):  # List to string
        str = ""
        for i in range(len(list)):
            str += list[i]
        return str

    def words(self):   # created word
        list = []
        x = 0
        for i in range(len(self.char)):

            if self.char[i] == " ":
                list.append(self.char[x:i])
                x = i + 1

            if i == len(self.char) - 1:
                list.append(self.char[x:])

        return list

    def maxlen(self):
        list = self.words()
        max = list[0]
        for i in range(len(list)):
            if len(list[i]) > len(max):
                max = list[i]
        return self.strlist(max)

    def occ_of_char(self, ch1):
        count = 0
        for i in range(len(self.char)):
            if self.char[i] == ch1:
                count += 1
        return count

    def palindrome(self):
        str1 = []
        for i in range(len(self.char)):
            if self.char[i] == " ":
                continue
            else:
                str1.append(self.char[i])
        x = len(str1)
        for i in range(0, x):
            if str1[i] != str1[x - i - 1]:  # Comparing the elements from front and end of the string
                print("The string ", s,
                      " is not a palindrome")  # If the characters are equal then printing palindrome
                break
            else:
                print("The string ", s,
                      " is a palindrome")  # If characters are not equal then printing not palindrome
                break

    def substring(self):
        sub = input("Enter the Substring :")
        subset = list(sub)
        if len(subset) == 0 or subset == {" "}:
            print('INVALID INPUT')
        else:
            count = 0
            done = False
            for i in range(0, len(s)):
                match = True
                if sub[0] == s[i]:
                    j = 0
                    for j in range(0, len(sub)):
                        if sub[j] != s[i + j]:
                            match = False
                            print("Not a substring")
                            break
                        else:
                            count = count + 1
                            if match == True and count == len(sub):
                                print("It is a Substring")
                                print("Position start:", i)
                                done = True
                                break
                if done == True:
                    break

    def word_occ(self):
        x = len(s)
        sub = input("Enter a substring: ")
        y = len(sub)
        i = 0
        val = 0
        while (i < x):
            if (s[i] == sub[0]):  # Checking if the charater in string is equal to first character in substring
                # Checking if the following characters after first character are equal
                if (s[i:i + y] == sub):
                    val += 1  # If equal then counter variable is incremented
            i += 1
        print("The occurence of ", sub, " in ", s, " is ", val, " times")


str = String()
s = str.strcreate()

set = set(list(s))
if len(s) == 0 or set == {" "}:
    print('INVALID INPUT')
else:
    while True:
        print("\n MENU")
        print("\n1. To display word with the longest length"
              "\n2. To determines the frequency of occurrence of particular character in the string"
              "\n3. To check whether given string is palindrome or not "
              "\n4. To count the occurrences of each word in a given string"
              "\n5. To display index of first appearance of the substring"
              "\n6. End")
        ch = int(input("Enter choice: "))
        if ch == 1:
            maxlength = str.maxlen()
            print("The longest word is " + maxlength +
                  " with length ", len(maxlength))
        elif ch == 2:
            char = input(
                "Enter the character you want to check for occurrences: ")
            charcount = str.occ_of_char(char)
            print("The character occurs {}".format(charcount), "times")
        elif ch == 3:
            str.palindrome()
        elif ch == 4:
            print("\nOccurrence of word")
            str.word_occ()

        elif ch == 5:
            print("Substring")
            str.substring()
        elif ch == 6:
            print("Thank You !!")
            break
        else:
            print("You have entered wrong choice!")
