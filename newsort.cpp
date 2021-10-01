#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
#include "newview.cpp"
using namespace std;

// function declarations
void mergeSort(string[], int, int, int);
void mergeThem(string[], int, int, int, int);
void sortVolID(bool);
void sortVolFname(bool);
void sortVolAge(bool);

void sortVolID(bool asc)
{
    fstream vfile, vidfile;
    string line, id, fname;
    bool ascending = asc;

    vector<string>ids;

    vidfile.open("volunteer-id.txt", ios::in);
    volHeader();
    if (!vidfile.is_open()) {                 // file not opened
        cout << "File not opened!" << endl;
    }
    else {                                  // file opened
        while (getline(vidfile, id)) {
            ids.push_back(id);
        }
    }

    int s = ids.size();
    string arr[s];
    for (int i=0; i<s; i++) {
        arr[i] = ids[i];
    }

    mergeSort(arr, 0, s-1, s);

    if (ascending == true) {
        for (int i=0; i<s; i++) {
            viewVol(arr[i], false);
        }
    }
    else {
        stack<string>stk;
        for (int i=0; i<s; i++) {
            stk.push(arr[i]);
        }
        while(!stk.empty()) {
            viewVol(stk.top(), false);
            stk.pop();
        }
    }
    cout << setfill('_') << setw(112) << "_" << endl;
}

void sortVolFname(bool asc)
{
    fstream vfile, vidfile, vofile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;
    bool ascending = asc;

    volHeader();

    vidfile.open("volunteer-id.txt", ios::in);

    vector<string>ids;
    vector<string>ids2;
    vector<string>fnames;

    // get id
    if (!vidfile.is_open()) {                 // file not opened
        cout << "file not opened!" << endl;
    }
    else {
        while (getline(vidfile, id)) {
            ids.push_back(id);
        }
        for (int i=0; i<ids.size(); i++) {
            // open volunteer file
            vfile.open("volunteer/" + ids[i] + ".txt", ios::in);

            if (!vfile.is_open()) {                 // file not opened
                cout << "File not opened!" << endl;
            }
            else {                                  // file opened
                vector<string>v;
                string v_ID="", v_fname="";
                getline(vfile, line);
                stringstream ss(line);

                while (ss.good()) {
                    string sub="";
                    getline(ss, sub, ';');
                    v.push_back(sub);
                }
                // assign substring to string variables
                v_ID = v[0];
                v_fname = v[1];
                fnames.push_back(v_fname);
            }
            vfile.close();
        }
        vidfile.close();
    }

    sort(fnames.begin(), fnames.end());

    vidfile.open("volunteer-id.txt", ios::in);

    for (int i=0; i<fnames.size(); i++) {
        for (int j=0; j<ids.size(); j++) {
            vector<string> v2;
            vfile.open("volunteer/" + ids[j] + ".txt", ios::in);

            string v_ID="", v_fname="";

            getline(vfile, line);
            stringstream ss(line);

            while (ss.good()) {
                string sub;
                getline(ss, sub, ';');
                v2.push_back(sub);
            }

            // assign substring to string variables
            v_ID = v2[0];
            v_fname = v2[1];
            if (fnames[i] == v_fname) {
                ids2.push_back(v_ID);
            }
            else {
            }
            vfile.close();
        }

    }
    vidfile.close();
    cout << endl;

    if (ascending == true) {
        for (int i=0; i<ids2.size(); i++) {
            viewVol(ids2[i], false);
        }
    }
    else {
        // stack for descending order
        stack<string> stk;

        for (int i=0; i<ids2.size(); i++) {
            stk.push(ids2[i]);
        }

        while(!stk.empty()) {
        viewVol(stk.top(), false);
            stk.pop();
        }
    }
    cout << setfill('_') << setw(112) << "_" << endl;
}

void sortVolAge(bool asc)
{
    fstream vfile, vidfile, vofile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;
    bool ascending = asc;

    volHeader();

    vidfile.open("volunteer-id.txt", ios::in);

    vector<string>ids;
    vector<string>ids2;
    vector<string>ages;

    // get id
    if (!vidfile.is_open()) {                 // file not opened
        cout << "file not opened!" << endl;
    }
    else {
        while (getline(vidfile, id)) {
            ids.push_back(id);
        }
        for (int i=0; i<ids.size(); i++) {
            // open volunteer file
            vfile.open("volunteer/" + ids[i] + ".txt", ios::in);

            if (!vfile.is_open()) {                 // file not opened
                cout << "File not opened!" << endl;
            }
            else {                                  // file opened
                vector<string>v;
                string v_ID="", v_age="";
                getline(vfile, line);
                stringstream ss(line);

                while (ss.good()) {
                    string sub="";
                    getline(ss, sub, ';');
                    v.push_back(sub);
                }
                // assign substring to string variables
                v_ID = v[0];
                v_age = v[3];
                ages.push_back(v_age);
            }
            vfile.close();
        }
        vidfile.close();
    }

    sort(ages.begin(), ages.end());

    vidfile.open("volunteer-id.txt", ios::in);

    for (int i=0; i<ages.size(); i++) {
        for (int j=0; j<ids.size(); j++) {
            vector<string> v2;
            vfile.open("volunteer/" + ids[j] + ".txt", ios::in);

            string v_ID="", v_age="";

            getline(vfile, line);
            stringstream ss(line);

            while (ss.good()) {
                string sub;
                getline(ss, sub, ';');
                v2.push_back(sub);
            }

            // assign substring to string variables
            v_ID = v2[0];
            v_age = v2[3];
            if (ages[i] == v_age) {
                ids2.push_back(v_ID);
            }
            else {
            }
            vfile.close();
        }

    }
    vidfile.close();

    if (ascending == true) {
        for (int i=0; i<ids2.size(); i++) {
            viewVol(ids2[i], false);
        }
    }
    else {
        // stack for descending order
        stack<string> stk;

        for (int i=0; i<ids2.size(); i++) {
            stk.push(ids2[i]);
        }

        while(!stk.empty()) {
        viewVol(stk.top(), false);
            stk.pop();
        }
    }
    cout << setfill('_') << setw(112) << "_" << endl;
}

void mergeSort(string a[], int first, int last, int sz)
{
    int s = sz;
    if (first < last) {
        int mid = (first+last)/2;

        mergeSort(a, first, mid, s);
        mergeSort(a, mid+1, last, s);

        mergeThem(a, first, mid, last, s);
    }
}

void mergeThem(string a[], int first, int mid, int last, int sz)
{
    int s = sz;
    string temparr[s];

    int first1 = first;
    int last1 = mid;
    int first2 = mid+1;
    int last2 = last;

    int index;

    for (index=first; (first1<=last1) && (first2<=last2); ++index) {
        if (a[first1] < a[first2]) {
            temparr[index] = a[first1];
            ++first1;
        }
        else {
            temparr[index] = a[first2];
            ++first2;
        }
    }

    while (first1 <= last1) {
        temparr[index] = a[first1];
        ++first1;
        ++index;
    }

    while (first2 <= last2) {
        temparr[index] = a[first2];
        ++first2;
        ++index;
    }

    for (index=first; index<=last; ++index) {
        a[index] = temparr[index];
    }
}

/**
int main()
{
    cout << "\n\t\tSORTING BY ID (ASCENDING)" << endl;
    sortVolID(true);
    cout << "\n\t\tSORTING BY ID (DESCENDING)" << endl;
    sortVolID(false);

    cout << "\n\t\tSORTING BY FIRST NAME (ASCENDING)" << endl;
    sortVolFname(true);
    cout << "\n\t\tSORTING BY FIRST NAME (DESCENDING)" << endl;
    sortVolFname(false);

    cout << "\n\t\tSORTING BY AGE (ASCENDING)" << endl;
    sortVolAge(true);
    cout << "\n\t\tSORTING BY AGE (DESCENDING)" << endl;
    sortVolAge(false);
    return 0;
}
**/
