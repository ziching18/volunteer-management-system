#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
#include "view.h"   // for display
using namespace std;

// function declarations
void mergeSort(string[], int, int, int);
void mergeThem(string[], int, int, int, int);
void sortVolID(bool);
void sortVolFname(bool);
void sortVolAge(bool);

// sort volunteer list by id - default display order
void sortVolID(bool asc)
{
    fstream vfile, vidfile;
    string line, id, fname;
    bool ascending = asc;

    vector<string>ids;

    vidfile.open("v_id.txt", ios::in);
    volHeader();
    if (!vidfile.is_open())
    {
        cout << "File not opened!" << endl;
    }
    else
    {
        while (getline(vidfile, id))
        {
            ids.push_back(id);      // get all volunteer ids and push into vector
        }
    }

    int s = ids.size();
    string arr[s];
    for (int i=0; i<s; i++)
    {
        arr[i] = ids[i];            // convert vector into array for merge sort
    }

    mergeSort(arr, 0, s-1, s);      // call merge sort

    if (ascending == true)
    {
        for (int i=0; i<s; i++) {
            viewVol(arr[i], false); // display volunteer list in current order (ascending)
        }
    }
    else
    {
        stack<string>stk;
        for (int i=0; i<s; i++)     // use stack to display volunteer list in opposite order (descending)
        {
            stk.push(arr[i]);
        }
        while(!stk.empty())
        {
            viewVol(stk.top(), false);  // display
            stk.pop();                  // remove from stack
        }
    }
    cout << setfill('_') << setw(152) << "_" << endl;
}

// sort volunteer list by first name
void sortVolFname(bool asc)
{
    fstream vfile, vidfile, vofile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;
    bool ascending = asc;

    volHeader();
    vidfile.open("v_id.txt", ios::in);

    vector<string>ids;
    vector<string>ids2;
    vector<string>fnames;

    // get volunteer name by id
    if (!vidfile.is_open())
    {
        cout << "File not opened!" << endl;
    }
    else
    {
        while (getline(vidfile, id))
        {
            ids.push_back(id);
        }
        for (int i=0; i<ids.size(); i++)
        {
            // open volunteer file
            vfile.open("volunteer/" + ids[i] + ".txt", ios::in);

            if (!vfile.is_open())
            {
                cout << "File not opened!" << endl;
            }
            else
            {
                vector<string>v;
                string v_ID="", v_fname="";
                getline(vfile, line);
                stringstream ss(line);

                while (ss.good())
                {
                    string sub="";
                    getline(ss, sub, ';');  // input stream converted into substrings with ; as delimiter
                    v.push_back(sub);       // substrings pushed into vector
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

    sort(fnames.begin(), fnames.end());     // sort first name using std::sort

    // get volunteer id from first name
    vidfile.open("v_id.txt", ios::in);
    for (int i=0; i<fnames.size(); i++)
    {
        for (int j=0; j<ids.size(); j++)
        {
            vector<string> v2;
            vfile.open("volunteer/" + ids[j] + ".txt", ios::in);

            string v_ID="", v_fname="";

            getline(vfile, line);
            stringstream ss(line);

            while (ss.good())
            {
                string sub;
                getline(ss, sub, ';');  // input stream converted into substrings with ; as delimiter
                v2.push_back(sub);      // substrings pushed into vector
            }

            // assign substring to string variables
            v_ID = v2[0];
            v_fname = v2[1];
            if (fnames[i] == v_fname)
            {
                ids2.push_back(v_ID);   // get id that the first name belongs to
            }
            vfile.close();
        }
    }
    vidfile.close();

    if (ascending == true)
    {
        for (int i=0; i<ids2.size(); i++)
        {
            viewVol(ids2[i], false);    // display volunteer list in current order (ascending)
        }
    }
    else
    {
        stack<string> stk;              // use stack to display volunteer list in opposite order (descending)
        for (int i=0; i<ids2.size(); i++)
        {
            stk.push(ids2[i]);
        }

        while(!stk.empty())
        {
            viewVol(stk.top(), false);  // display
            stk.pop();                  // remove from stack
        }
    }
    cout << setfill('_') << setw(152) << "_" << endl;
}

// sort volunteer list by age
void sortVolAge(bool asc)
{
    fstream vfile, vidfile, vofile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;
    bool ascending = asc;

    volHeader();

    vidfile.open("v_id.txt", ios::in);

    vector<string>ids;
    vector<string>ids2;
    vector<string>ages;

    // get volunteer age from id
    if (!vidfile.is_open())
    {
        cout << "File not opened!" << endl;
    }
    else
    {
        while (getline(vidfile, id))
        {
            ids.push_back(id);
        }
        for (int i=0; i<ids.size(); i++)
        {
            // open volunteer file
            vfile.open("volunteer/" + ids[i] + ".txt", ios::in);

            if (!vfile.is_open())
            {
                cout << "File not opened!" << endl;
            }
            else
            {
                vector<string>v;
                string v_ID="", v_age="";
                getline(vfile, line);
                stringstream ss(line);

                while (ss.good())
                {
                    string sub="";
                    getline(ss, sub, ';');  // input stream converted into substrings with ; as delimiter
                    v.push_back(sub);       // substrings pushed into vector
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

    int s = ages.size();
    string arr[s];
    for (int i=0; i<s; i++)
    {
        arr[i] = ages[i];            // convert vector into array for merge sort
        //cout << "ages[i]: " << ages[i] << endl;
    }

    mergeSort(arr, 0, s-1, s);      // call merge sort
    //sort(ages.begin(), ages.end());

    vidfile.open("v_id.txt", ios::in);

    // get volunteer id from age
    for (int i=0; i<s; i++)
    {
        for (int j=0; j<ids.size(); j++)
        {
            vector<string> v2;
            vfile.open("volunteer/" + ids[j] + ".txt", ios::in);

            string v_ID="", v_age="";

            getline(vfile, line);
            stringstream ss(line);

            while (ss.good())
            {
                string sub;
                getline(ss, sub, ';');  // input stream converted into substrings with ; as delimiter
                v2.push_back(sub);      // substrings pushed into vector
            }

            bool same = false;
            // assign substring to string variables
            v_ID = v2[0];
            v_age = v2[3];
            if (arr[i] == v_age)
            {
                for(int k=0; k<ids2.size(); k++)
                {
                    if(v_ID == ids2[k])
                    {
                        same = true;
                    }
                }
                if(same == false) {
                    //cout << "\npushing " << v_ID << " " << v_age << " ";
                    ids2.push_back(v_ID);
                }
            }
            vfile.close();
        }
    }
    vidfile.close();

    if (ascending == true)
    {
        for (int i=0; i<ids2.size(); i++)
        {
            //cout << "\nsorted: " << ids2[i];
            viewVol(ids2[i], false);        // display volunteer list in current order (ascending)
        }
    }
    else {
        stack<string> stk;
        for (int i=0; i<ids2.size(); i++)   // use stack to display volunteer list in opposite order (descending)
        {
            stk.push(ids2[i]);
        }

        while(!stk.empty())
        {
            viewVol(stk.top(), false);      // display
            stk.pop();                      // remove from stack
        }
    }
    cout << setfill('_') << setw(152) << "_" << endl;
}

// merge sort algorithm
void mergeSort(string a[], int first, int last, int sz)
{
    int s = sz;
    if (first < last)
    {
        int mid = (first+last)/2;

        // recursive calls to mergeSort(), divide arrays
        mergeSort(a, first, mid, s);
        mergeSort(a, mid+1, last, s);

        // merge sorted arrays
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

    for (index=first; (first1<=last1) && (first2<=last2); ++index)
    {
        if (a[first1] < a[first2])
        {
            temparr[index] = a[first1];
            ++first1;
        }
        else
        {
            temparr[index] = a[first2];
            ++first2;
        }
    }

    while (first1 <= last1)
    {
        temparr[index] = a[first1];
        ++first1;
        ++index;
    }

    while (first2 <= last2)
    {
        temparr[index] = a[first2];
        ++first2;
        ++index;
    }

    for (index=first; index<=last; ++index)
    {
        a[index] = temparr[index];
    }
} // end merge sort


