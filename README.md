# UVA Answers in Visual Studio (Discontinued)

## Features

- Answers to UVA, still ongoing
- If the title is (WA), it means I believe the algorithm is correct but missing either the test cases or presentation error, so do not use for submission
- Provided test cases and test code
- Easy testing answers and finding difference, some details are hard to notice especially spaces, thus the test cases will save your points

---

## How to use

### Visual Studio Way

- Used Visual Studio 2015, but 2013 can do (but just update your Visual Studio)
- Open the project
- Each proect is linked to test cases
- **Important: Exclude all files from running, and choose only one file because all files have main function**

### Non-Visual Studio Way

- Well, use any IDE or editor you like, just grab the files from UVA folder

---

## On Submission

- Pick any files, and remove these 4 lines:

        #include "C.h" // at the top of file, to remove
        
        Test *t = new Test("Test filename"); // just after main(), to remove
        
        t -> begin(); // just after main(), to remove
        
        delete t; // at the end of file before return 0, to remove
        
---
