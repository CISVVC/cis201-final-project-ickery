#include "concordance.h"

Concordance::Concordance(std::string filename)
{
    m_filename = filename;
}

void Concordance::parse()
{
    std::ifstream file(m_filename.c_str());
    std::string sentence;
    int line_count = 1;
    // Loops through each line in the text
    while(std::getline(file, sentence))
    {
        std::istringstream stream(sentence);
        std::string word;
        // Loops through each word in line
        while(stream >> word)
        {
          int word_index = find_word(word);
          // If word was found, add count and line to existing word. 
          if(word_index != -1)
          {
                m_word_stats[word_index].add_count(1);
                m_word_stats[word_index].add_line(line_count);
          }
          // If word was not found, create new word and place it into word_stats
          else
          {
                Word new_word(word);
                new_word.add_line(line_count);
                m_word_stats.push_back(new_word);
          }
          std::cout << word << std::endl;
        }
        line_count += 1;
    }
}

bool Concordance::is_whitespace(char c)
{
  return (c == ' ' || c == '\n' ||  c == '\t');
}

void Concordance::eat_whitespace(std::ifstream& input)
{
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_whitespace(c))
        {
            input.putback(c); // this will put the character back on the input stream
            break;
        }
    }
}

std::string Concordance::next_word(std::ifstream& input)
{
    std::string word;
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_whitespace(c))
        {
            word += c;
        }
        else
        {
            eat_whitespace(input);
            break;
        }
    }
    return word;
}

int Concordance::find_word(std::string word)
{
    for(int i = 0; i < m_word_stats.size(); i++)
    {
        if(m_word_stats[i].get_word() == word){ return i;}
    }
    return -1;
}

void Concordance::print()
{
    for(int i = 0; i < m_word_stats.size(); i++)
    {
        std::cout << m_word_stats[i].get_word() << " : " << m_word_stats[i].get_count() << " : ";
        m_word_stats[i].print_lines();
        std::cout << std::endl;
    }
}
