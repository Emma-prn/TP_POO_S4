# Clean Code with C++

## Legends

### Lessons

- 📗 Read
- 📕 Unread

### Assignments

- 🌑 Undone
- 🌒 Starting
- 🌓 In progress
- 🌔 First version
- 🌕 Done

## Lessons

### Level 0

- 📗 Introduction (09/02/22)

### Level 1

- 📗 Install a compiler (09/02/22)
- 📗 Use an IDE (09/02/22)
- 📗 Use Git (09/02/22)
- 📗 Use a debugger (09/02/22)
- 📗 Use a formatting tool (09/02/22)
- 📗 Use static analysers (09/02/22)
- 📗 Naming (09/02/22)
- 📗 Stack vs Heap (09/02/22)
- 📗 Consistency in style (09/02/22)

### Level 2

- 📗 Make it work, then make it good (09/02/22)	
- 📗 Prefer free functions (09/02/22)
- 📗 Design cohesive classes (09/02/22)
- 📗 Use structs to group data (16/02/22)
- 📗 Write small functions (16/02/22)
- 📗 DRY : Don't repeat yourself (23/02/22)
- 📗 Enums (23/02/22)
- 📗 Split problems in small pieces (23/02/22)
- 📗 Composition over Inheritance (02/03/22)

### Level 3

- 📗 std::vector (02/03/22)
- 📗 Documentation (02/03/22)
- 📗 Use libraries (09/03/22)
- 📗 assert (09/03/22)
- 📗 auto (16/03/22)
- 📗 Testing (16/03/22)
- 📕 Type design
- 📗 Dependencies (23/03/22)
- 📕 Lambda functions
- 📕 Master your IDE
- 📗 std::optional (06/04/22)
- 📗 Single Source of Truth (06/04/22)
- 📗 Strong Typing (20/04/22)
- 📕 Code reviews
- 📗 const (06/04/22)
- 📗 Documentation (06/04/22)
- 📗 Don't overfocus on performance
- 📗 Git submodules (23/03/22)
- 📕 STL algorithms
- 📕 Debug vs Release
- 📕 Immediately Invoked Function
- 📗 Markdown (13/04/22)
- 📗 Range-based for loop (13/04/22)
- 📗 Smart Pointers (20/04/22)
- 📗 std::function (20/04/22)
- 📕 Error Handling
- 📗 Git Pull Requests
- 📕 Advanced Git features
- 📗 CMake (23/03/22)
- 📕 Functional programming
- 📗 Move semantics (11/05/22)
- 📗 The Rule of 5 (11/05/22)
- 📕 State and Strategy
- 📕 std::variant
- 📕 Cache and Branches
- 📕 Multithreading
- 📕 Polymorphism
- 📗 Space out your code (11/05/22)

## Assignments

### 🌕 Guess the number
    
    16/02/22
    🌕 Create pick_a_random_number function
    🌕 Create get_number_from_player function
    🌕 Create play_guess_the_number function
    🌕 Split en h and cpp files

    23/02/22
    🌕 Remove pick_a_random_number and get_number_from_player from the header file. Use static in the cpp file
    🌕 Get the number of try and print it at the end of the game

    23/03/22
    🌕 Use get_imput_from_player function in the get_number_from_player

### 🌕 Random.h

    23/02/22
    🌕 Put the pick_a_random_number in its own h file and using a template

### 🌕 Hangman

    23/02/22
    🌕 Create pick_a_word_to_guess function
    🌕 Create get_character_from_player function
    🌕 Create show_number_of_lives function
    🌕 Create player_is_alive function

    02/03/22
    🌕 Create player_has_won function
    🌕 Create show_word_to_guess_with_missing_letters function
    🌕 Create remove_one_life function
    🌕 Create show_congrats_message function
    🌕 Create show_defeat_message function

    09/03/22
    🌕 Create word_contain function

    16/03/22
    🌕 Create mark_as_guessed function
    🌕 Complete play_hangman function
    🌕 Add some context to the game

    23/03/22
    🌕 Use get_imput_from_player function in the get_character_from_player

### 🌔 Adding a menu

    16/03/22
    🌕 Create show_the_list_of_commands function
    🌕 Update the main function

    23/03/22
    🌕 Use the get_input_from_player funtion
    🌕 Create show_menu function and put it in its own h file

### 🌕 PlayerInput.h

    16/03/22
    🌕 Create the template for the get_input_from_player

### 🌓 Noughts and Crosses

    06/04/22
    🌕 Add p6 lib
    🌒 Create play_nought_and_cross function (base)

    13/04/22
    🌕 Create case_index structure
    🌕 Create case_radius function
    🌕 Create case_bottom_left_corner function
    🌕 Create draw_case function
    🌕 Use draw_case in draw_board
    🌔 Create case_hovered

    20/04/22
    🌔 Create draw_nought function
    🌔 Create draw_cross function
    🌔 Create Board class
    🌔 Create draw_nought_and_cross function

    11/05/22
    🌔 Create change_player function
    🌔 Create try_to_place_symbol function

### 🌑 Connect 4

### 🌑 Adding tests

### 🌑 An AI for Hangman