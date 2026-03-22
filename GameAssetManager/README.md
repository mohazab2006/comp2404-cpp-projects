# COMP2404 – Assignment 2

**Student Name:** Mohamed Azab  
**Student Number:** 101331588  

---

## Overview

This program implements an Asset and Project Management system.

It allows users to:

- Manage game development assets  
- Create and manage projects  
- Add assets to projects  
- Clone projects using deep copies  
- Delete assets and projects safely  
- View project and asset details  

The program follows the provided UML, specifications, and grading constraints.

---

## Design Decisions

### Memory Ownership

- AssetStore owns all `Asset*` pointers.
- Project owns deep-copied `Asset*` pointers.
- ProjectManager owns all `Project*` pointers.
- AssetArray and ProjectArray are non-owning containers.

All dynamically allocated memory is deleted exactly once.

Valgrind confirms that there are no memory leaks.

---

### Deep Copy

When assets are added to projects or projects are cloned, deep copies are created using copy constructors.

This ensures that deleting assets or projects does not affect other objects.

---

### Const Correctness

All getter and print functions that do not modify data are marked as `const`.

This ensures safe access and clean compilation.

---

## Compilation

To compile the program:

```bash
make clean
make
This creates:
    a2 (main program)
    a2test (test program)
Run it with:
    ./a2
    ./a2test
```     
Check for memory leaks with Valgrind:

```bash
valgrind --leak-check=full ./a2
valgrind --leak-check=full ./a2test

Test Results:
    All automated tests passed (18/18)
    No memory leaks
    No crashes or errors

Files Included
    Asset.h / Asset.cc
    AssetStore.h / AssetStore.cc
    Project.h / Project.cc
    ProjectArray.h / ProjectArray.cc
    ProjectManager.h / ProjectManager.cc
    AssetArray.h / AssetArray.cc
    Control.h / Control.cc
    View.h / View.cc
    Tester.h / Tester.cc
    TestControl.h / TestControl.cc
    main.cc
    testmain.cc
    Makefile
    README.md
