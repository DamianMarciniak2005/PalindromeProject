#include <stdio.h>
#include <string.h>

static void palindromeFunction(char word[]);

int main()
{
    char input[100];
	// Declare a character array of size 100 to store the input word

    printf("Please enter a single word to identify (100 letters max): ");

    
    fgets(input, sizeof(input), stdin);
	// Use fgets to read input from the user. It is safer than scanf as it avoids buffer overflow

       
    
    input[strcspn(input, "\n")] = '\0';
	// Remove the newline character that fgets captures when the user presses Enter

    printf("You entered the word: %s\n", input);
	// Print the word entered by the user and use %s format specifier to print a string


    palindromeFunction(input);
	// Call the palindrome function to check if the entered word is a palindrome


    return 0;
}

static void palindromeFunction(char word[])
{
	int length = strlen(word);
	// Get the length of the input word

	int low = 0;
	// Pointer to the beginning of the word

	int high = length - 1;
	// Pointer to the end of the word


	// Loop through the word to compare characters from both ends
	while (low <= high)
	{
		// If characters at both ends match and the word has an odd length
		if ((word[low] == word[high]) && (length % 2 != 0))
		{
			low++;
			// Move the pointer from the beginning towards the middle

			high--;
			// Move the pointer from the end towards the middle

			// If the low pointer equals the high pointer, it's a palindrome
			if (low == high)
			{
				// Print result
				printf("Yes, %s is a palindrome.\n", word);
			}
		}

		// If characters at both ends match and the word has an even length
		else if ((word[low] == word[high]) && (length % 2 == 0))
		{
			low++;
			// Move the pointer from the beginning towards the middle

			high--;
			// Move the pointer from the end towards the middle

			 // If low pointer reaches the halfway point, it's a palindrome
			if (low == length / 2)
			{
				// Print result
				printf("Yes, %s is a palindrome.\n", word);
			}
		}

		// If characters at both ends don't match, it's not a palindrome
		else
		{
			// Print result
			printf("No, %s is not a palindrome.\n", word);

			// Exit the loop as the word is not a palindrome
			break;
		}
	}
}