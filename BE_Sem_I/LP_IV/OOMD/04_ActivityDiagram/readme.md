
## **04. Activity Diagrams**

### **Objective**
The objective of this practical is to design **Activity Diagrams** to represent the flow of activities within a system. Activity diagrams are used to display business processes or workflows in a system, similar to flow charts, but with more advanced features like concurrency and decisions.

### **Theory**
An **Activity Diagram** in UML represents the flow of control or data in a system. It is used to describe workflows and business processes. The key elements of an activity diagram include:
- **Activities**: Represent actions or operations.
- **Transitions**: Arrows that show the flow between activities.
- **Decision Nodes**: Represent choices based on conditions.
- **Start/End Nodes**: Represent the beginning and end of an activity.
- **Fork/Join Nodes**: Represent parallel activities (concurrency).

### **Procedure**
1. Identify the flow of activities or business processes.
2. Define the activities, decisions, and conditions.
3. Draw the **Activity Diagram** using appropriate symbols.
4. Illustrate both normal and alternative flows within the system.

### **Design Model**
#### **Activity Diagram for a Library Book Borrowing Process**
Below is an example of an **Activity Diagram** to represent the **Book Borrowing Process** in a **Library Management System**.

**Steps in the Process**:
1. Member logs into the system.
2. Member searches for a book.
3. System checks availability.
4. If available, member borrows the book.
5. If unavailable, member places a hold.
6. Member returns the book.

**Activity Diagram Representation**:

```
+---------------------+         +------------------------+
| Start               |         |     Book Search        |
+---------------------+         +------------------------+
          |                            |
          v                            v
+---------------------+         +------------------------+
| User Login          |-------->| Check Book Availability|
+---------------------+         +------------------------+
          |                            |
          v                            v
+---------------------+         +------------------------+
| Is Book Available?  | <------> | Borrow Book            |
+---------------------+         +------------------------+
          |                            |
   [No]  /  \ [Yes]              /  |  \ 
        v      v                  v   v
 +--------------+          +------------------+
 | Place Hold   |          | Return Book      |
 +--------------+          +------------------+
          |                            |
          v                            v
+---------------------+         +------------------------+
| End                 |         | End                    |
+---------------------+         +------------------------+
```

#### **Key Elements**:
- **Start**: The process begins when the user logs in.
- **Activity**: Each action (e.g., User Login, Search for Book) is an activity.
- **Decision Node**: The decision point where the system checks if the book is available.
- **Fork/Join**: Represents the two parallel actions: Borrow Book or Place Hold, depending on the availability.

#### **Activity Diagram for Online Purchase Process** (Alternative Scenario)
This diagram can represent the process of an **online purchase**.

**Steps in the Process**:
1. User logs into the e-commerce website.
2. User searches for products.
3. If the product is available, user adds to cart.
4. User checks out and makes payment.
5. If payment is successful, user receives an order confirmation.

**Activity Diagram Representation**:

```
+---------------------+         +------------------------+
| Start               |         |     Search Product     |
+---------------------+         +------------------------+
          |                            |
          v                            v
+---------------------+         +------------------------+
| User Login          |-------->| Product Availability   |
+---------------------+         +------------------------+
          |                            |
          v                            v
+---------------------+         +------------------------+
| Is Product Available?| <------> | Add to Cart            |
+---------------------+         +------------------------+
          |                            |
   [No]  /  \ [Yes]              /  |  \ 
        v      v                  v   v
 +--------------+          +------------------+
 | Place Order  |          | Proceed to Checkout|
 +--------------+          +------------------+
          |                            |
          v                            v
+---------------------+         +------------------------+
| Make Payment        |         | Order Confirmation     |
+---------------------+         +------------------------+
          |                            |
          v                            v
+---------------------+         +------------------------+
| End                 |         | End                    |
+---------------------+         +------------------------+
```

---

### **Results**
The **Activity Diagrams** effectively represent the **business flows** for both **Library Book Borrowing** and **Online Purchase** processes. The diagrams clearly show the flow of activities, decision points, and parallel processes.

### **Conclusion**
This practical demonstrates the importance of **Activity Diagrams** in visualizing and understanding business processes. By using decision points and parallel flows, we can model complex workflows efficiently. These diagrams are crucial for designing and analyzing business and system processes.


### **Review Questions**
Here are answers for the review questions:

---

**Q1. What are the elements of a use case diagram?**  
**A:** The main elements of a **use case diagram** are:
- **Actors**: Represent users or systems that interact with the system.
- **Use Cases**: Describe the functionalities or services the system provides.
- **Relationships**: Shows how actors and use cases are connected, including association, include, extend, and generalization.
- **System Boundary**: Defines the scope of the system.

---

**Q2. What are static and behavior diagrams?**  
**A:** **Static diagrams** show the structure of a system, such as **Class Diagrams** and **Component Diagrams**. They represent relationships and dependencies but don’t capture dynamic behavior.  
**Behavior diagrams** illustrate the dynamic aspects of a system, showing **how it behaves over time** (e.g., **Use Case Diagrams, Activity Diagrams, Sequence Diagrams**).

---

**Q3. Which relationships are used in a use case diagram?**  
**A:** Relationships in a **use case diagram** include:
- **Association**: Link between actors and use cases.
- **Include**: Shows that a use case includes the behavior of another use case.
- **Extend**: Adds optional behavior to a use case.
- **Generalization**: Defines inheritance between actors or use cases.

---

**Q4. How are use cases and actors organized?**  
**A:** **Actors** and **use cases** are organized by:
- Identifying **actors** as external entities that interact with the system.
- Placing **use cases** within the system boundary to show services provided by the system.
- Using relationships to illustrate how actors interact with each use case.

---

**Q5. How to describe a use case?**  
**A:** To describe a **use case**:
- **Name** the use case clearly.
- Define the **Actor(s)** involved.
- Write a **Brief Description** summarizing the use case’s purpose.
- Detail **Preconditions** and **Postconditions** to specify the required system state before and after the use case.
- List the **Main Flow** and **Alternative Flows** (steps) for each scenario.

