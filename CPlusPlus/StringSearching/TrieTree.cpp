#include <iostream>
#include <vector>

class TrieNode {
    public:
    int wordEndCount;
    std::vector<TrieNode*> childArray;
    TrieNode() {
        wordEndCount=0;
        childArray.resize(256,NULL);
    }
};
class TrieTree {
    private:
    TrieNode* root;
    int charIndex(char c) {
        return c-0;
    }
    public:
    TrieTree() {
        root = new TrieNode();
    }
    void insertString(std::string line) {
        TrieNode* curr = root;
        int i;
        TrieNode* prev = NULL;
        for (i=0; i<line.size(); ++i) {
            if (curr->childArray[charIndex(line[i])]==NULL) {
                prev = curr;
                curr->childArray[charIndex(line[i])] = new TrieNode();
            }

            curr = curr->childArray[charIndex(line[i])];
        }
        ++(prev->wordEndCount);
    }
    void deleteString(std::string line) {
        TrieNode* curr = root;
        int i;
        TrieNode* prev = NULL;
        for (i=0; i<line.size(); ++i) {
            if (curr->childArray[charIndex(line[i])]==NULL) {
                return;
            }
            prev=curr;
            curr = curr->childArray[charIndex(line[i])];
        }
        if (prev->wordEndCount>0) {
            --prev->wordEndCount;
        }
    }
    bool searchString(std::string line) {
        TrieNode* curr = root;
        int prevWordCount=0;
        for (int i=0; i<line.size(); ++i) {
            if (curr->childArray[charIndex(line[i])]==NULL) {
                return false;
            }
            prevWordCount = curr->wordEndCount;
            //std::cout << curr->wordEndCount << " " << curr->childArray[charIndex(line[i])] <<std::endl;
            curr = curr->childArray[charIndex(line[i])];   
        }
        if (prevWordCount>0) {
            return true;
        }
        return false;
    }
    void displayTree() {
        TrieNode* curr = root;
        std::string word;
        bool wordFound=false;
        for (int i=0; i<255; ++i) {
            if (curr->wordEndCount>0) {
                std::cout << word;
            }
            if (curr->childArray[i]!=NULL) {
                word.push_back(0+i);
                wordFound=true;
            }
        }
    }
};

int main() {
    TrieTree* t = new TrieTree;
    t->insertString("tree");
    t->insertString("tub");
    t->insertString("torso");
    if (t->searchString("tree")) {
        std::cout << "String found\n";
    }
    else {
        std::cout << "String not found\n";
    }
    if (t->searchString("tub")) {
        std::cout << "String found\n";
    }
    else {
        std::cout << "String not found\n";
    }
    if (t->searchString("torso")) {
        std::cout << "String found\n";
    }
    else {
        std::cout << "String not found\n";
    }
    if (t->searchString("trees")) {
        std::cout << "String found\n";
    }
    else {
        std::cout << "String not found\n";
    }
    t->deleteString("tree");
    if (t->searchString("tree")) {
        std::cout << "String found\n";
    }
    else {
        std::cout << "String not found\n";
    }
    return 0;
}