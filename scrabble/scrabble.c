#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// prototype
int compute_score(string word);

int main(void)
{
    string word1 = get_string("Player1:");
    string word2 = get_string("Player2:");

    // Compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]))
        {
            int index1 = char(word[i]) - 'A';
            score += POINTS[index1];
        }
        else if (islower(word[i]))
        {
            int index2 = char(word[i]) - 'a';
            score += POINTS[index2];
        }
    }
    return score;
}

