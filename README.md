# Welcome to CPP_babel_2019 👋

> In the Advanced C++ track, you will delve deeper into the architecture of a C++ program. You will have to make projects that build and run the same on Unix (which you should be accustomed to now) and Windows systems.
The projects are based on industry usages of C++.

Therefore, we are going to introduce this very profound philosophic difference between Unix and Windows in a way that serves our purposes: creating software abstractions that allow natively portable programs to be developed on all of the systems. 

This abstraction focuses on a key concept that governs the entirety of our course's themes: Application Programming Interfaces (API),  which are elements that are inseparable from Object-Oriented Programming, all languages combined. 

In this unit in particular, you will have to make a VOIP client/server program (just like Skype).

## Install

First of all, you'll need to add the remote of three conan's repository.

For the conan-center repository :
```sh
conan remote add <REMOTE> https://api.bintray.com/conan/conan/conan-center 
```

For the epitech repository :
```sh
conan remote add <REMOTE> https://api.bintray.com/conan/epitech/public-conan 
```

For the bintray repository :

```sh
conan remote add <REMOTE> https://api.bintray.com/conan/bincrafters/public-conan 
```

To build the project :

```sh
mkdir build && cd build && conan install .. && cmake .. -G & "Unix Makefiles" && cmake --build .
```
##### All executables will be in the './build/bin' directory at the root of the project.

## To use the babel :

1. Execute ./bin/babel_server
2. In a new terminal, execute ./bin/babel_client

3. Enjoy your call !


Guide of the babel's shell :

- for login with a pseudo -> login {YourPseudo}

- to accept a friend request -> accept {FriendPseudo}
- to refuse a friend request -> refuse {FriendPseudo}
- to add a friend -> add {FriendPseudo}
- to call a friend -> call {FriendPseudo}

- to quit a call -> closecall (or Ctrl + C)
- to accept a call -> acceptcall

##### ! If you write a wrong command you'll see "Invalid comman. Please check syntax." !




***
