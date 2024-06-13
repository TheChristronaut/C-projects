#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// create points
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_score(string word);

int main(void)
{
    // prompt player 1 for a word
    string word_1 = get_string("Player one type a word: ");
    // prompt player 2 for a word
    string word_2 = get_string("Player two type a word: ");

    // calculate score of each word
    int player_1_score = calculate_score(word_1);
    int player_2_score = calculate_score(word_2);

    // determine winner
    // display the winner
    if (player_1_score > player_2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_2_score > player_1_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie\n");
    }
}

int calculate_score(string word)
{
    // score counter
    int score = 0;

    // compute word score
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }
    }
    return score;
}
