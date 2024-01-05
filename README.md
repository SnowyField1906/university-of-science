# Fundamentals

## First Year

### First Term

#### English 1

#### Physical Education 1

#### Introduction to Information Technology

#### Introduction to Programming

#### Calculus 1B

#### Discrete Mathematics

### Second Term

#### Physical Education 2

#### Introduction to Law

#### Introduction to Psychology

#### Introduction to Biology 2

#### Programming Techniques

#### Human And Environment

#### Calculus 2B

#### Linear Algebra

#### Introduction to Physics 1 (Mechanics + Thermodynamics)

## Second Year

### First Term

#### Data Structures and Algorithms

#### Computer Network

#### Probability and Statistics

#### Combinatorics

### Second Term

#### Ho Chi Minh Ideology

#### Marxism-Leninism Philosophy

#### Object Oriented Programming

#### Introduction to Databases

#### Computer Architecture

#### Applied Mathematics And Statistics

## Third Year

### First Term

#### Introduction to Operating Systems

- **Introduction to OS**
  - OS: WHAT and WHY?
    - Operating System definition
    - Computer System overview
    - Role of an Operating System
  - Classification
    - Batch OS
    - Multiprogramming OS
    - Timesharing (Multitasking) OS
    - Parallel (Multiprocessing) OS
    - Distributed OS
    - Real-time OS (RTOS)
    - Embedded OS
  - Main components
    - Process (and Thread) management
    - Memory management
    - File & Disk management
    - I/O management
    - System call
    - Shell or Command Interpreter
    - Protection and security
  - OS Structure
    - Simple structure
    - Monolithic structure
    - Layered structure
    - Microkernel structure
    - Hybrid structure
    - And other ...
- **Process and Inter-process Communication**
  - Process concepts
    - Process vs. Program
  - Process features
    - Process state
    - Process address space
    - Process control block (PCB)
    - Context switch
  - Process operations
    - Process creation
    - Process termination
    - System calls for process management
  - Inter-process Communication (IPC)
    - Overview
    - Pipe
    - Shared memory
    - Socket
    - Connectionless (UDP) socket
    - Connection-oriented (TCP) socket
    - And other ...
- **CPU Scheduling**
  - Basic concepts
    - CPU – I/O burst cycle
    - Scheduling procedure
    - Scheduling criteria
    - When to schedule
    - Scheduling types
  - Scheduling algorithms
    - First-Come, First-Served (FCFS) scheduling
    - Round-Robin (RR) scheduling
    - Shortest-Job-First (SJF) scheduling
    - Shortest-Remaining-Time-Next (SRTN) scheduling
    - Priority scheduling
    - Multilevel Priority Queue (MLPQ) scheduling
    - Multilevel Queue (MLQ) scheduling
    - And other ...
- **Thread**
  - Thread concepts
    - What is a Thread?
    - Purpose
    - Benefits
  - Thread models
    - Thread-level implementation
    - User-level implementation
    - Kernel-level implementation
    - Kernel-level and User-level Thread mapping
  - Thread management
    - User-level vs. Kernel-level management
    - Thread scheduling
    - Thread libraries
- **Synchronization**
  - Critical section problem
    - Race conditions
    - Critical section problem
  - Synchronization
    - Synchronization requirements
    - Synchronization solutions
    - Busy waiting
      - Lock variable
      - Strict alternation
      - Peterson’s solution
      - Interrupt disabling
      - Test-and-Set (TSL)
    - Sleep and wakeup
      - Semaphore
      - Monitor
      - And other ...
  - Classic synchronization problems
    - Producer-Consumer problem
    - Producer-Consumer solution
    - Readers-Writers problem
    - Readers-Writers solution
    - Dining-Philosophers problem
    - Dining-Philosophers solution
- **Deadlock**
  - Introduction to Deadlock
    - Recall: Dining-Philosophers problem
    - Resource allocation graph
    - Deadlock definition
    - Conditions for deadlock
  - Deadlock handling
    - Deadlock ignorance
    - Deadlock prevention
    - Deadlock avoidance
    - Deadlock detection and recovery
- **Main Memory**
  - Fundamentals
    - Address space
    - Address binding (Relocation)
    - Memory management unit (MMU)
    - Memory management
  - Contiguous memory allocation
    - Characteristics
    - Fixed-partitions
    - Variable-partitions
    - Memory allocation strategies
    - Address protection
    - Address binding
  - Swapping
    - Principles
    - Memory management with bitmap
    - Memory management with linked list
    - Swap time
  - Issue: Fragmentation
    - External fragmentation
    - Internal fragmentation
- **Virtual Memory**
  - Fundamentals
    - Basic definitions
    - Virtual memory
    - Non-contiguous memory allocation
  - Segmentation
    - Principles
    - Address binding and protection
  - Paging
    - Principles
      - Memory management with paging
      - Logical and physical address
      - Address representation
      - Logical and physical address with paging
      - Address binding and protection
      - Demand paging
      - How to know if a page is presented or absent?
      - Page fault handling
      - Effective memory-access time (EAT or EMAT)
      - Translation lookaside buffer (TLBs)
      - EAT (or EMAT) with TLBs support
      - What if no free frame?
      - Page replacement
    - Page replacement algorithm
      - FIFO algorithm
      - Optimal algorithm
      - Least recently used (LRU) algorithm
      - Second chance algorithm
      - And other ...
      - Issue: Thrashing
    - Paging with large address space
      - Issue
      - Hierarchical (or Multilevel) paging
      - Hashed page table
      - Inverted page table
- **File System**
  - File system interface
    - File concept
    - File operations
    - Access methods
    - File structure
    - Directory concept
    - Directory operations
    - Directory organization
    - Protection
  - File system implementation
    - Overview
      - File system
      - Secondary storage: Disk drive
      - Windows file system: FAT/exFAT
      - Windows file system: NTFS
      - UNIX-based file system: ext2/ext3/ext4
    - File and directory implementation
      - Fundamentals
      - Contiguous allocation
      - Linked list allocation
      - Indexed allocation
      - Windows: File-allocation table (FAT)
      - UNIX-based: Indexed allocation (I-nodes)
      - Free-space management
      - Directory implementation
    - File system structure
      - Disk layout
      - Master boot record
      - FAT structure
      - NTFS structure
      - UNIX I-node structure
  - Disk storage
    - Disk management
      - Disk structure
      - Disk formatting
      - Disk accessing
      - CHS - LBA mapping
    - Disk scheduling algorithms
      - Disk access time
      - Disk scheduling
      - FCFS (First-Come First-Served)
      - SSTF (Shortest Seek Time First)
      - SCAN
      - C-SCAN (Circular SCAN)
      - LOOK
      - C-LOOK (Circular LOOK)

#### Fundamentals of Artificial Intelligence

- **Introduction to Artificial Intelligence**
  - What is Artificial Intelligence (AI)?
    - AI innovations
    - Large language models
    - Intelligent vs. Artificial Intelligence
    - The field of Artificial Intelligence
    - What is Artificial Intelligence?
    - Systems that act like humans
    - A better Turing test
    - Major roles and goals of AI
  - The foundations of AI
    - Research fields related to AI
    - AI and related concepts
    - Pros and cons of AI
  - A brief history of AI
  - AI applications in various fields
    - Autonomous planning and scheduling
    - Medicine
    - Games and entertainment
  - What are we going to learn?
    - Main topics in AI
    - Solving problems by searching
    - Knowledge and reasoning
    - Machine learning
- **Intelligent Agents**
  - Agents and environments
  - The concept of rationality
    - Rationality
    - Omniscience, learning, and autonomy
  - The nature of environments
    - Specifying the task environment
    - Properties of task environments
  - The structure of agents
    - Agent programs
    - Simple reflex agents
    - Model-based reflex agents
    - Goal-based agents
    - Utility-based agents
    - Learning agents
- **Solving Problems by Searching (Part 1)**
  - Problem-solving agents
    - Well-defined problems and solutions
    - Formulating problems
  - Example problems
    - Toy problems
    - Real-world problems
  - Searching for solutions
    - Infrastructures for search algorithms
    - Measuring problem-solving performance
- **Solving Problems by Searching (Part 2)**
  - Uninformed search strategies
  - Breadth-first search
  - Uniform-cost search
  - Depth-first search
  - Depth-limit search
  - Iterative deepening search
  - Bidirectional search
- **Solving Problems by Searching (Part 3)**
  - Informed (Heuristic) search strategies
  - Best-first search
  - Greedy best-first search
  - A* search
  - Memory-bounded heuristic search
  - Heuristic functions
- **Local Search Algorithms and Optimization Problems**
  - Optimization problems
  - Hill-climbing search
  - Simulated annealing
  - Local beam search
  - Genetic algorithm
- **Adversarial Search**
  - The concept of games in AI
  - Optimal decisions in games
    - Minimax algorithm
    - Optimal decisions in multiplayer games
  - α-β Pruning
  - Imperfect, real-time decisions
    - Evaluation functions
    - Cutting off search
    - Forward pruning
    - Search vs. Lookup
  - Stochastic games
- **Constraint Satisfaction Problems**
  - Constraint satisfaction problems (CSPs)
    - Defining the Constraint satisfaction problems
    - Example problem: Map coloring and Job-shop scheduling
    - Variations on the CSP formalism
  - Constraint propagation: Inference in CSPs
    - Node consistency
    - Arc consistency
    - Path consistency
    - K-consistency
    - Global constraints
  - Backtracking search for CSPs
    - Backtracking search
    - Variable and value ordering
    - Interleaving search and inference: Forward checking
  - Local search for CSPs
  - The structure of problems
- **Logical Agents**
  - Knowledge-based agents
  - The Wumpus world
  - Propositional logic: A very simple logic
  - Propositional theorem proving
    - Proof by resolution
    - Forward and backward chaining
  - Effective propositional model checking
- **First-Order Logic**
  - Representation revisited
  - Syntax and semantics of first-order logic (FOL)
  - Writing FOL sentences: Case studies
  - Propositional vs. First-order inference
  - Unification and lifting
  - Forward chaining
  - Backward chaining
  - Resolution
- **Machine Learning Basic Algorithms**
  - Introduction to Machine learning
  - ID3 Decision tree
  - Naïve Bayesian classification
- **Introduction to Neural Networks**
  - Introduction to Artificial neural networks
  - Perceptron and Learning
  - Multi-layer neural networks

#### Introduction to Complexity Analysis

- **Introduction to Complexity Analysis**
  - Summary
  - Experimental exploration of algorithm complexity
  - Complexity analysis using mathematical methods
  - Reference materials
  - Introduction to algorithms, complexity evaluation, and Big-O
- **Computational Techniques**
  - Algebraic transformation techniques
  - Analytical tools
  - Practice simplification and sum estimation
- **?**
- **Overview of Theoretical Approach**
  - Experimental evaluation recap
  - Theory and illustrative examples
  - Practice exercises for skill enhancement
- **Counting Techniques (Part 1)**
  - Recap of assignment and comparison in counting techniques
  - Solving sample problems
  - Approaching recursive algorithms
- **Counting Techniques (Part 2)**
  - Master Theorem and applied examples
  - Advanced examples
- **Tools for Average Time Complexity Assessment**
  - Probability Generating and Distribution Functions
  - Probability Generating Functions and properties
  - Applications
- **Cycles and Inversions**
  - Cycles and Inversion in Permutations
  - Properties
  - Relation to sorting algorithms
- **?**
- **P-NP Problem**
  - Introduction to P-NP

#### Introduction to Cryptography and Cryptanalysis

- **Concepts in Cryptography (Part 1)**
  - Basic concepts, terminologies, and symbols
  - Cipher systems
    - Types of Cipher systems
      - Symmetric ciphers
      - Asymmetric ciphers
      - Cryptographic Hash Functions
    - Properties of Cipher systems
    - Encryption methods
- **Concepts in Cryptography (Part 2)**
  - Cipher system attacks
    - Cryptanalysis
    - Information theft
- **Public Key Encryption (Part 1)**
  - Public key cryptography
    - Design principles
    - Methods for designing Public Key systems
  - RSA Public Key system (Rivest - Shamir - Adleman)
    - RSA theorem
    - RSA protocol
    - Proof of RSA theorem
    - Fast RSA decryption
- **Public Key Encryption (Part 2)**
  - Diffie-Hellman Public Key system
    - Key establishment protocol
    - Mathematical foundations of Diffie-Hellman protocol
    - Diffie-Hellman protocol implementation
    - Analysis of Diffie-Hellman system
- **Secret Key Encryption (Part 1)**
  - Secret Key Cryptography
    - Design principles
    - Design methods
  - Some Secret Key systems
    - Linear codes
    - Matrix codes
    - Permutation codes
  - Modern Cryptography
    - Substitution-Permutation codes
    - Modern codes (AES)
- **Secret Key Encryption (Part 2)**
  - Operation Method of Secret Key Encryption
    - Block cipher
    - Stream cipher
    - Other methods
  - High-Speed cipher system
- **Applied Cryptography**
  - Cryptographic Hash Functions and applications
  - Random numbers
  - Digital signatures
  - Database security
  - Multi-party systems
  - Information security

## Projects

### First Year

- [GameHub](/Introduction%20to%20Information%20Technology/Project-%20GameHub//): A static website that contains a collection of games.
- [Bitmap Image Processor](/Programming%20Techniques/Project%20-%20Bitmap%20Image%20Processor/): A program that can manipulate (convert, resize) bitmap images.

### Second Year

- [Web Socket](/Computer%20Network/Project%20-%20Web%20Socket/): A web socket server that can download any files or folders with multiple requests/connections from a URL.
- [Sorting Algorithms Comparison](/Data%20Structures%20and%20Algorithms/Project%20-%20Sorting%20Algorithms%20Comparison/): The comprehensive comparison of the complexity on different sorting algorithms.
- [Maximum Likelihood Estimation](/Applied%20Mathematics%20And%20Statistics/Project%20-%20MLE/): Maximum Likelihood Estimation of the parameters of a distribution (research).

### Third Year

- [RSA Cryptography](/Introduction%20to%20Cryptography%20and%20Cryptanalysis/Project%20-%20RSA/): RSA Cryptography implementation.


