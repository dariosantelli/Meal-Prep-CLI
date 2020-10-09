# MealPrepCLI

This is a lightweight console application meant to quickly and easily keep track of meal prep recipes.

# Storage:
A text file called 'mealprepdata.txt' is used to store the data of the recipes in a custom format.

This format consists of a string in the form "recipe_name|{ingredient1;ingredient2;ingredient3}|{direction1;direction2;direction3}|{keyword1;keyword2}"

Each newline containing a string in that format within the text file represents another recipe that is accessible by the client

# Use:
The user is not meant to edit the text file, rather, the client provides provision to manage the recipes.

These functions are accessed by using the keypad number associated with them:
    - 1: View recipes by recipe name
    - 2: View the full details of a single recipe
    - 3: Add a new recipe
    - 4: Edit an existing recipe
    - 8: Access the tutorial/help prompt
    - 9: Exit the program

