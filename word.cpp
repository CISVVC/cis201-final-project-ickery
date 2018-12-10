/* 
File: word.cpp
Author: Davidserrano
Email: davids2016@student.vvc.edu
Description: .cpp file for word class
*/
#include "word.h"

//Constructor for word. Loops through every char in string and makes them lower case via <cctype>
//Param word - word as string
Word::Word(std::string word)
{
   std::string lower_case_word = "";
   for(int i = 0; i < word.size();i++)
   {
        lower_case_word += tolower(word[i]);
   }
   m_word = lower_case_word;
   m_count = 1;
}

// Adds an amount to count of word
//@Param amount to be counted
void Word::add_count(int count)
{
   m_count++;
}

// Adds line to vector of line occurences.
//@Param line to be added
void Word::add_line(int line)
{
   for(int i = 0; i < m_line.size(); i++)
   {
      if (m_line[i] == line){return;}
   }
   m_line.push_back(line);
}

// Returns word string
std::string Word::get_word()
{
    return m_word;
}

// Returns word count
int Word::get_count()
{
    return m_count;
}

// Prints all lines where word occurs
void Word::print_lines()
{
    for(int i = 0; i < m_line.size(); i++)
    {
        std::cout  << m_line[i];
        if(i < m_line.size()-1){ std::cout << ", ";}
    }
}
