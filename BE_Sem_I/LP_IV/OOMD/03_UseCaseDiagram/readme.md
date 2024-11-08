## **03. Use Case Diagram**

### **Objective**
The objective of this practical is to create **Use Case Diagrams** to capture and represent the **requirements** of a system, using various scenarios to model how different actors interact with the system. This helps in identifying system behavior from the user's perspective.

### **Theory**
A **Use Case Diagram** is used to visualize the interactions between **actors** (external users or systems) and the **system** itself. Each **use case** represents a function or interaction within the system. The key components of a use case diagram are:
- **Actors**: Entities interacting with the system (e.g., users, other systems).
- **Use Cases**: Actions or services provided by the system.
- **System Boundary**: Defines the scope of the system.

### **Procedure**
1. Identify the main **actors** (e.g., user, admin, system).
2. List the **use cases** that describe system functionality.
3. Draw the **Use Case Diagram** and describe each use case with a template.
4. Provide detailed steps for each use case scenario.

### **Design Model**
#### **Use Case Diagram for a Library Management System**
Below is an example of how a **Library Management System** can be represented using use case diagrams.

**Actors**:
- **Library Member**: A user who can borrow and return books.
- **Librarian**: A user who manages the library, adds/removes books, and manages member accounts.
- **System**: A computer system that manages transactions.

**Use Cases**:
- **Borrow Book**
- **Return Book**
- **Add New Book** (for Librarian)
- **Remove Book** (for Librarian)
- **Register Member** (for Librarian)

**Use Case Diagram Representation**:

```
+-------------------------------------------------+
|                Library Management System        |
|                                                 |
|  +----------------------+   +----------------+  |
|  |    Library Member    |   |    Librarian   |  |
|  |----------------------|   |----------------|  |
|  |  - Borrow Book       |   |  - Add Book    |  |
|  |  - Return Book       |   |  - Remove Book |  |
|  +----------------------+   |  - Register    |  |
|           |                 +----------------+  |
|           |                                    |
|           +------------------------------------+
|                     System                    |
+-------------------------------------------------+
```


![svgviewer-png-output](https://github.com/user-attachments/assets/f18acecf-fb07-4ff3-9f84-ce01bb1584b3)

**Note**

#### **Use Case Templates**:
Each use case must be detailed with its description and steps:

---

#### **1. Use Case: Borrow Book**

- **Primary Actor**: Library Member
- **Goal in Context**: The member borrows a book from the library.
- **Preconditions**: The member is registered, and the book is available.
- **Main Success Scenario**:
  1. The member searches for the book.
  2. The member selects the book to borrow.
  3. The system checks availability.
  4. The system registers the borrowing transaction.
  5. The member receives the book.
- **Postconditions**: The book is borrowed, and its status is updated in the system.
- **Alternative Scenario**:
  - If the book is not available, the system notifies the member.
  - The member can place a hold on the book.

---

#### **2. Use Case: Return Book**

- **Primary Actor**: Library Member
- **Goal in Context**: The member returns a borrowed book to the library.
- **Preconditions**: The member has previously borrowed the book.
- **Main Success Scenario**:
  1. The member approaches the librarian or system for returning the book.
  2. The system checks the return date.
  3. The system updates the status of the book to available.
  4. The member receives a receipt confirming the return.
- **Postconditions**: The book is returned and is available for other members.
- **Alternative Scenario**:
  - If the book is late, the system applies a fine and notifies the member.

---

#### **3. Use Case: Add New Book** (for Librarian)

- **Primary Actor**: Librarian
- **Goal in Context**: The librarian adds a new book to the library system.
- **Preconditions**: The librarian has authorization to add books.
- **Main Success Scenario**:
  1. The librarian selects the "Add Book" option.
  2. The librarian enters book details (title, author, ISBN, etc.).
  3. The system saves the new book in the catalog.
- **Postconditions**: The new book is available for borrowing by members.
- **Alternative Scenario**:
  - If the book already exists, the system alerts the librarian.

---

#### **4. Use Case: Remove Book** (for Librarian)

- **Primary Actor**: Librarian
- **Goal in Context**: The librarian removes a book from the library system.
- **Preconditions**: The librarian has authorization to remove books.
- **Main Success Scenario**:
  1. The librarian selects the "Remove Book" option.
  2. The librarian searches for the book to be removed.
  3. The system confirms removal of the book.
  4. The book is removed from the catalog.
- **Postconditions**: The book is no longer available for borrowing.
- **Alternative Scenario**:
  - If the book is currently borrowed, the system alerts the librarian.

---

### **Results**
The use case diagram successfully captures the primary requirements for the **Library Management System** and describes various scenarios for book transactions. These scenarios help in identifying system functionalities from the user’s perspective.

### **Conclusion**
This practical reinforced the use of **Use Case Diagrams** to capture system requirements effectively. Each use case described real-world actions and interactions, and the use of scenarios ensured that system behavior was well-understood from all perspectives.
