/**
 * Project Untitled
 */


#ifndef _STRINGMATCHER_H
#define _STRINGMATCHER_H

class StringMatcher {
public: 
    void brute_force(pattern: string, text: string, max_distance: int): vector<int>;
    void rabin_karp(pattern: string, text: string): vector<int>;
    
/**
 * @param s1
 * @param s2
 */
int hamming_distance(string s1, string s2);
    
/**
 * @param pattern
 * @param text
 * @param max_distance
 */
vector<int> brute_force(string pattern, string text, int max_distance);
    
/**
 * @param pattern
 * @param text
 */
vector<int> rabin_karp(string pattern, string text);
private: 
    int max_distance;
};

#endif //_STRINGMATCHER_H