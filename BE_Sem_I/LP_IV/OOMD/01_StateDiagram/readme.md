##  01. State Model Diagram

### **Objective**
The goal of this practical is to design a **State Model** for a telephone line, highlighting various states and activities such as "Idle", "Off-hook", "Dialing", "Ringing", and "Talking".

### **Theory**
A **State Model** represents the various states of an object and transitions between those states based on specific events. For a telephone line, we will model the following key states:
- **Idle**: The telephone line is ready but not in use.
- **Off-hook**: The user picks up the receiver.
- **Dialing**: The user is dialing a number.
- **Ringing**: The phone is ringing, waiting for the receiver to pick up.
- **Talking**: The line is in use for communication.
- **On-hook**: The user hangs up the receiver.

### **Procedure**
1. Identify the various states of the telephone line.
2. Define the events that trigger state transitions.
3. Draw the state model using the **UML State Diagram** notation.

### **Design Model**
#### **State Model Diagram**
- States: Idle, Off-hook, Dialing, Ringing, Talking, On-hook.
- Transitions: 
  - From **Idle** → **Off-hook** (user picks up the receiver).
  - From **Off-hook** → **Dialing** (user starts dialing).
  - From **Dialing** → **Ringing** (call is being connected).
  - From **Ringing** → **Talking** (user answers the call).
  - From **Talking** → **On-hook** (call ends and receiver is hung up).
  - From **On-hook** → **Idle** (telephone line returns to idle state).

![The-telephone-system-state-machine-diagram](https://github.com/user-attachments/assets/9d3e248d-9b90-49c1-b1a5-e9caf87acf4d)


### **Code Implementation**
For this model, a simplified version might involve handling state transitions using a state machine. Below is an example of a basic state transition structure in Java:

```java
public class TelephoneLine {
    enum State {
        IDLE, OFF_HOOK, DIALING, RINGING, TALKING, ON_HOOK
    }
    
    private State currentState;

    public TelephoneLine() {
        currentState = State.IDLE;
    }

    public void pickUpReceiver() {
        if (currentState == State.IDLE) {
            currentState = State.OFF_HOOK;
        }
    }

    public void dialNumber() {
        if (currentState == State.OFF_HOOK) {
            currentState = State.DIALING;
        }
    }

    public void answerCall() {
        if (currentState == State.RINGING) {
            currentState = State.TALKING;
        }
    }

    public void hangUp() {
        if (currentState == State.TALKING) {
            currentState = State.ON_HOOK;
        }
    }

    public State getCurrentState() {
        return currentState;
    }
}
```

### **Results**
The state model was successfully created to represent the life cycle of a telephone line, and the system transitions between various states based on actions like picking up the receiver, dialing, answering, and hanging up.

### **Conclusion**
This practical helped reinforce the understanding of state modeling and its application to real-world systems like a telephone line.

--- 

Adjust the **state diagram image** and **code implementation** based on your actual work for the practical.
