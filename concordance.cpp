/*
File:concordance.cpp
Author: David Serrano
Email: davids2016@student.vvc.edu   
Description: .cpp file for concordance class
*/

#include "concordance.h"


// Construct a concordance using information from filename
// Param filename - file to use
Concordance::Concordance(std::string filename)
{
    m_filename = filename;
}

// Loops through each line in text and pulls each word in line individually
// Logs information of each word in a vector.
void Concordance::parse()
{
    std::ifstream file(m_filename.c_str());
    std::string sentence;
    int line_count = 1;
    while(std::getline(file, sentence))
    {
        std::istringstream stream(sentence);
        std::string word;
        while(stream >> word)
        {
          int word_index = find_word(word);
          if(word_index != -1)
          {
                m_word_stats[word_index].add_count(1);
                m_word_stats[word_index].add_line(line_count);
          }
          else
          {
                Word new_word(word);
                new_word.add_line(line_count);
                m_word_stats.push_back(new_word);
          }
        }
        line_count += 1;
    }
}

// Returns index of a word in m_word_stats vector
//@Param word to be searched
int Concordance::find_word(std::string word)
{
    std::string lower_case_word = "";
    for(int i = 0; i < word.size(); i++)
    {
        lower_case_word += tolower(word[i]);
    }

    for(int i = 0; i < m_word_stats.size(); i++)
    {
        if(m_word_stats[i].get_word() == lower_case_word){ return i;}
    }
    return -1;
}

//Prints information of all words in m_word_stats
void Concordance::print()
{
    for(int i = 0; i < m_word_stats.size(); i++)
    {
        std::cout << m_word_stats[i].get_word() << " : " << m_word_stats[i].get_count() << " : ";
        m_word_stats[i].print_lines();
        std::cout << std::endl;
    }
}
