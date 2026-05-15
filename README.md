# Project E: Final Project README 

## Important Instructions

- **Do not delete your previous README content.**  
- First, copy and paste your existing README text into the section titled **Prior README Content** below.  
- Then, work through this template to add the required new sections for Project E.  
- Update your README so that it reflects your FINAL project, following the rubric and prompts.

---

# Prior README Content

*Paste your previous README here (from Project A/B/C/D) before making any changes.*

# Project A: Dynamic Array, Struct, and Search System README

## Student Info

- **Name**: \[Jose Rodriguez\]  
- **Repository**:\[[https://github.com/Reedley-College-CSCI/csci-41-sp26-project-a-dynamicarray-struct-and-search-system-JoseRodriguez21](https://github.com/Reedley-College-CSCI/csci-41-sp26-project-a-dynamicarray-struct-and-search-system-JoseRodriguez21)\]

---

## Project Summary

Briefly describe the theme or purpose of your program.

The purpose of this program is to manage the inventory of a small store. The user can add, delete, search for, and display all products. This is done by sorting the array alphabetically with bubble sort. When searching for a product, the user enters the product name. The binary search algorithm is used to locate the desired item in the array. 

---

## Project Structure/File Overview

Provide a complete list of the files (including text files) and classes in your project, along with their purposes.

* Storage.txt: Text file to save information about the storage system.  
* main.cpp: Provides a menu interface that allows the user to interact with the inventory system and perform different actions on the Storage text file.  
* Class Inventory: This class manages the storage system by sorting the array and providing functions such as loading data, searching for a product, adding a product, etc.

---

## Requirements Checklist and Where They Are Met

Be specific. Vague statements such as “it works” or “it loads data” will not receive credit.

| Requirement | How It’s Met (What specifically happens?) | File/Class/Function |
| :---- | :---- | :---- |
| Dynamic Array | When adding a new product, the program adds it to the array and then uses the sorting system to sort it again. When deleting the program, it removes the product from the array and then sorts the array again. | void addProduct() void deleteProduct() void sortByName() |
| Read from File (≥ 20 entries) | Loads storage data from Storage.txt using a function before the program asks the user for anything. | Storage.txt and void loadData(const string& filename) |
| Struct w/ ≥ 3 elements | Struct Products has 4 elements: the product name, the number of items in stock, the product price, and the product category. | Struct Products      string productName     Int itemStock     double price     string category |
| Struct inside a Class | The Inventory class manages the Products struct, creating a dynamic array for all the data. | Class Inventory |
| Menu UI | Allow the user to add, delete, search, and quit the program | Private:     void displayMenu() |
| Update external file with changes (save on quit/modify) | Saves the products back into the Storage text file once we quit the program, typing \-99. | updateData() |
| Search Functionality Type of search What field is searched Do data need to be sorted? |  When searching for a product name using binary search, the data must be sorted. This program uses bubble sort.  | searchProduct(productName, opCount) |
|  Search Time Reporting |  Added a report of elapsed execution on case 4 when searching for a product. |  Void Inventory::selectOption() |
| Input Validation | Prevents users from typing letters when selecting an option.   | Void Inventory::selectOption() |
| Exception Handling (file I/O or invalid input) (Note: wrapping file open failure in try/catch alone is not sufficient.) | Before loading or uploading data back into the text file, the program makes sure the file is open correctly. If this doesn’t happen, the program prints a message letting the user know. | Void Inventory::updateData(const string& filename) Void Inventory::loadData(const string& filename) |

---

## One Representative Operation

## Describe, step-by-step, how ONE item is added to the dynamic array, including:

When adding a product to the dynamic array, the program first checks whether the array has capacity for another product. If the array is full, the program calls the resize function to allocate more space. Then the program asks the user for all the product details, sorts the array again, and updates the file if the user exits the program before time.  
---

## Known Issues or Planned Enhancements

Optional, but helpful if you encountered bugs or want to add more features later.

For project B, I will fix a bug that occurs when adding a product. If the user enters two numbers separately when the program asks for the number of items in stock, the code treats the first as the stock quantity and the second as the price. Which breaks the code visually, but in the program, it still saves each value in the right spot. I also plan to add a feature to edit products and see how much profit each product makes by adding the price it was bought for. 

# Project C: Stack or Queue System README

## Student Info

- **Name**: \[Jose Rodriguez\]  
- **Repository**: \[https://github.com/Reedley-College-CSCI/csci-41-sp26-project-c-stack-and-queue-JoseRodriguez21\]

---

## Project Summary

Briefly describe:  
My project builds on the starting data types from project A. The program can now successfully manage logs and pending deliveries. The logs are being managed by a linked list, while the pending deliveries are managed using a queue. I chose a queue because I wanted to add deliveries at the end and remove them from the front. Also used a queue list because I didn’t want to resize the pending deliveries; instead, use pointers to remove them and avoid moving all the deliveries when one was removed from the front. This extends the functionality of project B and uses aspects from the past two projects to connect everything. Giving the user different interactions when managing their storage. The user can update the array from the queue by confirming the number of products that they receive. Also, this action is recorded in the history log, similar to when a user adds or removes a product.

* What data your program manages  
* Whether you implemented a stack (LIFO) or queue (FIFO)  
* How this new structure enhances or extends functionality from Project B

Be specific. This summary should reflect your actual design choices, not just restate the assignment.

---

## Project Continuity

Explain how you satisfied the **first-commit requirement**:

I satisfied this by just doing my first commit with no changes, and then adding changes to the missing parts from the last project in the Project C repository.

---

## Stack / Queue Choice 

* Data structure implemented: Stack ☐ Queue ☐

* Underlying implementation: (array-based, linked list-based, etc.)

* Why this structure was chosen for your data:   
  I used a linked list-based approach because, when removing a delivery ticket, the rest didn’t have to move; I just had to update the pointers. Another reason is searching, because if I had decided on an array, my method would have been linear, which was something that can also be done in a linked list-based.

---

## Requirements Checklist and Where They Are Met

Be specific. Vague statements such as “it works” or “it loads data” will not receive credit. Do not explain why here. Explanations belong in the sections below.

| Requirement | How It’s Met (What specifically happens?) | File/Class/Function \- identify specifically |
| :---- | :---- | :---- |
| Stack or Queue Implemented | Stack / Queue  A queue that adds new tickets to the back and removes from the front | InventoryDelivery.cpp DeliveryQueue.cpp DeliveryQueue.h Deliveries.txt QueueADT.h |
| Push / Enqueue Operation | Creates a new pending delivery ticket with items that the user has to process | DeliveryQueue.cpp    Enqueue InventoryDelivery.cpp    createTicket    returnToFront DeliveryQueue.h    addItem  |
| Pop / Dequeue Operation | Eliminates the pending ticket completely if the user receives all their items if not adds the item back to the front. | DeliveryQueue.cpp    Dequeue InventoryDelivery.cpp    processTicket     |
| Display All Items | Displays all the pending delivery tickets that haven’t been processed by the user | InventoryMenu.cpp     deliverySelectionOption          Case 3: DeliveryQueue.cpp     Display |
| Contains / Search Boolean | Searches for a specific product inside the ticket showing all the tickets that contain that specific product | DeliveryQueue.cpp     Contains     searchItem InventoryDelivery.cpp     searchQueue |
| Follows LIFO or FIFO Rules | My queue follows the FIFO rule, a new ticket is always added to the back, and removing will always eliminate a ticket from the front. | Delivery.cpp InventoryMenu.cpp |
| Integrated into Existing Program | The queue was integrated with everything that already existed in the program. It works with the dynamic array to update products and add new ones, also having the power to resize the array. For the linked list, any action done is recorded in the record files. | InventoryMenu.cpp Inventory.h |
| Menu Options Added | Added a menu option in the switch statement case 7: here is the access to the submenu to interact with the queue | InventoryMenu.cpp    selectionOption        deliverySelectionOption |
| Input Validation | Makes sure that the user is actually inputting a int or double and not a weird number that might make the program crash | Inventory.cpp    getValidInt    getValidDouble    getPositiveInt    getPositiveDouble |
| Error / Exception Handling (file I/O or invalid input) (Note: wrapping file open failure in try/catch alone is not sufficient.) | Make sure that when loading the three text file their are no errors, and when saving not having a infinite while loop that saves to many and corrupts the file. | InventoryIO.cpp    All DeliveryQueue.cpp    loadDeliveries    saveDeliveries |

---

## Stack / Queue Design Details

### **Purpose of the Stack or Queue**

* What data it stores

* Why a stack or queue is appropriate

The data stored is unique ID’s for every pending delivery. Stores the Product name, stock, price, and category for every product in the pending delivery ticket. My decision to use a queue was mainly to remove the first pending delivery from the queue and add a new pending delivery to the back. A stack wouldn’t be able to do that.

### **Operations Implemented**

Explain briefly how each works:

* **Push / Enqueue: Adds a pending delivery to the back of the queue using the back pointer to connected to the queue**

* **Pop / Dequeue: Removes the pending delivery if the user agrees all items arrive if not it sends it back to the fron of the queue.**

* **Display: Traverses all pending delivery tickets and prints each ticket with the items in it.**

* **Contains / Search: Used both, one sees if the product name is found and returns true, while the other goes through every ticket and finds all the matches.**

### **Time Complexity**

* **Push / Enqueue:**

* **Pop / Dequeue:**

* **Search (if implemented):**

Your answers must match your actual implementation.

---

## Integration with Existing Components

Describe **how the stack or queue interacts meaningfully** with:

* The dynamic array: When processing a ticket, if the product name already exists, use binary search to update the stock in the array. If the product name doesn’t exist, a new product is added to the array, and if the array’s full, it gets resized.  

* The linked list: Any actions performed on the dynamic array via the queue are logged, and the creation of a ticket is also logged in the history log. Meaning both text files for dynamic arrays and linked lists also get updated when processing a pending delivery.

* Sorting or searching functionality: When processing a ticket, the function uses binary search to ensure the product doesn’t already exist, if it doesn’t, it's added and sorted.

Example: “The queue temporarily stores sorted results before displaying them.”

If your stack/queue is isolated, explain why and what limitations that introduces.

---

## One Representative Operation

## Choose ONE operation and explain it step-by-step:

* ## Push / Enqueue

* ## Pop / Dequeue

## Dequeue:

## For my dequeue for queue, it starts with an edge case, seeing if the queue is empty to prevent running the next lines and encountering an error. Then we save the first ticket from because we only remove it completely if the user receives all their pending products. After that, we get a new front in case the user actually removes the pending delivery.  Then we check whether the new front is null; if so, we set the back to null as well because there are no more tickets in the queue. This is another edge case. Then we remove the ticket from the queue and remove one from ticketCount in case the user receives all the items in their pending delivery. After that, we send the saved ticket to the user for him to process it. If everything is fine, he removes it completely. If something is missing, he calls a function to send the ticket back into the queue as a priority, meaning it will automatically be at the front of the queue.

	

* ## Data structure state before and after

* ## Edge cases handled (empty structure, full structure, invalid input)

---

## ---

## **User Interface Overview**

## Explain how the menu system allows users to:

* ## Add items 

* ## Remove items 

* ## Display items 

* ## Search for items (if applicable) 

## Comment briefly on usability and clarity.

## ---

## **Testing and Validation**

## Describe how you verified:

* ## Correct stack or queue behavior (LIFO or FIFO): I verified that the queue was actually adding, removing, and sending to the front by displaying all the tickets, allowing me to see if it was doing what I wanted. 

* ## Integration with Project B features: Used logs to keep track of my actions while using the queue. When adding products that were in the pending deliveries to the dynamic array. 

* ## Edge cases and invalid input: Added edge cases when it was empty to make sure lines of code weren’t run without a purpose. Also used the code from the last project to validate ints and doubles, making sure the user wasn’t entering any weird numbers. For invalid inputs or errors, the only thing was an infinite while loop when saving into the text file, which required me to pull some commits because around 12 million lines were created. 

## ---

## **Feedback Integration from Project B**

## List specific changes made in response to feedback from Project B.

Specific changes made in this Project C were the actual addition of the linked list into the main. Which was missing in Project B. So I was able to make the logs work and keep track of the user's actions, mainly adding and deleting. Also, fix a bug that caused an infinite while loop when saving the history logs to the text file.

## Security Checklist (Project C – First Pass)

### Step 1: Identify Project Data

## List each distinct type of data your program currently uses.

## ---

### Step 2: Security Checklist Table

Add rows as necessary.

| Data Item | Sensitivity | Impact | Confidentiality | Integrity | Availability |
| ----- | ----- | ----- | ----- | ----- | ----- |
|  | Low / Med / High | Low / Med / High | Low / Med / High | Low / Med / High | Low / Med / High |
|  |  |  |  |  |  |
|  |  |  |  |  |  |

## ---

### Step 3: Security Reflection 

## In about one paragraph, answer:

* ## Which data items require the most protection? Why?

* ## What have you already done, or plan to do, in your code to protect this data? 

## Video Demonstration

You must include a short narrated video demonstrating that your **stack or queue** works correctly and is integrated into your program. See prompt in Canvas for complete instructions. 

**REQUIRED Link to video: [https://youtu.be/X0Z89KsZnwI](https://youtu.be/X0Z89KsZnwI)**

## Known Issues or Planned Enhancements

Optional, but helpful if you encountered bugs or want to add more features later.

My way of finding bugs or enhancing my project is to let others try it out, give them a brief introduction to what it is, and gather ideas from their comments. For this Project C, this method really worked out, and it was the idea behind my queue. Also, make the visual for the user look more appealing.

---

# Project D: Hash Table System

## Student Info

- **Name**: \[Jose Rodriguez\]  
- **Repository**: \[https://github.com/Reedley-College-CSCI/csci-41-sp26-project-d-hash-table-JoseRodriguez21\]

---

## Project Summary

Briefly describe:

* What data your program manages

* How the hash table is used to store and retrieve that data

* How Project D extends functionality from Project C

My program gives the user the option to manage their storage. They can modify products stock and price. They also have the opportunity to add new products giving them a name, price, stock and category. There are different ways to add products, they can make it manually and also automatically. Every log is saved into a linked list where the user can see all the actions that have been made to his storage system. For my hash table I utilized category which was something added since project A and was never used. Using the chaning to divide the products by category giving the option to the user to search for a certain category and see all the products on it. They can also display all the categories and let the user interact with products from a specific category where they can modify it making it easier to make changes to products. 

---

## Project Continuity

Explain how you satisfied the **first-commit requirement**:

* Confirm that Project C files were used as the starting point

* Identify any structural changes made immediately after cloning

  In the first commit all the files from Project C where used to start Project D. Nothing was changed everything was kept the same.

---

## **Hash Table Overview (Required)**

* **Key type:** (e.g., string, integer, composite key)

  The key type for my hash table is string because category variable is a string which will be used to find the categories.

* **Value type:** (what data is stored per key)  
  The values stored in the hash tables are the product names. With all the information from them, price and stock.

* **Table size:** (constant or configurable)

  For table size I used a constant because the idea of my program is a small store. This removes complexity when we have to resize the hash table, but it can be implemented if later the program is thought to manage a bigger store with more categories.

---

## Requirements Checklist and Where They Are Met

Complete all rows.  
Use concise, factual entries. Explanations belong in later sections.

| Requirement | How It’s Met (What specifically happens?) | File/Class/Function \- identify specifically |
| :---- | :---- | :---- |
| Hash Table Implemented | Creates a hashtable that has categories as the key that decides in which bucket it goes. Inside this key their is a linked list with the products that have that category. | HashTable.cpp HashTable.h HashNode.h |
| Hash Function Defined |  |  |
| Collision Handling Method | Chaining / Open Addressing If a item has the same bucket the program uses chaning and when the user search for a certain category it goes through all the bucket and sees in the category exists. | HashTable.cpp |
| Insert Operation | Inserts a category into the hashtable first it looks if it doesn’t exists if it does then only the item is added if not the category is added as the first one in the bucket or after the already existing category in the bucket. | Void HashTable:: insert() |
| Search Operation | Uses hash to find the index and from their it goes from all the items inside that bucket if the function finds it it’s return if nothing is found the function returns null. | HashNode\* HashTable:: search() |
| Remove Operation | The user can either remove a item inside a category or a whole category. A item is used when a user deletes a product from the dynamic array completely. While category is a option that the user can input from the submenus displayed. | Bool HashTable::removeProduct Bool HashTable::removeCategory |
| Display Table Contents | If the user inputs selection 1 in the submenu after selecting option 8 in the main menu they can see all the information inside each category seeing all the product names. | Void HashTable::display() |
| Integrated into Existing Program | I can remove and add from the hash table when deleting from already existing code. If a user completely deletes a functions that is display into the hash table. | InventoryActions.cpp |
| Menu Options Added | A new menu is added with three options for the user to do the second option is not finished but onces it is finish the user has the chance to modify more the category. | InventoryMenu.cpp |
| Input Validation |  |  |
| Error / Exception Handling (file I/O or invalid input) (Note: wrapping file open failure in try/catch alone is not sufficient.) |  |  |

---

## How to Run

List instructions here if special input files or arguments are needed.

Example: Ensure `movies.txt` is in the same folder. Run the program and use the menu to add or search for movies.

To run this program, all the files must be in the same folder, and it depends on the compiler being used.  
Using Visual Studio 2019: If using this compiler, nothing extra needs to be done; just place all files in the same folder with no extra commands.  
Using Visual Studio 2022 (Mac): If using this compiler, the user has to first type the command make and then ./main into the terminal, and then run, which will make the code work  
Using Visual Studio 2022 (Windows): Haven’t added anything to make it work yet, use Visual Studio 2019\.   
---

## Hashing Design Details

### **Hash Function**

* Describe how keys are converted into indices

* Why this function is suitable for your key type

The keys are turned into indices by reading one character at the time and using the formula. This is the most suitable for my program because I have some hyphens in my keys and using this method makes it work. Also if I want to use case sensitive using this method will give good results.

### **Collision Handling**

Explain briefly how each works:

* Method used: Chaining or Open Addressing

* How collisions are resolved in your implementation

If using open addressing, specify the probing strategy.

The method used in collision handling is chaining because there are not going to be too many categories added that might collide. Also, the size is set to 13, reducing the likelihood of too many items in one bucket.

---

## AI Design Review

Document your AI design review exchange below.

1. Your prompt (summarized or pasted): What did you tell AI about your design, and what did you ask it to evaluate?

	

2. AI recommendation: What did it suggest or critique about your hash function or collision handling?

	

3. Your evaluation: Was the recommendation correct, partially useful, or unsuitable for your data set? Explain using your actual key type, table size, expected number of records, and expected collision behavior. Be specific.  
 


4. What did you keep, change, or reject: How did the AI exchange influence, or not influence, your final design?

---

## **Hash Table Operations and Complexity**

For your implementation, state the expected time complexity:

| Operation | Average Case | Worst Case |
| ----- | ----- | ----- |
| Insert | O(1) | O(n) |
| Search | O(1) | O(n) |
| Remove | O(1) | O(n) |

Your answers must match your design and collision handling method.

---

## **Integration with Existing Components (Required)**

Describe how the hash table interacts meaningfully with:

* Dynamic array

  

* Linked list

* Stack or queue

Example: “The hash table replaces linear search in the array for faster lookups.”

If the hash table duplicates functionality already present, explain why.

---

## One Representative Operation

## Choose ONE operation and explain it step-by-step:

* ## Insert

* Search  
* Remove

## Include:

* ## How the hash index is computed

* What happens during a collision  
* Edge cases handled (duplicate keys, missing keys, full table)

## ---

## **Testing and Validation**

## Describe how you verified:

* ## Correct insertion, search, and removal 

* ## Collision handling behavior 

* ## Edge cases (non-existent keys, repeated keys) 

## ---

## **Feedback Integration from Project C**

## List specific changes made in response to feedback from Project C.

* ## What changed 

* ## Why 

* ## Where

For this project, I made the new hash table look a little nicer than how things were looking in Project C. I still need to make it visually better for project E. I wanted to do this because the presentation given to the user in some aspects weren’t the best. 

## Security Checklist (Project D – Updated)

### Step 1: Updated Data Items

## List any **new data types** introduced in Project D and note which existing items changed in importance.

## ---

### Step 2: Updated Checklist Table

Add rows as necessary.

| Data Item | Sensitivity | Impact | Confidentiality | Integrity | Availability |
| ----- | ----- | ----- | ----- | ----- | ----- |
|  | Low / Med / High | Low / Med / High | Low / Med / High | Low / Med / High | Low / Med / High |
|  |  |  |  |  |  |
|  |  |  |  |  |  |

## ---

### Step 3: Security Reflection (5-7 sentences)

## Answer:

* ## What changed since Project C?

* ## Why did those changes occur?

* ## How did you respond in your code? 

## Video Demonstration

You must include a short narrated video demonstrating that your **hash table** works correctly and is integrated into your program. See prompt in Canvas for complete instructions. 

**REQUIRED Link to video: [https://youtu.be/EEIHaPasIgM](https://youtu.be/EEIHaPasIgM)**

---

## Known Issues or Planned Enhancements

Optional, but helpful if you encountered bugs or want to add more features later.  
For my next project and last one, I plan to add partial search to my hash table. It’s something that will really benefit my hash because the user is going to have more flexibility at the time of searching inside the categories. Also, I want to enhance the visuals and finish the parts of my hash tables that weren’t completed on time.

---

# Project E

## Student Info

- **Name:** \[Jose Rodriguez Muro\]  
- **Repository:**\[[https://github.com/Reedley-College-CSCI/csci-41-sp26-project-e-data-retrieval-and-processing-JoseRodriguez21](https://github.com/Reedley-College-CSCI/csci-41-sp26-project-e-data-retrieval-and-processing-JoseRodriguez21)

---

## Project Summary

Brief overview of your application:

- What does your program do?  
- What kind of data does it process?  
- What problem does it solve or what functionality does it provide?  
- This program is a storage system or storage management where the user can interact with the items inside. It processes product names, stock, quantity, price and category. The program solves the program of having to manually keep track of your inventory and instead does it digitally having easier access to all the information. It has a user interface that makes it easy for them to understand what to do. Allowing the user to add, delete, modify, search and sort products. It keeps track of all the actions done in the program in the history also manages pending deliveries through a queue system. Also organizes arrays with category using hash table. All data is saved in the text files which are frequently updated during the session.

---

## Project Structure/File Overview

Provide a complete list of the files (including text files) and classes in your project and their purpose. \[**Example**:\]

* Storage.txt: Text file that saves the products with their information such as, Product names, stock, prices and category  
* History.txt: Saves all the log/actions that the user makes throughout the program  
* Deliveries.txt: Saves tickets with products that have to be delivered.  
* Inventory.h: Declares the inventory class with the most important functions in the program.  
* Products.h: Creates a struct with product name, stock, price and category  
* Inventory.cpp: Defines resize and validates ints and doubles.   
* InventoryMenu.cpp: Defines all the switch statements that allow the user to interact with menus and submenus.  
* InventoryActions.cpp: Defines the functions for adding and removing products from the storage system.  
* InventorySearch.cpp: Defines quicksort used to search for specific products and displays them to the user.  
* InventorySort.cpp: Sorts the items inside the storage system by name and could also do it in reverse order.  
* InventoryIO.cpp: Loads and saves functions used towards the storage.txt file.  
* InventoryDelivery.cpp: Defines functions to create delivery tickets, let the user process the delivery tickets, and search for products that are in process.  
* InventoryCategory.cpp: Checks if a category exists, displays specific category, delete category and search category  
* InventoryModify.cpp: Let’s the user modify a product data, price, stock, category or name  
* ListADT.h: Creates the struct transactions and declares functions  
* HistoryLinkedList.h: defines the functions that the linked list has.  
* HistoryLinkedNode.h: Creates the node for the linked list  
* QueueADT: Creates a class and declares the functions that the queue is going to have.  
* DeliveryQueue.h: Creates the structs for single items and the pending delivery ticket with their information, also declares functions used.  
* DeliveryQueue.cpp: Defines all the functions declared on the class, such as enqueue, dequeue, searchItem, etc.  
* HashTable.cpp: Defines all the functions inside the hash table h declarations.  
* HashTable.h: Declares all the function for the hash table to work correctly  
* HashNode.h: Creates Product node and hash node struct used for the hash table  
* Makefile: Created this file to be able to run the code in Visual Studio 2022 with a mac

---

## Requirements Checklist and Where They Are Met

| Area | How Requirement Is Met | File/Class |
| :---- | :---- | :---- |
| Add/Remove | Products are added and deleted usind two functions inside the inventory actions cpp file. The actions are saved inside the linked list. When something is remove the delete functions shifts the items | InventoryAction.cpp InventoryCategory.cpp |
| Data Structures | Used a dynamic array for inventory, singly linked list for history, queue for deliveries, hash table for category. | HashTable.cpp DeliveryQueue.cpp HistoryLinkedList.cpp InventorySearch.cpp InventorySort.cpp |
| Input Validation | Empty string checks, verify if ints and doubles are positive preventing negatives from being read. Single category word that prevents bugs when occurring when reading from the text file | Inventroy.cpp InventoryActions.cpp InventoryModify.cpp |
| Security Checklist | All the data types are highly needed to be available for the user at all times. While some vary on how confidential it should be | Security checklist |
| Ethics Checklist | The program is designed for a small business to keep track of their storage | Ethics checklsit |
| Advanced Techniques | Used pointers for most of the data structures, file I/O using ifstream and outstream to read text files.  | InventoryIO.cpp HashTable.cpp HistoryLinkedList.cpp  |
| Searching and Sorting | Binary search was only use when searching for items, while linear search was used for the parts where I had pointers also quicksort was used to sort the products for binary search. | InventorySearch.cpp InventorySort.cpp  |
| Algorithm Complexity | Several algorithms with different complexity, the selection was mainly O(1) or O(n) because most of the project has pointers | Multiple files |
| User Interface | Provided menus and submenus to make it more visually appealing to the user. Also having messages before completing actions that they might have not wanted to do. | InventoryMenu.cpp |
| Modularity | 11 different cpp files also several h files and three text files to prevent having to many lines of code in only one file also each cpp file has a specific functionality that made sense. | Multiple files |
| Readability | Consistently adding comments to explain what the code was doing. Using the skills learned in class and zybooks to make the code easy to read also spaced it out correctly. | All files |
| README | This document; covers all Project E requirements | `README.md` |

---

## Changes from Previous Projects and Code Reviews

- **From Project D:**  
  - Added a new function into the main menu that lets the user modify the products inside the array. Fixed single-word for category to prevent bugs from occuring when closing the program and re compiling. Instead of modifying by searching the product I gave the user options which made it look cleaner and easier to write.   
- **From most recent code review:**  
  - 

---

## Data Structures Used

- **Primary and secondary data structures used in the FINAL version of your project:** \[e.g., Hash Table, Linked List, etc.\] (cover for your major data structures implemented)  
- **Why Chosen:** \[Why this structure fits your problem best\]  
- **Alternatives Considered:** \[Optional\]  
- **Dynamic Array:**   
  Used for the main inventory storage, Fast to access index, also had the opportunity to be resized as well as using faster algorithms to search and sort.  
  Operations: delete product and delete product, search O(log n) binary search, sort O(log n) QuickSort


	**Singly Linked LIst:**  
Used for transaction history logs, this was chosen because I learned it before doubly linked list, also this has the option to prepend which doesn't require the resize or shift when removing.  
	Operations: Prepend O(1), traverse O(n), search by ID O(n), clear O(n)

	**Queue:**   
Used for pending delivery tickets, choose this because search was not going to be use also FIFO was more viable because the delivery that had to be process first had to be the first one in. Also I could add a function that sends the delivery back to the front in case all didn’t arrive

Operations: Equeue(1), dequeue O(1), returnToFront O(1), display O(n), contains O(n)  
	  
	**Hash Table (Chaining):**   
Used for category organization, used chaining to handle collisions and keep them in the same index because it was easier when searching. Used category name to search the hash table to find the specific category. Works better like this then opening addressing.

	Operations: Insert O(1), search O(1), remove O(1), display O(n)  
	

---

## Algorithm Time Complexities (include major algorithms--you might have multiple searches, etc.)

Include all major search, insert, remove, and sort operations used in your final program. Add rows as necessary.

| Operation | Algorithm Used | Big-O Complexity | Notes |
| :---- | :---- | :---- | :---- |
| Search Products | Binary Search | O(log n) | Requires a sorted array to work |
| Sort Products | Quick Sort | O(log n) or O(n^2) | Has a worse case scenario with random data, rare to occur in my program |
| Search Id in linked list | Linear Search | O(1) | Has to go through the entire list |
| Enqueue Delivery | Queue enqueue | O(1) | To access it you have to dequeue the ones in front |
| Dequeue Delivery | Queue dequeue | O(1) |  |
| Search Queue | Linear Search | O(n) | Traverses through all the tickets and items |
| Hash Table Insert | Polynomial Hash \+ Chain | O(1) or O(n) | Worst case occurs if all keys collide |
| Hash table search | Polynomial Hash \+ Chain | O(1) or O(n) | Worst care occurs if all keys collide |
| Hash Table remove | Polynomial  Hash \+ Chain | O(1) or O(n) | Worst case occurs if all keys collide |
| Add product to Array | Array insert | O(1) or O(n) | Worst case only when having to resize the array |
| Delete product from array | Array Shift | O(1) | Have to shift elements after deleting |

---

## Ethics Checklist

**Example Only:**  
The following is a sample for how much depth and organization is expected.  
You must customize this section based on your own project's data, purpose, and audience. These examples demonstrate expected depth, not expected content. Your responses must be specific to your project.

- **Potential Harms to the Public:**  
  (Example) Inaccurate or misleading analysis could cause users to misinterpret their performance.  
  **Prompt:** What could go wrong if your data were wrong, misused, or misunderstood?  
  Having the incorrect stock could be misleading for the store because it could mean there can be problems when ordering more. Removing all logs which anyone can do both owner and employee can be a problem losing crucial data.  
    
- **How Harms Were Addressed:**  
  (Example) Clear disclaimers about data accuracy were added; sensitive data handling was implemented.  
  **Prompt:** What measures did you add to avoid harming users?  
  When the user wanted to delete something he was asked if he really wanted to do that just to prevent data from being removed. All changes were saved into the text files to prevent that data being saved instantly. Also used history log as a way of understanding why things are missing or what might have occurred.  
    
- **Positive Contribution to the Public:**  
  (Example) Helps users make informed decisions about gameplay improvement.  
  **Prompt:** How does your project make people's lives better or more informed?  
  Helps owners to have a better tracking on how their business is doing. Reducing errors that can be made if kept track by humans in a spreadsheet or paper, also makes it easier to access all the information in one place.  
    
- **Who Exactly Is the Public:**  
  (Example) Competitive gamers, casual players, and online gaming communities.  
  **Prompt:** Who benefits most from your program?  
  The people that benefit the most from my program is small retail stores, family businesses or a simple inventory location that manages some sort of product.

---

## Security Checklist

| Data | Sensitivity | Impact | Confidentiality | Integrity | Availability |
| :---- | :---- | :---- | :---- | :---- | :---- |
| Product Name | Low | Low | Low | High | High |
| Stock  Quantities | Medium | Medium | low | High | High |
| Gameplay Statistics | Medium | high | medium  | High | High |
| Category name | low | low | low | medium | high |
| Transaction  History | Medium | Medium | High | high | high |
| Delivery  Tickets | Medium | Medium | low | high | high |

**Security Considerations Summary:**

- **Product names:**  
  Not sensitive on its own. It’s important to be available for users to find, and integrity is important to be able to search in the system and lookup inside the hash table.  
    
- **Stock Quantities:**  
  It’s sensitive because it can show operations, having some impact but shouldn’t be confidential because others knowing the stock doesn’t do nothing. Integrity and Availability are high because having a wrong count or not being able to access the information can be harmful for business.  
    
- **Product prices:**  
  It’s crucial that this information is more confidential than stocks because it has a bigger impact if other stores know about it. It’s sensitive for the store because it can show the earning if there was a lot of access. High integrity because the prices have to be correct for financial records. Availability is high because knowing the price as the owner is crucial.  
- **Category names:**  
  Category names aren’t sensitive, impactful or should be confidential because they are just labels for products. Integrity is medium because having a incorrect category can break the hash table and availability is high because it’s necessary when searching.  
- **Transaction history:**  
  Sensitivity is somewhat crucial because it can reveal patterns or activity that occurs. Leakage is not that impactful but still has importance on the store and confidential is high because only the owner should have access because employees can corrupt it. Both integrity and availability are high because history has to be accurate and the owner has to be able to access past activity to make business better.  
- **Delivery tickets**  
  Both sensitivity and impact are medium because wrong data could be impactful or duplicated deliveries. The suppliers and quantities supplied are also important but are not high. Confidentiality is low because who the suppliers are is not too important. Both integrity and availability are high because they have to be accessible and accurate for the people. 

**Prompt:** For each data type you collect, ask:

- Could leaking this data hurt someone?  
- What steps protect the data's confidentiality, accuracy, and availability?

---

## Test Log

We learned a **test log** records the results of key tests you performed to verify correctness, robustness, and edge-case behavior in your final project. It helps demonstrate that you verified *functionality did not break* as new features were added.

#### **Instructions**

1. **Identify what you tested.**  
    Include at least 5 test cases that verify different parts of your project (e.g., insert/search/delete in a data structure, file input, validation of bad data, etc.).

   * At least one should test *expected* (“normal”) behavior.

   * At least one should test an *edge case* or invalid input.

   * Use the table in \#2 and replace cell contents with your testing documentation. Add rows as necessary.

2. **Record results using this table :**

| Test Case ID | Feature / Function Tested | Input / Conditions | Expected Output or Behavior | Actual Output | Pass / Fail | Notes / Fixes Made |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| TC-01 | Clear history when empty | Select clear history when their is no logs in existence | “Log history is already empty.” message | Matched expectation | Pass | isEmpty() prevents from breaking |
| TC-02 | Empty product name | Press enter without typing nothing | Gives the prompt again “Product name can’t be empty” | Gives the prompt until a name is inputed | **Pass** | **Loop handles the edge case** |
| TC-03 | Multi-word category | Enter “Lip Item” as a category | Saves the whole category  | **Does save the category but a bug occurs when exiting the program** | **Fail** | **When the program is recompiled the code breaks because when reading the information having two words for category breaks the code. Fix: Only save the first word to the text file** |
| TC-04 | Delete entire category | Category:  Delete chips category with 4 products | All 4 products are remove from the category and hash table, each one gets logged | **Array count decrease by 4, category gone from hash table** | **pass** | **Verified in storage.txt** |
| TC-05 | Hash Table collision | Load storage.txt with, chips, pastries, general and coca cola | Chips and coca-cola at index 6, pastries and general at index 5 | **Changing correctly links colliding categories** | **pass** |  |

3. **Reflect briefly** below the table:

   The most interesting bug that appear in my program was when a category had two words or more. No error would occur while the program was running but once the user exited the program and re complied it this would break due to how the information was read from the text file. The easiest fix was to add code that only reads the first word when asking for category instead of re adjusting the reading of the text file.

---

## How to Compile and Run

Include any special instructions (e.g., input files required, arguments to pass at runtime).  
To run this program, all the files must be in the same folder, and it depends on the compiler being used.  
Using Visual Studio 2019: If using this compiler, nothing extra needs to be done; just place all files in the same folder with no extra commands.  
Using Visual Studio 2022 (Mac): If using this compiler, the user has to first type the command make and then ./main into the terminal, and then run, which will make the code work

---

## Known Issues or Future Enhancements

Some issues of my program are that categories are single names and can’t have several. Ask that the log grows indefinitely until the user eliminates it. Some enhancements for the future are adding a sales track where you can see all the items sold. Maybe also show data of the products that are being purchased more frequently and products that aren’t being sold. Being able to have receipts for transaction and create something that limits the employee access to certain things on the system like the logs.

---

## Video Demonstration

You must include a short narrated video demonstrating that your **final project** works correctly and is integrated into your program. See prompt in Canvas for complete instructions. 

**REQUIRED Link to video:** https://youtu.be/ESJfDtybqH8

---

## Acknowledgments

- Lectures and zybooks from this class  
- Program inspired from my mom store which the program she uses for her store has a lot of flaws


