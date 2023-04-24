/**
 * Project Untitled
 */


#ifndef _PDETECTOR_H
#define _PDETECTOR_H

class PDetector {
public: 
    
void find_corpus();
    
/**
 * @param filename
 */
string read_file(string filename);
    
/**
 * @param text
 */
vector<string> split_sentences(string text);
    
void detect_plagiarism();
private: 
    vector<string> corpus;
};

#endif //_PDETECTOR_H