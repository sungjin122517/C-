#include <iostream>
#include <fstream>

using namespace std;
#define MAX_NUM_STU 20

// TASK1: Merge two files into a new file.
void mergeFile(const string ip_filename1, const string ip_filename2, const string op_filename){
    
    ifstream ifs1(ip_filename1);    // create a ifstream object called ifs1
    ifstream ifs2(ip_filename2);    // create a ifstream object called ifs2
    ofstream ofs(op_filename);      // create a ofstream object called ofs
    
    // char temp;
    // while (ifs1 >> noskipws >> temp)    // reads data from file through ifs1
    //     ofs << temp;
    // ofs << "\n";
    // while (ifs2 >> noskipws >> temp)
    //     ofs << temp;

    char c1;
    ifs1.get(c1);           // try to get the first char
    while (!ifs1.eof()) {   // check if EOF is reached
        ofs.put(c1);        // copy one char at a time 
        ifs1.get(c1);       // try to get the next char

    }
    ofs << "\n";

    char c2;
    while (!ifs2.eof()) {
        ofs.put(c2);
        ifs2.get(c2);
    }

    ifs1.close();
    ifs2.close();
    ofs.close();
    

}

// TASK2: Clean a given file and save it to a new file.
void cleanFile(const string ip_filename, const string op_filename){
    
    ifstream ifs(ip_filename);
    ofstream ofs(op_filename);

    char c;
    ifs.get(c);            // try to get the first char
    while (!ifs.eof()) {   // check if EOF is reached
        if ( (int)c >= 48 && (int)c <= 57 ) {       // for numbers
            ofs.put(c);         
            ifs.get(c);
            if ( !( (int)c >= 48 && (int)c <= 57 ) ) 
                ofs << "\n";
        }
        else if ( ((int)c >= 65 && (int)c <= 90) || ((int)c >= 97 && (int)c <= 122) ) {         // for characters
            ofs.put(c);
            ifs.get(c);
            if ( !( ((int)c >= 65 && (int)c <= 90) || ((int)c >= 97 && (int)c <= 122) ) )
                ofs << "\t";
        }
        else
            ifs.get(c);
    }

    ifs.close();
    ofs.close();    

    
    // string s[10];
    // for (int i = 0; i < 10; i++) {
    //     getline(ifs, s[i], ' ');
    //     cout << s[i] << endl;
    // }


}

// TASK3: Analyze a file, that is, to find the two students who have got the lowest and the highest grade, respectively.
// If two or more students got the same lowest/highest grade, you only need to return the first-appeared ones.
void analyzeFile(const string filename, string &low_name, string &high_name, int &low_grade, int &high_grade){

    // read each line getline()
    // separate name and score by tab
    // put the number as int
    // store as max and compare in loop

    ifstream ifs(filename);

    string s[12*2];
    for (int i = 0; i < 12*2; i+=2) {
        getline(ifs, s[i], '\t');
        getline(ifs, s[i+1]);
    }

    // cout << s[6] << endl;
    
    int k = 0;
    int score[MAX_NUM_STU];

    for (int j = 1; j < 12*2; j += 2) {
        score[k] = stoi(s[j]);
        k++;
    }

    // cout << score[5] << endl;

    low_name = s[0];
    high_name = s[0];
    low_grade = score[0];
    high_grade = score[0];

    int stu_name = 2;

    for (int i = 1; i < 12; i++) {
        if (low_grade > score[i]) {
            low_grade = score[i];
            low_name = s[stu_name];
        }

        if (high_grade < score[i]) {
            high_grade = score[i];
            high_name = s[stu_name];
        }
        
        stu_name += 2;

    }

    ifs.close();

    

    
}

// Display a given file.
void displayFile(const string filename){
    string temp;
    ifstream ifs(filename);
    if (!ifs){
        cerr << "Error: Cannot open " << filename << endl;
        return;
    }
    
    cout << filename << endl;
    while (!ifs.eof()){
        getline(ifs, temp);
        cout << temp << endl;
    }
    cout << endl;
    ifs.close();
    return;
}

int main(){
    string low_name, high_name;
    int low_grade = 0, high_grade = 0;

    displayFile("record1.txt");
    displayFile("record2.txt");

    cout << (int)('!') <<endl;

    mergeFile("record1.txt", "record2.txt", "record.txt");
    displayFile("record.txt");

    cleanFile("record.txt", "record_clean.txt");
    displayFile("record_clean.txt");

    analyzeFile("record_clean.txt", low_name, high_name, low_grade, high_grade);
    cout << low_name << " got the lowest grade: " << low_grade << endl;
    cout << high_name << " got the highest grade: " << high_grade << endl;
    return 0;
}