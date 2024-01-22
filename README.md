# Project 1 README

Student: Tho Nguyen (921017457)

## Project Status
This the current status of the project is Completed

## Known Issues
N/A The code had passed all of the given google test provided from the student.

## Code References
* [GoogleTest](https://youtu.be/THkBVaWfFUA?feature=shared)
* [StringOperators](https://en.cppreference.com/w/cpp/string/basic_string)
* [StripFunctionC++](https://stackoverflow.com/questions/9358718/similar-function-in-c-to-pythons-strip)
* [FindFunctionC++](https://www.scaler.com/topics/cpp-find/)
* [ReplaceFunctionC++] (https://www.scaler.com/topics/cpp-string-replace/)
* [VectorFunctionC++](https://www.programiz.com/cpp-programming/vectors#:~:text=In%20C%2B%2B%2C%20vectors%20are the%20C%2B%2B%20Standard%20Template%20Library.)
* [MoreVectorC++](https://www.tutorialspoint.com/how-to-print-out-the-contents-of-a-vector-in-cplusplus)
* [Levenshtein](https://en.wikipedia.org/wiki/Levenshtein_distance)

## Generative AI Use
* Prompt 1:
I used ChatGpt to help me figure out how to implement the files into my makefile.

* Prompt 3:
I used ChatGPT to figure out the meaning of .base() command of a string.


### Prompt 1
How do I include google test into my makefile so that it can run the google tests? (Pasted the makefile code from discussion)

### Response 1
The error indicates that the compiler cannot find the 'gtest/gtest.h' file, which is likely a part of the Google Test framework. To resolve this issue, you need to ensure that the necessary include paths are correctly specified in your Makefile and that the Google Test library is installed.

Here's how you can fix the issue:

Install Google Test:
Make sure that you have Google Test installed on your system. You can follow the instructions provided by Google Test to download and install it. You may need to clone the Google Test repository and build it.

Update Makefile with Google Test Include Paths:
Modify your Makefile to include the necessary paths for Google Test. Update the CXXFLAG to include the path where 'gtest/gtest.h' is located. Additionally, update the LDFLAGS to include the path where the Google Test library is located.

Here's an example:

"CC = gcc
CXX = g++

INC_DIR = ./include
SRC_DIR = ./src
TESTSRC_DIR = ./testsrc
BIN_DIR = ./bin
OBJ_DIR = ./bin
GTEST_DIR = /path/to/gtest

CXXFLAG = -std=gnu++17 -I $(INC_DIR) -I $(GTEST_DIR)/include
LDFLAGS = -L /opt/local/lib -L $(GTEST_DIR)/lib -lgtest -lgtest_main -lpthread

all: directories $(BIN_DIR)/teststrutils

$(BIN_DIR)/teststrutils: $(OBJ_DIR)/StringUtilsTest.o $(OBJ_DIR)/StringUtils.o
    $(CXX) -o $(BIN_DIR)/teststrutils $(OBJ_DIR)/StringUtilsTest.o $(OBJ_DIR)/StringUtils.o $(LDFLAGS)

$(OBJ_DIR)/StringUtilsTest.o: $(TESTSRC_DIR)/StringUtilsTest.cpp $(INC_DIR)/StringUtils.h
    $(CXX) -o $(OBJ_DIR)/StringUtilsTest.o $(CXXFLAG) -c $(TESTSRC_DIR)/StringUtilsTest.cpp

$(OBJ_DIR)/StringUtils.o: $(SRC_DIR)/StringUtils.cpp $(INC_DIR)/StringUtils.h
    $(CXX) -o $(OBJ_DIR)/StringUtils.o $(CXXFLAG) -c $(SRC_DIR)/StringUtils.cpp

directories:
    mkdir -p $(BIN_DIR)
    mkdir -p $(OBJ_DIR)

.PHONY: clean

clean:
    rm -rf $(BIN_DIR) $(OBJ_DIR) "

Replace /path/to/gtest with the actual path where you have installed Google Test.

Rebuild Your Project:
After updating your Makefile, run make again. This should resolve the 'gtest/gtest.h' file not found error.

Make sure that you have the Google Test library installed in the specified path and that the include paths are correctly set in your Makefile.

### Changes 1
With that I changed my makefile to have the gtest directory, which for me was just "/googletest/googletest" because I added the test files within the project folder. After that I changed my CXXFLAGS and LDFLAGS so that it included the directory of the googletest so that when i compile everything with the makefile, it connects them to the googltest that has the library in the folder.
To download the google test and figure out how to fully implement it to my computer, I used the video in the code reference section.

### Prompt 2
For my strip function, I stumbled upon a stackoverflow link that had a really good strip code, that I used for my function.
As my original code was this:

auto cpy_str = str.begin();
for(size_t i = 0; i < str.length(); i++)
    {
        if(std::isspace(cpy_str[i]))
        {
            cpy_str++;
        }
        else
        {
            break;
        }
    }

### Response 2
Someone replied to the original post with a function for strip that works exactly as it suppose to. However instead of a for loop they managed to do the function with a while loop.
What I wanted my function to do is to iterate through every character within the string, and if the character that it is currently on is a whitespace, then it pushes the str further. If the character is a letter then it should break out of the loop.
However, the code would randomly stop after the first few or would go farther and delete some letters.

The code from the stackoverflow:

std::string strip(const std::string &inpt)
{
    auto start_it = inpt.begin();
    auto end_it = inpt.rbegin();
    while (std::isspace(*start_it))
        ++start_it;
    while (std::isspace(*end_it))
        ++end_it;
    return std::string(start_it, end_it.base());
}

### Changes 2
So I changed my function to the one similar in the stackoverflow. Since I didn't do the code myself, I had to understand what the code meant. At the time I found this code, I was working on the Lstrip function, so I wanted to take apart the code that essentially built that strip. The code from stackoverflow was very similiar to what I tried, but I was stuck on was the *start_it, but then after researching I figured that its just the pointer to the current character.


And so for the Lstrip I used the code:

auto cpy_str = str.begin();
while(std::isspace(*cpy_str))
{
    ++cpy_str;
}
return std::string(cpy_str, str.end())

### Prompt 3
1.What does str.base() mean? -> 2.Then would you say that .base() is the stopping point? -> 3.So if i were do to something like cpy_str = str.rbegin(), then whatever iterator that it is at, if i do .base() then it coverts it to str.begin()?

### Responses 3
1. In C++, the member function base() is not directly applicable to std::string. Instead, it is commonly associated with iterators.

If you are dealing with iterators in C++, such as those obtained from std::string, std::vector, or other container classes, you may encounter the base() member function.

For example, consider the use of iterators in a std::string:

cpp
Copy code
std::string str = "Hello, World!";
auto it = str.begin();
In this case, it is an iterator pointing to the beginning of the string. If you want to access the underlying iterator type (like const_iterator or reverse_iterator), you can use the base() member function. Here's an example:

cpp
Copy code
std::string::iterator it = str.begin();
std::string::iterator base_it = it.base();
In the above code, base_it will be an iterator of the underlying iterator type (char* in this case).

Keep in mind that the base() member function is used in the context of iterators and is not applicable to the entire std::string object directly. If you provide more context or code, I can provide a more specific explanation.

2. No, the base() function is not a stopping point. It is a mechanism to obtain the underlying iterator from an iterator adaptor, such as a reverse iterator. It is used to switch back to the original iterator type.

In the context of reverse iterators, the base() function is more about conversion rather than stopping. It allows you to switch between the forward and reverse iterations seamlessly.

If you're experiencing issues with your code randomly stopping, it's likely related to other parts of your code, not specifically to the use of base(). You may want to examine the rest of your code, especially the loop conditions and any other interactions with iterators, to identify the root cause of the stopping behavior.

3. Yes, that's correct. When you use rbegin() to obtain a reverse iterator, and then you call base() on that reverse iterator, it gives you an iterator that corresponds to the begin() of the original sequence.

Here's an example:

cpp
Copy code
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";

    // Get a reverse iterator
    std::string::reverse_iterator rit = str.rbegin();

    // Use base() to obtain the corresponding forward iterator
    std::string::iterator forward_it = rit.base();

    // Output the characters using the forward iterator
    while (forward_it != str.end()) {
        std::cout << *forward_it;
        ++forward_it;
    }

    return 0;
}
In this example, rit is a reverse iterator created using rbegin(), and then base() is used to get the corresponding forward iterator (forward_it). The loop then prints the characters of the string in reverse order using the forward iterator.

### Changes 3
With the strip code from stackoverflow, I looked into the part that can be used for RStrip. Another thing I was confused on was .base(), was it wasn't a function I've seen? .begin() and .end() has been covered in class, and i may have missed .base(). Overall, what I learned is that .base() is a command that converts the reverse iterator, caused by rbegin(), to the normal iteration. So it changes the function from rbegin() to begin().

And so my code for RStrip is:

    auto cpy_str = str.rbegin();

    while(std::isspace(*cpy_str))
    {
        ++cpy_str;
    }

    return std::string(str.begin(), cpy_str.base());

###