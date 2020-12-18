/*
Problem 1

The Constitution of a certain country states that the leader is the person with the name 
containing the greatest number of different alphabet letters. (The country uses the uppercase
English alphabet from A through Z.) For example, the name GOOGLE has four different alphabet
letters: E, G, L, and O. The name APAC CODE JAM has eight different letters. If the country
only consists of these 2 persons, APAC CODE JAM would be the leader.

If there is a tie, the person whose name comes earliest in alphabetical order is the leader.

Given a list of names of the citizens of the country, can you determine who the leader is?

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test 
case starts with a line with an interger N, the number of people in the country. Then N lines 
follow. The i-th line represents the name of the i-th person. Each name contains at most 20 
characters and contains at least one alphabet letter.

Output

For each test case, output one line containing Case #x: y, where x is the test case number 
(starting from 1) and y is the name of the leader.

Limits

1 ≤ T ≤ 100.
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ N ≤ 100.
Small dataset (Test set 1 - Visible)

Each name consists of at most 20 characters and only consists of the uppercase English letters 
A through Z.
Large dataset (Test set 2 - Hidden)

Each name consists of at most 20 characters and only consists of the uppercase English letters 
A through Z and ' '(space).

All names start and end with alphabet letters.

Sample

Input
2
3
ADAM
BOB
JOHNSON
2
A AB C
DEF

Output

Case #1: JOHNSON
Case #2: A AB C


  

In sample case #1, JOHNSON contains 5 different alphabet letters('H', 'J', 'N', 'O', 'S'), so 
he is the leader.

Sample case #2 would only appear in Large data set. The name DEF contains 3 different alphabet 
letters, the name A AB C also contains 3 different alphabet letters. A AB C comes alphabetically
earlier so he is the leader.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

void print_vector_pair(vector<pair<short, short>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << i << " : " << vec[i].first << " " << vec[i].second << endl;
    }
    return;
}

void print_vector_string(vector<string> names) {
    for (int i = 0; i < names.size(); i++) {
        cout << i << " : " << names[i] << endl;
    }
    return;
}

vector<pair<short, short>> sub_func_1(vector<string> names) {
    short char_map[26];
    vector<pair<short, short>> distinct_alpha;
    for (int i = 0; i < names.size(); i++) {
        short freq = 0;
        memset(char_map, 0, sizeof(char_map));
        for (int j = 0; j < names[i].size(); j++) {
            if (names[i][j] != ' ') // to avoid any segmentation faults at run time
                char_map[names[i][j] - short('A')] = 1;
        }
        for (int j = 0; j < 26; j++) {
            freq = (char_map[j] == 1)?(freq+1):(freq);
        }
        distinct_alpha.push_back(make_pair(i, freq));
    }
    // ~O(n) {'n' names; each name is atmost 20 chars + iterate over 26 = O(46n)}
    sort(distinct_alpha.begin(), distinct_alpha.end(), [ ](const auto & lhs, const auto & rhs){
        return lhs.second > rhs.second;
    });
    // ~O(nlogn) {assuming quicksort algo}
    vector<pair<short, short>> result;
    short benchmark = distinct_alpha[0].second;
    for (int i = 0; i < distinct_alpha.size(); i++) {
        if (distinct_alpha[i].second == benchmark) {
            result.push_back(distinct_alpha[i]);
        } else {
            break;
        }
    }
    // ~O(n) {worst case}
    return result;
}

string function(vector<string> names) {
    vector<pair<short, short>> max_distinct_alpha = sub_func_1(names); 
    //print_vector_pair(max_distinct_alpha);
    if (max_distinct_alpha.size() == 1) {
        return names[max_distinct_alpha[0].first];
    } else {
        vector<string> result;
        for (int i = 0; i < max_distinct_alpha.size(); i++) {
            result.push_back(names[max_distinct_alpha[i].first]);
        }
        sort(result.begin(), result.end());
        return result[0];
    }
}

int main () {
    int t;
    cin >> t;
    for (int case_num = 1; case_num <= t; case_num++){
        int n; // number of people in the country
        cin >> n;
        vector<string> names;
        string temp;
        getline(cin, temp); // to discard or not read previous '\n' char
        while (n > 0) {
            getline(cin, temp);
            names.push_back(temp);
            n --;
        }
        //print_vector_string(names);
        string result = function(names);
        cout << "Case #" << case_num << ": " << result << endl;
    }
    return 0;
}