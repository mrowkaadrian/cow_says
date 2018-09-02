//Description: Just a simple algorithm which pastes a quote into a cloud above a cow
// (as it was said by cow)

#include <iostream>
#include <string>

void print_text();
void print_cow();

int main()
{
    std::string text;

    std::cout << "Paste a quote: "
    std::cin >> text;

    print_text();
    print_cow();
}

void print_text()
{
    //print upper frame
    //check length of the quote, if it has less than 40 characters -> print whole
        //else: print up to first space before 40th character + add ' ' to fill rest of the line
    //check length for rest of the quote
    //do the same while there are any characters left
}

void print_cow() 
{
    //just print ascii "cow"
}