#include <cs50.h>
#include <stdio.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}

// prototype
int compute_score(string word);

int main(void)
{
    string word1 = get_char("Player1:");
    string word2 = get_char("Player2:");

    // Compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


}

int compute_score(string word)
{
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        sum += 
    }
}

string scrabble(string a, string b)
{
    while (a[i] != "/0")
    {
        sum1 +=
    }
}
