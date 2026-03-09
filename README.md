# Medical Store Management System

A console-based medicine inventory manager written in C, built as a Data Structure & Algorithm lab project.

## Build & Run

**Requirements:** GCC, Dev C++ (Windows recommended — uses `conio.h`)

```bash
gcc "Medical Store Management System.cpp" -o medical_store
./medical_store
```

> On Linux/WSL, remove `#include<conio.h>` and replace `fflush(stdin)` with `__fpurge(stdin)` if needed.

## Menu Options

| # | Operation |
|---|-----------|
| 1 | Purchase a medicine |
| 2 | Add review/info for a medicine |
| 3 | View all stock |
| 4 | View medicine info |
| 5 | Add a new medicine |
| 6 | Delete a medicine |
| 7 | Update medicine details |
| 8 | Exit |

## Notes

- Supports up to **100 medicines** in memory
- Data is **not saved** on exit — no file or database persistence
- Pre-loaded with one medicine (Paracetamol) on startup
