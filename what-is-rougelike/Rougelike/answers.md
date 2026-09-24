\# Answers



\## Work Booklet



\### Week beginning 21/09/2026



Section 1



1. Inventory.h | H, F, B, C



2. Inventory.cpp | D



3. main.cpp | E, A, G


2. 

I - That would go wrong because it would give 2 definitions of the same function. You should use include guards to prevent this from happening.

K - Including a CCP file in a header file is not a good practice because it can lead to multiple definitions of the same function or variable, which can cause compilation errors. Instead, you should include only the necessary declarations in the header file and implement the functions in the corresponding CPP file.

J - #pragma once call is a Microsoft specific extension and is not portable. It is better to use standard C++ features for portability.

L - It's already declared in the header file, so you don't need to declare it again in the CPP file. You can just define it in the CPP file.



Section 2



1. It's a compiler error because the error code begins with the letter C. I would go to the "Inventory.ccp" file and check for the line that includes the "Inventory.h" file and make sure that the spelling is correct. If it is incorrect, I would correct it to "Inventory.h" and recompile the program.
2. It's a compiler error because the error code begins with the letter C. The cause of this is most likely that slots is not defined in the Inventory class. I would go to the "Inventory.h" file and check for the definition of slots. If it is not defined, I would add the definition of slots in the Inventory class and recompile the program.
3. It's a linker error because the error code begins with "LNK". The cause is that "SlotsUsed" is declared bet never defined anywhere. I would go to the "Inventory.cpp" file and check for the definition of "SlotsUsed". If it is not defined, I would add the definition of "SlotsUsed" in the "Inventory.cpp" file and recompile the program.
4. It's a compiler error because the error code begins with the letter C. The cause is a missing include guard in the header defining dtrct Items. I would go to the "Inventory.h" file and add an include guard at the top of the file to prevent multiple definitions of the same function or variable.
5. It's a linker error because the error code begins with "LNK". The cause is because the function body is in the header with no inline specifier. I would go to the "Inventory.h" file and add the inline specifier to the function definition to prevent multiple definitions of the same function or variable.

This is the error code I get when I try to build the cpp file, with the incorrect spelling calling the Inventory.h

```
1>------ Build started: Project: Rougelike, Configuration: Debug|Win32 ------
1>  Inventory.cpp
1>F:\Downloads\dvkPjH\First-Repository\what-is-rougelike\Rougelike\Inventory.cpp(1,10): error C1083: Cannot open include file: 'Inventorsdy.h': No such file or directory
========== Build: 0 succeeded, 1 failed, 0 up-to-date, 0 skipped ==========
Build failed.
```

Section 3

The changes should be in the actual files themselves.

Section 4

1.

```
// <iostream> would go here

// from "Item.h"
struct Item
{
    int weight;
};

// from "Inventory.h", which first pastes "Item.h" again
struct Item
{
    int weight;
};

int TotalWeight(int itemCount);

int main()
{
    Item sword;
    sword.weight = 5;
    std::cout << sword.weight << "\n";
    return 0;
}
```

2. C2011: 'Item': 'struct' type redefinition. It would be a compiler error as the problem is inside "main.cpp", with struct Item defined twice. That happens because main.cpp includes Item.h directly, and then Inventory.h includes it again. Neither header has a guard, so both copies get pasted in.

3. Changed 'Item.h' by adding a single guard. 

4. Yes, you should add a guard to Inventory.h anyway. Inventory.h is included just once, and it only contains a function declaration, which is allowed to be repeated. But if a struct is added to it, or another header starts including it, it'll break with the same redefinition error.

Section 5

1.

The first time, from main.cpp's own #include "Colours.h":

#ifndef COLOURS_H: COLOURS_H hasn't been defined yet, so it carries on.
#define COLOURS_H: now COLOURS_H is defined.
struct Colour { ... }; is pasted into main.cpp.
#endif: that's the end of the file.

The second time, through Palette.h's #include "Colours.h":

#ifndef COLOURS_H: COLOURS_H is defined now, from step 2 above, so it skips everything down to #endif.
Nothing gets pasted. The file was opened and read, but it produced no code.

2. Once. Stopping the second copy is the whole point of the guard.

3. Nothing important changes, and it still compiles.

4. 

Predicted error: C2011: 'Colour': 'struct' type redefinition. With no guard, both routes paste the struct, so it's defined twice in main.cpp. Palette.h still has its own guard, but that doesn't help, since it only stops Palette.h itself being pasted twice. It doesn't protect the files it includes.

Section 6

1. int MaxSlots(int level); goes in the header. It's a declaration, and other files need to see it so they can call the function.
2. The body of MaxSlots goes in the source file. A function body must exist exactly once, and anything in a header gets pasted into every file that includes it.
3. struct Item { int weight; }; goes in the header. Every file that uses Item needs to know what's inside it, which is also why headers need guards.
4. #include <iostream>, needed only by one function's body, goes in the source file. Include it where it's used; in a header, it would be forced on every file that includes that
5. #include "Item.h", where the header mentions Item, goes in the header. A header should work on its own, so whoever includes it doesn't have to know to include Item.h first.
6. #ifndef INVENTORY_H goes in the header. Guards stop a file being pasted twice, and .cpp files are never included, so they have nothing to guard against.
7. A helper function nobody else calls goes in the source file. If no other file needs it, it shouldn't be advertised in the header.
8. int main() goes in the source file. A program has exactly one main, and in a header it would be copied into every file that includes it.

The two people get wrong: 2 and 4. Both put something in a header that should have stayed in a .cpp.

1. A function body in the header is in every .cpp that includes it. The linker finds finds duplicates and gives a LNK2005: already defined. 

2. 4 breaks quietly. No errors, every file that includes the header gets <iostream> even if they don't need it. The more files that calls for <iostream> but doesn't need it, the slower each buld is going to get.