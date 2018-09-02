//Description: Just a simple algorithm which pastes a quote into a cloud above a cow
// (as it was said by cow)

#include <iostream>
#include <string>
#include <fstream>

#define CLOUD_LENGTH 25

void print_text(std::string);
void print_cow();
bool is_short(std::string);
void print_upper_frame();
void print_line(std::string);
void print_lower_frame();

int main()
{
    std::string text;

    std::cout << "Type a quote: ";
    getline(std::cin, text);

    print_text(text);
    print_cow();
}

void print_text(std::string text)
{
    std::cout << "\n\n";
    print_upper_frame();

    if (is_short(text))
    {
        print_line(text);
        print_lower_frame();
        return;
    }

    std::string::iterator it = text.begin();

    while (it != text.end())
    {
        std::string line = "";
        int i = 0;
        for(; (it != text.end()) && (i < CLOUD_LENGTH); ++it, ++i)
        {
            line.push_back(*it);
        }
        print_line(line);
    }
    print_lower_frame();
    //print upper frame
    //check length of the quote, if it has less than 40 characters -> print whole
        //else: print up to first space before 40th character + add ' ' to fill rest of the line
    //check length for rest of the quote
    //do the same while there are any characters left
}

void print_cow() 
{
    std::fstream cow;
    std::string line;
    cow.open("src/cow1.txt");

    if (cow.is_open())
    {
        std::cout << '\n';
        while (getline(cow, line))
            std::cout << "    " << line << '\n';
        
        cow.close();
    }
    else
        std::cout << "Can't open cow file!\n";

    //just print ascii "cow"
}

void print_upper_frame()
{
    char h = 205, sw = 187, se = 201;
    std::cout << ' ' << se;
    for (int i = 0; i < CLOUD_LENGTH; ++i)
        std::cout << h; 
    std::cout << sw << '\n';
}

void print_line(std::string text)
{
    text.resize(CLOUD_LENGTH, ' ');
    char v = 186;
    std::cout << ' ' << v << text << v << '\n';
}

void print_lower_frame()
{
    char v = 186, h = 205, nw = 188, ne = 200, se = 201;
    std::cout << ' ' << v << se;
    for (int i = 0; i < CLOUD_LENGTH-1; ++i)
        std::cout << h; 
    std::cout << nw << '\n';
    std::cout << ' ' << '\\' << v << std::endl;
}

bool is_short(std::string text)
{
    if (text.size() > CLOUD_LENGTH)
        return false;
    else
        return true;
}

