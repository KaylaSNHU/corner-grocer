# Corner Grocer – Item-Tracking Program

## Project summary
A C++ console application that reads a day’s purchase log, counts how many times each grocery item was sold, and presents that information through a menu (lookup, full count list, histogram, and automatic backup file).

## Reflection

| Prompt | My response |
|--------|-------------|
| **What problem was it solving?** | Helped store managers identify high frequency produce items for better shelf placement. |
| **What did you do particularly well?** | Encapsulated logic in a single `ItemTracker` class with clear public API; added case-insensitive lookups and automatic backup for data safety. |
| **Where could you enhance your code?** | Options: speed up file load with `std::unordered_map::reserve`, accept CSV input, add colorized histogram output. These tweaks would improve efficiency and UX. |
| **Most challenging piece and how you overcame it?** | Making lookups case-insensitive without duplicating data. Solution: convert every word to lower-case on both insert and query using `std::transform`. |
| **Transferable skills?** | Working with file I/O, hash maps, input validation, and tidy header / source separation, all common in real-world C++ projects. |
| **How did you keep it maintainable?** | Used header guards, self documenting names, inline comments, a `.gitignore`, and split UI (`main.cpp`) from business logic (`ItemTracker`). |

