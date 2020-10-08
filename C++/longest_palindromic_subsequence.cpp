#include<bits/stdc++.h>
using namespace std;

/* Returns LCS X and Y */
string lcs(string &X, string &Y)
{
    int m = X.length();
    int n = Y.length();

    int L[m+1][n+1];

    /* Following steps build L[m+1][n+1] in bottom
       up fashion. Note that L[i][j] contains
       length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    // Following code is used to print LCS
    int index = L[m][n];

    // Create a string length index+1 and
    // fill it with \0
    string lcs(index+1, '\0');

    // Start from the right-most-bottom-most
    // corner and one by one store characters
    // in lcs[]
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y
        // are same, then current character
        // is part of LCS
        if (X[i-1] == Y[j-1])
        {
            // Put current character in result
            lcs[index-1] = X[i-1];
            i--;
            j--;

            // reduce values of i, j and index
            index--;
        }

        // If not same, then find the larger of
        // two and go in the direction of larger
        // value
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    return lcs;
}

// Returns longest palindromic subsequence
// of str
string longestPalSubseq(string &str)
{
    // Find reverse of str
    string rev = str;
    reverse(rev.begin(), rev.end());

    // Return LCS of str and its reverse
    return lcs(str, rev);
}

/* Driver program to test above function */
int main()
{
    string str;
    cin>>str;
    cout << longestPalSubseq(str);
    return 0;
}
