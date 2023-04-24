/**
 * Project Untitled
 */


#ifndef _DISPLAYPGSENTENCE_H
#define _DISPLAYPGSENTENCE_H

class DisplayPGSentence {
public: 
    
string get_text();
    
vector get_matches();
    
/**
 * @param matches
 */
void set_matches(void matches);
private: 
    string Text;
    vector Matches;
};

#endif //_DISPLAYPGSENTENCE_H