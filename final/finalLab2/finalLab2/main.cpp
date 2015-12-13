#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct Toggles {
    bool caseSensitive = true;
    bool andOr = true;
    bool ranking = true;
    bool exit = false;
};

void displayMenu(Toggles toggle) {
    cout << "1- Togglecase sensitive search (currently " << (toggle.caseSensitive ? "ON" : "OFF") << ")"<< endl
    << "2- Toggle AND/OR search (currently " << (toggle.andOr ? "AND" : "OR") << ")" << endl
    << "3- Toggle Ranking with OR search(currently " << (toggle.ranking ? "ON" : "OFF") << ")" << endl
    << "4- Exit" << endl;
}

string stringTolower(string str) {
    for (int i = 0; i < str.size() && isalpha(str.at(i)); i++) {
        str.at(i) = tolower(str.at(i));
    }
    return str;
}

void vectorReader(vector <string> &bookList, string fileName) {
    fstream in(fileName, ios::in);
    if (in) {
        string buffer;
        while (getline(in, buffer)) {
            bookList.push_back(buffer);
        }
        cout << "The input file has been read to the vector\n";
    } else {
        cout << "The input file is failed to open\n";
    }
    in.close();
}

void searchMatch(Toggles toggle, string input, vector<string> bookList, vector<string> &results) {
    results.clear();
    stringstream ss;
    ss << input;
    string buffer;
    vector<string> keywords;
    while(ss) {
        ss >> buffer;
        cout << buffer << endl;
        if (toggle.caseSensitive) {
            buffer = stringTolower(buffer);
        }
        keywords.push_back(buffer);
    }
    bool isFound;

        for (int i = 0; i < bookList.size(); i++) {
            string aTitle = bookList.at(i);
            if (toggle.caseSensitive) {
                stringTolower(aTitle);
            }
            
            if (toggle.andOr) {
                // and search
                isFound = true;
                for (int j = 0; j < keywords.size() && isFound; j++) {
                    size_t found = aTitle.find(keywords.at(j));
                    if (found == std::string::npos) {
                        isFound = false;
                    }
                }
                if (isFound) {
                    results.push_back(aTitle);
                }
            } else {
                // or search
                isFound = false;
                for (int j = 0; j < keywords.size() && !isFound; j++) {
                    size_t found = aTitle.find(keywords.at(j));
                    bool isFound = false;
                    if (found != std::string::npos) {
                        results.push_back(aTitle);
                        isFound = true;
                    }
                }
            }
        }
    cout << results.size() << " results\n";
    for (int i=0; i<results.size(); i++) {
        cout << results.at(i) << endl;
    }
    
}

int main() {
    
    
    Toggles toggle;
    string fileName("/Users/satoru/Desktop/finalLab2/finalLab2/Textbooks.txt");
    vector<string> bookList;
    vector<string> results;
    vectorReader(bookList, fileName);
    
    
    while (!toggle.exit) {
        displayMenu(toggle);
        cout << "Your input > ";
        string input;
        getline(cin, input);
        stringstream ss;
        ss << input;
        int choice;
        ss >> choice;
        
        switch (choice) {
            case 1:
                toggle.caseSensitive = !toggle.caseSensitive;
                cout << "Case sensitive search is now " << (toggle.caseSensitive ? "ON" : "OFF") << endl;
                break;
            case 2:
                toggle.andOr = !toggle.andOr;
                cout << "AND/OR search is now " << (toggle.andOr ? "AND" : "OR") << endl;
                break;
            case 3:
                toggle.ranking = !toggle.ranking;
                cout << "Ranking with OR search is now " << (toggle.ranking ? "ON" : "OFF") << endl;
                break;
            case 4:
                toggle.exit = !toggle.exit;
                cout << "Bye" << endl;
                break;
            default:
                searchMatch(toggle, input, bookList, results);
                break;
        }
    }
    
    return 0;
}
