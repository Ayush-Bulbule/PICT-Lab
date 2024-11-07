## 02 Class Diagram

### **Objective**
The goal of this practical is to design **Class Diagrams** that help identify and describe key concepts such as **classes**, **types**, and their **relationships** within a system. This will help in understanding how to represent the structure and behavior of objects in a system.

### **Theory**
A **Class Diagram** in UML is used to represent the structure of a system by showing the system's classes, their attributes, methods, and relationships between the classes. The basic concepts are:
- **Classes**: Templates for creating objects.
- **Attributes**: Properties of a class.
- **Methods**: Functions associated with the class.
- **Relationships**: Includes **association**, **inheritance**, and **composition**.

### **Procedure**
1. Identify the core components of the system.
2. Determine the key classes, attributes, methods, and relationships.
3. Draw the Class Diagram using UML notation.

### **Design Model**
#### **Class Diagram for a Library Management System**
Here is an example of how the **Library Management System** might be structured in a basic class diagram.

**Classes and Relationships**:
- **Library** (has many **Books**, **Members**)
- **Book** (has attributes like title, author, and methods like borrow(), return())
- **Member** (has attributes like name, memberID, and methods like borrowBook(), returnBook())
- **Librarian** (inherits from **Member** and has methods like addBook(), removeBook())

**Class Diagram Representation**:

```
+---------------------+
|     Library         |
+---------------------+
| - books: List<Book> |
| - members: List<Member>|
+---------------------+
| + addMember()       |
| + removeMember()    |
| + addBook()         |
| + removeBook()      |
+---------------------+
          |
          |
          v
+-------------------+       +------------------+
|     Book          |<>-----|     Member       |
+-------------------+       +------------------+
| - title           |       | - name           |
| - author          |       | - memberID       |
| - ISBN            |       +------------------+
+-------------------+       | + borrowBook()    |
| + borrow()        |       | + returnBook()    |
| + return()        |       +------------------+
+-------------------+
          |
          |
          v
  +---------------------+
  |     Librarian       |
  +---------------------+
  | + addBook()         |
  | + removeBook()      |
  +---------------------+
```

#### **Key Relationships**:
- **Association**: Library has many Books and Members (denoted by lines connecting classes).
- **Generalization (Inheritance)**: Librarian is a subclass of Member (denoted by an arrow pointing from Librarian to Member).

### **Code Implementation**
Here’s a simplified Java implementation based on the above diagram:

```java
class Book {
    private String title;
    private String author;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    public void borrow() {
        System.out.println(title + " borrowed");
    }

    public void returnBook() {
        System.out.println(title + " returned");
    }
}

class Member {
    private String name;
    private int memberID;

    public Member(String name, int memberID) {
        this.name = name;
        this.memberID = memberID;
    }

    public void borrowBook(Book book) {
        book.borrow();
    }

    public void returnBook(Book book) {
        book.returnBook();
    }
}

class Librarian extends Member {
    public Librarian(String name, int memberID) {
        super(name, memberID);
    }

    public void addBook(Book book) {
        System.out.println(book + " added to library");
    }

    public void removeBook(Book book) {
        System.out.println(book + " removed from library");
    }
}
```

### **Results**
The class diagram accurately represents the key objects in the **Library Management System**, and their interactions are well-defined with inheritance and relationships.

### **Conclusion**
This practical reinforced the ability to design class diagrams and identify relationships between objects. By analyzing key concepts like classes, methods, and inheritance, we were able to effectively represent the system's structure.

---

Adjust the **Class Diagram** and **code** based on your specific system and requirements.