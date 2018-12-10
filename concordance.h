/*
File: concordance.h
Author: David Serrano
Email: davids2016@student.vvc.edu
Description: header file for concordance 
*/

#ifndef CONCORDANCE_H
#define CONCORDANCE_H
#include "word.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
class Concordance
{
public:
    Concordance(std::string filename);
    // Computes information from current file
    void parse();
    // Searches through vector for index a word. Returns -1 if no index.
    int find_word(std::string word);
    // Prints information of every word in vector
    void print();
private:
    // Vector of word objects
    std::vector<Word> m_word_stats;
    // Name of file
    std::string m_filename;
};

#endif
