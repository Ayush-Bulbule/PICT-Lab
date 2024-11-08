
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
[Learn More Here](https://www.visual-paradigm.com/guide/uml-unified-modeling-language/what-is-activity-diagram/)

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
![image](https://github.com/user-attachments/assets/45aafcb8-f7c1-4dea-a0a2-0b001a84fe8e)


#### **Key Elements**:
- **Start**: The process begins when the user logs in.
- **Activity**: Each action (e.g., User Login, Search for Book) is an activity.
- **Decision Node**: The decision point where the system checks if the book is available.
- **Fork/Join**: Represents the two parallel actions: Borrow Book or Place Hold, depending on the availability.

#### Activity Diagram: Ticket Vending Machine
This is an Activity Diagram for a Ticket Vending Machine system that shows the interaction between three participants: Commuter, Ticket Vending Machine, and Bank. Let me explain the flow:

1. Initial Flow:
   - The process starts with the Commuter initiating a "Start Session"
   - The machine "Requests Trip Info"
   - Commuter "Provides Trip Info"
   - Machine "Processes Trip Info"

2. Payment Process:
   - Machine "Requests Payment"
   - Commuter "Provides Payment Info"
   - Machine "Processes Payment"

3. Payment Decision (Diamond symbol represents decision point):
   Two payment paths are shown:
   - [pay with card]: Routes to Bank for "Authorize Card Payment"
   - [pay with cash]: Proceeds directly to "Dispense Ticket"

4. Ticket and Change Handling:
   - Machine "Dispenses Ticket" (represented as an object 'Ticket')
   - Commuter "Gets Ticket"
   - If paid with cash & requires change (condition shown in diamond):
     * Machine "Dispenses Change" (represented as an object 'Change')
     * Commuter "Gets Change"

5. Conclusion:
   - Process ends with "Show Thank You" message
   - Reaches final state (black circle with ring)

Key Features of the Diagram:
1. Swimlanes:
   - Clearly separates responsibilities between Commuter, Machine, and Bank
   - Shows which entity is responsible for each action

2. Control Flow:
   - Arrows showing the sequence of activities
   - Decision points for payment method and change handling

3. Object Flows:
   - 'Ticket' and 'Change' shown as objects being passed
   - Demonstrates physical items being transferred

4. Decision Points:
   - Payment method selection
   - Change dispensing condition

This diagram effectively shows:
- The complete ticket purchasing process
- Clear separation of responsibilities
- Both card and cash payment flows
- Object handling (ticket and change)
- System boundaries and interactions
- Sequential flow of activities


**Activity Diagram Representation**:

![image](https://github.com/user-attachments/assets/839d4b31-348a-42eb-8c20-5c32b717baa9)


### **Results**
The **Activity Diagrams** effectively represent the **business flows** for both **Library Book Borrowing** and **Online Purchase** processes. The diagrams clearly show the flow of activities, decision points, and parallel processes.

### **Conclusion**
This practical demonstrates the importance of **Activity Diagrams** in visualizing and understanding business processes. By using decision points and parallel flows, we can model complex workflows efficiently. These diagrams are crucial for designing and analyzing business and system processes.

<hr>

### **Review Questions**

**Q1. What are the elements of an activity diagram?**  
**A:** Key elements of an **activity diagram** include:
- **Action**: A single step in the workflow.
- **Activity**: A set of actions representing a larger process.
- **Control Nodes**: Include start nodes, end nodes, decision nodes, merge nodes, fork nodes, and join nodes.
- **Object Nodes**: Represent objects involved in the workflow.
- **Swimlanes**: Divide actions based on roles or responsibilities.



**Q2. What are the advantages of an activity diagram?**  
**A:** **Advantages** of activity diagrams:
- **Visualizes workflows** in complex systems.
- Helps in **identifying parallel processes** and **decision points**.
- Useful for **capturing requirements** and **documenting business processes**.
- Provides a clear **overview of system dynamics** and aids in better design.


**Q3. Which control elements are used in an activity diagram?**  
**A:** **Control elements** in activity diagrams include:
- **Start Node**: Marks the beginning of the process.
- **End Node**: Indicates the completion of the process.
- **Decision Node**: Represents branching based on conditions.
- **Merge Node**: Combines multiple flows into one.
- **Fork Node**: Splits a flow into parallel paths.
- **Join Node**: Merges parallel paths back into a single flow.



**Q4. How to show parallel flows in UML?**  
**A:** **Parallel flows** in UML activity diagrams are shown using:
- **Fork Nodes**: Split a single flow into multiple parallel flows.
- **Join Nodes**: Merge parallel flows back into a single flow after they complete.


**Q5. What is an action and activity?**  
**A:**  
- **Action**: Represents a **single atomic task** in the workflow (e.g., sending an email).
- **Activity**: Comprises **multiple actions** and represents a broader workflow or process (e.g., processing a customer order). Actions are the building blocks of activities.
