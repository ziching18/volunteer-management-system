#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
#include "view.cpp"
//#include <filesystem>
using namespace std;

void mergeSortAsc(string[], int, int, int);
void mergeAsc(string[], int, int, int, int);
void mergeSortDesc(string[], int, int, int);
void mergeDesc(string[], int, int, int, int);

void sortIDAsc();
void sortIDDesc();

void sortFnameAsc();
void sortFnameDesc();

void sortIDAsc()
{
    fstream vfile, vidfile;
    string line, id, fname;
    //string a[3] = {};
    vector<string>ids;

    //vfile.open("volunteer.txt", ios::in);
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

    mergeSortAsc(arr, 0, s-1, s);

    for (int i=0; i<s; i++) {
        viewVol(arr[i], false);
    }
    /**
    // sort
    stack<string> stck;

    //while (!a.empty()) {
    for (int j=0; j<sizeof(a)/sizeof(a[0]); j++) {
        for (int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
            if(a[0] < a[i]) {
                a[0] = a[i];
            }

        }
        cout << a[0];
        stck.push(a[0]);
        a[0] = '\0';
        cout << a[0];
    }

    //}
    fname = stck.top();
    //cout << fname;
    **/
}

void sortIDDesc()
{
    fstream vfile, vidfile;
    string line, id, fname;
    //string a[3] = {};
    vector<string>ids;

    //vfile.open("volunteer.txt", ios::in);
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

    mergeSortDesc(arr, 0, s-1, s);

    for (int i=0; i<s; i++) {
        viewVol(arr[i], false);
    }
}

void sortFnameAsc()
{
    fstream vfile, vidfile, vofile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;

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
            //cout << "volunteer/" << ids[i] << ".txt" << endl;
            vfile.open("volunteer/" + ids[i] + ".txt", ios::in);

            if (!vfile.is_open()) {                 // file not opened
                cout << "File not opened!" << endl;
            }
            else {                                  // file opened
                vector<string>v;
                string v_ID="", v_fname="";
                getline(vfile, line);
                //cout << line << endl;
                stringstream ss(line);

                while (ss.good()) {
                    string sub="";
                    getline(ss, sub, ';');
                    v.push_back(sub);
                    //cout << sub << endl;
                }
                // assign substring to string variables
                v_ID = v[0];
                v_fname = v[1];
                /**
                for (int i=0; i<v.size(); i++) {
                    cout << v[i] << endl;
                }
                **/

                // get fname
                //cout << "herebitch" << v_ID << " " << v_fname << endl;
                fnames.push_back(v_fname);

                //vfile.close();
            }
            vfile.close();
        }
        vidfile.close();
    }

    sort(fnames.begin(), fnames.end());

    vidfile.open("volunteer-id.txt", ios::in);

    for (int i=0; i<fnames.size(); i++) {
        //cout << "\n" << fnames[i] << endl;
        for (int j=0; j<ids.size(); j++) {
            vector<string> v2;
            vfile.open("volunteer/" + ids[j] + ".txt", ios::in);

            string v_ID="", v_fname="";

            getline(vfile, line);
            //cout << line << endl;
            stringstream ss(line);

            while (ss.good()) {
                string sub;
                getline(ss, sub, ';');
                v2.push_back(sub);
            }

            // assign substring to string variables
            v_ID = v2[0];
            v_fname = v2[1];
            //cout << "\n" << fnames[i] << " " << v_fname;
            if (fnames[i] == v_fname) {
                ids2.push_back(v_ID);
                //cout << "yas" << endl;
                //viewVol(v_ID, false);
            }
            else {
                //cout << "fuck off" << endl;
            }
            vfile.close();
        }

    }
    vidfile.close();
    cout << endl;

    for (int i=0; i<ids2.size(); i++) {
        viewVol(ids2[i], false);
    }
}

void sortFnameDesc()
{
    fstream vfile, vidfile, vofile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;

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
            //cout << "volunteer/" << ids[i] << ".txt" << endl;
            vfile.open("volunteer/" + ids[i] + ".txt", ios::in);

            if (!vfile.is_open()) {                 // file not opened
                cout << "File not opened!" << endl;
            }
            else {                                  // file opened
                vector<string>v;
                string v_ID="", v_fname="";
                getline(vfile, line);
                //cout << line << endl;
                stringstream ss(line);

                while (ss.good()) {
                    string sub="";
                    getline(ss, sub, ';');
                    v.push_back(sub);
                    //cout << sub << endl;
                }
                // assign substring to string variables
                v_ID = v[0];
                v_fname = v[1];
                /**
                for (int i=0; i<v.size(); i++) {
                    cout << v[i] << endl;
                }
                **/

                // get fname
                //cout << "herebitch" << v_ID << " " << v_fname << endl;
                fnames.push_back(v_fname);

                //vfile.close();
            }
            vfile.close();
        }
        vidfile.close();
    }

    sort(fnames.begin(), fnames.end());

    vidfile.open("volunteer-id.txt", ios::in);

    for (int i=0; i<fnames.size(); i++) {
        //cout << "\n" << fnames[i] << endl;
        for (int j=0; j<ids.size(); j++) {
            vector<string> v2;
            vfile.open("volunteer/" + ids[j] + ".txt", ios::in);

            string v_ID="", v_fname="";

            getline(vfile, line);
            //cout << line << endl;
            stringstream ss(line);

            while (ss.good()) {
                string sub;
                getline(ss, sub, ';');
                v2.push_back(sub);
            }

            // assign substring to string variables
            v_ID = v2[0];
            v_fname = v2[1];
            //cout << "\n" << fnames[i] << " " << v_fname;
            if (fnames[i] == v_fname) {
                ids2.push_back(v_ID);
                //cout << "yas" << endl;
                //viewVol(v_ID, false);
            }
            else {
                //cout << "fuck off" << endl;
            }
            vfile.close();
        }

    }
    vidfile.close();
    cout << endl;

    stack<string> stk;

    for (int i=0; i<ids2.size(); i++) {
        //viewVol(ids2[i], false);
        stk.push(ids2[i]);
    }

    while(!stk.empty()) {
        viewVol(stk.top(), false);
        stk.pop();
    }
}

void mergeSortAsc(string a[], int first, int last, int sz)
{
    int s = sz;
    if (first < last) {
        int mid = (first+last)/2;

        mergeSortAsc(a, first, mid, s);
        mergeSortAsc(a, mid+1, last, s);

        mergeAsc(a, first, mid, last, s);
    }
}

void mergeAsc(string a[], int first, int mid, int last, int sz)
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

void mergeSortDesc(string a[], int first, int last, int sz)
{
    int s = sz;
    if (first < last) {
        int mid = (first+last)/2;

        mergeSortDesc(a, first, mid, s);
        mergeSortDesc(a, mid+1, last, s);

        mergeDesc(a, first, mid, last, s);
    }
}

void mergeDesc(string a[], int first, int mid, int last, int sz)
{
    int s = sz;
    string temparr[s];

    int first1 = first;
    int last1 = mid;
    int first2 = mid+1;
    int last2 = last;

    int index;

    for (index=first; (first1<=last1) && (first2<=last2); ++index) {
        if (a[first1] > a[first2]) {
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

int main()
{
    sortIDAsc();
    sortIDDesc();
    sortFnameAsc();
    sortFnameDesc();
    return 0;
}
