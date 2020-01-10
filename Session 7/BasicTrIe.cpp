#include <cstring>
#include <iostream>
using namespace std;

// current implementation works on upper case i.e. why array of 26 is taken

class trieNode {
   private:
    trieNode *data[26];
    bool endOfQuery;

   public:
    trieNode() {
        for (int i = 0; i < 26; i++) {
            data[i] = nullptr;
        }
        endOfQuery = false;
    }

    void insert(string __input) {
        trieNode *temp = this;

        for (int i = 0; i < __input.size(); i++) {
            int index = __input[i] - 'A';
            if (temp->data[index] == nullptr) {
                temp->data[index] = new trieNode();
                temp = temp->data[index];
            } else {
                temp = temp->data[index];
            }
        }
        temp->endOfQuery = true;
    }

    bool search(string __query) {
        trieNode *temp = this;

        for (int i = 0; i < __query.size(); i++) {
            int index = __query[i] - 'A';
            if (temp->data[index] == nullptr) {
                return false;
            } else {
                temp = temp->data[index];
            }
        }

        return (temp && temp->endOfQuery);
    }

    ~trieNode() {}
};

class Trie {
   private:
    trieNode root;

   public:
    Trie() : root() {}

    void insert(string __input) {
        this->root.insert(__input);
    }

    void search(string __query) {
        if (this->root.search(__query)) {
            cout << __query << " found in trie\n";
        } else {
            cout << __query << " not found in trie\n";
        }
    }

    ~Trie() {}
};

int main(int argc, char const *argv[]) {
    Trie sample;
    sample.insert("BANANA");
    sample.insert("APPLE");
    sample.search("BAN");
    sample.search("APPLE");
    return 0;
}
